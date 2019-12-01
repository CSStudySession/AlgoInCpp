//
// Created by aarliu on 11/30/19.
//

#include <vector>

using namespace std;

class Solution {

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> clr_to_num;
        vector<bool> isClrCld;
        int di[] = {0, 0, 1, -1};
        int dj[] = {1, -1, 0, 0};

         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    isClrCld.push_back(true);
                    dfs(grid, i, j, isClrCld, di, dj);
                }
            }
        }

         int result = 0;
         for (int k = 0; k < isClrCld.size(); k++) {
             if (isClrCld[k]) result++;
         }

         return result;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j,
            vector<bool>& isClrCld, int di[], int dj[]) {
        grid[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (!valid(ni, nj, grid.size(), grid[0].size())) {
                isClrCld[isClrCld.size() - 1] = false;
            } else if (grid[ni][nj] == 0) {
                dfs(grid, ni, nj, isClrCld, di, dj);
            }
        }
    }


    bool valid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

};