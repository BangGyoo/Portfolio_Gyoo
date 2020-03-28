#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
	
#define STACK_SIZE 30*1024*1024				// 12MByte 정도
#define SWAP(X,Y) {dataType temp; temp = X; X=Y; Y=temp; }
typedef int dataType;					// Range of INT_MAX is from -2,147,483,648 to 2,147,438,647


enum Alignment {					//오름차순 내림차순 설정
	ascendingOrder = 0x1,
	descendingOrder = 0x2
};

typedef struct _Node {
	dataType low;
	dataType high;
}Node;

typedef struct _Stack {
	Node *top;
	int length;
}Stack;

void InitStack(Stack *const stack, const int size) {
	stack->top = (Node*)malloc(sizeof(Node)*size);
	stack->length = 0;
}

void PushStack(Stack *const stack, const dataType lowOfPartition, const dataType highOfPartition) {
	int length = ++(stack->length);
	stack->top[length].low = lowOfPartition;
	stack->top[length].high = highOfPartition;
}

Node *PopStackOrNull(Stack *const stack) {

	if (stack->length == 0) return NULL;			// 스택 값 x

	int length = (stack->length);
	stack->length = (stack->length) - 1;

	return &(stack->top[length]);

}

void DeleteStack(Stack **const stack) {					// 댕글링 포인터 제거를 위해 이중 포인터 사용
	free((*stack)->top);
	(*stack)->top = NULL;
	free(*stack);
	*stack = NULL;
}

void InitArray(dataType *const data, const int setting,const int arraySize) {			// setting은 오름차순 내림차순 결정, 가급적이면 enum상수를 사용하기 권장

	register dataType i;
	if (setting & ascendingOrder) for (i = 0; i < arraySize; i++) data[i] = i + 1;
	else for (i = 0; i < arraySize; i++) data[i] = arraySize - i;
}

void MakeNonsortedArray(dataType *const data, const int gab,const int arraySize) {			// 랜덤이 최대 0x8000 까지 이므로 사이즈보다 큰 rand를 사용하기 위해 2회사용
	register dataType i;
	for (i = 0; i < arraySize; i += gab) {
		dataType passer = ((dataType)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1)*arraySize));
		SWAP(data[i], data[passer]);
	}
	printf("준비완료\n");
}

double CheckRegular(const dataType *data, const dataType n) {				// 임시 고안한 함수,배열의 복잡도 조사에 사용되었다. 0.0<=result<=1.0이 반환되며 오름차순 내림차순 유무를 판단
	dataType checkerUp = 0;
	dataType checkerDown = 0;
	register dataType i;
	for (i = 0; i < n; i++) {
		if (data[i + 1] > data[i]) checkerUp++;
		else checkerDown++;
	}
	(checkerUp > checkerDown ? printf("Up\n") : printf("Down\n"));			// 오름차순 내림차순 확인
	return (checkerUp > checkerDown ? ((double)checkerUp / n - 0.5)*2.0 : ((double)checkerDown / n - 0.5)*2.0);
}
/*
void InsertionSort(dataType *const data, const dataType n) {		// 데이터 복사를 이용한 InsertionSort이지만.. array가 10M이상일 때는 효율이 급격히 감소, 적은양일 때 퀵소트 개선에 사용
	register dataType i, j, item;
	for (i = n - 1; i >= 0; i--) {
		item = data[i];
		if (data[i] < data[i + 1]) continue;
		for (j = i; j<n - 1; j++) {
			if (data[i] > data[j] && data[i] < data[j + 1]) break;
		}
		if (data[i] > data[j]) {
			memcpy(data + i, data + i + 1, sizeof(*data) * (j - i));
			data[j] = item;
		}
	}
}
*/
void QuickSort(dataType *const data, const dataType arrayStart, const dataType arrayEnd) {		// arrayStart == pivot이다.				
	dataType pivot = arrayStart;
	dataType end = arrayEnd;
	dataType dataOfPivot;
	register dataType  low, high;
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	Node *partition;

	InitStack(stack, STACK_SIZE);
	PushStack(stack, pivot, end);
	while (stack->length > 0) {
		partition = PopStackOrNull(stack);

		end = partition->high;
		pivot = partition->low;
		low = pivot, high = pivot + 1;
		dataOfPivot = data[pivot];

		while (high <= end) {
			if (dataOfPivot > data[high]) {
				++low;
				SWAP(data[low], data[high]);
			}
			++high;
		}
		SWAP(data[pivot], data[low]);
		if (pivot < end - 1) {
			PushStack(stack, pivot, low - 1);
			PushStack(stack, low + 1, end);
		}
	}
	DeleteStack(&stack);
}

