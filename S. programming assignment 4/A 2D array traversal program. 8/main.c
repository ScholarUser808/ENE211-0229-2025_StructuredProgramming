#include <stdio.h>

#define ROWS 6 /* Number of rows in the 2D array */
#define COLS 4 /* Number of columns in the 2D array */

int main(void) {
    /* Create and initialize the 6x4 2D array with preset values */
    int matrix[ROWS][COLS] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };

    /* Display the preset 2D array to the user */
    printf("Preset 6x4 array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    /* Ask the user whether to keep the preset array or enter custom values */
    char choice;
    printf("Use preset 6x4 array or enter custom values? (p = preset, c = custom): ");
    if (scanf(" %c", &choice) == 1 && (choice == 'c' || choice == 'C')) {
        /* Read custom values into each cell of the 2D array */
        printf("Enter %d integers (%d rows x %d cols):\n", ROWS * COLS, ROWS, COLS);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
    }

    /* Traverse and print each element with its row and column indices */
    printf("\nTraversing 6x4 2D array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("matrix[%d][%d] = %d\t", i, j, matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
