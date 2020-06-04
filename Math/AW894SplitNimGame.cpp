//
// link: https://www.acwing.com/problem/content/896/
//
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_set>


using namespace std;

const int N = 105;
int f[N]; //f[i]: i的sg值

int sg(int x) {
    if (f[x] != -1) return f[x];

    unordered_set<int> S; // 记录当前局面能到达的其他局面
    // 枚举从x分成两堆后 两堆石子的个数
    for (int i = 0; i < x; i++) {
        for (int j = 0; j <= i; j++) { // 规定第二堆石子个数小于等于第一堆
            S.insert(sg(i) ^ sg(j)); // 当前局面的sg等于两堆分开后sg值的异或
        }
    }

    // mex操作:找当前集合中不存在的最小自然数
    for (int k = 0; ; k++) {
        if (S.count(k) == 0) return f[x] = k; // 要把k赋值给f[x]
    }
}

int main() {
    int n;
    cin >> n;

    // 记忆化搜索前把结果标记成不存在的值 表示没搜到过
    memset(f, -1, sizeof f);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    // 整个局面的sg是各个sg的值异或后的结果
    if (res != 0) puts("Yes");
    else puts("No");

    return 0;
}