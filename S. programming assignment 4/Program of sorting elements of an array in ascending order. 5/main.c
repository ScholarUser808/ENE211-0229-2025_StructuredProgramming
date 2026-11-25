#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    /* Read array size. */
    printf("Input the size of array : ");
    scanf("%d", &n);

    /* Read elements into the array. */
    int arr[100];
    printf("Input %d elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    /* Print the current list of the array. */
    printf("The current list of the array : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Read the value and position. */
    int val, pos;
    printf("Input the value to be inserted : ");
    scanf("%d", &val);
    printf("Input the position where the value is to be inserted :");
    scanf("%d", &pos);

    /* Shift elements to the right to make space (1-based position index). */
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;

    /* Print sorted array. */
    printf("After inserting the element, the new list is : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
