//
// Created by Aaron Liu on 4/13/20.
//

#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 505;
int n,m;
int g[N][N];
int dist[N];
bool st[N];

int main() {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    for ( ; m > 0; m--) {
        int a, b,c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }

}



