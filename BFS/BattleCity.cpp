//
// link: https://blog.csdn.net/yinghui_yht/article/details/68920801
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int x,y;
    int step;
} st,ed;

int bfs(vector<vector<char>>& map, vector<vector<bool>>& visited) {
    int next[4][2]= {{-1,0}, {1,0}, {0,1}, {0,-1}};
    queue<node> que;
    que.push(st);

    while (!que.empty()) {
        st = que.front();
        que.pop();

        if (map[st.x][st.y] == 'T') {
            return st.step;
        }

        if (map[st.x][st.y] == 'B') {
            st.step = st.step + 1;
            map[st.x][st.y] = 'E';
            que.push(st);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            ed.x = st.x + next[i][0];
            ed.y = st.y + next[i][1];
            if (ed.x < 0 || ed.x >= map.size() || ed.y < 0 || ed.y >= map[0].size() ||
                map[ed.x][ed.y] == 'S' || map[ed.x][ed.y] == 'R' || visited[ed.x][ed.y]) {
                continue;
            }

            ed.step = st.step + 1;
            visited[ed.x][ed.y] = true;
            que.push(ed);
        }
    }

    return -1;
}

int main() {
    vector<vector<char>> map = {{'S', 'E', 'B', 'Y'}, {'S', 'T', 'B', 'B'}};
    int m = map.size(), n = map[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    st.x = 0, st.y = 3;
    st.step = 0;
    int ret = bfs(map, visited);
    cout << "ret == " << ret << endl;
}