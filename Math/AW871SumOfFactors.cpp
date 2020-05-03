//
// 871. 约数之和
// link: https://www.acwing.com/problem/content/873/

#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;

unordered_map<int, int> primes;

// 对x分解质因数
void factor(int x) {
    for (int i = 2; i <= x / i; i++) {
        while (x % i == 0) {
            x /= i;
            primes[i]++; // 质因数i的指数自增
        }
    }
    if (x > 1) primes[x]++;
}


int main() {
    int n;
    cin >> n;

    for (; n > 0; n--) {
        int x;
        cin >> x;
        factor(x);
    }

    LL res = 1;
    for (auto prime : primes) {
        int p = prime.first;  // 当前质因子的底数
        int a = prime.second; // 当前质因子的指数

        LL t = 1;

        /*
         计算: p^0 + p^1 + ... + p^a
         f(t) = p*t + 1 while a > 0
         */
        for (; a-- > 0;) {
            t = (p * t + 1) % mod;
        }
        res = (res * t) % mod;

    }
    cout << res << endl;

    return 0;
}

