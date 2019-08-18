#include <stdio.h>
#include <math.h>

double square_root(double x) {
	return sqrt(x);
}

double integrate_sq_root(double a, double b, int n) {
	if(n%6 != 0) {
		n = n/6 * 6;
	}

	double h = (b-a)/n; // individual interval length
	
	double sum = square_root(a) + square_root(b);
	int i, j;
	double sum_1 = 0.0, sum_2 = 0.0, sum_3 = 0.0, sum_4 = 0.0;

	for(i = 2; i < n; i+=6) {
		sum_1 += square_root(a+i*h) + square_root(a+(i+2)*h);
	}
	for(i = 1; i < n; i+=6) {
		sum_2 += square_root(a+i*h) + square_root(a+(i+4)*h);
	}
	for(i = 3; i < n; i+=6) {
		sum_3 += square_root(a+i*h);
	}
	for(i = 6; i < n; i+=6) {
		sum_4 += square_root(a+i*h);
	}
	
	sum += ( sum_1 + 5*sum_2 + 6*sum_3 + 2*sum_4 );
	
	return ((3*h/10)*sum); // final result
}

int main() {
	while(1) {
		double a, b;
		int n;
		printf("Enter the value of lower bound(a): ");
		scanf("%lf", &a);
		printf("Enter the value of upper bound(b): ");
		scanf("%lf", &b);
		printf("Enter the number of sub-intervals(n)(should be multiple of 6): ");
		scanf("%d", &n);
	
		double result = integrate_sq_root(a, b, n);
		printf("The result of Integration is: %.4lf\n", result);
		printf("                              -------------\n");			
		
		char choice;
		printf("Do you want to continue?(Y/N): ");
		scanf("\n%c", &choice);
		if(choice != 'Y' && choice != 'y') break;
	}
	return 0;
}
