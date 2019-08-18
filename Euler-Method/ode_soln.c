#include<stdio.h>
#include<math.h>

double f(double x, double y) {
	return (y - x)/(y + x);
}

double getYn(double x0, double y0, double h, double xn) {
	double x1 = x0, y1 = y0;
	int i = 1;
	
	while(x0 < xn) {
		x1 = x0 + h;
		y1 = y0 + h*f(x0, y0);		
		printf("%d \t\t %lf \t\t %lf \t\t %lf \t\t %lf\n", i, x0, y0, x1, y1);
		i++;
		x0 = x1;
		y0 = y1;
	}
	
	return y1;
	
}

int main() {

	int acc;
	printf("Enter required accuracy: ");
	scanf("%d", &acc);
	double x, y, h, xn;
	printf("Enter the initial value of x: ");
	scanf("%lf", &x);
	printf("Enter the initial value of y: ");
	scanf("%lf", &y);	
	printf("Enter the interval value h: ");
	scanf("%lf", &h);	
	printf("Enter the final value of x: ");
	scanf("%lf", &xn);	
	
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("i \t\t x(n) \t\t\t y(n) \t\t\t x(n+1) \t\t y(n+1)\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	double root = getYn(x, y, h, xn);	
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("The value of y(n) is %.*lf\n\n", acc,root);
	return 0;
}
