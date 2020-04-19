//
// AcWing 860. 染色法判定二分图
// link: https://www.acwing.com/problem/content/862/

#include <cstring>
#include <algorithm>

using namespace std;

// 无向图边的个数要乘2
const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx += 1;
}

bool dfs(int u, int c) {
    color[u] = c; // 把u染成c颜色
    // 对u的所有临边进行dfs染色
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (color[j] == 0) {
            // 一共两种颜色 1,2 -> 3-c会让1,2交替出现
            if (!dfs(j, 3 - c)) return false;
        } else if (color[j] == c) return false; // 一条边的两端颜色相同 冲突
    }
    return true;
}

bool colorGraph() {
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for (; m > 0; m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    if (colorGraph()) puts("Yes");
    else puts("No");

    return 0;
}

