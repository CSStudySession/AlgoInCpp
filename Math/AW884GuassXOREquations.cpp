//
// link: https://www.acwing.com/problem/content/886/
//
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int n;
int a[N][N];

int gauss() {
    int r, c;
    for (r = c = 0; c < n; c++) { // 按列枚举 行列下标初始都是0
        int t = r; // 找不是0的行 初始化成当前行
        for (int i = r; i < n; i++) { // 从当前行开始枚举
            if (a[i][c] != 0) {
                t = i;
                break; // 找到第一个不是0的行 就可以break
            }
        }
        if (a[t][c] == 0) continue; // 不存在所求 等于已经削成0了

        for (int i = c; i <= n; i++) { // 把第t行往上挪
            swap(a[t][i], a[r][i]); // 第t行的第i列和第r行第i列交换
        }

        for (int i = r + 1; i < n; i++) { // 用当前行把下面所有行的改列值削成0
            if (a[i][c] == 0) continue;
            for (int j = c; j <= n; j++) { // 一个个消掉
                a[i][j] ^= a[r][j];
            }
        }
        r++; // 行数往下移一个
    }

    if (r < n) { // 上三角矩阵行数小于n -> 无解或者无穷多解
        for (int i = r; i < n; i++) { // 此时等式左边都是0 看等式右边有没有非零
            if (a[i][n] != 0) return 2; // "0 == 非零" 无解
        }
        return 1; // 无穷多解
    }

    // 有唯一解 倒着推一边 把解算出来
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) { // 如果a[i][j]已经是0 不用消 如果不是零 就异或消掉
            a[i][n] = a[i][j] == 0 ? a[i][n] : a[i][n] ^ a[j][n];
        }
    }

    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) { // 读入方程组系数
        for (int j = 0; j < n + 1; j++) {
            cin >> a[i][j];
        }
    }

    int res = gauss();

    if (res == 0) {
        for (int i = 0; i < n; i++) {
            cout << a[i][n] << endl;
        }
    } else if (res == 1) {
        puts("Multiple sets of solutions");
    } else {
        puts("No solution");
    }

    return 0;
}
