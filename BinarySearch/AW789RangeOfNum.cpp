//
// link: https://www.acwing.com/problem/content/791/
//
#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int n, q;
int nums[N];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    while (q-- > 0) {
        int x;
        scanf("%d", &x);

        int left = 0, right = n - 1;
        // 找左边界
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= x) right = mid; // nums[mid]在右半区间且nums[mid]是可能的边界
            else left = mid + 1;
        }
        // 如果x不存在 则left/right最终指向第一个(最小的)大于x的元素
        if (nums[left] != x) cout << "-1 -1" << endl;
        else {
            cout << left << ' ';
            // 找右边界 最后一个x的下标idx满足性质:idx左边的元素都小于等于x 右边都不满足这个性质
            left = 0, right = n - 1;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (nums[mid] <= x) left = mid; // nums[mid]满足性质 更新后区间需要包含mid
                else right = mid - 1;
            }
            cout << left << endl;
        }
    }
    return 0;
}