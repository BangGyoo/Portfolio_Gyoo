#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LONG_VARIABLE_MAX 12												

unsigned long Repeat_Factorial(int variable);

int main(int argc, char *argv[]) {
   
   
   clock_t start,finish;
   double duration;
   srand(time(NULL));
   int random_Integer=rand()%1001;                                    		         // 0부터 ~ 1000까지 

    
    	start = clock();
        printf("%d\n",Repeat_Factorial(random_Integer));
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%f 초입니다.\n",duration);
        
		system("pause");
        return 0;
    

}


unsigned long Repeat_Factorial(int variable){
   int i; int tmp=1;
   for(i=1 ; i <= variable ; i++){
      printf("%d*",i);
      tmp = i*tmp;
   }
   printf("=");
   return tmp;
}
