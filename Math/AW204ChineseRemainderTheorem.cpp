//
// link: https://www.acwing.com/problem/content/description/206/
//
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL& x, LL&y) {
    if (b == 0) {
        x = 1, y = 1;
        return a;
    } else {
        LL d = exgcd(b, a % b, y, x);
        y  -= (a / b) * x;
        return d;
    }
}


int main() {
    int n;
    // 最多只有25个方程 数据量不大 可以用cin
    cin >> n;

    bool has_ans = true;
    LL a1, m1;

    cin >> a1 >> m1; // 读入第一组方程的系数
    for (; n-- > 1;) { // 后面n-1组方程的系数
        LL a2, m2;
        cin >> a2 >> m2;

        LL k1, k2;
        int d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d != 0) {
            has_ans = false;
            break; // 无解时直接停下
        } else {
            k1 *= (m2 - m1) / d;
            // k1 + K*(a2/d)都是解(K是任意整数) 我们要求最小的k1>0 使得方程成立
            LL t = a2 / d;
            k1 = (k1 % t + t) % t; // k1变成模(a2/d)下的最小正整数解
            m1 = a1 * k1 + m1;
            a1 = abs(a1 / d * a2); // 正的最小公倍数[a1, a2]
        }
    }
    if (has_ans) {
        cout << (m1 % a1 + a1) % a1 << endl;
    } else {
        puts("-1");
    }

    return 0;
}
