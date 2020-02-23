#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
int loopcount = 0; 					//전체 몇번사용하는지 카운트 

typedef struct _arrayListType{
	element list[MAX_LIST_SIZE];
	int length;
}arrayListType;  

void Error(char *message){
	fprintf(stderr, "%s\n",message);  // exit(1)는 에러종료를 뜻한다. 
	exit(1);        // but exit는 좋은 함수가 아니다. 가급적이면 return 을 씁시다. 
}

void ClearArrayList(arrayListType *L){
	L->length = 0;
}

int Is_empty(arrayListType *L){
	return L->length == 0;
}

int Is_full(arrayListType *L){
	return L->length == MAX_LIST_SIZE;
}

int DisplayArrayList(arrayListType *L){
	int i;
	for(i = 0; i < L->length; i++){
		printf("%d",L->list[i]);
	}
	return L->length;
}

int AddArrayList(arrayListType *L,int position, element item){
	int i;
	
	if(L->length != 0){
		for(i = L->length;i!=position;i--){
			L->list[i] = L->list[i-1];
			loopcount++;
		}
	}
	L->length++;
	L->list[position] = item;
 
	return item;
}

element DeleteArrayList(arrayListType *L,int position){
	element item = L->list[position];
	int i;
	for(i=position; i != L->length; i++){
		L->list[i] = L->list[i+1];
		loopcount++;
	}
	L->length--;
	L->list[L->length] = 0;
	return item;
}

void add_last(arrayListType *L, element item){ // 리스트 L의 맨 마지막에 item 삽입
	 L->list[L->length] = item;
	 L->length++;
}

void add_first(arrayListType*L, element item){  // 리스트 L 의 맨 처음에 item 삽입
	int i;
	for(i = L->length;i!=0;i--){
		L->list[i] = L->list[i-1];
		loopcount++;
		}
	L->length++;
	L->list[0] = item;
 
}

int clear(arrayListType*L){  // 리스트 L을 비어 있는 리스트로 만듬
	int i;
	for(i=0;i<L->length;i++){
		L->list[i] = 0;
	}
	int firstListLength = L->length;
	L->length = 0;
	return firstListLength;
}

int replace(arrayListType *L, int pos, element item){ // 리스트 L의 pos 위치에 item으로 치환
	L->list[pos] = item;
	return item;
}
element get_entry(arrayListType *L, int pos){ // 리스트 L의 pos 위치에 있는 값을 반환
	return L->list[pos];
}
int get_length(arrayListType *L){  // 리스트 L에 있는 데이터의 수를 반환
	return L->length;
}
int main(int argc, char *argv[]) {
	arrayListType list1;
	arrayListType *plist;
 
	ClearArrayList(&list1);
	AddArrayList(&list1,0,10);
	printf("%d\n",list1.list[0]);
	AddArrayList(&list1,0,20);
	printf("%d\n",list1.list[0]);	
	AddArrayList(&list1,0,30);
	printf("%d\n",list1.list[0]);	
    
    add_last(&list1, -10);
    printf("라스트 값 %d\n",list1.list[list1.length-1]);
    add_first(&list1, 40);
    printf("처음 값 %d\n",list1.list[0]);
    replace(&list1, 1, -20);
    printf("1번 값은 %d이고, 총길이는 %d입니다.\n",get_entry(&list1, 1),get_length(&list1));
    
    
	plist = (arrayListType *)malloc(sizeof(arrayListType));
 
	printf("%d\n%d\n",list1.list[1],list1.length);
	DeleteArrayList(&list1,2);
	printf("딜리트함수 사용 %d,%d\n",list1.list[1],list1.list[2]);
	clear(&list1);
	printf("클리어함수 사용 %d,%d\n",list1.list[1],list1.list[2]);

 	
 	printf("\n%d번 반복문 사용하였습니다.~\n",loopcount);
	system("pause");
	return 0;
}

