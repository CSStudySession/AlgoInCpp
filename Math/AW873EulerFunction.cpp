//
// link: https://www.acwing.com/problem/content/875/
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (; n-- > 0;) {
        int a;
        cin >> a;

        int res = a;
        // 分解质因数模板
        for (int i = 2; i <= a / i; i++) {
            if (a % i == 0) {
                /*
                 * 化简: res = res * (1 - 1 / a) 因为不能有小数 都要整除
                 * 先除以a 再乘上(a - 1)即可
                 */
                res = res / i * (i - 1);

                // 把i除干净
                while (a % i == 0) a /= i;
            }
        }
        // a 有一个很大的质因子
        if (a > 1) res = res / a * (a - 1);

        cout << res << endl;
    }
}

