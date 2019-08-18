#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ln_2(double x) {
	return log(x) * log(x); // (ln(x))^2
}

double integrate_ln_x_2(double a, double b, int n) {

	double h = (b-a)/n; // individual interval length
	
	double sum = ln_2(a) + ln_2(b);
	int i;
	double temp_sum = 0.0;
	
	for(i = 1; i < n; i++) {
		temp_sum += ln_2(a + i*h);		
	}
	
	sum += 2*temp_sum; // [y(0)+y(n)+2*{y(1)+y(2)+........}]
	
	return ((h/2)*sum); // final result
}

int main() {
	double a, b;
	int n;
	printf("Enter the value of lower bound(a): ");
	scanf("%lf", &a);
	printf("Enter the value of upper bound(b): ");
	scanf("%lf", &b);
	printf("Enter the number of sub-intervals(n): ");
	scanf("%d", &n);
	
	double result = integrate_ln_x_2(a, b, n);
	printf("The result of Integration is: %lf\n", result);
	
	return 0;
}
