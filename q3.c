<<<<<<< HEAD
#include <stdio.h>

void readMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrisin elemanlarini girin (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Matris[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}


void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Sonuc Matrisi:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}


void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}


void multiplyMatrices(int r1, int c1, int mat1[r1][c1], int r2, int c2, int mat2[r2][c2], int result[r1][c2]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}


int determinant(int size, int matrix[size][size]) {
    if (size == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else if (size == 3) {
        return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
             - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
             + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    } else {
        printf("Şu an sadece 2x2 ve 3x3 determinant hesaplaniyor.\n");
        return 0;
    }
}

void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transposed[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j]; 
        }
    }
}


int main() {
    int rows, cols, choice;

   
    printf("Matrisin satir ve sutun sayisini girin: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

  
    printf("\nBirinci matrisi girin:\n");
    readMatrix(rows, cols, matrix1);

   
    printf("\nYapmak istediğiniz işlemi seçin:\n");
    printf("1 - Matris Toplama\n");
    printf("2 - Matris Carpma\n");
    printf("3 - Determinant Hesaplama\n");
    printf("4 - Matris Transpoz Alma\n");
    printf("Seciminiz: ");
    scanf("%d", &choice);

    if (choice == 1) {
        
        printf("\nİkinci matrisi girin:\n");
        readMatrix(rows, cols, matrix2);

     
        addMatrices(rows, cols, matrix1, matrix2, result);
        printMatrix(rows, cols, result);

    } else if (choice == 2) {
        int r2, c2;
        printf("İkinci matrisin satir ve sutun sayisini girin: ");
        scanf("%d %d", &r2, &c2);

        if (cols != r2) {
            printf("Hata: Carpma için ilk matrisin sutun sayisi, ikinci matrisin satir sayisina eşit olmalidir!\n");
            return 1;
        }

        int matrix2[r2][c2], resultMatrix[rows][c2];
        printf("\nİkinci matrisi girin:\n");
        readMatrix(r2, c2, matrix2);

        multiplyMatrices(rows, cols, matrix1, r2, c2, matrix2, resultMatrix);
        printMatrix(rows, c2, resultMatrix);

    } else if (choice == 3) {
        if (rows != cols) {
            printf("Hata: Determinant yalnizca kare matrisler icin hesaplanabilir!\n");
        } else {
            int det = determinant(rows, matrix1);
            printf("Matrisin determinanti: %d\n", det);
        }

    } else if (choice == 4) {
        int transposed[cols][rows];
        transposeMatrix(rows, cols, matrix1, transposed);
        printMatrix(cols, rows, transposed);

    } else {
        printf("Gecersiz seçim!\n");
    }

    return 0;
}

  


   

        
