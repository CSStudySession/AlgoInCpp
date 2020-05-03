//
// 868. 筛质数
// https://www.acwing.com/problem/content/870/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

// 埃氏筛法 复杂度O(nloglogn) ~= O(n)
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (st[i]) continue; // 被筛掉过了
        primes[cnt++] = i; // 找到了新的素数
        // 把素数的倍数都筛掉 每次加一倍的i
        for (int j = i + i; j <= n; j += i) {
            st[j] = true;
        }
    }
}

/*
 * 线性筛法: 把每一个合数 用它最小的质因子筛掉
 * 任何一个合数一定会被筛掉 筛的时候 我们也只用最小质因子来筛 每个数都只有一个最小质因子 所以每个数都只会被筛一次
 * 所以时间复杂度是线性的
 */

void linear_get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i; // 如果没有被筛掉(是质数) 就加到质数表里去

         //从小到大枚举质数表里有的质数 用来筛掉所有合数 当枚举的质数大于n/i时 break
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true; /*
                                       把primes[j]*i筛掉 且用的是最小质因子primes[j]筛掉的
                                       为什么primes[j]一定是primes[j]*i的最小质因子呢? 分类讨论:
                                       1. i % primes[j] == 0: 理由见下面的注释
                                       2. i% primes[j] != 0:
                                       由于是从小到大枚举的primes[j] 所以primes[j]一定小于i的任何质因子
                                       primes[j]又是质数 -> primes[j]*i的最小质因子一定是primes[j]
                                       */
            if (i % primes[j] == 0) break; /*
                                            此时primes[j]一定是i的最小质因子
                                            因为是从小到大枚举的primes[j] 第一次出现(i%primes[j]==0)时
                                            primes[j]一定是i最小的质因子了 因此 primes[j]一定是
                                            primes[j]*i的最小质因子
                                            */
        }
    }
}

int main() {
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}

