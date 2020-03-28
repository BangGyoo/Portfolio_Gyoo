#include <stdio.h>
#include <stdlib.h>
#define INF 0xffff						// INT_MAX로 했을 때 오버플로우 난다 주의.
#define VERTEX_SIZE 12

typedef int number;
typedef int index;

index W[VERTEX_SIZE][VERTEX_SIZE] = {
{  0 ,  7 , INF,  1 , INF, INF, INF, INF, INF, INF, INF, INF },
{  3 ,  0 ,  5 , INF,  8 , INF, INF, INF, INF, INF, INF, INF },
{ INF,  3 ,  0 , INF, INF,  3 , INF, INF, INF, INF, INF, INF },
{  3 , INF, INF,  0 ,  4 , INF,  4 , INF, INF, INF, INF, INF },
{ INF, 13 , INF,  3 ,  0 ,  1 , INF, INF, INF, INF, INF, INF },
{ INF, INF,  5 , INF,  2 ,  0 , INF,  5 , INF, INF, INF, INF },
{ INF, INF, INF,  5 , INF, INF,  0 ,  5 ,  3 ,  3 , INF, INF },
{ INF, INF, INF, INF,  2 , INF,  5 ,  0 , INF,  3 ,  3 , INF },
{ INF, INF, INF, INF, INF, INF,  3 , INF,  0 ,  6 , INF,  5 },
{ INF, INF, INF, INF, INF, INF,  6 , INF, INF,  0 ,  2 ,  1 },
{ INF, INF, INF, INF, INF, INF, INF,  1 , INF, INF,  0 ,  2 },
{ INF, INF, INF, INF, INF, INF, INF, INF,  4 , INF,  3 ,  0 }
};

number P[VERTEX_SIZE][ 1 << VERTEX_SIZE];
number minLength = INT_MAX;

char incheon = 0;
char seoul = 1;
char gangneung = 2;
char cheongan = 3;
char cheongju = 4;
char donghae = 5;
char daejeon = 6;
char uljin = 7;
char gwangju = 8;
char daegu = 9;
char ulsan = 10;
char busan = 11;

char *city[VERTEX_SIZE] = { &incheon, &seoul, &gangneung, &cheongan, &cheongju, &donghae, &daejeon, &uljin, &gwangju, &daegu, &ulsan, &busan };

void DisplayByMat() {
	char *city[VERTEX_SIZE] = { &incheon, &seoul, &gangneung, &cheongan, &cheongju, &donghae, &daejeon, &uljin, &gwangju, &daegu, &ulsan, &busan };
	int i,j;
	for (i = 0; i<VERTEX_SIZE; i++) printf("%d  ", *city[i]);
	printf("\n");
	for (i = 0; i<VERTEX_SIZE; i++) {
		for (j = 0; j<VERTEX_SIZE; j++) printf("%d   ", W[i][j]);
		printf("\n");
	}
	printf("\n\n");
	system("pause");
}


void SetStartCity(index startCity) {

	index tmp[VERTEX_SIZE];
	static int start = 0;
	

	int i, j, k;

	start = (start + startCity)%VERTEX_SIZE;
	for (i = 0; i < VERTEX_SIZE; i++) {
		*city[i] = (VERTEX_SIZE - start + i) % VERTEX_SIZE;
	}


	for (i = 0; i < startCity; i++) {
		for (j = 0; j < VERTEX_SIZE; j++) {
			tmp[j] = W[0][j];
			for (k = 1; k < VERTEX_SIZE; k++) {
				W[k - 1][j] = W[k][j];
			}

			W[VERTEX_SIZE - 1][j] = tmp[j];
		}
		for (j = 0; j < VERTEX_SIZE; j++) {
			tmp[j] = W[j][0];
			for (k = 1; k < VERTEX_SIZE; k++) {
				W[j][k - 1] = W[j][k];
			}
			W[j][VERTEX_SIZE - 1] = tmp[j];
		}
		
	}

}





number Shift(number now, index size, index k, int LSB) {
	int j, count;
	index MAX = 1 << (size-LSB);
	now = now >> LSB;

	for (now += 1; now < MAX; now++) {
		count = 0;
		for (j = 0; j < size; j++) {
			if ((1 << j) & now) count++;
		}
		if (k == count) return now<<LSB;
	}

	return -1;			
}

index SearchNotElement(number A,index i,index size) {
	
	for(i++; i < size;i++){
		if ((~A)&(1 << i)) break;
	}
	return i;
}
index SearchElement(number A, index i, index size) {
	for (i++; i < size; i++) {
		if (A&(1 << i)) break;
	}
	return i;
}

void Display(index pos) {
	if (pos == incheon)
		printf("인천");
	else if(pos == seoul)
		printf("서울");
	else if (pos == gangneung)
		printf("강릉");
	else if (pos == cheongan)
		printf("천안");
	else if (pos == cheongju)
		printf("청주");
	else if(pos == donghae)
		printf("동해");
	else if(pos == daejeon)
		printf("대전");
	else if(pos == uljin)
		printf("울진");
	else if(pos == gwangju)
		printf("광주");
	else if(pos == daegu)
		printf("대구");
	else if(pos == ulsan)
		printf("울산");
	else if(pos == busan)
		printf("부산");
}

void travel(int n, index W[][12], number P[][1<<VERTEX_SIZE], number *minlength) {
	index i, j, k;
	number A;
	number **D;
	D = (number**)malloc(sizeof(number*)*n);
	for (i = 0; i < n; i++) {	
		D[i] = (number*)malloc(sizeof(number) * 1 << n);
		for (j = 0; j < (1 << n); j++) {
			D[i][j] = INF;
		}
	}
	for (i = 1; i < n; i++)
		D[i][0x000] = W[i][0];
		
	for (k = 1; k <= n - 2; k++) {
		for (A = Shift(0x0, n, k, 1); A != -1; A = Shift(A, n, k, 1)){
			for (i = SearchNotElement(A, 0, n); i < n; i = SearchNotElement(A, i, n)) {
				for (j = SearchElement(A, 0, n); j < n; j = SearchElement(A, j, n)) {
					if (W[i][j] + D[j][A ^ (1 << (j))] < D[i][A]) {
						D[i][A] = W[i][j] + D[j][A ^ (1 << (j))];
						P[i][A] = j;
						}
					}
				}
			
			}
			
		}
	for (j = SearchElement(0xffe, 0, n); j<n; j = SearchElement(0xffe, j, n))
		if (W[0][j] + D[j][0xffe ^ (1 << (j))] < D[0][0xffe]) {
			D[0][0xffe] = W[0][j] + D[j][0xffe ^ (1 << (j))];
			P[0][0xffe] = j;
		}
	A = 0xffe;
	Display(0);
	printf("(%d)-> ", W[0][P[0][A]]);
	for (i = P[0][A]; A != 0x0 ;i = P[i][A]) {
		A = A ^ (1 << (i));
		Display(i);
		printf("(%d)-> ", W[i][P[i][A]]);
	}

	*minlength = D[0][0xffe];
	
}

int main() {
	int i;
	for (i = 0; i < 12; i++) {
		SetStartCity(1);
		travel(12, W, P, &minLength);
		printf("결과는 = %d\n\n", minLength);
	}
	system("pause");
	return 0;
}
