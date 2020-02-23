#include <stdio.h>
#include <stdlib.h>


int Add(int numberInput_1,int numberInput_2);
int Subtract(int numberInput_1,int numberInput_2);
int Multiply(int numberInput_1,int numberInput_2);
float Device(int dividend, int divisor);				// 과제 1번 

short Sort(int *originalArray,int *copyArray);	// 과제 2번 


int main(int argc, char *argv[]) {
	int choice;
	printf("문제를 선택하세요. (1,2,3) 안에 선택");
	scanf("%d",&choice);								// 스위치문으로 과제 1,2,3 번 따로따로 한 프로그램에서 실행하도록. 
	switch(choice){
		case 1: {										// 과제 1번 
			printf("과제 1번\n"); 
			int inputNumber1, inputNumber2;
	
			printf("두수를 입력하시오.");
			scanf("%d",&inputNumber1);
			scanf("%d",&inputNumber2);
	
	
			printf("두수의 덧셈은%d\n", Add(inputNumber1,inputNumber2));
			printf("두수의 뺄셈은%d\n", Subtract(inputNumber1,inputNumber2));
			printf("두수의 곱셈은%d\n", Multiply(inputNumber1,inputNumber2));
			printf("두수의 나눗셈은%.2f\n",Device(inputNumber1,inputNumber2));
	
			system("pause");
			return 0;
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 2: {																									//과제 2번 
			int iArray[] = {21,83,28,94,27,35,78,65,14,18,98,54,17,65,34,48,59,68,49,62};
			int sortArray[20];
			if(Sort(iArray,sortArray) != 1) return 0;
			printf("5번째로 큰 MAX값은 %d 이다.",sortArray[4]);
			
			system("pause");
			return 0;
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 3: {													//과제 3번.. 
			return 0;
		} 
		default: {
			printf("예외 번호입니다.\n");
            return 0; 
        }
	}
}

int Add(int numberInput_1,int numberInput_2){
	return numberInput_1 + numberInput_2;
}


int Subtract(int numberInput_1,int numberInput_2){
	return numberInput_1 - numberInput_2;
}

int Multiply(int numberInput_1,int numberInput_2){
	return numberInput_1 * numberInput_2;;
}

float Device(int dividend, int divisor){
	return (float)dividend / divisor;
}



short Sort(int originalArray[20],int *copyArray){
	int i=0; int j=0; int inspetion[20];
	while(j<20){
		copyArray[j] = 0; i = 0;
		while(i < 20){
			if(copyArray[j] < originalArray[i] && j==0) copyArray[j] = originalArray[i];
			else if(copyArray[j] < originalArray[i] && copyArray[j-1] > originalArray[i]) copyArray[j] = originalArray[i];
			i++;
		}
	j++;
	}
	return 1;
}

/*

int main(int argc, char *argv[]) {

	// 두수를 비교하도록 짜야함 , 전체를 한번 훑고, 최대값 다음값 최대 구하는식으로 가야함 
	int i=0; int j=0; int inspetion[20];
	
	while(j<20){
		inspetion[j] = 0; i = 0;
		while(i < 20){
			if(inspetion[j] < iArray[i] && j==0) inspetion[j] = iArray[i];
			else if(inspetion[j] < iArray[i] && inspetion[j-1] > iArray[i]) inspetion[j] = iArray[i];
			i++;
		}
		printf("inspetion[%d] = %d \n",j,inspetion[j]);
		j++;
	}
	printf("4번째로 큰 MAX값은 %d 이다.",inspetion[5]);
	
	system("PUASE");
	return 0; 
	
}


*/

