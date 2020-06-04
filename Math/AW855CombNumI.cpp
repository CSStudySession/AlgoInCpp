//
// link: https://www.acwing.com/problem/content/887/
//
#include <algorithm>

using namespace std;

const int N = 2010, mod = 1e9 + 7;
int c[N][N];

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) { // c(a,b) = c(a-1,b) + c(a-1, b-1)
            c[i][j] = (j == 0) ? 1 : (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

int main() {
    init();

    int n;
    scanf("%d", &n);

    for (; n-- > 0;) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }

    return 0;
}