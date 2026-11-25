#include <stdio.h>

int main()
{
    int n;
    /* Read the number of elements to be stored in the array that have been input. */
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    /* Read elements into the array. */
    int arr[n];
    printf("Input %d elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    /* Check frequency of each element across the array. */
    printf("The unique elements found in the array are: ");
    for(int i = 0; i < n; i++) {
        int isUnique = 1;
        for(int j = 0; j < n; j++) {
            if(i != j && arr[i] == arr[j]) {
                isUnique = 0;
                break;
            }
        }

        /* An element with a total count of 1 occurs uniquely. */
        if (isUnique) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}

