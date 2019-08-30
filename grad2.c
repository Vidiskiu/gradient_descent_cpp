#include <stdio.h>
#include <math.h>
#define dim 3
#define stepsize 0.01

float x[dim]= {10,10,10};
float grad[dim];

float gradie()
{
	int i;
	float temp=0;

	for (i=0;i<dim;i++)
	{
		temp = temp + (grad[i]*grad[i]);
	}
	return(sqrt(temp));
}

int main()
{
	int i;
	int count=0;
	float g;
	//f(x)=2(x1)^2+ 3(x2)^2 + 4(x3)^2+ x1 + x2 + x3
	grad[0] = 4*x[0]+1;
	grad[1] = 6*x[1]+1;
	grad[2] = 8*x[2]+1;
	g=gradie();
	
	while ( g > 1.e-5)
	{
		grad[0] = 4*x[0]+1;
		grad[1] = 6*x[1]+1;
		grad[2] = 8*x[2]+1;
		
		for (i=0;i<dim;i++)
			x[i] = x[i] - (stepsize * grad[i]);
		count++;
		g= gradie();
		
		printf("iteration=%d x0=%f, x1=%f, x2=%f, grad= %f\n", count, x[0], x[1], x[2], g);
	}
	
}
