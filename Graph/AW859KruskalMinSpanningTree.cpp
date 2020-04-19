//
// 859. Kruskal算法求最小生成树
// link: https://www.acwing.com/problem/content/861/

#include <algorithm>

using namespace std;

const int N = 200010;
int n, m;
int p[N];

struct Edge {
    int a, b, w;

    // overload小于号 方便按边权排序
    bool operator < (const Edge &other) const {
        return w < other.w;
    }
} edges[N];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

int kruskal() {
    // 先把边按照边权排序
    sort(edges, edges + m);

    // 初始化并查集
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    // res:最小生成树所有树边的权重只和
    int res = 0;
    // 当前最小生成树加入了多少条边
    int cnt = 0;

    // 从小到大枚举所有边
    for (int i = 0; i < m; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].w;

        // 找到a和b的祖宗节点 如果不连通 就把a->b这条边加进来
        a = find(a);
        b = find(b);

        if (a != b) {
            res += w;
            cnt += 1;

            // a和b所在的集合合并
            p[a] = b;
        }
    }

    // 图不连通 不存在最小生成树
    if (cnt < n - 1) return -1;
    else return res;
}


int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    int ret = kruskal();
    if (ret == -1) puts("impossible");
    else printf("%d\n", ret);

    return 0;
}