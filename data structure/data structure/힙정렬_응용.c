#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define ARRIVAL 1
#define ORDER 2
#define LEAVE 3
#define TRUE 1
#define FALSE 0

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수

//typedef struct {
//	int key;
//} element;

typedef struct {
	int type;	// 이벤트의 종류
	int key;	// 이벤트가 일어난 시각
	int number;	// 고객의 숫자
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

void insert_min_heap(HeapType *h, element item) 
{ 
int i; 
i = ++(h->heap_size); 
// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
while((i != 1) && (item.key < h->heap[i/2].key)){ 
	 h->heap[i] = h->heap[i/2]; 
i /= 2; 
} 
h->heap[i] = item; // 새로운 노드를 삽입
} 


element delete_min_heap(HeapType *h) 
{ 
int parent, child; 
element item, temp;
item = h->heap[1];
temp = h->heap[(h->heap_size)--];
parent = 1;	
child = 2;
while( child <= h->heap_size ){
	 if( ( child < h->heap_size ) && 
	 (h->heap[child].key) > h->heap[child+1].key)
	 child++;
	 if( temp.key <= h->heap[child].key ) break;
	 h->heap[parent] = h->heap[child];
	 parent = child;
	 child *= 2;
}
h->heap[parent] = temp;
return item;
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

void heap_sort(element a[], int n)
{
	int i;
	HeapType h;

	init(&h);
	for(i=0;i<n;i++){
		insert_max_heap(&h, a[i]);
	}
	for(i=(n-1);i>=0;i--){
		a[i] = delete_max_heap(&h);
	}
}
int random(int n)
{
return rand() % n;
}
// 자리가 가능하면 빈 자리수를 사람수만큼 감소시킨다.
int is_seat_available(int number)
{
	printf("%d명의 고객 도착\n", number);
	if( free_seats >= number ){
		free_seats -= number;
		return TRUE;
	}
	else {
		printf("자리가 없어서 떠남\n");
		return FALSE;
	}
}
void order(int scoops)
{
	printf("아이스크림 %d개 주문 받음\n", scoops);
	profit += 0.35 * scoops;
}
// 고객이 떠나면 빈자리수를 증가시킨다.
void leave(int number)
{
	printf("%d명이 매장을 떠남\n", number);
	free_seats += number;
}
void process_event(HeapType *heap, element e)
{
	int i=0;
	element new_event;
	
	printf("현재 시간=%d\n", e.key);
	switch(e.type){
	case ARRIVAL:
		// 자리가 가능하면 주문 이벤트를 만든다.
		if( is_seat_available(e.number) ){
			new_event.type=ORDER;
			new_event.key = e.key + 1 + random(4);
			new_event.number=e.number;
			insert_min_heap(heap, new_event);
		}
		break;
	case ORDER:
		// 사람수만큼 주문을 받는다.
		for (i = 0; i < e.number; i++){
	 		order(1 + random(3));
		}
		// 매장을 떠나는 이벤트를 생성한다.
		new_event.type=LEAVE;
		new_event.key = e.key + 1 + random(10);
		new_event.number=e.number;
		insert_min_heap(heap, new_event);
		break;
	case LEAVE:
		// 고객이 떠나면 빈자리수를 증가시킨다.
		leave(e.number);
		break;
	}
}

int main()
{
element event;
HeapType heap;
unsigned int t = 0;

init(&heap);
// 처음에 몇개의 초기 이벤트를 생성시킨다.
while (t < 5) {
t += random(6);
	 event.type = ARRIVAL;
	 event.key = t;
	 event.number = 1 + random(4);
	 insert_min_heap(&heap, event);
}
while (!is_empty(&heap)) {
	 event = delete_min_heap(&heap);
	 process_event(&heap, event);
}
printf("전체 순이익은 =%f입니다.\n ", profit);
}


//void main()
//{
//	element e1={10}, e2={5}, e3={30};
//	element e4, e5, e6;
//	HeapType heap;	// 히프 생성
//	init(&heap);		// 초기화
//	// 삽입
//	insert_max_heap(&heap, e1);
//	insert_max_heap(&heap, e2);
//	insert_max_heap(&heap, e3);
////	print_heap(&heap);
//	// 삭제
//	e4 = delete_max_heap(&heap);
//	printf("< %d > ", e4.key);
//	e5 = delete_max_heap(&heap);
//	printf("< %d > ", e5.key);
//	e6 = delete_max_heap(&heap);
//	printf("< %d > ", e6.key);
//}

