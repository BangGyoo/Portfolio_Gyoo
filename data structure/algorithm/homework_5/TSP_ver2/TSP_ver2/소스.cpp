#include <iostream>
#include <stack>

#define MAX_SIZE 5
#define POW_16(x) (1<<((x)*4))				// 자릿수 , 이값과 해당 도시의 num을 곱한다.
#define RIGHT_16(x) >>((x)*4)
using namespace std;


int WEIGHT[MAX_SIZE][MAX_SIZE] = { { 0 , 14,  4, 10, 20 },
					 			   { 14 ,  0,  7,  8,  7 },
								   { 4 ,  5,  0,  7, 16 },
								   { 11 ,  7,  9,  0,  2 },
								   { 18 ,  7, 17,  4,  0 }
};


class Node {
public :
	int items;					// 0x16 으로 0이면 null, 1~f까지 각각 도시
	int bound;
	int MSB;					// items의 최상위비트 확인

	Node(int items) {
		this->items = items;
	}

	bool hasBeenCompleted() {
		if ((MSB) > MAX_SIZE-1) return true; // 최상위 비트가 값이 있으면 모두 다 찾았다는 뜻
		else return false;
	}
};

int SearchFlag(Node setting) {
	int searchedFlag = 0x0;
	for (int i = setting.items; i > 0x0; i = i RIGHT_16(1)) {
		searchedFlag += 1 << (i%POW_16(1) - 1);
	}
	return searchedFlag;
}
void Display(Node nowPos) {
	for (int i = nowPos.items; i > 0x0; i = i RIGHT_16(1)) {
		cout  << (i % POW_16(1)) << "->";
	}
	cout << endl;
	
}

int IsBound(Node setting) {
	int pos = setting.items;
	int current = 0, bound = 0;
	int prev = pos % POW_16(1);
	int next = (pos % POW_16(2)) RIGHT_16(1);
	int searchedFlag = 0x1;					// 나머지 bound 값을 찾기위해 이전 값을 제외하는 것에 이용 0,1로 비트 연산
	
	while (next) {
		
		searchedFlag += (1 << (prev - 1));		// 0번부터 첫번째 도시이다.

		current += WEIGHT[prev-1][next-1];
		pos = pos RIGHT_16(1);
		prev = pos % POW_16(1);
		next = (pos % POW_16(2)) RIGHT_16(1);
	}
	int notVisitedFlag = searchedFlag ^ ((1<< MAX_SIZE) - 1);
	
	for (int flag = notVisitedFlag,i = 0; flag > 0x0; flag = flag >> 1) {
		int min = 0xffffff;
		if (flag % 2) {
			for (int j = 0; j < MAX_SIZE; j++) if (min > WEIGHT[i][j] && i != j)
				min = WEIGHT[i][j];
			//cout << min << " + ";
			bound += min;
		}
		i++;
	}

	return current + bound;
}


stack <Node> backTrack;		

void TSP_ver2() {
	
	Node first(0x1);
	first.MSB = 1;
	first.bound = IsBound(first);
	backTrack.push(first);
	Node value(0x0);
	value.bound = 0xffffff;

	while (!backTrack.empty()) {
		Node nowNode = backTrack.top();
		backTrack.pop();
		Display(nowNode);


		if(value.bound > nowNode.bound){
			if (!nowNode.hasBeenCompleted()) {
				int searchedFlag = SearchFlag(nowNode);
				int notVisitedFlag = searchedFlag ^ ((1 << MAX_SIZE) - 1);
				for (int i = notVisitedFlag, city = 1; i > 0x0; i = i >> 1,city++) {
					if (i % 2) {
						Node insertedNode ((nowNode.items * POW_16(1)) + city);
						insertedNode.MSB = nowNode.MSB + 1;
						insertedNode.bound = IsBound(insertedNode);
						
						backTrack.push(insertedNode);
					}
				}
			}
			else {
				nowNode.bound += WEIGHT[0][(nowNode.items % POW_16(1)) - 1];
				nowNode.items = nowNode.items * POW_16(1) + 1;
				if (value.bound > nowNode.bound) {
					value.items = nowNode.items;
					value.bound = nowNode.bound;
					value.MSB = nowNode.MSB;
					Display(nowNode);
					cout << "최저 비용이 " << value.bound << "로 갱신" << endl;
				}
			}
		}
		else {
			cout << "bound = " << nowNode.bound << ", value = " << value.bound << endl;
			cout << "bound 값이 현재 value 비용보다 크다. back Tracking" << endl;
		}
	}
	cout << "최종 결과" << endl;
	Display(value);
}

int main() {

	TSP_ver2();

	system("pause");
	return 0;
}