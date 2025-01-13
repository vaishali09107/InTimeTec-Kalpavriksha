#include <stdio.h>
#include <stdlib.h>

void searchInMatrix(int **matrix, int numRows, int numCols, int targetElement) {
    int currentRow = 0, currentCol = numCols - 1;
    while (currentRow < numRows && currentCol >= 0) 
    {
        if (matrix[currentRow][currentCol] == targetElement) 
        {
            printf("Element %d found at position: (%d, %d)\n", targetElement, currentRow, currentCol);
            return;
        } 
        else if (matrix[currentRow][currentCol] > targetElement)
        {
            currentCol--;
        } 
        else 
        {
            currentRow++;
        }
    }
    printf("Element %d not found in the matrix.\n", targetElement);
}

int main() {
    int numRows, numCols, i, j, targetElement;

    printf("Enter number of rows: \n");
    scanf("%d", &numRows);
    printf("Enter number of columns: \n");
    scanf("%d", &numCols);

    int **matrix = (int **)malloc(numRows * sizeof(int *));
    if (matrix == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < numRows; i++) 
    {
        matrix[i] = (int *)malloc(numCols * sizeof(int));
        if (matrix[i] == NULL) 
        {
            printf("Memory allocation failed for row %d.\n", i);
            return 1;
        }
    }

    printf("Enter array elements: \n");
    for (i = 0; i < numRows; i++) 
    {
        for (j = 0; j < numCols; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the element to search: \n");
    scanf("%d", &targetElement);

    printf("Printing matrix elements: \n");
    for (i = 0; i < numRows; i++) 
    {
        for (j = 0; j < numCols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    searchInMatrix(matrix, numRows, numCols, targetElement);

    for (i = 0; i < numRows; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
