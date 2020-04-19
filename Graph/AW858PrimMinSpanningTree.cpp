//
// 858. Prim算法求最小生成树
// link: https://www.acwing.com/problem/content/860/

#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];
bool st[N];


int prim() {
    memset(dist, 0x3f, sizeof dist);

    // 最小生成树上的边权之和
    int ret = 0;

    for (int i = 0; i < n; i++) {
        int t = -1; // 找当前距离最小的点 初始化点下标成-1
        for (int j = 1; j <= n; j++) {
            // 必须在集合外 且 (当前没找任何一个点 或 候选点t的距离大于当前j的距离)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j; // 更新候选点t
            }
        }
        // 不是第一个点 且 当前距离最近的点到集合的距离是正无穷 -> 图不连通 不存在最小生成树
        if (i != 0 && dist[t] == INF) return INF;

        /*
        只要不是第一个点 dist[t]表示当前点和集合中某个点的数边的边权 用来更新ret
        注意这里要先更新ret 再更新其他点到集合的距离 如果有自环的情况出现 例如 {3, 3, -1}
        边权是-1 如果先更新其他点到集合的距离 会把自己到集合的距离也更新了(因为-1后会更小)
        但是最小生成树的定义里是不允许出现环的 所以自环边是不允许出现的
        */
        if (i != 0) ret += dist[t];

        for (int j = 1; j <= n; j++) {
            // 注意这里是跟Dijkstra算法的区别 dist[j]和g[t][j]都是某条连边的长度 不是到某个点的距离
            dist[j] = min(dist[j], g[t][j]);
        }

        st[t] = true;
    }

    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);

    for (; m > 0; m--) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = g[b][a] = min(g[a][b], w);

    }

    int t = prim();
    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}