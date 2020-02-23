#include <stdio.h>
#define MAX_VERTICES 100
#define INF 1000
// 프로그램 10.7의 union-find 프로그램 삽입
// ...
// 히프의 요소 타입 정의
typedef struct {
	int key; 	// 간선의 가중치
	int u; 	// 정점 1
	int v; 	// 정점 2
} element;
// 프로그램 8.5 중에서 최소 히프 프로그램 삽입
// ...
// 정점 u와 정점 v를 연결하는 가중치가 weight인 간선을 히프에 삽입
void insert_heap_edge(HeapType *h, int u, int v, int weight) {
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;
	insert_min_heap(h, e);
}
// 인접 행렬이나 인접 리스트에서 간선들을 읽어서 최소 히프에 삽입
// 현재는 예제 그래프의 간선들을 삽입한다.
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


int parent[MAX_VERTICES]; 	// 부모 노드
int num[MAX_VERTICES]; 	// 각 집합의 크기
// 초기화
void set_init(int n)		
{int i;
for(i=0;i<n;i++){
	parent[i] = -1;
	num[i] = 1;
	}
}
 // vertex가 속하는 집합 반환
int set_find(int vertex)		
{
     int p, s, i=-1;
     for(i=vertex;(p=parent[i])>=0;i=p) ;	// 루트 노드까지 반복
     s = i; 				// 집합의 대표 원소
     for(i=vertex;(p=parent[i])>=0;i=p)
	parent[i] = s; 		// 집합의 모든 원소들의 부모를 s로 설정
     return s;
}
// 두 개의 원소가 속한 집합을 합함
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
// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(int n)
{
int edge_accepted=0; 	// 현재까지 선택된 간선의 수
HeapType h; 		// 최소 히프
int uset, vset; 	// 정점 u와 정점 v의 집합 번호
element e; 		// 히프 요소
init(&h); 		// 히프 초기화
insert_all_edges(&h); 	// 히프에 간선들을 삽입
set_init(n); 		// 집합 초기화
while( edge_accepted < (n-1) ) // 간선의 수 < (n-1)
	{
	e = delete_min_heap(&h); 	// 최소 히프에서 삭제
	uset = set_find(e.u); 		// 정점 u의 집합 번호
	vset = set_find(e.v); 		// 정점 v의 집합 번호
	if( uset != vset ){ 		// 서로 속한 집합이 다르면
		printf("(%d,%d) %d \n",e.u, e.v, e.key);
		edge_accepted++;
		set_union(uset, vset); 	// 두개의 집합을 합친다.
		}
	}
}
//
main()
{
kruskal(7);
}

