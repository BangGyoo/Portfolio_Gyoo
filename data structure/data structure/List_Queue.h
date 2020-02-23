#include "..\ListNode\Linked_List.h"

#define TRUE 1
#define FALSE 0

typedef int boolean;

typedef struct _Queue{
	ListNode *front;
	ListNode *rear;
}Queue;


void InitQueue(Queue *queue){
	queue->front = NULL;
	queue->rear  = NULL;
	return ;
}

boolean Is_Empty_Queue(Queue *queue){
	return (queue->front == NULL);
}

boolean Is_Full_Queue(Queue *queue){
	return (NULL == malloc(sizeof(Queue)));
}

void CreateQueue(Queue **queue){
	*queue = (Queue*)malloc(sizeof(Queue));
	InitQueue(*queue);
}

void Enqueue(Queue *queue,element item){
	if(Is_Full_Queue(queue) == TRUE){
		fprintf(stderr,"Queue is full");
		return ;
	}
	ListNode *node;
	CreateNode(&node,item);
	if(queue->rear == NULL){
		queue->front= node;
		queue->rear = node;
	}
	else{
		queue->rear->next = node;
		queue->rear		  = node;
	}
	return ;
}

element Dequeue(Queue *queue){
	if(Is_Empty_Queue(queue) == TRUE){
		fprintf(stderr,"Queue is empty");
		return FALSE;
	}
	element deletion_Data = queue->front->data;
	ListNode *deletion_Node = queue->front;
	queue->front = queue->front->next;
	free(deletion_Node);
	return deletion_Data;
}

