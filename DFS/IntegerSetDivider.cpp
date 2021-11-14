//
// Salesforce OA
//

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class IntegerSetDivider {
public:
    int splitArray(vector<int>& arr, vector<int>& final) {
        if (arr.size() <= 1) return 0;
        vector<int> tmp;
        int cnt = arr.size() / 2;
        cout << "cnt:" << cnt << endl;
        int ret = 0x3f3f3f;

        int totSum = 0;
        for (int num : arr) {
            totSum += num;
        }
        cout << "totSum " << totSum << endl;

        dfs(0, arr, tmp, final, cnt, 0, totSum, ret);
        return ret;
    }

private:
    void dfs(int idx, vector<int>& arr, vector<int>& tmp, vector<int>& final,
             int cnt, int curSum, int totSum, int& ret) {
        if (tmp.size() >= cnt) {
            if (abs(2 * curSum - totSum) < ret) {
                ret = abs(2 * curSum - totSum);
                final.resize(tmp.size());
                cout << "tmp: ";
                for (int k = 0; k < tmp.size(); k++) {
                    cout << " " << tmp[k];
                    final[k] = tmp[k];
                }
                cout << endl;
            }
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            tmp.emplace_back(arr[i]);
            dfs(i + 1, arr, tmp, final, cnt, curSum + arr[i], totSum, ret);
            tmp.pop_back();
        }
    }
};

/*
int main() {
    vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    vector<int> final;
    IntegerSetDivider inst;
    int ret = inst.splitArray(arr, final);
    cout << "ret: " << ret << endl;

    cout << "final: ";
    for (int j : final) {
        cout<< " " << j;
    }

    return 0;
}
*/



