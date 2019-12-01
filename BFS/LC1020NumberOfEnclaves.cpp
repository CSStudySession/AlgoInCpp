//
// Created by aarliu on 11/29/19.
//

#include <vector>
#include <unordered_map>
using namespace std;

class NumberOfEnclaves {
public:
    int numEnclaves(vector<vector<int>>& A) {
        if (A.empty()) return 0;
        int n = A.size();
        int m = A[0].size();
        vector<int> clr_to_num;
        vector<bool> reachedOut;
        int di[] = {0, 0, 1, -1};;
        int dj[] = {1, -1, 0, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == 1) {
                    reachedOut.push_back(false);
                    clr_to_num.push_back(1);
                    dfs(i, j, A, reachedOut, di, dj, clr_to_num);
                }
            }
        }

        int res = 0;
        for (int k = 0; k < reachedOut.size(); k++) {
            // 注意这里要选择不能达到边界之外的点！
            if (!reachedOut.at(k)) res += clr_to_num[k];
        }
        return res;
    }

    void dfs (int i, int j, vector<vector<int>>& A, vector<bool>& reachedOut,
                int di[], int dj[], vector<int>& clr_to_num) {
        A[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            // 注意这里坐标别敲错了！
            int ni = i + di[k];
            int nj = j + dj[k];
            if (!valid(ni, nj, A.size(), A[0].size())) {
                reachedOut[reachedOut.size() - 1] = true;
            } else {
                if (A[ni][nj] == 1) {
                    clr_to_num[clr_to_num.size() - 1] += 1;
                    dfs(ni, nj, A, reachedOut, di, dj, clr_to_num);
                }
            }
        }
    }

    bool valid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
};

int main() {
    NumberOfEnclaves inst;
    vector<vector<int>> A =
            {{0,0,0,0}
            ,{1,0,1,0},
             {0,1,1,0},
             {0,0,0,0}};
    int result = inst.numEnclaves(A);
    return result;
}


