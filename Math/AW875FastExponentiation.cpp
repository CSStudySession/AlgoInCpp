//
// link: https://www.acwing.com/problem/content/877/
//
#include <algorithm>

using namespace std;

typedef long long LL; // 两个10^9数量级的数相乘 会爆int 得用long long

// return a^k % p 注意乘法运算每次乘完要对p取模
int qmi(int a, int k, int p) {
    int res = 1;
    // a的反复平方配合k的二进制拆解
    for (; k > 0;) {
        if (k & 1 == 1) { // 每次看k二级制表示的末位
            res = (LL) res * a % p; // a是变化的 每次平方 下面会处理
        }
        k >>= 1; // k末尾算完了 右移一位把当前位删掉 下次看二级制表示的下一位
        a = (LL)a * a % p; // 反复平方 第一次迭代 a=a^(2^0) 第二次迭代a=a^(2^1) ...
    }

    return res;
}

int main() {
    // 读入的数字多 用scanf快
    int n;
    scanf("%d", &n);

    int a, k, p;
    for (; n-- > 0;) {
        scanf("%d%d%d", &a, &k, &p);

        printf("%d\n", qmi(a, k, p));
    }

    return 0;
}