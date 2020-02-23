#include <stdio.h>
#include <stdlib.h>
#include "Normal_Array_Stack.h"
#define MAX_ELEMENT 2000
#define TRUE 1
#define FALSE 0

// 초기화 함수1
typedef struct TreeNode {
	int weight;
	char character;
	struct TreeNode *left_child;
	struct TreeNode *right_child;
} TreeNode;

typedef struct _element{
	TreeNode *ptree;
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

init(HeapType *h)
{
	h->heap_size =0;
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
// 이진 트리 생성 함수
TreeNode *make_tree(TreeNode *left, TreeNode *right)
{
	TreeNode *node= (TreeNode *)malloc(sizeof(TreeNode));
	if( node == NULL ){
		fprintf(stderr,"메모리 에러\n");
		exit(1);
	}
	node->left_child = left;
	node->right_child = right;
	return node;
}
// 이진 트리 제거 함수
void destroy_tree(TreeNode *root)
{
	if( root == NULL ) return ;
	destroy_tree(root->left_child);
	destroy_tree(root->right_child);
	free(root);
}
void Print_tree(TreeNode *root,boolean where){
	
	if(where == 0 || where == 1)	Push(where);	
	if( root->left_child == NULL && root->right_child == NULL ){
		printf("%d\t|%c\t|",root->weight,root->character);
		Print_Stack();
		Pop();		
		printf("\n");
		return ;
	}

	Print_tree(root->left_child,1);		
	Print_tree(root->right_child,0);

	top = 0;
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
void huffman_tree(int freq[], int n,char node_Name[])
{
	int i;
	TreeNode *node, *x;
	HeapType heap;
	element e, e1, e2;
	init(&heap);
	for(i=0;i<n;i++){
		node = make_tree(NULL, NULL);
		node->character = node_Name[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(&heap, e);
	}
	for(i=1;i<n;i++){
		// 최소값을 가지는 두개의 노드를 삭제
		e1 = delete_min_heap(&heap);
		e2 = delete_min_heap(&heap);
		// 두개의 노드를 합친다.
		x = make_tree(e1.ptree, e2.ptree); 
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		insert_min_heap(&heap, e);
	}
	e = delete_min_heap(&heap); // 최종 트리

	Print_tree(e.ptree,-1);
	destroy_tree(e.ptree);	
}



void main()
{
	int freq[] = { 23, 1, 1, 1, 11,8,5,11,6,2,9,5,7,8,14,6,8,10,9,4,1,3 };
	char node_Name[] = { ' ',',','H','I','a','c','d','e','f','h','i','l','m','n'
	,'o','p','r','s','t','u','x','y'};
	huffman_tree(freq,22,node_Name);
}

