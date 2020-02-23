#include <stdio.h>
#include <stdlib.h>

typedef int element;



typedef struct _ListNode{
	element coef;
	element expon; 
	struct _ListNode* link;
}ListNode;

typedef struct _ListHeader{
	int length;
	ListNode *head;
	ListNode *tail;
}ListHeader;

void Init(ListHeader *list){
	list->length = 0;
	list->head = NULL;
	list->tail = NULL;
}


void DeleteAll(ListHeader *list){						// Init 만들다 보니 구현... 
	
	ListNode *next = list->head;
	ListNode *deletion;	
	
	while(next != NULL){

		list->head = next;
		next->coef = 0;
		next->expon= 0;
		deletion = next;
		next = next->link;
		free(deletion);
		(list->length)--;
	}
	list->head = NULL;
	list->tail = NULL;
}


ListHeader *CreateNode(ListHeader *list,element InputExpon,element InputCoef){		// expon의 순서대로 노드를 추가한다. 
	if(list == NULL){																// list가 null일 경우 노드를 생성한다. 
		list = (ListHeader*)malloc(sizeof(ListHeader));								// 기존의 insert와 create의 상위버전 

		ListNode *next = (ListNode*)malloc(sizeof(ListNode));

		next->expon = InputExpon;
		next->coef  = InputCoef;
		next->link  = NULL;
		list->length= 0;
		list->tail  = next;
		list->head  = next;		

		(list->length)++;
		
		return list;
	}
	else if(list->head == NULL){
		ListNode *next = (ListNode*)malloc(sizeof(ListNode));

		next->expon = InputExpon;
		next->coef  = InputCoef;
		next->link  = NULL;
		list->length= 0;
		list->tail  = next;
		list->head  = next;		

		(list->length)++;
		
		return list;
	}
	
	else{
		ListNode *tmp = list->head;
		
		if(tmp->expon < InputExpon){
			ListNode *next = (ListNode*)malloc(sizeof(ListNode));
			next->coef = InputCoef;
			next->expon= InputExpon;
			next->link = list->head;
			list->head = next;
			(list->length)++;
			return list;
		}		
		while(tmp->link != NULL){
			if(tmp->expon == InputExpon){
				tmp->coef = tmp->coef + InputCoef;
				return list;
			}
			if(tmp->link->expon < InputExpon) break;
			tmp = tmp->link;
		}
		if(tmp->expon == InputExpon){
			tmp->coef = tmp->coef + InputCoef;
			return list;
		}
		
		ListNode *next = (ListNode*)malloc(sizeof(ListNode));
		next->coef = InputCoef;
		next->expon = InputExpon;
		
		if(tmp == NULL){
			list->tail = next;
			tmp->link  = next;
			next->link = NULL;
			(list->length)++;
		}
		else{
			next->link = tmp->link;
			tmp->link = next;
			next->coef = InputCoef;
			next->expon= InputExpon;
			(list->length)++;
		}
		return list;
	}	
}


void Display(ListHeader *list){
	int i;
	ListNode *next = list->head;
	while(next != NULL){
		printf("(%dX^%d) +",next->coef,next->expon);
		next = next->link;
	}
	printf("\n 결과 출력\n");
}

ListHeader *RemoveNode(ListHeader *list,int index){
	if(index > list->length) return list;

	ListNode *next = list->head;
	if(index == 1){
		list->head = next->link;
		free(next);
		(list->length)--;
		return list;
	}
	else{
		int i;
		for(i=2;i<index;i++){
			next = next->link; 
		}
	ListNode *deletion = next->link;
	next->link = deletion->link;
	free(deletion);
	(list->length)--;
	return list;
	}
}
void Search(ListHeader *list,element surfExpon){
	ListNode *next = list->head;
	int count=1;
	while(next != NULL){
		if(next->expon == surfExpon){
			printf("search 결과: %d번째에 %dX^%d가 존재합니다.\n",count,next->coef,next->expon);
			exit(0); 
		}
		next = next->link;
		count++;
	}
	printf("search 결과: 값이 존재하지 않습니다.\n");
}

ListHeader *PolyAdd(ListHeader *list1, ListHeader *list2){
	ListHeader *list3 = NULL;

	ListNode *next1 = list1->head;
	ListNode *next2 = list2->head;

	while(next1 != NULL){
		list3 = CreateNode(list3,next1->expon,next1->coef);
		next1 = next1->link;
		
	}
	while(next2 != NULL){
		list3 = CreateNode(list3,next2->expon,next2->coef);
		next2 = next2->link;
	}
	return list3;
	
}

int main(int argc, char *argv[]) {
	ListHeader *list1 = CreateNode(NULL,10,2);
	ListHeader *list2 = CreateNode(NULL,0,0);
	list1 = CreateNode(list1,5,10);
	CreateNode(list1,4,9);
	CreateNode(list1,4,11);
	CreateNode(list1,-2,5);
	Display(list1);
	list2 = PolyAdd(list1,list1); 
	Display(list2);
	RemoveNode(list1,2);
	Display(list1);
	CreateNode(list1,3,6);
	CreateNode(list1,8,10);
	Display(list1);
	DeleteAll(list1);
	if(list1 != NULL) Display(list1);
	list1 = CreateNode(list1,3,6);
	Display(list1);
	
	system("pause");
	return 0;
}
