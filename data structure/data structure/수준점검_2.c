#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	int iArray[] = {21,83,28,94,27,35,78,65,14,18,98,54,17,65,34,48,59,68,49,62};
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
