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

};