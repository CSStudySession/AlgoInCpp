//
// 867. 分解质因数
// link: https://www.acwing.com/problem/content/869/

#include <iostream>
#include <algorithm>

using namespace std;

void divide(int x) {
    // 优化: i只需要枚举到x/i
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) { /* 满足条件(x % i == 0)的i 一定是质数
                             当枚举到i时 [2,i-1]所有的质因子已经被除干净了
                             x已经不包含任何[2,i-1]内的质因子了
                             如果i是合数 那么它肯定可以分解成比i小的质数 与假设矛盾
                        */
            int cnt = 0; // 记录质因子i对应的指数
            // 只要i可以整除x 就一直除下去
            for (; x % i == 0; ) {
                x /= i;
                cnt++; // i对应的指数自增
            }
            cout << i << " " << cnt << endl;
        }
    }
    // 如果x大于1 那么x就是大于sqrt(x)的那个质因子 没有被上面的for loop枚举到 这里特殊处理一下
    if (x > 1) cout << x << " " << 1 << endl;
    cout << endl;
}

int main() {
    int n;
    scanf("%d", &n);
    for (; n > 0; n--) {
        int x;
        scanf("%d", &x);
        divide(x);
    }

    return 0;
}

