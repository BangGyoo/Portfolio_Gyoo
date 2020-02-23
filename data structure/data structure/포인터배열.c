#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_ARRAY_SIZE 100

typedef int element;

typedef struct _arrayType{
	int size;
	element data[MAX_ARRAY_SIZE];
}arrayType;

arrayType* Create(int n);

element Retrieve(arrayType* array, int index);

element Store(arrayType* array, int index, element data);



int main(int argc, char *argv[]) {

	arrayType* array = Create(5);
	array->data[0] = 1;
	array->data[1] = 2;
	
	printf("%d\n\n",array->data[1]);
	printf("%d",Retrieve(array,1));
	printf("%d",Store(array,2,3));
	printf("%d",array->data[2]);
	
	system("pause");
	return 0;

}

//////////////////////////////////////////////////////////////////////
arrayType* Create(int n){
	
	arrayType* array = (arrayType*)malloc(sizeof(arrayType));
	
	array->size = n;
	array->data[n];
	
	return array;
}

element Retrieve(arrayType* array, int index){
	if(array->size < index) return -1;
	
	element outPut = *(array->data + index);
	
	return outPut;
}

element Store(arrayType* array, int index, element data){
	if(array->size < index) return -1;
	*(array->data + index) = data;
	return data;
}
