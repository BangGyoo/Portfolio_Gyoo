#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LONG_VARIABLE_MAX 12

unsigned long Recur_Factorial(int variable);
unsigned long _Recur_Factorial(int variable,int n);


int main(int argc, char *argv[]) {
   
   clock_t start,finish;
   double duration;
   srand(time(NULL));
   int random_Integer=rand()%1001;                                    		         // 0���� ~ 1000���� 

        start = clock();
        printf("%d\n",Recur_Factorial(LONG_VARIABLE_MAX));                           // MAX ���� 12�����ΰ��� �˼��ִ�. 
        finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("%f ���Դϴ�.\n",duration);
      
        system("puase");
        return 0;     
}

unsigned long Recur_Factorial(int variable){
    	return _Recur_Factorial(variable,1);
}

unsigned long _Recur_Factorial(int variable, int n){
    
    
	if(variable == n) {
		printf("%d=",n);
    	return variable;
    }
    else{
    	printf("%d*",n);
    	return n*_Recur_Factorial(variable,n+1);
    }
}
