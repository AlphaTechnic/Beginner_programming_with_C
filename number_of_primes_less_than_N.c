#include <stdio.h>
int num_of_primes(int n){
	int i, j;
	int count = 1;
	int checker;
	
	if (n == 1){
		return 0;
	}
	else if (n == 2){
		return 1;
	}
	else{
		for (i = 3; i<=n; i = i+2){
			checker = 1;
			for (j = 2; j<i; j++){
				if (i % j == 0){
					checker = 0;
					break;
				}
			}
			if (checker == 1){
				count += 1;
			}
		}
		return count;		 
	}
}

int main(){
	int k;
	 
	printf("�Է��Ͻ� �� ������ �Ҽ� ������ �˷��帮�ڽ��ϴ�:");
	scanf("%d", &k);
	printf("%d������ �Ҽ��� ������ : %d", k, num_of_primes(k));
	
	return 0;
}
