#include <stdio.h>

int main()
{
    int n;

    /* Read the number of elements that have been input. */
    printf("Input the number of elements to store in the array : ");
    scanf("%d", &n);


    /* Read elements into the array. */
    int arr[n];
    printf("Input %d number of elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }


    /* Display elements in original order. */
    printf("The values stored into the array are : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    /* Display values stored into the array in reverse order. */
    printf("The values stored into the array in reverse are: ");
    for(int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}

