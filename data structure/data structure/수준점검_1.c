#include <stdio.h>
#include <stdlib.h>


int Add(int numberInput_1,int numberInput_2);
int Subtract(int numberInput_1,int numberInput_2);
int Multiply(int numberInput_1,int numberInput_2);
float Device(int dividend, int divisor);				// ���� 1�� 

short Sort(int *originalArray,int *copyArray);	// ���� 2�� 


int main(int argc, char *argv[]) {
	int choice;
	printf("������ �����ϼ���. (1,2,3) �ȿ� ����");
	scanf("%d",&choice);								// ����ġ������ ���� 1,2,3 �� ���ε��� �� ���α׷����� �����ϵ���. 
	switch(choice){
		case 1: {										// ���� 1�� 
			printf("���� 1��\n"); 
			int inputNumber1, inputNumber2;
	
			printf("�μ��� �Է��Ͻÿ�.");
			scanf("%d",&inputNumber1);
			scanf("%d",&inputNumber2);
	
	
			printf("�μ��� ������%d\n", Add(inputNumber1,inputNumber2));
			printf("�μ��� ������%d\n", Subtract(inputNumber1,inputNumber2));
			printf("�μ��� ������%d\n", Multiply(inputNumber1,inputNumber2));
			printf("�μ��� ��������%.2f\n",Device(inputNumber1,inputNumber2));
	
			system("pause");
			return 0;
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 2: {																									//���� 2�� 
			int iArray[] = {21,83,28,94,27,35,78,65,14,18,98,54,17,65,34,48,59,68,49,62};
			int sortArray[20];
			if(Sort(iArray,sortArray) != 1) return 0;
			printf("5��°�� ū MAX���� %d �̴�.",sortArray[4]);
			
			system("pause");
			return 0;
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 3: {													//���� 3��.. 
			return 0;
		} 
		default: {
			printf("���� ��ȣ�Դϴ�.\n");
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

	// �μ��� ���ϵ��� ¥���� , ��ü�� �ѹ� �Ȱ�, �ִ밪 ������ �ִ� ���ϴ½����� ������ 
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
	printf("4��°�� ū MAX���� %d �̴�.",inspetion[5]);
	
	system("PUASE");
	return 0; 
	
}


*/

