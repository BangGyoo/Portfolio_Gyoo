#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define ARRIVAL 1
#define ORDER 2
#define LEAVE 3
#define TRUE 1
#define FALSE 0

// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�

//typedef struct {
//	int key;
//} element;

typedef struct {
	int type;	// �̺�Ʈ�� ����
	int key;	// �̺�Ʈ�� �Ͼ �ð�
	int number;	// ���� ����
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
// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
while((i != 1) && (item.key < h->heap[i/2].key)){ 
	 h->heap[i] = h->heap[i/2]; 
i /= 2; 
} 
h->heap[i] = item; // ���ο� ��带 ����
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

    //  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
    while((i != 1) && (item.key > h->heap[i/2].key)) {
	   h->heap[i] = h->heap[i/2]; 
       i /= 2; 
    }
    h->heap[i] = item;     // ���ο� ��带 ����
 }
 

// ���� �Լ�
element delete_max_heap(HeapType *h) 
{ 
    int parent, child; 
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;	
    child = 2;
    while( child <= h->heap_size ) {
	  // ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
	  if( ( child < h->heap_size ) && 
	      (h->heap[child].key) < h->heap[child+1].key)
	      child++;
	  if( temp.key >= h->heap[child].key ) break;
	  // �Ѵܰ� �Ʒ��� �̵�
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
// �ڸ��� �����ϸ� �� �ڸ����� �������ŭ ���ҽ�Ų��.
int is_seat_available(int number)
{
	printf("%d���� �� ����\n", number);
	if( free_seats >= number ){
		free_seats -= number;
		return TRUE;
	}
	else {
		printf("�ڸ��� ��� ����\n");
		return FALSE;
	}
}
void order(int scoops)
{
	printf("���̽�ũ�� %d�� �ֹ� ����\n", scoops);
	profit += 0.35 * scoops;
}
// ���� ������ ���ڸ����� ������Ų��.
void leave(int number)
{
	printf("%d���� ������ ����\n", number);
	free_seats += number;
}
void process_event(HeapType *heap, element e)
{
	int i=0;
	element new_event;
	
	printf("���� �ð�=%d\n", e.key);
	switch(e.type){
	case ARRIVAL:
		// �ڸ��� �����ϸ� �ֹ� �̺�Ʈ�� �����.
		if( is_seat_available(e.number) ){
			new_event.type=ORDER;
			new_event.key = e.key + 1 + random(4);
			new_event.number=e.number;
			insert_min_heap(heap, new_event);
		}
		break;
	case ORDER:
		// �������ŭ �ֹ��� �޴´�.
		for (i = 0; i < e.number; i++){
	 		order(1 + random(3));
		}
		// ������ ������ �̺�Ʈ�� �����Ѵ�.
		new_event.type=LEAVE;
		new_event.key = e.key + 1 + random(10);
		new_event.number=e.number;
		insert_min_heap(heap, new_event);
		break;
	case LEAVE:
		// ���� ������ ���ڸ����� ������Ų��.
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
// ó���� ��� �ʱ� �̺�Ʈ�� ������Ų��.
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
printf("��ü �������� =%f�Դϴ�.\n ", profit);
}


//void main()
//{
//	element e1={10}, e2={5}, e3={30};
//	element e4, e5, e6;
//	HeapType heap;	// ���� ����
//	init(&heap);		// �ʱ�ȭ
//	// ����
//	insert_max_heap(&heap, e1);
//	insert_max_heap(&heap, e2);
//	insert_max_heap(&heap, e3);
////	print_heap(&heap);
//	// ����
//	e4 = delete_max_heap(&heap);
//	printf("< %d > ", e4.key);
//	e5 = delete_max_heap(&heap);
//	printf("< %d > ", e5.key);
//	e6 = delete_max_heap(&heap);
//	printf("< %d > ", e6.key);
//}

