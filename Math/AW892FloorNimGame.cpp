//
// link: https://www.acwing.com/problem/content/894/
//
#include <algorithm>

using namespace std;

/*
 * 只关心奇数级台阶上的石子个数 偶数级台阶忽略
 */
int main() {
    int n;
    int res = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (i % 2 == 1) {
            res ^= x;
        }
    }

    if (res != 0) puts("Yes");
    else puts("No");

    return 0;
}