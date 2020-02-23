#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 100		// 이큐는 사이즈 제한이 있어서, 제한 있게 사용하기 괜찮다. 
#define TRUE			1		// 1회성 큐다. 전역변수로 하나만 쓸거. 
#define FALSE			0

typedef short boolean;
typedef int element;

Array_Queue[MAX_ARRAY_SIZE];
rear  = 0;
front = 0;						// 최초 Init 선언

boolean Is_Empty_Queue(Array_Queue){
	return (rear == front);
}


boolean Is_Full_Queue(Array_Queue){
	return ()
}


//
//Is_Empty_Queue
//
//CreateQueue
//Enqueue
//Dequeue 
