#include <stdio.h>
#include <stdlib.h>
#define dA1(I,J) (*(dA1 + (I)*(3) + (J)))
#define A1(I,J) (*(A1 + (I)*(3) + (J)))
#define dRV(I,J) (*(dRV + (I)*(1) + (J)))
#define RV(I,J) (*(RV + (I)*(1) + (J)))
#define B1(I,J) (*(B1 + (I)*(3) + (J)))
#define C1(I,J) (*(C1+ (I)*(3) + (J)))
#define D1(I,J) (*(D1 + (I)*(3) + (J)))

double determinant(double *A1){

    int row, col;
    int a, b, c, d, e, f, g, h, i;
    long det;
    double temp1,temp2,temp3;
   
    a = A1(0,0);
    b = A1(0,1);
    c = A1(0,2);
    d = A1(1,0);
    e = A1(1,1);
    f = A1(1,2);
    g = A1(2,0);
    h = A1(2,1);
    i = A1(2,2);

    temp1 = (a*(e*i - f*h));
    temp2 = (b*(d*i - f*g));
    temp3 = (c*(d*h - e*g));
    det = (temp1 - temp2 + temp3);
    return det;

}
	void kramer(double *A1,double *RV){
		double x=0.0,y=0.0,z=0.0;
		double *B1,*C1,*D1;
		B1= (double*)malloc(3*3*sizeof(double));
		C1= (double*)malloc(3*3*sizeof(double));
		D1= (double*)malloc(3*3*sizeof(double));
		B1(0,0)=RV(0,0);
		B1(0,1)=A1(0,1); 
		B1(0,2)=A1(0,2);
		B1(1,0)=RV(1,0); 
		B1(1,1)=A1(1,1);
		B1(1,2)=A1(1,2);
		B1(2,0)=RV(2,0);
		B1(2,1)=A1(2,1);
		B1(2,2)=A1(2,2);
        
        C1(0,0)=A1(0,0);
		C1(0,1)=RV(0,0); 
		C1(0,2)=A1(0,2);
		C1(1,0)=A1(1,0); 
		C1(1,1)=RV(1,0);
		C1(1,2)=A1(1,2);
		C1(2,0)=A1(2,0);
		C1(2,1)=RV(2,0);
		C1(2,2)=A1(2,2);
   
        D1(0,0)=A1(0,0);
		D1(0,1)=A1(0,1); 
		D1(0,2)=RV(0,0);
		D1(1,0)=A1(1,0); 
		D1(1,1)=A1(1,1);
		D1(1,2)=RV(1,0);
		D1(2,0)=A1(2,0);
		D1(2,1)=A1(2,1);
		D1(2,2)=RV(2,0);
         
        x=x+ determinant(B1)/determinant(A1);
        y=y+ determinant(C1)/determinant(A1);
        z=z+ determinant(D1)/determinant(A1);
        printf("x= %f\n",x);
        printf("y= %f\n",y);
        printf("z= %f",z);
        
     }
int main(){
	double *dA1,*A1; 
	int i,j;
	dA1= (double*)malloc(3*3*sizeof(double));
 		printf("Enter elements in matrix of size 3x3: \n");
 		for(i=0; i<3; i++){
 		for(j=0; j<3; j++){
 			scanf("%lf",&dA1(i,j));
		 }
	 }
	  double *dRV;
	  dRV= (double*)malloc(1*3*sizeof(double));
	  	printf("Enter elements in vector of size 3x1: \n");
 		for(i=0; i<1; i++){
 		for(j=0; j<3; j++){
 			scanf("%lf",&dRV(i,j));
		 }
	 }
	 kramer(dA1,dRV);	 
}
