#include <stdio.h>

int main()
 {
    /* Read the number of elements that have been input. */
    int n, sum = 0;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);

    /* Read and accumulate the sum of the elements. */
    int arr[n];
    printf("Input %d elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    /* Print the final sum. */
    printf("Sum of all elements stored in the array is : %d\n", sum);

    return 0;
}

