#include <stdio.h>
#include <stdlib.h>
#define OPENERR "Error opening file\n"
#define CLOSEERR "Error closing file\n"

int get_data(FILE *inSp, int *num, float* price, int *inventory, int* ROP, int *order_min, int* order);

int main(){
	FILE *inSp;
	int num, inventory, ROP, order_min, order;
	float price;
	int result;        // get_data�� return���� �޴� ���� 
	int state;         // ������ �� �������� Ȯ���ϴ� ���� 
	
	printf("\tInventory Report\n");
	printf("��ǰ��ȣ     ����    ���  ���ֹ�����  �ּ��ֹ���  �ֹ���\n");
	
	inSp = fopen("C:\\Users\\juho3\\Desktop\\C_language\\Visual_stdudio_practice\\week9\\inventory.txt", "r");
	if (inSp == NULL){
		printf(OPENERR);
		exit(100);
    }
	
	while(1){
		result = get_data(inSp, &num, &price, &inventory, &ROP, &order_min, &order);
		if (result == 0){
			break;
		}
		printf("  %04d       %5.2f     %2d        %2d          %2d        %2d\n", num, price, inventory, ROP, order_min, order);		
	}
	printf("\nEnd of Report");
	
	state = fclose(inSp);
	if (state == EOF){
		printf(CLOSEERR);
	}
	
	return 0;
}

int get_data(FILE *inSp, int *num, float* price, int *inventory, int* ROP, int *order_min, int* order){
	int ioResult;
    
    ioResult = fscanf(inSp, "%d %f %d %d %d", num, price, inventory, ROP, order_min);
    if (ioResult == 5 ){
		if (*inventory <= *ROP){
			*order = (*ROP + *order_min) - *inventory;
		}
		else{
			*order = 0;
		}
		return 1;
	}
    else if (ioResult == EOF){
    		return 0;
		}
	else{
		printf("Error reading data\n");
		return 0;
	}
}
