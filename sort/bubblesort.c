#include <stdio.h>
#include <stdbool.h>

// 打印数组
void printArray(int *arr, size_t count) {
    for(int i = 0;i <count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 如果left值 < right值则交换值，并返回true
bool swap(int *left, int *right) {
    if (*left < *right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        return true;
    }
    return false;
}

// 冒泡排序, origin传入数组, count传入数组大小
void bubbleSort(int *origin, size_t count) {
    if (origin == NULL || count <= 1) { return; }
    
    int *begin, *end;
    end = origin + count - 1;
    begin = origin;
    bool changed = false;
    while(begin != end) {
        int *right = end;
        int *left = --end;
        bool isSwapped = swap(left, right);
        end = left;
        if (isSwapped) {
            printArray(origin, count);  
        } else {
            printf("no need swap\n");
        }
        changed |= isSwapped;
        
        // 已完成
        if (end == begin) {
            if (changed) {
                printf("restart\n");
                end = origin + count - 1;
                changed = false;
            } else {
                break;
            }
            begin++;
        }
    }
}

int main() {
    int arr[] = {1, 3, 8, 7, 6, 10, 20};
    printArray(arr, sizeof(arr)/sizeof(int));
    bubbleSort(arr, sizeof(arr)/sizeof(int));
   
   return 0;
}