#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

// �� ��������� �߿��Ѱ� �ϳ��� ���Ÿ� ����ϸ� �ɵ�, ������ ������ �ȵ�. 
typedef int element;
typedef short boolean;

element Stack[MAX_STACK_SIZE];
int top;

void InitStack(){
	top = -1;
	return ;
}
boolean Is_Empty_Stack(){
	return (top==-1);
}

boolean Is_Full_Stack(){
	return (top==MAX_STACK_SIZE-1);
}

void Push(element item){
	if(Is_Full_Stack() == TRUE){
		fprintf(stderr,"Stack is Ful\n");
		return ;
	}	
	Stack[++top] = item;
	return ;
}

element Pop(){
	if(Is_Empty_Stack()){
		fprintf(stderr,"Stack is empty\n");
		return 0;
	}
	return Stack[top--];
}

element Peek(){
	if(Is_Empty_Stack()){
		fprintf(stderr,"Stack is empty\n");
		return 0;		
	}
	return Stack[top];
}
