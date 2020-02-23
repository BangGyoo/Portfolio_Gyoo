#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 10
#define SWAP(x,y,z) ((x) = (y) , (y) = (z) , (z) = (x))
typedef int element;

void Quick_Sort( element *sort_Array ,int left , int right);
void Display(element *array);


void Quick_Sort( element *sort_Array ,int left , int right){
	
	int pivot = left; int low = left+1;								// low에 left + 1을 하는 이유는 pivot이 자기자신 스왑을 안해야하기 때문 
	int high  = right;
	element temp; 						
	
	if( left < right ){
		do{
			while( sort_Array[pivot] > sort_Array[low] && low < MAX_ARRAY_SIZE ){				// low가 아닐때 까지 탐색 
				low++; 
			}
			while( sort_Array[pivot] < sort_Array[high] && high > 0){				// high가 아닐때 까지 탐색 
				high--;
			}
			if( low < high ){
				SWAP(temp,sort_Array[low],sort_Array[high]);
			}
			else break;
				
		}while(1);
		
		SWAP(temp,sort_Array[pivot],sort_Array[high]);
		printf("함수 종료  low = %d, high = %d , pivot = %d  ",low,high,pivot);
		Display(sort_Array);
		
		Quick_Sort(sort_Array,left,high-1);
		Quick_Sort(sort_Array,high+1,right);
	}
	return ;
}

void Display(element *array){
	int i = 0;
	for(i=0;i<MAX_ARRAY_SIZE;i++){
		printf("%d->",array[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	element main_Array[MAX_ARRAY_SIZE] = { 9, 8, 7, 8, 5 ,3 ,2 ,2 ,1 ,0};
	Display(main_Array);
	Quick_Sort(main_Array,0,MAX_ARRAY_SIZE-1);
	
	return 0;
}
