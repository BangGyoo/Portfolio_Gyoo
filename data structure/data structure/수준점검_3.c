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
		printf("학생의 이름은?\n");
		scanf("%s",&student[i].studentName);
		printf("학과명은?\n");
		scanf("%s",&student[i].department);
		printf("학생의 학번은?\n") ;
		scanf("%d",&student[i].studentNumber);
		printf("학생의 학년은?\n");
		scanf("%d",&student[i].grade);
	}
	*/
	while (i<5){
		printf("학생의 이름은?\n");
		scanf("%s",student.studentName);
		printf("학생의 학과명은?\n");
		scanf("%s",student.department);
		printf("학생의 학번은?\n");
		scanf("%s",student.studentNumber);
		printf("학생의 학년은?\n");
		scanf("%s",student.garde);
		student.nextPoint;
		 
	}
/*
	struct student a;
	point(&a);
	if(a.studentNumber == 5234132) printf("맞습니다.");
	 
*/		
	system("pause");
	return 0;
}

void point(struct student *data){
	struct data *cost;
	
	cost = (struct data *) data;
	
	cost -> studentNumber = 5234132; 
	
}
