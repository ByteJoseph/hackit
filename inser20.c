#include <stdio.h>

void main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && temp<arr[j]){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = temp;

    }
    //print the sorted array
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}