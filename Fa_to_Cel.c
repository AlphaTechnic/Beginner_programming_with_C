#include <stdio.h>
int main(){
	float Fa, Cel;
	
	printf("ȭ�� �µ��� �Է��Ͻÿ�:");
	scanf("%f", &Fa);
	printf("�Է��� ȭ���µ� = %-10.1f\n", Fa);
	
	Cel = (Fa-32) * 5 / 9;
	
	printf("��ȯ�� �����µ� = %-10.1f", Cel);
	
	return 0;
}
