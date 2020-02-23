#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

#define TRUE 1
#define FALSE 0

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

int free_seats=10;
double profit=0.0;


void init(HeapType *h){
	h->heap_size =0;
}

int is_empty(HeapType *h)
{
	if( h->heap_size == 0 )
		return TRUE;
	else
		return FALSE;
}

void insert_max_heap(HeapType *h, element item) 
 {
    int i; 
    i = ++(h->heap_size); 

    //  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while((i != 1) && (item.key > h->heap[i/2].key)) {
	   h->heap[i] = h->heap[i/2]; 
       i /= 2; 
    }
    h->heap[i] = item;     // 새로운 노드를 삽입
 }

// 삭제 함수
element delete_max_heap(HeapType *h) 
{ 
    int parent, child; 
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;	
    child = 2;
    while( child <= h->heap_size ) {
	  // 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
	  if( ( child < h->heap_size ) && 
	      (h->heap[child].key) < h->heap[child+1].key)
	      child++;
	  if( temp.key >= h->heap[child].key ) break;
	  // 한단계 아래로 이동
	  h->heap[parent] = h->heap[child];
	  parent = child;
	  child *= 2;
    }
    h->heap[parent] = temp;
    return item;
 }


void search_node(HeapType *h, int key){
	int i= 0;
	while(i != h->heap_size ){
		if(h->heap[i].key == key){
			printf("Found %d at [%d], comp_cnt: %d\n",key,i,i);	
			return ;
			
		}
	i++;
	}
	printf("not Found %d, comp_cnt: %d\n",key,i);
}
//void search_node(HeapType *h, int key){
//	int i=1;		// 히프어레이 넘버 
//	int count = 1;
//
//	while( key < h->heap[i].key || i < h->heap_size ){
//		if( key == h->heap[i].key ){
//			printf("Found %d at [%d], comp_cnt: %d\n",key,i,count);	
//			return ;
//		}
//		else if(h->heap[i].key > h->heap[2*i+1].key) i = 2*i;
//		else i = 2*i + 1;
//		count++;
//	}
//	printf("not Found %d, comp_cnt: %d\n",key,count);
//}


void main()
{
	element e[10];
	e[0].key = 170;
	e[1].key = 150;
	e[2].key = 160;	
	e[3].key = 10;
	e[4].key = 90;
	e[5].key = 5;
	e[6].key = 40;
	e[7].key = 30;	
	e[8].key = 100;
	e[9].key = 60;
	HeapType heap;	// 히프 생성
	init(&heap);		// 초기화
	// 삽입
	int i;
	for(i=0; i<10;i++){
		insert_max_heap(&heap, e[i]);
	}
	search_node(&heap, 30);
	search_node(&heap, 9);
	
	for(i=0; i<10; i++){
		printf("< %d >",delete_max_heap(&heap));
	}
}
