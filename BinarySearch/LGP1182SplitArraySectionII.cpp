//
// link: https://www.luogu.com.cn/problem/P1182
//
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 100010;
int nums[SIZE];
int n, m;

bool check(int target) {
    int tot = 0, sections = 1;
    for (int k = 1; k <= n; k++) {
        if (tot + nums[k] <= target) {
            tot += nums[k];
        } else {
            sections++;
            tot = nums[k];
        }
    }
    return sections <= m;
}

int getMinMax(int lo, int hi) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    scanf("%d%d", &n, &m);
    int lo = -1, hi = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        lo = max(lo, nums[i]);
        hi += nums[i];
    }

    int res = getMinMax(lo, hi);
    printf("%d", res);
    return 0;
}

