//
// 854. Floyd求最短路
// link: https://www.acwing.com/problem/content/856/

#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, q;
int d[N][N];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == i) {
                d[i][j] = 0;
            } else {
                d[i][j] = INF;
            }
        }
    }

    for (; m > 0; m--) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        d[a][b] = min(d[a][b], w);
    }
    floyd();

    for (; q > 0; q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        // 特殊情况: 负权边更新负最大
        if (d[a][b] > INF / 2) puts("impossible");
        else printf("%d\n", d[a][b]);
    }

    return 0;
}