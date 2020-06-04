//
// link: https://www.acwing.com/problem/content/893/
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int res = 0;

    scanf("%d", &n);

    for (;n-- > 0;) {
        int x;
        scanf("%d", &x);
        res ^= x;
    }

    if (res != 0) puts("Yes");
    else puts("No");

    return 0;
}
