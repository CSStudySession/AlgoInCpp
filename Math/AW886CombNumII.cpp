//
// link: https://www.acwing.com/problem/content/888/
//
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 100010, mod = 1e9 + 7;
int fact[N], infact[N];

// 快速幂模板
int qmi(int a, int k, int p) {
    int res = 1;
    for (; k != 0;) {
        if (k & 1 == 1) {
            res = (LL)res * a % p;
        }
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}


int main() {
    fact[0] = infact[0] = 1; // 1/1 = 1
    for (int i = 1; i < N; i++) {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }

    int n;
    scanf("%d", &n);

    for (; n-- > 0;) {
        int a, b;
        scanf("%d%d", &a, &b);

        // 两个1e9相乘不会longlong溢出 但是三个就会 需要及时取模
        int curr = (LL)fact[a] * infact[b] % mod * infact[a - b] % mod;
        printf("%d\n", curr);
    }

    return 0;

}