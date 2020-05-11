//
// link: https://www.acwing.com/problem/content/876/
//
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1000010;
int primes[N], cnt; // primes[]存每一个质数 cnt质数的下标
bool st[N]; // st[i]: i是否被筛掉
int phi[N];

// 欧拉函数的和会很大 N^2级别 会爆int 要用long long记录
LL get_eulers(int n) {
    phi[1] = 1; // 由定义 特殊规定
    for (int i = 2; i <= n; i++) {
        if (!st[i]) { // i没被筛掉过 i是质数
            primes[cnt++] = i;
            phi[i] = i - 1; // i是质数 [1,i-1]均与i互质
        }
        // 从小到大枚举所有已知质数
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true; // 筛掉primes[j]*i
            if (i % primes[j] == 0) { // 重要优化 有此优化才是线性复杂度
                phi[primes[j] * i] = primes[j] * phi[i];
                break;
            } else { // i % p[j] != 0
                phi[primes[j] * i] = phi[i] * (primes[j] - 1);
            }
        }
    }

    LL res = 0; // 统计答案
    for (int k = 0; k <= n; k++) {
        res += phi[k];
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    cout << get_eulers(n) << endl;

    return 0;
}