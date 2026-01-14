#include <stdlib.h>
#include <math.h>

// Структура для одного елемента таблиці
typedef struct {
    int key;   // Саме число
    int value; // Його індекс у масиві
    int filled; // Прапорець: чи зайнята ця комірка (0 - ні, 1 - так)
} HashNode;

// Проста хеш-функція
int hash(int key, int size) {
    int h = key % size;
    return (h < 0) ? (h + size) : h; // Обробка від'ємних чисел
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 1. Створюємо хеш-таблицю. 
    // Розмір беремо у 2 рази більше за numsSize, щоб було менше колізій.
    int tableSize = numsSize * 2;
    HashNode* table = (HashNode*)calloc(tableSize, sizeof(HashNode));

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // 2. Шукаємо complement у таблиці
        int h = hash(complement, tableSize);
        while (table[h].filled) {
            if (table[h].key == complement) {
                // Знайшли! Формуємо результат
                result[0] = table[h].value;
                result[1] = i;
                *returnSize = 2;
                free(table); // Звільняємо тимчасову таблицю
                return result;
            }
            h = (h + 1) % tableSize; // Переходимо до наступної комірки (Linear Probing)
        }

        // 3. Якщо не знайшли, додаємо поточне число в таблицю
        h = hash(nums[i], tableSize);
        while (table[h].filled) {
            h = (h + 1) % tableSize;
        }
        table[h].key = nums[i];
        table[h].value = i;
        table[h].filled = 1;
    }

    free(table);
    return NULL;
}