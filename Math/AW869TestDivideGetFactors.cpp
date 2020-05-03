//
// 869. 试除法求约数
// https://www.acwing.com/problem/content/871/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_factors(int x) {
    vector<int> res;
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            res.push_back(i);
            // 避免i和x/i重复被放入res
            if (i != x / i) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;

    for (; n > 0; n--) {
        int x;
        cin >> x;

        auto res = get_factors(x);
        for (auto num : res) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

