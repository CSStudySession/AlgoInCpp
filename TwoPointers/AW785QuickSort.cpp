//
// link: https://www.acwing.com/problem/content/787/
//
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 5;
int nums[N];

void quickSort(int lo, int hi) {
    if (lo >= hi) return; // base case

    int pivot = nums[lo + (hi - lo) / 2]; // 轴点选取中点元素
    int i = lo,  j = hi;
    while (true) {
        while (nums[i] < pivot) i++; // i寻找大于等于轴点元素
        while (nums[j] > pivot) j--; // j寻找小于等于轴点元素

        if (i >= j) break; // 指针cross over 直接break 无需swap

        swap(nums[i], nums[j]); // 交换i,j指针位置的元素
        // 交换完成后 i,j指针各走一步 准备下次循环检查
        i++;
        j--;
    }

    // 注意下面的j和j+1的选取 选错会有边界问题
    quickSort(lo, j);
    quickSort(j + 1, hi); // j+1确保取不到pivot的位置
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    quickSort(0, n - 1);

    for (int j = 0; j < n; j++) {
        printf("%d ", nums[j]);
    }

    return 0;
}