double Display(int arraySize,int randomSet){
	printf("%d개 실행\n", arraySize);
	dataType *data = (dataType*)malloc(sizeof(dataType)*arraySize);
	InitArray(data, ascendingOrder,arraySize);
	srand((unsigned)time(NULL));
	time_t startTime = 0, endTime = 0;
	if(randomSet) MakeNonsortedArray(data, 1,arraySize);
	
	startTime = clock();
	double x = CheckRegular(data, arraySize);
	printf("적중률 : %f", x);
		if (x < 0.90) {								// 256 millon 기준으로 약 90% 이상은 성능이 떨어진다.
		printf("Quick Sort");
		QuickSort(data, 0, arraySize - 1);
	}
	else {										// 값 재설정 후, 복잡도 재검사(시간 비용이 들지만, 봐줄만한 정도)
		MakeNonsortedArray(data, 5,arraySize);			// 차후 속도의 최적화를 위해서는 난수 swap의 간격 최적화가 필요
		double x = CheckRegular(data, arraySize);
		printf("적중률 : %f", x);
		QuickSort(data, 0, arraySize - 1);
	}
	endTime = clock();	
	float gab = (double)(endTime - startTime) / (CLOCKS_PER_SEC);
	
	printf("총 %f 초 걸림\n", gab);
	dataType i;
	for (i = 0; i<arraySize; i++) {
		if (data[i] != i + 1) {
			fprintf(stderr,"error\n\n\n\n");
			system("pause");
			return 0;
		}
	}
	

	free(data);
	data = NULL;
	return gab;
}

void SaveToXML(int arraySize,double resultTime,int randomSet,FILE *f){
	fprintf(f,"<Field arraySize=\"%d\" time=\"%f\" randomSet=\"%s\"/>\n",arraySize,resultTime,(randomSet?"true":"false"));
}

int main(void) {
	FILE *f;	
	f = fopen("graphItem.xml","w");
	fprintf(f,"<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\" ?>\n");
	fprintf(f,"<QuickSortGraph>\n");	
	
	int arraySize;
	int randomSet;
	double resultTime;

	arraySize = 300000000;
	randomSet = 0;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	
	
	arraySize = 300000000;
	randomSet = 1;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	
	
/////////////////////////////////////////////////////////////////////////////////	
	arraySize = 400000000;
	randomSet = 0;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	
	
	arraySize = 400000000;
	randomSet = 1;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	
///////////////////////////////////////////////////////////////////////////////////	
	arraySize = 500000000;
	randomSet = 0;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	

	arraySize = 500000000;
	randomSet = 1;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	
///////////////////////////////////////////////////////////////////////////////////
	arraySize = 600000000;
	randomSet = 0;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	

	arraySize = 600000000;
	randomSet = 1;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	
////////////////////////////////////////////////////////////////////////////////////
	arraySize = 700000000;
	randomSet = 0;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	

	arraySize = 700000000;
	randomSet = 1;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	
////////////////////////////////////////////////////////////////////////////////////
	arraySize = 800000000;
	randomSet = 0;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	

	arraySize = 800000000;
	randomSet = 1;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	
////////////////////////////////////////////////////////////////////////////////////
	arraySize = 900000000;
	randomSet = 0;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	

	arraySize = 900000000;
	randomSet = 1;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	
///////////////////////////////////////////////////////////////////////////////////
	arraySize = 1000000000;
	randomSet = 0;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	

	arraySize = 1000000000;
	randomSet = 1;
	resultTime = Display(arraySize,randomSet);
	SaveToXML(arraySize,resultTime,randomSet,f);	
////////////////////////////////////////////////////////////////////////////////

	fprintf(f,"</QuickSortGraph>\n");	
	fclose(f);	
	
	system("pause");
	return 0;
}

