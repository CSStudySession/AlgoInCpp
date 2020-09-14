//
// https://www.acwing.com/problem/content/794/
//
#include <iostream>
#include <vector>

using namespace std;
const int N = 1e6 + 5;

// C = A - B
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0; // 前一位的借位
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) { // 判断B有没有越界 B有当前位才减掉
            t -= B[i];
        }
        /*
         t >= 0: 这一位就是t
         t < 0: 这一位是 t + 10
         */
        C.push_back((t + 10) % 10);
        if (t < 0) {
            t = 1;
        } else {
            t = 0;
        }
    }

    // 可能有leading zeros 需要把前导0都去掉 比如123 - 120 = 3 目前会记录成003
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back(); // 扔掉C的最后一位
    }
    return C;
}

// 判断是否a >= b
bool cmp(vector<int> &A, vector<int> &B) {
    // 位数不等比位数
    if (A.size() != B.size()) return A.size() >= B.size();
    // 位数相等 从高位开始比较
    for (int k = A.size() - 1; k >= 0; k--) {
        if (A[k] != B[k]) {
            return A[k] > B[k];
        }
    }
    return true;
}

int main() {
    string a,b; // 输入太长了 用字符串读进来
    vector<int> A, B; // 把字符串拆开 存到vector里面去
    cin >> a >> b;

    // 倒着存储 第一位存个位 方便最后可能的进位
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }
    for (int j = b.size() - 1; j >= 0; j--) {
        B.push_back(b[j] - '0');
    }

    // 如果 a>=b 直接算
    if (cmp(A, B)) {
        auto C = sub(A, B);
        for (int k = C.size() - 1; k >= 0; k--) {
            printf("%d", C[k]);
        }
    } else { // a <= b 计算b-a 然后加个负号再输出结果
        auto C = sub(B, A);
        printf("-");
        for (int k = C.size() - 1; k >= 0; k--) {
            printf("%d", C[k]);
        }
    }

    return 0;
}
