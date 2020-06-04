//
// link: https://www.acwing.com/problem/content/895/
//
#include <cstring>
#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 110, M = 10010;
int n, k;
int s[N], f[M]; // s[i]:石子堆i有多少石子 f[i]:sg[i]的值

// 记忆化搜索求SG的值 每个状态只算一次
int sg(int x) {
    if (f[x] != -1) {
        return f[x];
    }

    // set存当前局面可以到达的其他局面的sg值
    unordered_set<int> S;
    for (int i = 0; i < k; i++) {
        int take = s[i]; // 当前可以拿石子的个数
        if (x >= take) {
            S.insert(sg(x - take));
        }
    }
    // 找当前集合中不存在的最小自然数
    for (int i = 0; ; i++) {
        if (S.count(i) == 0) {
            return f[x] = i;
        }
    }
}

int main() {
    cin >> k; // 每次可以取的石子个数
    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }

    cin >> n;
    memset(f, -1, sizeof(f));

    int res = 0;
    // 分别算每堆石子的sg值 然后异或起来
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; // 第i堆石子数量
        res ^= sg(x);
    }

    if (res != 0) puts("Yes");
    else puts("No");

    return 0;
}


