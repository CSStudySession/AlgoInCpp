//
// link: https://www.acwing.com/problem/content/793/
//
#include <iostream>
#include <vector>

using namespace std;
const int N = 1e6 + 5;

// C = A + B
vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int carry = 0;

    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) {
            carry += A[i];
        }
        if (i < B.size()) {
            carry += B[i];
        }
        // carry = ai + bi + last carry
        C.push_back(carry % 10);
        carry /= 10;
    }
    // 最后可能有上次剩下的进位1
    if (carry != 0) {
        C.push_back(1);
    }

     return C;
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

    auto C = add(A, B);
    for (int k = C.size() - 1; k >= 0; k--) {
        printf("%d", C[k]);
    }
    return 0;
}