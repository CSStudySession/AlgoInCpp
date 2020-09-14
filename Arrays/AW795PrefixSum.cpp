//
// link: https://www.acwing.com/problem/content/797/
//
#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int n, m;
int a[N], s[N];

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) { // 下标从1开始 idx=0的位置空出来
        scanf("%d", &a[i]);
    }
    for (int j = 1; j <= n; j++) {
        s[j] = s[j - 1] + a[j]; // 前j-1个数的和加上a[j]
    }

    while (m-- > 0) { // m次询问
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}