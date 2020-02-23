#include <stdio.h>
#define MAX_VERTICES 100
#define INF 1000
// ���α׷� 10.7�� union-find ���α׷� ����
// ...
// ������ ��� Ÿ�� ����
typedef struct {
	int key; 	// ������ ����ġ
	int u; 	// ���� 1
	int v; 	// ���� 2
} element;
// ���α׷� 8.5 �߿��� �ּ� ���� ���α׷� ����
// ...
// ���� u�� ���� v�� �����ϴ� ����ġ�� weight�� ������ ������ ����
void insert_heap_edge(HeapType *h, int u, int v, int weight) {
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;
	insert_min_heap(h, e);
}
// ���� ����̳� ���� ����Ʈ���� �������� �о �ּ� ������ ����
// ����� ���� �׷����� �������� �����Ѵ�.
void insert_all_edges(HeapType *h) {
	insert_heap_edge(h, 0, 1, 29);
	insert_heap_edge(h, 1, 2, 16);
	insert_heap_edge(h, 2, 3, 12);
	insert_heap_edge(h, 3, 4, 22);
	insert_heap_edge(h, 4, 5, 27);
	insert_heap_edge(h, 5, 0, 10);
	insert_heap_edge(h, 6, 1, 15);
	insert_heap_edge(h, 6, 3, 18);
	insert_heap_edge(h, 6, 4, 25);
}


int parent[MAX_VERTICES]; 	// �θ� ���
int num[MAX_VERTICES]; 	// �� ������ ũ��
// �ʱ�ȭ
void set_init(int n)		
{int i;
for(i=0;i<n;i++){
	parent[i] = -1;
	num[i] = 1;
	}
}
 // vertex�� ���ϴ� ���� ��ȯ
int set_find(int vertex)		
{
     int p, s, i=-1;
     for(i=vertex;(p=parent[i])>=0;i=p) ;	// ��Ʈ ������ �ݺ�
     s = i; 				// ������ ��ǥ ����
     for(i=vertex;(p=parent[i])>=0;i=p)
	parent[i] = s; 		// ������ ��� ���ҵ��� �θ� s�� ����
     return s;
}
// �� ���� ���Ұ� ���� ������ ����
void set_union(int s1, int s2)	
{
     if( num[s1] < num[s2] ){
         parent[s1] = s2;
         num[s2] += num[s1];
    }
     else {
           parent[s2] = s1;
           num[s1] += num[s2];
    }
}
// kruskal�� �ּ� ��� ���� Ʈ�� ���α׷�
void kruskal(int n)
{
int edge_accepted=0; 	// ������� ���õ� ������ ��
HeapType h; 		// �ּ� ����
int uset, vset; 	// ���� u�� ���� v�� ���� ��ȣ
element e; 		// ���� ���
init(&h); 		// ���� �ʱ�ȭ
insert_all_edges(&h); 	// ������ �������� ����
set_init(n); 		// ���� �ʱ�ȭ
while( edge_accepted < (n-1) ) // ������ �� < (n-1)
	{
	e = delete_min_heap(&h); 	// �ּ� �������� ����
	uset = set_find(e.u); 		// ���� u�� ���� ��ȣ
	vset = set_find(e.v); 		// ���� v�� ���� ��ȣ
	if( uset != vset ){ 		// ���� ���� ������ �ٸ���
		printf("(%d,%d) %d \n",e.u, e.v, e.key);
		edge_accepted++;
		set_union(uset, vset); 	// �ΰ��� ������ ��ģ��.
		}
	}
}
//
main()
{
kruskal(7);
}

