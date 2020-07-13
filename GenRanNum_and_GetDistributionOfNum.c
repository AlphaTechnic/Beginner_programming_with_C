#include <stdio.h>
#include <stdlib.h>
#define OPENERR "Error opening file\n"
#define CLOSEERR "Error closing file\n"

int gen_ranint(FILE *outSp_genranint);
int classify_rannum(FILE *inSp_genranint, FILE *outSp_0to29, FILE *outSp_30to59, FILE *outSp_60to89, FILE *outSp_90to100,\
						int *count0to29, int *count30to59, int *count60to89, int *count90to100,\
						float *avrg0to29, float *avrg30to59, float *avrg60to89, float *avrg90to100);

int main(){
	FILE *outSp_genranint;
	FILE *inSp_genranint;
	FILE *outSp_oto29;
	FILE *outSp_30to59;
	FILE *outSp_60to89;
	FILE *outSp_90to100;
	int count0to29, count30to59, count60to89, count90to100;
	float avrg0to29, avrg30to59, avrg60to89, avrg90to100;
	
	gen_ranint(outSp_genranint);
	classify_rannum(inSp_genranint, outSp_oto29, outSp_30to59, outSp_60to89, outSp_90to100,\
					&count0to29, &count30to59, &count60to89, &count90to100,\
					&avrg0to29, &avrg30to59, &avrg60to89, &avrg90to100);
					
	
	printf("\nó�� ���\n");
	printf("%2d ~ %3d �̸�: count = %2d, ��� = %4.1f\n", 0, 30, count0to29, avrg0to29);
	printf("%2d ~ %3d �̸�: count = %2d, ��� = %4.1f\n", 30, 60, count30to59, avrg30to59);
	printf("%2d ~ %3d �̸�: count = %2d, ��� = %4.1f\n", 60, 90, count60to89, avrg60to89);
	printf("%2d ~ %3d ����: count = %2d, ��� = %4.1f\n", 90, 100, count90to100, avrg90to100);
	
	// ���� 100���� ���������Ͽ���, �̸� 0~29, 30~59, 60~89, 90~100 �� �������� �з��Ͽ����Ƿ�, count���� �� ���ϸ� 100�� �Ǿ���Ѵ�. 
	printf("������ ������ count = %d", 100 - (count0to29 + count30to59 + count60to89 + count90to100));
	
	return 0;
}

int gen_ranint(FILE *outSp_genranint){
	int ran, ran0to100;
	int i;
	int state;
	
	outSp_genranint = fopen("C:\\Users\\juho3\\Desktop\\C_language\\Visual_stdudio_practice\\week9\\integer.txt", "w");
	if (outSp_genranint == NULL){
		printf(OPENERR);
		exit(100);
	}
	
	srand(20121277);
	for (i=0; i<=99; i++){	
		ran = rand();
		ran0to100 = ran % 101;
		fprintf(outSp_genranint, "%d ", ran0to100);
		if (i % 10 == 9){
			fprintf(outSp_genranint, "\n");
		}
	}
	
	state = fclose(outSp_genranint);
	if (state == EOF){
		printf(CLOSEERR);
	}
	
	return 0;
}

int classify_rannum(FILE *inSp_genranint, FILE *outSp_0to29, FILE *outSp_30to59, FILE *outSp_60to89, FILE *outSp_90to100,\
						int *count0to29, int *count30to59, int *count60to89, int *count90to100,\
						float *avrg0to29, float *avrg30to59, float *avrg60to89, float *avrg90to100){
	int rannum;      // integer ������ �����͸� �����ͼ� rannum ������ �����Ѵ�. 
	int ioResult;    // ioResult�� EOF�� �Ǿ��� ��, ������ �б⸦ �׸��Ѵ�. 
	int state;       // ������ �� close �Ǿ����� �����ϴ� ���� 
	
	*count0to29 = *count30to59 = *count60to89 = *count90to100 = 0;
	*avrg0to29 = *avrg30to59 = *avrg60to89 = *avrg90to100 = 0;
	
	// ����, ���Ͻ�Ʈ�������͵� �� �����Ѵ�. 
	inSp_genranint = fopen("C:\\Users\\juho3\\Desktop\\C_language\\Visual_stdudio_practice\\week9\\integer.txt", "r");
	if (inSp_genranint == NULL){
		printf(OPENERR);
		exit(100);
    }
    outSp_0to29 = fopen("C:\\Users\\juho3\\Desktop\\C_language\\Visual_stdudio_practice\\week9\\0to29.txt", "w");
	if (outSp_0to29 == NULL){
		printf(OPENERR);
		exit(100);
    }
    outSp_30to59 = fopen("C:\\Users\\juho3\\Desktop\\C_language\\Visual_stdudio_practice\\week9\\30to59.txt", "w");
	if (outSp_30to59 == NULL){
		printf(OPENERR);
		exit(100);
    }
    outSp_60to89 = fopen("C:\\Users\\juho3\\Desktop\\C_language\\Visual_stdudio_practice\\week9\\60to89.txt", "w");
	if (outSp_60to89 == NULL){
		printf(OPENERR);
		exit(100);
    }
    outSp_90to100 = fopen("C:\\Users\\juho3\\Desktop\\C_language\\Visual_stdudio_practice\\week9\\90to100.txt", "w");
	if (outSp_90to100 == NULL){
		printf(OPENERR);
		exit(100);
    }
    
    while(1){
    	ioResult = fscanf(inSp_genranint, "%d", &rannum);
		if (ioResult == EOF){                 // ������ ������ �а� �Ǹ�, while���� ���������� �ȴ�. 
    		break;
		}
		
		if (0 <= rannum && rannum <= 29){
			fprintf(outSp_0to29, "%d ", rannum);
			*count0to29 += 1;
			*avrg0to29 += rannum;
		}
		else if (30 <= rannum && rannum <= 59){
			fprintf(outSp_30to59, "%d ", rannum);
			*count30to59 += 1;
			*avrg30to59 += rannum;
		}
		else if (60 <= rannum && rannum <= 89){
			fprintf(outSp_60to89, "%d ", rannum);
			*count60to89 += 1;
			*avrg60to89 += rannum;
		}
		else if (90 <= rannum && rannum <= 100){
			fprintf(outSp_90to100, "%d ", rannum);
			*count90to100 += 1;
			*avrg90to100 += rannum;
		}
	}
	*avrg0to29 = *avrg0to29 / *count0to29;
	*avrg30to59 = *avrg30to59 / *count30to59;
	*avrg60to89 = *avrg60to89 / *count60to89;
	*avrg90to100 = *avrg90to100 / *count90to100;
	
	state = fclose(inSp_genranint);
	if (state == EOF){
		printf(CLOSEERR);
	}
	state = fclose(outSp_0to29);
	if (state == EOF){
		printf(CLOSEERR);
	}
	state = fclose(outSp_30to59);
	if (state == EOF){
		printf(CLOSEERR);
	}
	state = fclose(outSp_60to89);
	if (state == EOF){
		printf(CLOSEERR);
	}
	state = fclose(outSp_90to100);
	if (state == EOF){
		printf(CLOSEERR);
	}
	
	return 0; 
}
