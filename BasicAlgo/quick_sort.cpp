#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int nums[N];

int partition(int st, int ed) {
    swap(nums[st + (ed - st) / 2], nums[st]);
    int i = st + 1;
    int j = ed;
    int pivot = nums[st];
    
    while (i <= j) {
        if (i <= j && nums[i] < pivot) i++;
        if (i <= j && nums[j] > pivot) j--;
        
        if (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    // printf("i:%d, j:%d, pi:%d\n", i, j, pivot);
    swap(nums[st], nums[j]);
    
    return j;
}


void quick_sort(int st, int ed) {
    if (st >= ed) return;
    
    int pivot = partition(st, ed);
    
    quick_sort(st, pivot - 1);
    quick_sort(pivot + 1, ed);
}