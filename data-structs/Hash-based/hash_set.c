#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    bool* occupied;
    int capacity;
}HashSet;

int hash(int key, int capacity){
    int h = key % capacity;
    return (h < 0) ? h + capacity: h;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) return false;

    HashSet set;
    set.capacity = numsSize * 2;
    set.data = (int*)malloc(set.capacity * sizeof(int));
    set.occupied = (bool*)calloc(set.capacity, sizeof(bool));

    for(int i = 0; i < numsSize; i++){
        int val = nums[i];
        int h = hash(val, set.capacity);

        while(set.occupied[h]) {
            if(set.data[h] == val) {
                free(set.data);
                free(set.occupied);
                return true;
            }
            h = (h + 1) % set.capacity;
        }

        set.data[h] = val;
        set.occupied[h] = true;
    }
    free(set.data);
    free(set.occupied);
    return false; 
}