#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int n;

    /* Read the number of elements that have been input. */
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);

    /* Read elements into the array. */
    int arr[n];
    printf("Input %d elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    /* Initialize maximum and minimum elements. */
    int max = arr[0];
    int min = arr[0];
    /* Compare remaining elements to update maximum and minimum elements. */
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    /* Display results. */
    printf("Maximum element is : %d\n", max);
    printf("Minimum element is : %d\n", min);

    return 0;
}
