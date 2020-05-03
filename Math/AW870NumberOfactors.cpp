//
// 870. 约数个数
// https://www.acwing.com/problem/content/872/

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
        res = res * (prime.second + 1) % mod;
    }
    cout << res << endl;

    return 0;
}
