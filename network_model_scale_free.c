#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 500


float sum=0;
float temp;
int matrix[DIM][DIM];
int i,j,k,m,l;
float rand_prob;
int r,c,ite,curr;
float prob[DIM+1];



void gen_prob()
{
	sum=0;

 for(k=0;k<20;k++)
 {
	r=rand()%curr;
	c=rand()%curr;
	if(r!=c)
	{
		matrix[r][c] =1;
		matrix[c][r] =1;
	}
 }

 prob[0]=0;
 for(i=0;i<curr;i++)
 {
	temp=0;	
	for(j=0;j<curr;j++)
		temp += matrix[i][j];

	prob[i+1]=temp;
	sum+=prob[i+1];
 } 

 for(i=1;i<=curr;i++)
	prob[i]+=prob[i-1];

 for(i=0;i<=curr;i++)
   {
	prob[i]/=sum;
	printf("#%d:%f   ",i,prob[i]);
   }	
printf("\n");
}

void gen_prob_2()
{
	sum=0;
 prob[0]=0;
 for(i=0;i<curr;i++)
 {
	temp=0;	
	for(j=0;j<curr;j++)
		temp += matrix[i][j];

	prob[i+1]=temp;
	sum+=prob[i+1];
 } 

 for(i=1;i<=curr;i++)
	prob[i]+=prob[i-1];

 for(i=0;i<=curr;i++)
   {
	prob[i]/=sum;
	printf("#%d:%f   ",i,prob[i]);
   }	
printf("\n");
}

void display(int count)
{
	int temp_sum;
	for(i=0;i<count;i++)
	{
		temp_sum=0;
		for(j=0;j<count;j++)
		{
			printf("%d ",matrix[i][j]);
			temp_sum+=matrix[i][j];		
		}

	printf("|\t %d \n",temp_sum);
	}
}

int main()
{
srand(time(0));
printf("current dimension : " );
scanf("%d", &curr);

printf("no of new_nodes to be added : ");
scanf("%d",&ite);

for(i=0;i<DIM;i++)
for(j=0;j<DIM;j++)
matrix[i][j]=0;

for(i=0;i<=curr;i++)
   prob[i]=0;

printf("###0\n");
gen_prob();
display(curr);
printf("------------\n");

for(l=0;l<ite;l++)
{
printf("###%d\n",l+1);
rand_prob= (rand()%1000000) /1000000.0;
printf("random generated : %f\n\n",rand_prob);

for(m=1;m<=curr;m++)
	if(rand_prob>=prob[m-1] && rand_prob<=prob[m])
	{
		matrix[m-1][curr]=1;
		matrix[curr][m-1]=1;
		curr++;
		display(curr);
		gen_prob_2();
		printf("------------\n");
		break;
	}		
}

for(i=0;i<curr;i++)
{
sum=0;
for(j=0;j<curr;j++)
	sum+=matrix[i][j];
prob[i]=sum;
}
int freq_count[DIM];
for(i=0;i<curr;i++)
   freq_count[i]=0;

for(i=0;i<curr;i++)
freq_count[(int)prob[i]]++;


printf("Distrbution\n\n");
for(i=1;i<=curr;i++)
{
printf("%d\t| ",i);
for(j=0;j<freq_count[i];j++)
printf("#");
printf("\n");
}



return 0;
}
