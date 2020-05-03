//
// AcWing 866 试除法判定质数
// link: https://www.acwing.com/problem/content/868/

#include <cstring>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;

    // 注意这里循环停止的条件 i <= n / i 不要写成 i*i > n i*i会有溢出的风险
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    for (; n > 0; n--) {
        int x;
        scanf("%d", &x);
        if (isPrime(x)) puts("Yes");
        else puts("No");
    }

    return 0;
}
