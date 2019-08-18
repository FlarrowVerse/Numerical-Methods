#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ln_base(double x, double base) {
	return (log(x) / log(base));
}

double ln_squared(double x) {
	//return log(x)*log(x); // {log(x)}^2
	return ln_base(1 + x*x, 10) / (1 + x*x);
}

double integrate_ln_squared(double a, double b, int n) {
	if(n%2 != 0) {
		printf("Total number of intervals is not even. Simpson's 1/3rd Rule is not applicable.\n\n");
		return -1;
	}

	double h = (b-a)/n; // individual interval length
	
	double sum = ln_squared(a) + ln_squared(b);
	int i;
	double even_sum = 0.0, odd_sum = 0.0;
	
	for(i = 1; i < n; i++) {
		if(i%2 == 0) even_sum += ln_squared(a + i*h);
		else odd_sum += ln_squared(a + i*h);
	}
	
	sum += 4*odd_sum + 2*even_sum; // [y(0) + y(n) + 4*{y(1)+y(3)+........} + 2*{y(2)+y(4)+........}]
	
	return ((h/3)*sum); // final result
}

int main() {
	while(1) {
		double a, b;
		int n;
		printf("Enter the value of lower bound(a): ");
		scanf("%lf", &a);
		printf("Enter the value of upper bound(b): ");
		scanf("%lf", &b);
		printf("Enter the number of sub-intervals(n)(should be even): ");
		scanf("%d", &n);
	
		double result = integrate_ln_squared(a, b, n);
		if(result != -1) {
			printf("The result of Integration is: %lf\n", result);
			printf("                              -------------\n");			
		}
		
		char choice;
		printf("Do you want to continue?(Y/N): ");
		scanf("\n%c", &choice);
		if(choice != 'Y' && choice != 'y') break;
	}
	return 0;
}
