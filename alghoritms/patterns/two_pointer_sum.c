#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

// Function to check whether any pair exists
// whose sum is equal to the given target value
bool twoSum(int arr[], int n, int target){
    // Sort the array
    

    int left = 0, right = n - 1;

    // Iterate while left pointer is less than right
    while (left < right){
        int sum = arr[left] + arr[right];

        // Check if the sum matches the target
        if (sum == target)
            return true;
        else if (sum < target)
            left++; // Move left pointer to the right
        else
            right--; // Move right pointer to the left
    }
    // If no pair  found
    return false;
}

int main(){
    int arr[] = {-3, -1, 0, 1, 2};
    int target = -2;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the twoSum function and print the result
    if (twoSum(arr, n, target))
        printf("true\n"); 
    else
        printf("false\n");

    return 0;
}