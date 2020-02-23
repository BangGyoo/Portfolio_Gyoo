#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct _ListNode{
	element data;
	struct _ListNode *next;
	struct _ListNode *before;
}ListNode;

void InitNode(ListNode *list){
	list->data = 0;
	list->next = list;
	list->before = list;
	return ;
}

void *CreateNode(ListNode **list,element item){
	ListNode *node;
	node = (ListNode*)malloc(sizeof(ListNode));
	InitNode(node);
	node->data = item;
	*list = node;
	return ;
}

void InsertNode(ListNode **pnode,element item){
	ListNode *node = *pnode;
	ListNode *inputNode;	
	if(node == NULL){
		CreateNode(&node,item);		
		node->data = item;
		*pnode = node;
	}
	else if(node->next == node){
		CreateNode(&inputNode,item);
		node->next   = inputNode;
		node->before = inputNode;
		inputNode->before = node;
		inputNode->next	 = node;
	}
	else{
		CreateNode(&inputNode,item);
		inputNode->before	= node->before;
		inputNode->next		= node;
		node->before->next	= inputNode;
		node->before		= inputNode;
	}
}

int Display(ListNode *list){						// list�� length�� ��ȯ ���Ŀ� deleteNode�� �������� ���� 
	ListNode *inputNode = list;
	int ListLength = 0;
	if(list != NULL){
		do{
			ListLength++;
			printf("%d->",inputNode->data);
			inputNode = inputNode->next;
		}while(inputNode != list);
	}
	else{
		fprintf(stdout,"��°��� �������� �ʽ��ϴ�.");
	}
	printf("\n");
	return ListLength;
}

void DeleteNode(ListNode **pnode,int place_Address){ // place_address�� ��� ��ȣ�� ���Ѵ�. 1������ start
	ListNode *p_deletionNode = *pnode;
	if( place_Address < 1 ) return ;
	else{
		while(place_Address != 1){
			p_deletionNode = p_deletionNode->next;
			place_Address--;
		}
		if(*pnode = p_deletionNode){					// ù��° ���� �����̸� pnode�� ������带 ����Ų��. 
			*pnode = (*pnode)->next;
		}
		p_deletionNode->before->next = p_deletionNode->next;
		p_deletionNode->next->before = p_deletionNode->before;
		free(p_deletionNode);
		printf("��� ���� �Ϸ�\n");
		return ;
	}
	
}

