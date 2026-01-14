#include <stdio.h>
#include <stdlib.h>



int main (){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int left = 0;
    int right = sizeof(arr)/sizeof(arr[0]) - 1;
    int target = 9;

    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            printf("Pair found: (%d, %d)\n", arr[left], arr[right]);
            break;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    return 0;
}