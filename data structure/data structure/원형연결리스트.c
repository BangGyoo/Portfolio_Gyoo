#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct _ListNode{
	element data;
	struct _ListNode* link;
}ListNode;

void Init(ListNode *list){
	list->data = 0;
	list->link = list;
}

ListNode *CreateNode(ListNode *head,element item){			//라스트에 노드를 추가시킨다. 
	ListNode *result = (ListNode *)malloc(sizeof(ListNode));
	ListNode *next = head;
	
	while(head != next->link){
		next = next->link;		
	} 
	result->data = item;
	result->link = next->link;
	next->link   = result;
		
	return head;
}

ListNode *LastNode(ListNode *list){							// 원형리스트의 마지막 노드의 링크를 첫번째 노드로 설정하기위해 구현 
	ListNode *next = list;
	while(list != next->link){
		next = next->link;
	}
	return next;
}

ListNode *InsertNode(ListNode *head, ListNode *p, element item){
	ListNode *input = (ListNode*)malloc(sizeof(ListNode));
	input->data = item;
	if(head == NULL){
		input = head;
		head = input->link;
		return input;
	}
	else if(p == NULL){
		input->link = head;
		ListNode *last = LastNode(head);
		last->link = input;
		
		return input;
	}
	else if(p->link == head->link){								// 원형리스트 이기 떄문에 따로 검사할 필욘없지만, 혹시나 
		input->link = p->link;
		p->link = input;
		return head;
	}
	else{
		input->link = p->link;
		p->link = input;
		return head;
	}
}

void Display(ListNode *list){
	ListNode *output = list;
	
	while(list != output->link){	
		printf("%d->",output->data);
		output = output->link;
	}
	printf("%d",output->data);
}

ListNode *RemoveNode(ListNode *node){
	ListNode *last = LastNode(node);						// 어자피 원형 리스트 이므로 전값이 마지막값 
	last->link = node->link;
	free(node);
	return last->link;
}

ListNode *Search(ListNode *list,element item){
	ListNode *next = list;
	while(list != next->link){
		if(next->data == item) return next;
		next = next->link;
	}
	return NULL;
}
//
//ListNode *PolyAdd(ListNode *list1, ListNode *list2){
//	ListNode *plusList = (ListNode *)malloc(sizeof(ListNode));
//}

int main(int argc, char *argv[]) {
	ListNode *list1 = (ListNode*)malloc(sizeof(ListNode));
	Init(list1);
	list1->data = 10;
	list1 = CreateNode(list1,20);
	list1 - CreateNode(list1,30);
	
	printf("%d->%d->%d\n",list1->data,list1->link->data,list1->link->link->data);
	
	RemoveNode(list1->link);
	Display(list1);
	
	ListNode *info = Search(list1,20);
	if(info != NULL) printf("\ninfo->data : %d",info->data);
	else printf("\n찾으려는 Search item이 존재하지 않음");
	list1 = InsertNode(list1,list1->link,40); 
	printf("\n");
	Display(list1);
	
	system("pause"); 
	return 0;
}
