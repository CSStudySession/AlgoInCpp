//
// link: https://www.acwing.com/problem/content/789/
//
#include <iostream>

using namespace std;

const int N = 1e6 + 5;
int n;
int q[N], tmp[N];

void mergeSort(int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2; // 找中点(分界点)
    // 递归sort左右两边
    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    // 递归结束回来 左右两边已经sort好了 二路归并 需要用到辅助数组
    int k = 0, i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    // 左边或右边可能有剩下的 直接无脑copy到tmp即可
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= right) tmp[k++] = q[j++];

    // 把结果写回到原数组里 目前结果还在临时数组tmp里
    for (int w = left, t = 0; w <= right; w++, t++) {
        q[w] = tmp[t];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    mergeSort(0, n - 1);

    for (int j = 0; j < n; j++) printf("%d ", q[j]);

    return 0;
}