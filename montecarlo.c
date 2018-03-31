#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define N 100000
#define PREC 100000

double func(double x){
return sin(x*x*x*log(x)+2*cos(x));
}

int main(void)
{
	srand(time(NULL));
	long int i;

	double a,b,r;
	double y,Y=0;

	printf("Lower Limit \t");
	scanf("%lf",&a);
	printf("Upper Limit \t");
	scanf("%lf",&b);

	for(i=0;i<N;i++)
	{
		r=((rand()%((int)( (b -a)*PREC) )))/(double)PREC+a;
		Y+=func(r);
	}

	printf("\nResult : %lf\n",(b-a)*Y/(double)N );
return 0;
}
