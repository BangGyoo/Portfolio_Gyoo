#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
int loopcount = 0; 					//��ü �������ϴ��� ī��Ʈ 

typedef struct _arrayListType{
	element list[MAX_LIST_SIZE];
	int length;
}arrayListType;  

void Error(char *message){
	fprintf(stderr, "%s\n",message);  // exit(1)�� �������Ḧ ���Ѵ�. 
	exit(1);        // but exit�� ���� �Լ��� �ƴϴ�. �������̸� return �� ���ô�. 
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

void add_last(arrayListType *L, element item){ // ����Ʈ L�� �� �������� item ����
	 L->list[L->length] = item;
	 L->length++;
}

void add_first(arrayListType*L, element item){  // ����Ʈ L �� �� ó���� item ����
	int i;
	for(i = L->length;i!=0;i--){
		L->list[i] = L->list[i-1];
		loopcount++;
		}
	L->length++;
	L->list[0] = item;
 
}

int clear(arrayListType*L){  // ����Ʈ L�� ��� �ִ� ����Ʈ�� ����
	int i;
	for(i=0;i<L->length;i++){
		L->list[i] = 0;
	}
	int firstListLength = L->length;
	L->length = 0;
	return firstListLength;
}

int replace(arrayListType *L, int pos, element item){ // ����Ʈ L�� pos ��ġ�� item���� ġȯ
	L->list[pos] = item;
	return item;
}
element get_entry(arrayListType *L, int pos){ // ����Ʈ L�� pos ��ġ�� �ִ� ���� ��ȯ
	return L->list[pos];
}
int get_length(arrayListType *L){  // ����Ʈ L�� �ִ� �������� ���� ��ȯ
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
    printf("��Ʈ �� %d\n",list1.list[list1.length-1]);
    add_first(&list1, 40);
    printf("ó�� �� %d\n",list1.list[0]);
    replace(&list1, 1, -20);
    printf("1�� ���� %d�̰�, �ѱ��̴� %d�Դϴ�.\n",get_entry(&list1, 1),get_length(&list1));
    
    
	plist = (arrayListType *)malloc(sizeof(arrayListType));
 
	printf("%d\n%d\n",list1.list[1],list1.length);
	DeleteArrayList(&list1,2);
	printf("����Ʈ�Լ� ��� %d,%d\n",list1.list[1],list1.list[2]);
	clear(&list1);
	printf("Ŭ�����Լ� ��� %d,%d\n",list1.list[1],list1.list[2]);

 	
 	printf("\n%d�� �ݺ��� ����Ͽ����ϴ�.~\n",loopcount);
	system("pause");
	return 0;
}

