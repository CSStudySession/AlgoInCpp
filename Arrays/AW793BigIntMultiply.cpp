//
// link: https://www.acwing.com/problem/content/795/
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> &A, int b) {
    vector<int> C;

    int carry = 0;
    for (int i = 0; i < A.size() || carry != 0; i++) {
        if (i < A.size()) {
            carry += A[i] * b;
        }
        C.push_back(carry % 10); // 取当前结果的个位为当前位
        carry /= 10;
    }

    // 删除leading zeros
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    return C;
}


int main() {
    string a; // a很大 需要用string存
    int b; // b很小 直接读进来
    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i--) {
        printf("%d", C[i]);
    }

    return 0;
}
