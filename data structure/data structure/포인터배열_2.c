#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_ARRAY 100

typedef int element;

typedef struct _arrayType{
   int size;
   int *data;
}arrayType;

arrayType* Create(int n);

element retrieve(arrayType *array, int index); 

element store(arrayType *array, int index, element data);






int main(int argc, char *argv[]) {
	int array_number = 5;
   
   arrayType* a;
   a = Create(array_number);
   
   store(a,0,1);
   store(a,1,2);

   printf("%d\n\n",a->data[0]);
   
   printf("%d",retrieve(a,1));
   

   system("pause");
   return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
arrayType* Create(int n){
   arrayType *array; 
   array = (arrayType*)malloc(sizeof(arrayType));
   array->size = n; 
   array->data = (int*)malloc(n*sizeof(int));
   

   return array;
}

element retrieve(arrayType *array, int index){
	element outPut;
	if(array->size <= index) return -1;
	outPut = *(array->data + index);
	
	return outPut;
} 

element store(arrayType *array, int index, element data){
	if(array->size <= index) return -1;
	*(array->data + index) = data;
	return data;
}


