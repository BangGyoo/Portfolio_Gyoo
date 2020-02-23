#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX_DEGREE 101 // 다항식 최대차수
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef float element;

typedef struct polynomialByArray {
	int degree;
	element coef[MAX_DEGREE];
} PolynomialByArray;

PolynomialByArray *create_poly(int degree){
	int i;
	PolynomialByArray *new_poly;
	
	new_poly = (PolynomialByArray *)malloc(sizeof (PolynomialByArray));
	
	if( degree > MAX_DEGREE ) {
		printf("Error in create_poly: too large degree(%d)\n",degree);
		return ((PolynomialByArray *)0);
	}
	
	for( i = 0; i <= degree; i++) new_poly->coef[i]=0.0;
	
	new_poly->degree = degree;
	
	return new_poly;
} 

int add_term_to_poly(PolynomialByArray *poly, int degree, element coef) {
	if(poly->degree < degree || degree < 0) {
		printf("Error in add_term_to_poly: too large degree(%d,%d)\n",poly->degree, degree);
		return -degree;		
	}
	
	poly->coef[(poly->degree)-degree]=coef;
	return degree;
} 

int del_term_from_poly(PolynomialByArray *poly, int degree) {
	if(poly->degree < degree || degree < 0) {
		printf("Error in add_term_to_poly: too large degree(%d,%d)\n",poly->degree, degree);
		return -degree;		
	}
	
	poly->coef[(poly->degree)-degree]=0.0;
	return degree;
} 

PolynomialByArray *destroy_poly(PolynomialByArray *poly) {
	free (poly);
}

int print_poly(PolynomialByArray *poly){
	int i;
	
	if(poly->degree < 0 || poly->degree >= MAX_DEGREE) {
		printf("Error in print_poly: illegal degree\n");
		return 0;
	}
	
	printf("Polynomial(%d): ",poly->degree);
	for(i=0; i <= poly->degree ; i++ ) {
		if (poly->coef[i] != 0) {
			if( i != 0 ) printf(" + ");
			printf("%.1fx^%d",poly->coef[i],(poly->degree) - i);
		}
	} 
	printf("\n");
	return poly->degree;
}


PolynomialByArray* poly_add1(PolynomialByArray *X, PolynomialByArray *Y){								//위 함수에 주석 처리 된 것은 변경전의 함수 구성이다. 
	PolynomialByArray *Z ;
	int i,j,k;
	
    Z = create_poly(MAX( X->degree, Y->degree));
	
	i = X->degree, j = Y->degree, k = Z->degree;
		while ( k >= 0){
		if ( i > j) {
//			Z->coef[(Z->degree)-k] = X->coef[(X->degree)-i] ;
			add_term_to_poly(Z, (X->degree)-i, X->coef[(X->degree)-i]);
			i--, k--;
		}
		else if ( i == j){
//			Z->coef[(Z->degree)-k] = X->coef[(X->degree)-i] + Y->coef[(Y->degree)-j];
		add_term_to_poly(Z, Z->degree-k, X->coef[(X->degree)-i] + Y->coef[(Y->degree)-j]);
			i--, j--, k--;
			}	
		else {
//			Z->coef[(Z->degree)-k] = Y->coef[(Y->degree)-j];
		add_term_to_poly(Z, (Y->degree)-j, Y->coef[(Y->degree)-j]);
			j--, k--;
		}
	}
	return Z;		
}


int main(int argc, char *argv[]) {
	
	// PolynomialByArray A = {5, {3,6,0,0,0,10}};
	// PolynomialByArray B = {4, {7,0,5,0,1}}; 
	PolynomialByArray *Aptr, *Bptr;
	
	Aptr = create_poly(5);
	print_poly(Aptr);
	
	add_term_to_poly(Aptr, 5, 3);
    add_term_to_poly(Aptr, 4, 6);
	add_term_to_poly(Aptr, 0, 10);

    print_poly(Aptr);

	Bptr = create_poly(4);
	add_term_to_poly(Bptr, 4, 7);
    add_term_to_poly(Bptr, 2, 5);
	add_term_to_poly(Bptr, 0, 1);


    print_poly(Bptr);

	PolynomialByArray *Cptr;
	
	//print_poly(&A);
	//print_poly(&B);
	
	// Cptr = poly_add1(&A, &B);
	
	Cptr = poly_add1(Aptr, Bptr);
	print_poly(Cptr);
		
	destroy_poly(Aptr);
	destroy_poly(Bptr);
	destroy_poly(Cptr);
	
	return 0;
}
