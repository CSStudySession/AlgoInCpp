//
// link: https://www.luogu.com.cn/problem/P1330
//
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 10010, M = 200010;
int h[N], e[M], ne[M], idx;
bool visited[M]; // if visited
int colors[N];  // color of each node
int sum[2];  // each number of nodes of two colors
queue<int> que;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx += 1;
}

bool bfs(int start) {
    que.push(start);
    visited[start] = true;
    colors[start] = 0;
    sum[0] = 1;
    sum[1] = 0;

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (visited[j]) {
              if (colors[j] != 1 - colors[u]) return false;
              continue;
            }
            visited[j] = true;
            colors[j] = 1 - colors[u];
            sum[colors[j]] += 1;
            que.push(j);
        }
    }
    return true;
}
/*
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    int a, b;
    for (; m-- > 0;) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        if (!bfs(i)) {
            printf("Impossible");
            return 0;
        }
        ret += min(sum[0], sum[1]);
    }

    printf("%d", ret);
    return 0;
}
 */