#include <stdio.h>
#include <stdlib.h>      // exit�� ����ϱ� ���� 
#include <math.h>        // sqrt�� ����ϱ� ���� 

int getnum(int *num);           // ����ڷκ��� num���� �Է� ����  
int factorize(int num);         // ������ ���ڷ� �޾�, ���μ����� �� ����� printf�ϰ�, ���μ��� ������ return�ϴ� �Լ� 
int isprime(int num);           // ������ ���ڷ� �޾�, �� ������ �Ҽ����� �ռ������� ���θ� �Ǵ��ϴ� �Լ�  

int main(){
	int num;
	
	getnum(&num);
	factorize(num);
	isprime(num);
	
	return 0;
}

int getnum(int *num){
		
	printf("Input an positive integer : ");
	scanf("%d", num);
	if (*num != 0){
		printf("%d = ", *num);
	} 
	
	if (*num == 0){
		printf("\n End of program");
		exit(100);
	}
	else if (*num <2){
		while(1){
			printf("\nIt is a invalid number !\n\n");
			printf("Input an positive integer : ");
	        scanf("%d", num);
			if (*num >= 2){                  // 2�̻��� ���� ���� �Է��ؾ߸�, while���� ���������� �ȴ�. 
				break;
			}		
		}
	}			
	return 0;	
}

int factorize(int num){
	int i;              // for������ ����� ���� 
	int num_storage;    // ������ �ӽ÷� �����ϴ� ����
	int primefactor;    // ���μ� 
	int power;          // ����(�ش� ���μ��� ����) 
	int count = 0;      // ���μ��� ������ ���� ���� 
	
	
	
	for (i = 2; i<=num; i++){
		power = 0;
		primefactor = i;
		num_storage = num;
		/*  �Ʒ� while���� ����ϸ鼭 num���� ��ȭ�ϰ� �ȴ�. �׷��� 
		while���� �������� ��, �� ���� ���� if���ǹ������� ������ 
		'��ȭ�� �ֱ� �� num��'���� �����ؾ߸� �ϴ� ������ �־���.
		�׷��� ��ȭ�� �ֱ� ���� num���� �ӽ÷� �����ϴ� ������ 
		num_storage�� �����Ͽ���.*/       
		
		while(num%i==0){
			power += 1;
			count += 1; 
			num = num / i;
		}
		
		if(num_storage % i == 0){
			if (power==1){                   // power�� 1�� ���, power�� ������� �ʱ� ���� ���ǹ� 
				if (num == 1){
					printf("%d", primefactor);
					break;
				}
				else{
					printf("%d*", primefactor);
				}
			}								
			else{                            // power�� 1�� �ƴ϶��, power�� �Բ� ������ش�. 
				if (num == 1){
					printf("%d^%d", primefactor, power);
					break;
				}
				else{
					printf("%d^%d*", primefactor, power);
				}
			}
		}
	
	}
	return count;                         // ���μ��� ������ ��ȯ 
}

int isprime(int num){                     
	int isprime = 1;
	int i;
	
	/*���ڷ� �־����� num�� Ŀ���� ���, ����ð��� ������� �Ǿ�, ������ ������ �̿��Ͽ���.
	"�־��� �ڿ��� N�� �Ҽ��̱� ���� �ʿ� ��������� 
	N�� N�� �����ٺ��� ũ�� ���� � �Ҽ��ε� �������� �ʴ´�."
	�� ������ �̿��ϸ�, �־����� ���� num���� 1 ���� ������ �湮���� �ʰ�, 
	�� ���� ���� root(num)���� �湮�ϴ� �ڵ带 �ۼ��� �� �ְԵǾ�, ����ð��� �����ų �� �ִ�. 
	�������� ���ϱ� ���Ͽ�, sqrt�� ����Ͽ���.*/
	for (i = 2; i<=(int)sqrt(num); i++){   
		if (num%i==0){
			isprime = 0;            // ���ڷ� �־����� ������ �� �������� ���� � ���� ������ �������� ���, �Ҽ��̳�(isprime?) �� ���� ������ �ƴϿ�(0)��� ���Ѵ�. 
			break;
		}
	}
	
	switch(isprime){
		case 0:
			printf("\nIt is a composite number !");
			break;
		case 1:
			printf("\nIt is a prime number !");
			break;
	}
	return 0;
}
