#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM  16

int matrix[DIM][DIM];
int i,j,k;
int r,c,ite;


void display()
{
	for(i=0;i<DIM;i++)
	{
		for(j=0;j<DIM;j++)
		printf("%d ",matrix[i][j]);
	printf("\n");
	}
}

int main()
{
srand(time(0));
printf("NO. of ITERATION :");
scanf("%d", &ite);

//initialization
for(i=0;i<DIM;i++)
for(j=0;j<DIM;j++)
matrix[i][j]=0;

//iteration
for(k=0;k<ite;k++)
{
r=rand()%DIM;
c=rand()%DIM;
if(r!=c){
matrix[r][c] =1;
matrix[c][r] =1;
}
}
display();
return 0;
}
