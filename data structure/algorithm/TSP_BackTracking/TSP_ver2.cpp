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
	
	for (int flag = notVisitedFlag,i = 0; flag > 0x0; flag = flag >> 1) {			// 교수님이 구현한 코드와 다소 다르다. 도착지를 1로 잡아놓고 반대로 도착부터 경로를 구하고있다. 
		int min = 0xffffff;															// 기존에 탐색한 노드를 제외한 city를 찾아서 최소값을 더한다. 
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
	Node value(0x0);					// // 초기화 
	value.bound = 0xffffff;						

	while (!backTrack.empty()) {
		Node nowNode = backTrack.top();				// back Tracking을 하기위한 stack 이다. 
		backTrack.pop();
		Display(nowNode);


		if(value.bound > nowNode.bound){
			if (!nowNode.hasBeenCompleted()) {
				int searchedFlag = SearchFlag(nowNode);
				int notVisitedFlag = searchedFlag ^ ((1 << MAX_SIZE) - 1);
				for (int i = notVisitedFlag, city = 1; i > 0x0; i = i >> 1,city++) {		// 이미간 city를 제외한 다음 갈수 있는 city를 구한다.
					if (i % 2) {
						Node insertedNode ((nowNode.items * POW_16(1)) + city);				 
						insertedNode.MSB = nowNode.MSB + 1;
						insertedNode.bound = IsBound(insertedNode);
						
						backTrack.push(insertedNode); 								// 갈수 있는 city를 stack에 넣어 갱신 
					}
				}
			}
			else {
				nowNode.bound += WEIGHT[0][(nowNode.items % POW_16(1)) - 1];		// 최종적으로 완성된 루트에 출발지와 도착지를 맞추기 위하여 연산한다. 
				nowNode.items = nowNode.items * POW_16(1) + 1;
				if (value.bound > nowNode.bound) {									// 이때 더해진 값들도 더 커질수 있기 때문에 분기문을 사용하였다. 
					value.items = nowNode.items;
					value.bound = nowNode.bound;
					value.MSB = nowNode.MSB;
					Display(nowNode);
					cout << "최저 비용이 " << value.bound << "로 갱신" << endl;
				}
			}
		}
		else {																		// 분기 한정법에 의하여 이미 지금의 결과값이 기대값보다 작으므로 이 이상의 연산은 필요 x 
			cout << "bound = " << nowNode.bound << ", value = " << value.bound << endl;
			cout << "bound 값이 현재 value 비용보다 크다. back Tracking" << endl;
		}
	}
	cout << "최종 결과" << endl;
	Display(value);
	cout << "최단 : "  << value.bound << endl;
}

int main() {

	TSP_ver2();

	system("pause");
	return 0;
}
