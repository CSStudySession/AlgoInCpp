//
// Created by Aaron Liu on 9/13/20.
//

#include <vector>
#include <queue>
using namespace std;

class LC286 {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0) return;
        queue<pair<int, int>> que;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) que.push({i,j});
            }
        }

        const int INF = 2147483647;
        vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (auto dir : dirs) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx < 0 || ny < 0 || nx >= rooms.size() || ny >= rooms[0].size() || rooms[nx][ny] != INF) continue;
                rooms[nx][ny] = rooms[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
};