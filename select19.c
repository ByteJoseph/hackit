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
    
    for (int i = 0;i<n-1;i++){
       int sm = i;
       for (int j=i+1;j<n;j++){
         if (arr[j]<arr[sm]){
            sm = j;
         }
       } 
       int temp = arr[sm];
       arr[sm] = arr[i];
       arr[i] = temp;
    }
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}