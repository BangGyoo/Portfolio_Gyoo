#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct _ListNode{
	element data;
	struct _ListNode *next;
	struct _ListNode *before;
}ListNode; 

void init(ListNode *list){
	list->data = 0;
	list->next = list;
	list->before = list;
}

ListNode *CreateNode(ListNode *listHead,element item,int selection){	// 마지막 셀렉션은 0은 처음 헤더변경+추가 
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));			// 셀렉션 true는 마지막에  노드 추가 
	newNode->data = item;
	
	if(listHead ==NULL){
		newNode->next = newNode;
		newNode->before = newNode;
		return newNode;
	}
	else{
		ListNode *nextNode = listHead;
		newNode->next = nextNode;
		newNode->before = nextNode->before;
		nextNode->before->next = newNode;
		nextNode->before = newNode;	
		if(selection == 0) return nextNode->before; 
		else			   return listHead;		
	}

}

void Display(ListNode *list){
	ListNode *nextNode = list;
	while(list != nextNode->next){
		printf("%d->",nextNode->data);
		nextNode = nextNode->next;
	}
	printf("%d\n",nextNode->data);
}

void ReverseDisplay(ListNode *list){
	ListNode *nextNode = list;
	while(list != nextNode->before){
		printf("%d->",nextNode->data);
		nextNode = nextNode->before;
	}
	printf("%d\n",nextNode->data);
}

ListNode *InsertNode(ListNode *head,ListNode *p,element item){
	ListNode *nextNode = head;
	
	if(head == NULL){
		ListNode *newNode = CreateNode(newNode,item,1);		
		return newNode;
	}
	else if(p == NULL){							//지정된 값이 없어서 그냥 헤드를 이걸로 바꿈 
		ListNode *newNode = CreateNode(head,item,0);  
		return newNode;
	}
	else{
		ListNode *newNode = CreateNode(newNode,item,1);	
		newNode->before = p;
		newNode->next   = p->next;
		p->next->before = newNode;
		p->next = newNode;
		
		return head;
	}
	
}

element RemoveNode(ListNode *node){				//리턴은 작동여부 판단. 
	element item = node->data;
	ListNode *p = node->before;
	ListNode *p2 = node->next;
	p->next = node->next;
	p2->before = node->before;
	free(node);
	return item;
}

ListNode *Search(ListNode *list,element item){
	ListNode *nextNode = list;
	while(nextNode->next != list){
		if(nextNode->data == item) return nextNode;
		nextNode = nextNode->next;
	}
	printf("Search 값을 찾을수 없습니다.");
	return NULL;
}

int main(int argc, char *argv[]) {
	
	element searchNode;
	ListNode *list1 = (ListNode*)malloc(sizeof(ListNode));
	init(list1);
	list1 = CreateNode(list1,10,1);
	list1 = CreateNode(list1,20,1);
	list1 = CreateNode(list1,30,1);
	Display(list1);
	RemoveNode(list1->next);
	Display(list1);
	list1 = InsertNode(list1,NULL,40);
	printf("%d->%d->%d\n",list1->data,list1->next->data,list1->next->before->data);
	Display(list1);
	ReverseDisplay(list1);
	printf("찾으시려는 값을 입력해주세요.");
	scanf("%d",&searchNode);
	ListNode *resultNode = Search(list1,searchNode);
	if(resultNode != NULL)printf("%d의 주소에 %d가 존재합니다.",resultNode,resultNode->data);
	
	system("pause");
	return 0;
}
