//
// link: https://www.acwing.com/problem/content/885/
//
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int guess() {
    int c, r;
    for (c = 0, r = 0; c < n; c++) { // 枚举每一列
        int t = r;
        for (int i = r; i < n; i++) { // 找绝对值最大的一列
            if (fabs(a[i][c]) > fabs(a[t][c])) {
                t = i;
            }
        }
        // 如果当前列最大的系数已经是0了 直接处理下一列
        if (fabs(a[t][c]) < eps) {
            continue;
        }

        for (int i = c; i <= n; i++) { // 将改行换到最上面 c之前的列都是0了
            swap(a[t][i], a[r][i]);
        }
        // 这里必须倒着来 如果正着算 会上来把第一个数变成1 之后的数就都除1了
        for (int i = n; i >= c; i--) { // 将该行第一个系数变成1
            a[r][i] /= a[r][c];
        }

        for (int i = r + 1; i < n; i++) { // 将下面所有行第c列消成0
            if (fabs(a[i][c]) > eps) { // 已经是0 不用消
                for (int j = n; j >= c; j--) { /*
                                                当前系数a[i][j] 减去
                                                最上面一层方程系数a[r][j] 的 a[i][c]倍
                                                因为最上面方程(在第r行)的第c列系数是1
                                                */
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++; // 每次处理完一列 别忘加一行 某一行往上调整后 位置就固定了
    }

    if (r < n) {
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps) return 2; // 0 == 非零 无解
        }
        return 1; // 无穷多解
    }

    for (int i = n - 1; i >= 0; i--) { // 从后往前把答案推出来
        for (int j = i + 1; j < n; j++) {
            a[i][n] -= a[i][j] * a[j][n]; // 除了当前系数xi 后面系数都消成0 a[j][n]是xj的值
        }
    }

    return 0; // 唯一解
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> a[i][j];
        }
    }

    int t = guess();

    if (t == 0) {
        for (int i = 0; i < n; i++) {
            printf("%.2lf\n", a[i][n]);
        }
    } else if (t == 1) {
        puts("Infinite group solutions");
    } else {
        puts("No solution");
    }

    return 0;
}