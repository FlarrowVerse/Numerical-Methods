#include <stdio.h>
#include <math.h>

double f(double x) {
	return (pow(x, 2*x));
}

double getRoot(double acc) {
	double x0 = 0, x1 = 1, x2, x2_old;
	
	while(f(x0)*f(x1) > 0) {
		x0++; x1++;
	}
	
	printf("Values of initial interval :: x(0): %lf; x(1): %lf\n\n", x0, x1);
	
	x2 = x1;
	x2_old = x0;
	
	int n = 0;
	
	printf("---------------------------------------------------------------------------\n");
	printf("Iter.\t\tx(0)(-ve)\t\tx(1)(+ve)\t\tx(2)\t\tf(x(2))\n");
	printf("---------------------------------------------------------------------------\n");
	
	while(fabs(x2 - x2_old) > acc) {
		x2_old = x2;
		x2 = x0 + ((x1 - x0) * f(x0)) / (f(x0) - f(x1)); // finding x2
		double fx_x2 = f(x2);
		n++;
		
		printf("%d\t\t%lf\t\t%lf\t\t%lf\t\t%lf\n", n, x0, x1, x2, fx_x2);
		
		if(fx_x2 < 0) 
			x0 = x2;
		else
			x1 = x2;
	}
	
	return x2;
	
}

int main() {
	int acc;
	printf("Enter the required accuracy: ");
	scanf("%d", &acc);
	
	printf("Root of the equation:: %.4lf\n", getRoot(pow(10, -acc)));	
	return 0;
}
