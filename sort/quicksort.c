#include <stdio.h>
#include <stdbool.h>

void printArr(int *arr, size_t count) {
  for(int i = 0; i < count;i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void quickSort(int *arr, size_t count) {
  if (count <= 1) {
    return;
  }
  if(count == 2){
    // 两个数比较大小，后者大则交换
    if (arr[0] < arr[1]) {
      int temp = arr[0];
      arr[0] = arr[1];
      arr[1] = temp;
    }
    return;
  }

  int i, j, k;
  i = 0;
  j = count - 1;
  
  bool anchorPointLeft = true;
  k = arr[i];
  while(i != j) {
    if (anchorPointLeft) {
         if (arr[j] > k) {
            // 交换值
            // 下次交换从左往右搜寻最小值
            arr[i] = arr[j];
            anchorPointLeft = false;
            i++;
         } else {
            j--;
         }
    } else {
      if (arr[i] < k) {
        arr[j] = arr[i];
        j--;
        // 交换值，下次搜寻从右往左找最大值
        anchorPointLeft = true;
      } else {
        i++;
       }
    }
  }
  // 把拿出来的k填上
  arr[i] = k;

  // 左边需要排序， 再次使用快速排序排列左边
  if (i > 1) {
      quickSort(arr, i);
  }
  // 右边需要排序， 再次使用快速排序排列右边
  if (count - 1 - i > 1) {
      int *temp = arr;
      temp += i + 1;
      quickSort(temp, count - i -1);
  }
}

int main(void) {
  int count = 4;
  int arr[] = {6, 5, 6, 8};
  printArr(arr, count);
  quickSort(arr, count);
  printArr(arr, count);
  return 0;
}

