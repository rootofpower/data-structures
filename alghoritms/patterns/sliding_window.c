#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxSum(int* arr, int n, int k){
    //window size cannot be bigger than input array
    if(n < k){
        printf('Error');
        return -1;
    }
    // init window sum
    int window_sum = 0;
    //fill windowsum with numbers of elements k from array
    for (int i = 0; i < k; i++){
        window_sum=arr[i];
    }
    //init max_sum
    int max_sum = window_sum;
    //go throuth full array, starting with k-element
    for ( int i = k; i < n; i++){
        //add to window k-element to the end and remove first (i-k)-element
        window_sum += arr[i] - arr[i - k];
        //if windowsum is bigger than max_sum, we redefine max_sum
        if(window_sum > max_sum) max_sum = window_sum;
    }
    return max_sum;
}

int main(){
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);

    int result = maxSum(arr, n, k);

    if (result != -1) {
        printf("Максимальна сума підмасиву розміром %d дорівнює: %d\n", k, result);
    }
    return 0;
}