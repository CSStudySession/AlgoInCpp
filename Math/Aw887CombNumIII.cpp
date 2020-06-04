//
// link: https://www.acwing.com/problem/content/889/
//
#include <iostream>

using namespace std;

typedef long long LL;

int p;

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

int C(int a, int b, int p) { //根据定义求组合数
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2, p) % p;
    }
    return res;

}

int lucas(LL a, LL b, int p) {
    if (a < p && b < p) {
        return C(a, b, p);
    }
    return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        LL a, b;
        int p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }

    return 0;
}