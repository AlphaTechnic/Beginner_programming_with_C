#include <stdio.h>
#include <math.h>     // fabs�� sqrt�� ����ϱ� ���� 
#define BOUND 0.001   // ��� BOUND�� 0.001�� �����Ͽ� BOUND���� ���� ���̶��, �� ���� 0���� ����Ϸ��� �Ѵ�. 

int getval(float *a, float *b, float *cx, float *cy, float *r);
int get_meetingpts(float a, float b, float cx, float cy, float r);

int main(){
	float a, b, cx, cy, r;
	
	getval(&a, &b, &cx, &cy, &r);
	get_meetingpts(a, b, cx, cy, r);
	
	return 0;
} 

int getval(float *a, float *b, float *cx, float *cy, float *r){
	printf("������ �Լ����� �Է��ϱ� �ٶ��ϴ�.\n");
	printf("y = ax + b\n");
	printf("���� a = ");
	scanf("%f", a);
	printf("������ b = ");
	scanf("%f", b);
	
	printf("\n���� �Լ����� �Է��ϱ� �ٶ��ϴ�.\n");
	printf("(x - cx)^2 + (y - cy)^2 = r^2\n");
	printf("cx = ");
	scanf("%f", cx);
	printf("cy = ");
	scanf("%f", cy);
	printf("������ r = ");
	scanf("%f", r);
	
	return 0; 
}

int get_meetingpts(float a, float b, float cx, float cy, float r){
	/*  ���� y = ax+b�� ���� ������ (x - cx)^2 + (y - cy)^2 = r^2����
	y�� �Ұ��ϸ鼭 �������� ���� ���ο� ������
	a1x^2+b1x+c1 = 0�� ���� ��, x�� ��� a1, b1, c1�� �Ʒ��Ͱ��� ���������.
	�� �������� ���� ���ǰ����� ���� ���ϸ�, ������ x��ǥ�� �ȴ�.*/ 	
	float a1 = a*a + 1;
	float b1 = 2*(-cx + a*(b-cy));
	float c1 = cx*cx + (b-cy)*(b-cy) - r*r;
	float D = b1*b1 - 4*a1*c1;  // ������������ �Ǻ��� D 
	
	float x1, y1, x2, y2;  // ���� ��ǥ�� ���е��� �Ҵ��ų ������  
	
	if (fabs(D)<BOUND){       // ������ ��� BOUND���� ���� ���� 0���� ����Ѵ�. �Ǻ��� D = 0�� ����� ���ǹ��̶�� �� �� �ִ�. 
		printf("���� ������ ���� ���մϴ�.\n");
		
		x1 = (-b1) / (2*a1);
		y1 = a*x1 + b;
		
		if (fabs(x1)<BOUND){   
			x1 = 0;
		}
		if (fabs(y1)<BOUND){
			y1 = 0;
		}
		printf("(%6.3f, %6.3f)", x1, y1);
	}
	else if (D>0){
		printf("�� �Լ����� �ΰ��� �������� �ֽ��ϴ�.\n");
		
		x1 = (-b1 - sqrt(D)) / (2.0*a1);
		y1 = a*x1 + b;
		x2 = (-b1 + sqrt(D)) / (2.0*a1);
		y2 = a*x2 + b;
		
		if (fabs(x1)<BOUND){
			x1 = 0;
		}
		if (fabs(y1)<BOUND){
			y1 = 0;
		}
		if (fabs(x2)<BOUND){
			x2 = 0;
		}
		if (fabs(y2)<BOUND){
			y2 = 0;
		}
		
		printf("(%6.3f, %6.3f), (%6.3f, %6.3f)", x1, y1, x2, y2);
	}
	else{
		printf("�� �Լ��� �������� �����ϴ�.");
	}
	
	return 0;
}

