//
// Created by Aaron Liu on 5/2/20.
//

//
// link: https://www.luogu.com.cn/problem/P1330
//
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 10010, M = 200010;
int h[N], e[M], ne[M], idx;
bool visited[M]; // if visited
int colors[N];  // color of each node
int sum[2];  // each number of nodes of two colors

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx += 1;
}

bool dfs(int node, int color) {
    if (visited[node]) {
        return colors[node] == color;
    }

    visited[node] = true;
    colors[node] = color;
    sum[color]++;

    for (int i = h[node]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!dfs(j, 1-color)) return false;
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

        sum[0] = sum[1] = 0;
        if (!dfs(i, 0)) {
            printf("Impossible");
            return 0;
        }
        ret += min(sum[0], sum[1]);
    }

    printf("%d", ret);
    return 0;
}
*/