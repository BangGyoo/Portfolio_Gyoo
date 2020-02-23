#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef char element;
typedef int boolean;



typedef struct _ListNode{
	element data;
	struct _ListNode* next;
}ListNode;

void Init(ListNode *list){
	list->next = NULL;
	list->data = '\0';
}

void Display(ListNode *list){
	ListNode *nextNode = list;
	while( nextNode != NULL){
		fprintf(stdout,"%c->",nextNode->data);
		nextNode = nextNode->next;
	}
	printf("\n");
}

boolean Is_empty(ListNode *list){
	if(list == NULL) return TRUE;
	else return FALSE;
}

boolean Is_full(void){
	if( NULL == malloc(sizeof(ListNode)) ) return TRUE;
	else return FALSE;
}

ListNode *CreateNode(element item){
	if( Is_full() == TRUE ){
		fprintf(stderr,"저장 공간 부족");
		return NULL;
	}
	else{
		ListNode *list = (ListNode*)malloc(sizeof(ListNode));
		Init(list);
		list->data = item;
		return list;
	}
}


ListNode *Push(ListNode *list,element item){
	if( Is_full() == TRUE ){
		fprintf(stderr,"저장 공간이 부족합니다.");
		return NULL;  
	}
	else if(list == NULL){
		list = CreateNode(item);
		return list;
	}
	else{
		ListNode *lastNode = CreateNode(item);
		ListNode *lastNext = list;
		while( lastNext->next != NULL ){
			lastNext = lastNext->next;
		}
	lastNext->next = lastNode;
	return list;
	}
}

element Pop(ListNode *list){
	if( Is_empty(list) == TRUE ){
		fprintf(stderr,"스택에 item이 존재하지 않습니다.");
		exit(1);
	}
	else{
		element item;
		ListNode *last = list;
		ListNode *plast;
		while(last->next != NULL){
			plast = last;
			last = last->next;
		}
		
		item = last->data;
		plast->next = NULL;
		free(last);

		return item;
	}
}
element peek(ListNode *list){
	if( Is_empty(list) == TRUE ){
		fprintf(stderr,"스택에 item이 존재하지 않습니다.");
		exit(1);
	}
	else{
		element item;
		ListNode *last = list;
		ListNode *plast;
		while(last->next != NULL){
			plast = last;
			last = last->next;
		}
		
		item = last->data;
		
		return item;
	}
}

boolean Check_maching(element *in){
	ListNode *list = NULL;
	int count = 0;
	while( count != strlen(in) ){
		list = Push(list,*(in+count));
		count++;
	}
	ListNode *nextNode = list;	
	
	while( nextNode != NULL ){
		switch(nextNode->data){
			case '(': 
			case '{': 
			case '[':
				fprintf(stdout,"%c값이 증가하였습니다.",);
				count++;
				break;
			case ')': case '}': case ']':
				count--;
				break;
			
		}
		nextNode = nextNode->next;
	}
	if(count == 0) return TRUE;
	else return FALSE;
}



int main(int argc, char *argv[]) {
	ListNode *list = CreateNode('0');

	printf("%d\n",Is_full());
	Push(list,'c');
	Push(list,'s');
	Push(list,'k');
	Display(list);
	Pop(list);
	Display(list);
	fprintf(stdout,"%c\n",peek(list));
	printf("%d",Check_maching("{sdrq()}"));
	
	
	

	
	system("pause");
	return 0;
}
