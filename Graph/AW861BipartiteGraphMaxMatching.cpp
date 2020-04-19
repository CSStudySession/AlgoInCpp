//
// 861. 二分图的最大匹配
// link: https://www.acwing.com/problem/content/863/

#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N]; // 右边点跟目前左边哪个点匹配中
bool st[N]; // 每次不要重复搜索一个点

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx += 1;
}

bool find(int x) {
    // 枚举x所有的连边 每一个都可能是x的匹配对象
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        // 如果j没有正在匹配的过程中
        if (!st[j]) {
            st[j] = true;
            // 如果j没有被匹配到某个点 或 与j配对的点可以被分配给别的点
            if (match[j] == 0 || find(match[j])) {
                // 把j匹配给x
                match[j] = x;
                return true;
            }
        }
    }
    // 尝试所有可能都无法给x匹配上
    return false;
}

int hungarian() {
    int res = 0;
    for (int i = 1; i <= n1; i++) {
        // 每次清空右边点的"正在匹配"情况 初始化都没尝试过与i匹配
        memset(st, false, sizeof st);
        if (find(i)) res += 1;
    }

    return res;
}


int main() {
    scanf("%d%d%d", &n1, &n2, &m);
    memset(h, -1, sizeof h);

    for (; m > 0; m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    printf("%d\n", hungarian());

    return 0;
}

