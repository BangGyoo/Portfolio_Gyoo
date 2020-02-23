#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 100
#define TRUE  1
#define FALSE 0

typedef int element;
typedef char boolean;

typedef struct _Heap{
	element node[MAX_ARRAY_SIZE];
	int max_Size;
}Heap;


void CreateHeap(Heap **first_Heap){								//어레이 히프를 만드는 함수 
	*first_Heap = (Heap*)malloc(sizeof(Heap));
	(*first_Heap)->max_Size = 0;
//	return TRUE;
}

boolean Heap_IsEmpty(Heap *heap){
	if(heap->max_Size == 0) return TRUE;
	else 					return FALSE;
}

void Swap(int *a,int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return ; 
}

void Node_Is_Inserted_Heap(Heap *heap,element item){
	
	heap->node[++heap->max_Size] = item;			// 노드 삽입 
	int leaf_Node = heap->max_Size; 						//  삽입된 노드가 부모 노드보다 큰지 검색 
	int parent_Node = leaf_Node/2;										 
	while( parent_Node >= 1 ){
		if(heap->node[leaf_Node] >= heap->node[parent_Node]){
			Swap(&(heap->node[leaf_Node]),&(heap->node[parent_Node]));
			leaf_Node/=2;
			parent_Node/=2;
		}
		else break;
	}
	return ;
}

element Delete_Heap(Heap *heap){
	if(Heap_IsEmpty(heap) == TRUE) return ;
	element result = heap->node[1];
	heap->node[1] = heap->node[heap->max_Size--];			//끝노드를 맨위로 올린다. 
	int key=1;
	while(key*2 + 1 <= heap->max_Size){						//자식노드가  밑에 있는지 노드확인 
		if(heap->node[key*2] > heap->node[key*2 + 1]){
			Swap(&(heap->node[key*2]),&(heap->node[key]));
		}
		else if(heap->node[key*2] < heap->node[key*2 + 1] ){
			Swap(&(heap->node[key*2+1]),&(heap->node[key]));
		}
		else{
			return result;
		}
		key = key*2; 
	}
	return result;
}


