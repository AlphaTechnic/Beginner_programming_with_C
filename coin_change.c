#include <stdio.h>
int main(){
	int change;
	int numof500, numof100, numof50, numof10;
	
	printf("�Ž����� �ݾ��� �Է� �ٶ��ϴ�. ");
	scanf("%d", &change);
	change = change - change % 10;
	
	numof500 = change / 500;
	change = change - numof500 * 500;
	numof100 = change / 100;
	change = change - numof100 * 100; 
	numof50 = change / 50;
	change = change - numof50 * 50;
	numof10 = change / 10;
	
	printf("500��: %d��, 100�� : %d��, 50�� : %d��, 10�� : %d��.", 
			numof500, numof100, numof50, numof10);
			
	return 0;
}
