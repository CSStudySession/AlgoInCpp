//
// 850. Dijkstra求最短路 II
// problem link: https://www.acwing.com/problem/content/852/
//

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 5;

typedef pair<int, int> PII; // 堆里存的是pair<int, int>
int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];


void add (int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx += 1;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0,1});

    for ( ; heap.size() > 0; ) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for ( ; m > 0; m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    cout << dijkstra() << endl;
    return 0;
}
