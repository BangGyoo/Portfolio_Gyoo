#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student{
	char studentName[20];
	int studentNumber;
	char department[20];
	short grade; 
	student *nextPoint = student;
}
/*
void point(struct student *data);
*/
int main(int argc, char *argv[]) {
	struct student student;
	int i=0;
/*	while(i < 5){
		printf("�л��� �̸���?\n");
		scanf("%s",&student[i].studentName);
		printf("�а�����?\n");
		scanf("%s",&student[i].department);
		printf("�л��� �й���?\n") ;
		scanf("%d",&student[i].studentNumber);
		printf("�л��� �г���?\n");
		scanf("%d",&student[i].grade);
	}
	*/
	while (i<5){
		printf("�л��� �̸���?\n");
		scanf("%s",student.studentName);
		printf("�л��� �а�����?\n");
		scanf("%s",student.department);
		printf("�л��� �й���?\n");
		scanf("%s",student.studentNumber);
		printf("�л��� �г���?\n");
		scanf("%s",student.garde);
		student.nextPoint;
		 
	}
/*
	struct student a;
	point(&a);
	if(a.studentNumber == 5234132) printf("�½��ϴ�.");
	 
*/		
	system("pause");
	return 0;
}

void point(struct student *data){
	struct data *cost;
	
	cost = (struct data *) data;
	
	cost -> studentNumber = 5234132; 
	
}
