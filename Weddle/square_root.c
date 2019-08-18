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
	int i;
	double sum_1 = 0.0, sum_2 = 0.0, sum_3 = 0.0, sum_0 = 0.0;

	for(i = 1; i < n; i++) {
		if(i%6 == 2 || i%6 == 4) sum_2 += square_root(a+i*h);
		else if(i%6 == 1 || i%6 == 5) sum_1 += square_root(a+i*h);
		else if(i%6 == 3) sum_3 += square_root(a+i*h);
		else if(i%6 == 0) sum_0 += square_root(a+i*h);
	}
	
	sum += ( sum_2 + 5*sum_1 + 6*sum_3 + 2*sum_0 );
	
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
