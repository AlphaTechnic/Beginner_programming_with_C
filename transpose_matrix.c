# include <stdio.h>
# include <stdlib.h>

int** transpose(int** matrix, int m, int n);
void printMatrix(int** matrix, int m, int n);

int main(void) {
    int rows, cols;
    int i, r, c;
    int** matrix;
    int** transposed_matrix;

    printf("Number of Rows : ");
    scanf("%d", &rows);
    printf("Number of Cols : ");
    scanf("%d", &cols);

    // matrix�� ����� ������ �޸𸮸� �Ҵ�޴´�.
    matrix = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    // matrix�� ���Ҹ� seed=20121277�� 1~100������ ���� ���ڷ� �����Ѵ�. 
    srand(20121277);
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            *(*(matrix + r) + c) = rand() % 100 + 1;
        }
    }

    printf("seed��ȣ 20121277�� ������ Matrix\n");
    printMatrix(matrix, rows, cols);

    transposed_matrix = transpose(matrix, rows, cols);

    printf("Transpose�� Matrix\n");
    // matrix�� ���ҵ��� print�� �� ���ԵǾ��� rows, cols�� ��ġ�� 
    // transposed_matrix�� ���ڷ� ������ �� ��ġ�� �ڹٲپ �����Ѵ�.
    printMatrix(transposed_matrix, cols, rows);

    // heap�޸𸮿� ����� matrix �Ҵ� ���� 
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // heap�޸𸮿� ����� transposed_matrix �Ҵ� ���� 
    for (i = 0; i < cols; i++) {
        free(transposed_matrix[i]);
    }
    free(transposed_matrix);
    return 0;
}

int** transpose(int** matrix, int m, int n) {
    int r, c;
    int transposed_rows, transposed_cols;
    int** transposed;

    // matrix�� row�� m�� transposed�� cols��, 
    // matrix�� column�� n�� transposed�� rows�� �Ҵ�
    transposed_rows = n;
    transposed_cols = m;

    // heap�޸𸮿� transposed�� ���� ���� �Ҵ� 
    transposed = (int**)malloc(sizeof(int*) * transposed_rows);
    for (r = 0; r < transposed_rows; r++) {
        transposed[r] = (int*)malloc(sizeof(int) * transposed_cols);
    }

    for (r = 0; r < transposed_rows; r++) {
        for (c = 0; c < transposed_cols; c++) {
            transposed[r][c] = matrix[c][r];
        }
    }
    return transposed;
}

void printMatrix(int** matrix, int m, int n) {
    int r, c;
    for (r = 0; r < m; r++) {
        for (c = 0; c < n; c++) {
            printf("%3d ", *(*(matrix + r) + c));
        }
        printf("\n");
    }
}
