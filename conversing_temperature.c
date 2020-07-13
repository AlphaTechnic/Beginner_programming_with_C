#include <stdio.h>

int getCel (float* Cel);
int Cel2Fah (float* Cel, float* Fah);
int printFah (float Fah);

int getFah (float* Fah);
int Fah2Cel (float* Cel, float* Fah);
int printCel (float Cel);

int main(){
	float Cel, Fah;
	
	getCel(&Cel);
	Cel2Fah(&Cel, &Fah);
	printFah (Fah);
	
	getFah(&Fah);
	Fah2Cel(&Fah, &Cel);
	printCel(Cel);
	
	return 0;
}

int getCel (float* Cel){
	printf("���� �µ��� �Է��Ͻñ� �ٶ��ϴ� : ");
	scanf("%f", Cel);
	
	return 0;
}

int Cel2Fah (float* Cel, float* Fah){
	*Fah = (9 * (*Cel) / 5) + 32;
	
	return 0; 
}

int printFah (float Fah){
	printf("ȭ�� �µ��� %5.2f �Դϴ�.\n\n", Fah);
	
	return 0;
} 
//////////////////////////////////////////////////////
//
int getFah (float* Fah){
	printf("ȭ�� �µ��� �Է��Ͻñ� �ٶ��ϴ� : ");
	scanf("%f", Fah);
	
	return 0; 
}

int Fah2Cel (float* Cel, float* Fah){
	*Cel = 5 * (*Fah - 32) / 9;
		
	return 0; 
}

int printCel (float Cel){
	printf("���� �µ��� %5.2f �Դϴ�.\n", Cel);
	
	return 0;
} 
