//Name: Saraf Parth Vikrant
//Roll No.: 19EE30029
//Week 4

#include<stdio.h>
#include<stdlib.h>
int min(int **S, int c[],int k, int t[])
{
	int i,j, m = 100000;
	int ans, sum,p;
	for(i=1;i<=k;i++)
	{
		if(c[i]==0)
		{
			return i;		//Return the counter no, where there are no custoemrs
		}
	}
	for(i=1;i<=k;i++)
	{
		sum=0;
		for(j=0;j<c[i];j++)
		{
			p = S[i][j];
			sum+= t[p];
		}
		if(sum<m)
		{
			m = sum;
			ans = i;
		}			//It finds the counter where there is minimum time
	}
	return ans;
}

int schedule_orders_a(int t[], int k, int **S, int n,int c[])
{
//	int **S = (int **)malloc((k+1) * sizeof(int *)); 
//    for (i=0; i<k; i++) 
//        S[i] = (int *)malloc(1 * sizeof(int)); 
	
	int i,min_ct,end;
//	for(i=1;i<=k;i++)
//		c[i]=0;
	
	for(i=1;i<=n;i++)
	{
		min_ct = min(S,c,k,t);		//Found the min customers of the k counters
		S[min_ct] = (int *)realloc(S[min_ct], (c[min_ct]+1)*sizeof(int));		//Dynamically increase the size by 1
		end = c[min_ct]+1;	//Add at the last
		S[min_ct][end-1] = i;		//Update the 2D array
		c[min_ct]++;		//Update count
	}
	int sum, max = 0,p,j; 
	for(i=1;i<=k;i++)
	{
		sum=0;
		for(j=0;j<c[i];j++)
		{
			p = S[i][j];
			sum+= t[p];			//To add the time of each customer
		}
		if(sum>max)
		{
			max = sum;			//Find the maximum closing time
		}
	}

	return max;
}
int waiting_time(int t[], int k, int **S, int n,int c[])
{
	int sum=0,i,j,p;
	for(i=1;i<=k;i++)
	{
		for(j=0;j<c[i];j++)
		{
			p=S[i][j];
			sum+=t[p]*(c[i]-j-1);		//Adds the element ans number of times where ans is occurence in the addition expression
		}
	}//Finds the waiting time
	return sum;
}
void print_schedule(int t[], int k, int **S, int n,int c[])
{
	int i,j,p;
	printf("\nOrder Schedule (processing time for each order within parentheses)\n");
	for(i=1;i<=k;i++)
	{
		printf("\n Counter %d: ",i);
		for(j=0;j<c[i];j++)
		{
			p = S[i][j];
			printf("%d(%d)\t",p,t[p]);		//Calculates the number and time for each
		}
		printf("\n");
	}
	//Prints the schedule for each counter
}
 
//void sort(int t[], int n)
//{
//	if(n==1)
//		return t;
//} 

int main()
{
	int i,n,k,maxtime;
	printf("n = ");
	scanf("%d",&n);
	printf("k = ");
	scanf("%d",&k);				// Inputed n and k
	int *t = (int *)malloc((n+1)*sizeof(int));	//Dynamically allocated t array
//	for (i=0; i<k; i++) 
//        S[i] = (int *)malloc(1 * sizeof(int)); 
	printf("\nEnter order processing times:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);		//Inputted the time array
	}
	int **S = (int **)malloc((k+1) * sizeof(int *));	//The schedule orders initialization
	
	int c[k+1];
	for(i=1;i<=k;i++)
		c[i]=0;		//Initially the no of customers is 0
		
	printf("\nPart (a)\n");
	maxtime = schedule_orders_a(t,k,S,n,c);		//Call the schedule_orders_a with the parameters
	print_schedule(t,k,S,n,c);					//Prints the schedule
	printf("\nCafe closes at time %d",maxtime);
	printf("\nTotal waiting time = %d",waiting_time(t,k,S,n,c));  //Print the waiting and the closing time of the cafe.
	
//	printf("\nPart (b)\n");
//	maxtime = schedule_orders_a(t,k,S,n,c);		//Call the schedule_orders_a with the parameters
//	print_schedule(t,k,S,n,c);					//Prints the schedule
//	printf("\nCafe closes at time %d",maxtime);
//	printf("Total waiting time = %d",waiting_time(t,k,S,n,c));		//Print the waiting and the closing time of the cafe.
//	
//	printf("\nPart (c)\n");
//	maxtime = schedule_orders_a(t,k,S,n,c);		//Call the schedule_orders_a with the parameters
//	print_schedule(t,k,S,n,c);
//	//Prints the schedule
//	printf("\nCafe closes at time %d",maxtime);
//	printf("Total waiting time = %d",waiting_time(t,k,S,n,c));		//Print the waiting and the closing time of the cafe.
	
	return 0;
}

