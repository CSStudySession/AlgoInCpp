//
// link: https://www.acwing.com/problem/content/880/
//
#include <iostream>

typedef long long LL;

/*
 * x,y引用传递 可以直接修改x,y在main方法中的值
 * (x,y)不唯一 只要输出一组满足条件的即可
 */
int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) { // 递归边界
        x = 1, y = 1;
        return a;
    }

    // 这里x, y参数顺序翻转一下 因为a和b位置翻转了
    int d = exgcd(b, a % b, y, x);
    /*
     * 递归返回时 已经求得（y,x）满足:  b*y + (a%b)*x = d
     * 以(a,b)为主元 展开整理: a*x + b*(y-(a/b)*x) = d => a = a, y = y-(a/b)*x
     */
    y -= (a / b) * x;
    return d;
}


int main() {
    int n;
    // 数据量大 用scanf更高效
    scanf("%d", &n);

    for (; n-- > 0;) {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);
        int x, y;
        int d = exgcd(a, m, x, y);
        if (b % d != 0) { // 判断方程是否有解
            puts("impossible");
        } else {
            // x乘以(b/d)后 模到m范围内
            printf("%d\n", (LL)x * (b / d) % m);
        }
    }

    return 0;
}
