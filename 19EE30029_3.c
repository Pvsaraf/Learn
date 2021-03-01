//Name : Saraf Parth Vikrant
//Roll NO.: 19EE30029
//Week 3
#include<stdio.h>
#include<stdlib.h>


typedef struct rectangle{
	float lx;	//x coordinate of the lower left vertex
	float ly;	//y coordinate of the lower left vertex
	float a;	//length of rectangle(across x axis)
	float b;	//Breadth of rectangle(across y axis)
}rect;

float vertLine(rect* R,int n);
//float maxj(rect* R,int n)
//{
//	float mx = 0;
//	for(int i=1;i<=n;i++)
//	{
//		if((R[i].ly + R[i].b)>mx)
//			mx = R[i].ly + R[i].b;
//	}
//	return mx;
//}
//float maxi(rect* R,int n)
//{
//	float mx = 0;
//	for(int i=1;i<=n;i++)
//	{
//		if((R[i].lx + R[i].a)>mx)
//			mx = R[i].lx + R[i].a;
//	}
//	return mx;
//}

//void compute_boundary(rect*R, int n, float l)
//{
//	//Divide by the floating line
//	int* Done;
//	float hmax= maxj(R,n);
//	float wmax= maxi(R,n);
//	float branch[100][2];
//	Done = (int *)malloc((hmax+1))
//	int j=1,k=1;
//	for(int i=1;i<=n;i++)
//	{
//		if(i==1)
//		{
//			branch[k][1]=l;
//			branch[k][2]=R[i].ly;
//			branch[k+1][1]=R[i].lx+R[i].a;
//			branch[k+1][2]=R[i].ly;
//			branch[k+2][1]=R[i].lx+R[i].a;
//			branch[k+2][2]=R[i].ly;
//			k++;
//		}
//		else
//		{
//			for(j=1;j<=k;j++)
//			{
//				if(R[i].lx+R[i].a <branch[j][1])
//				{
//					if(R[i].ly<branch[j][2])
//					{
//						if(R[i].ly+R[i].b>=branch[j][2])
//						{
//				
//							branch[k+2][2]=R[i].ly+R[i].b;
//							branch[k+2][1]=R[i].lx+R[i].a;
//							branch[k+1][1]=R[i].lx+R[i].a;
//							branch[k+2][2]=R[i].ly+R[i].b;
//							
//						}
//					}
//				}
//			}
//		}
//		
//	}
//}
float** Merge(float **b1, float **b2)
{
	int i,j;
	for(i=1;i<100 && b1[i][1]!=-2000000;i++)
	{
		for(j=1;j<100 && b2[j][1]!=-2000000;j++)
		{
		
		}
	}
}

float** compute_bound_r(rect*R, int n, float l)
{
	if(n<=1) //base condition
	{
		int i;
		float** branch;
		branch = (float **)malloc(100*sizeof(float*));
		for( i=1;i<=99;i++)
		{
			branch[i] = (float *)malloc(3 * sizeof(float));
		}
		branch[1][1]=l;
		branch[1][2]=R[1].ly;
		branch[2][1]=R[1].lx;
		branch[2][2]=R[1].ly;
		branch[3][1]=R[1].lx;
		branch[3][2]=R[1].ly+R[1].b;
		branch[4][1]=l;
		branch[4][2]=R[1].ly+R[1].b;
		branch[5][1]=-2000000;
		return branch;			//Base condition --> return all the 4 vertices.
	}
	//Split into n/2 rectangles
	rect* R1;
	rect* R2;
	int i;
	R1 = (rect *)malloc((n/2+1)*sizeof(rect));
	for(i=1;i<=n/2;i++)
	{
		R1[i].lx=l;
		R1[i].ly=R[i].ly;
		R1[i].a=R[i].lx+R[i].a-l;
		R1[i].b=R[i].b;		//Decomposition of 1st n/2 elements
	}
	R2 = (rect *)malloc((n/2+1)*sizeof(rect));		
	for(i=n/2+1;i<=n;i++)
	{
		R1[i-n/2].lx=l;
		R1[i-n/2].ly=R[i].ly;
		R1[i-n/2].a=R[i].lx+R[i].a-l;
		R1[i-n/2].b=R[i].b;		//Last n/2 elements
	}
	
	float** branch;
	branch = (float **)malloc(100*sizeof(float*));
	for( i=1;i<=99;i++)
	{
		branch[i] = (float *)malloc(3 * sizeof(float));
	}
	float** branch1;
	branch1 = (float **)malloc(100*sizeof(float*));
	for( i=1;i<=99;i++)
	{
		branch1[i] = (float *)malloc(3 * sizeof(float));
	}
	float** branch2;
	branch2 = (float **)malloc(100*sizeof(float*));
	for( i=1;i<=99;i++)
	{
		branch2[i] = (float *)malloc(3 * sizeof(float));
	}
	//Dynamically allocated branch1, branch2 and branch assuming that it's not more than 100 points
	
	
	branch1 = compute_bound_r(R1,n/2,l);		//Recursive calls 
	branch2 = compute_bound_r(R2,n/2,l);		
	branch = Merge(branch1,branch2);			//Recomposition 
	return branch;
}
int main()
{
	int n,i;
	rect* R;
	float len;
	printf("Write n: ");
	scanf("%d",&n);		//Read n from the user
	R = (rect *)malloc((n+1)*sizeof(rect));		//Dynamically allocated the memory to all the rectangles
	for(i=1;i<=n;i++)
	{
		scanf("%f %f %f %f",&R[i].lx,&R[i].ly,&R[i].a,&R[i].b);		//Inputted the rectangles
	}
//	printf("%f\n",vertLine(R,n));
	len = vertLine(R,n);		//Function call to find the piercing line
	
//	for(i=1;i<=n;i++)
//	{
//		printf("%f %f %f %f\n",R[i].lx,R[i].ly,R[i].a,R[i].b);
//	}
	return 0;
}

float vertLine(rect* R,int n)
{
	float base2 =100000, base1 = -100000;
	float r1,r2;
	int i;
	for(i=1;i<=n;i++)
	{
		r1 = R[i].lx; 
		r2 = R[i].a;
		if(r1 > base1)
			base1 = r1;			//Found the leftmost xcoordinate of the intersecting base
		if(r1+r2 < base2)
			base2 =r1+r2;		//Found the rightmost xcoordinate of the intersecting base
	}
//	printf("%f\n",(base1+base2)/2);
	return (base1+base2)/2;			//Return the middle of the base
}


