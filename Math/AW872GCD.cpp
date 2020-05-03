//
// 872. 最大公约数
// link: https://www.acwing.com/problem/content/874/

#include <iostream>

using namespace std;

// (a,b) = (b,a%b) 欧几里得算法T(n) = O(lgN)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);

    int a, b;
    for (; n-- > 0;) {
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }

    return 0;
}