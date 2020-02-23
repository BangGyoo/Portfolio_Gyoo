#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef short boolean;
typedef int element;

typedef struct _Stack{
	element *top;
	int length;
}Stack;

void InitStack(Stack **stack){
	*stack = (Stack*)malloc(sizeof(Stack));
	(*stack)->top = (element*)malloc(sizeof(element)*MAX_STACK_SIZE);
	(*stack)->length = -1;
}
boolean Is_Empty_Stack(Stack *stack){
	return (stack->length == -1);
}
boolean Is_Full_Stack(Stack *stack){
	return (stack->length > MAX_STACK_SIZE);
}

void push(Stack *stack,element item){
	if( Is_Full_Stack(stack) == TRUE ){
		fprintf(stderr,"Stack is full\n");
	}
	else{
		stack->length++;
		stack->top[stack->length] = item;
	}
	return ;
}

element Pop(Stack *stack){
	element data;
	if( Is_Empty_Stack(stack) == TRUE ){
		fprintf(stderr,"Stack is empty\n");
	}
	else{
		data = stack->top[stack->length];
		stack->length--;
	}
	return data;
}

element Peek(Stack *stack){
	element data;
	if( Is_Empty_Stack(stack) == TRUE ){
		fprintf(stderr,"Stack is empty\n");
	}
	else{
		data = stack->top[stack->length];
	}
	return data;	
}
