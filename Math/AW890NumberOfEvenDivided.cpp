//
// link: https://www.acwing.com/problem/content/892/
//
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 20;
int n, m;
int p[N];

int main() {
    cin>> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i]; // 读入m个质数
    }

    int res = 0;
    for (int i = 1; i < 1 << m; i++) { // 从1开始枚举到2^m
        int t = 1, cnt = 0; // t:当前所有质数的乘积 cnt:当前i二进制表示有几个1/当前选法里有几个集合
        for (int j = 0; j < m; j++) { // 从0开始 枚举m位
            if (i >> j & 1 == 1) { // 当前这一位是1
                cnt++;
                if ((LL) t * p[j] > n) { // p_i范围很大 如果乘起来>n 就不用算了
                    t = -1; // 标记一下
                    break;
                }
                t *= p[j];
            }
        }
        if (t != -1) { // 几个质数的乘积<=n
            if (cnt % 2 == 1) { // 奇数的时候+=
                res += n / t;
            } else { // 偶数的时候-=
                res -= n / t;
            }
        }
    }
    cout << res << endl;
    return 0;
}