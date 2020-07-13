#include <stdio.h>
#include <math.h>
#define BOUND 0.00001

int main(){
	double a, b, c;
	double root1, root2;
	double D;
	printf("���������� ��� a, b, c�� �Է��Ͻÿ�.");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D = b*b - 4*a*c;
	
	if (fabs(D) <= BOUND){
		root1 = -b / (2.0*a);
		printf("�߱� = %3.f\n", root1);
	}
	
	else if (D>0){
		D = sqrt(D);
		root1 = (-b+D) / (2.0*a);
		root2 = (-b-D) / (2.0*a);
		printf("2���� �� = %.3lf, %.3lf\n", root1, root2);		
	}
	
	else printf("���� �����ϴ�.\nD=%.4f", D);
	
	return 0;
}
