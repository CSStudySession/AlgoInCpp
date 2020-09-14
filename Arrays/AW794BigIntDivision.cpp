//
// link: https://www.acwing.com/problem/content/796/
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// C + r = A / b r is reminder
vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C;
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i]; // r每次十进制下左移一位 加上当前A[i]
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end()); // C第一位是最高位 与其他大整数运算相反

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

    int r;
    auto C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--) {
        printf("%d", C[i]);
    }
    cout << endl <<  r << endl;

    return 0;
}
