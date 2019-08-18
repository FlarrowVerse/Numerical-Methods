#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double inverse(double x) {
	return x + (1/x); // 1/(1+x)
}

double integrate_inverse(double a, double b, int n) {

	double h = (b-a)/n; // individual interval length
	
	double sum = inverse(a) + inverse(b);
	int i;
	double temp_sum = 0.0;
	
	for(i = 1; i < n; i++) {
		temp_sum += inverse(a + i*h);		
	}
	
	sum += 2*temp_sum; // [y(0)+y(n)+2*{y(1)+y(2)+........}]
	
	return ((h/2)*sum); // final result
}

int main() {
	while(1) {
		double a, b;
		int n;
		printf("Enter the value of lower bound(a): ");
		scanf("%lf", &a);
		printf("Enter the value of upper bound(b): ");
		scanf("%lf", &b);
		printf("Enter the number of sub-intervals(n): ");
		scanf("%d", &n);
	
		double result = integrate_inverse(a, b, n);
		printf("The result of Integration is: %lf\n", result);
		printf("                              -------------\n");
		
		char choice;
		printf("Do you want to continue?(Y/N): ");
		scanf("\n%c", &choice);
		if(choice != 'Y' && choice != 'y') break;
	}
	return 0;
}
