//
// link: https://leetcode.com/problems/shortest-path-with-alternating-colors/
//
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class LC1129 {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        // build graph, using adj list.
        vector<unordered_set<int>> edges_r(n);
        vector<unordered_set<int>> edges_b(n);

        for (const auto& e : red_edges) {
            edges_r[e[0]].insert(e[1]);
        }

        for (const auto& e : blue_edges) {
            edges_b[e[0]].insert(e[1]);
        }

        unordered_set<int> seen_r;
        unordered_set<int> seen_b;

        vector<int> ans(n, -1);
        queue<pair<int, int>> q; // (node, last step color)
        q.push({0,0}), q.push({0, 1});
        seen_r.insert(0), seen_b.insert(0); // 0:red, 1:blue
        int steps = 0;

        for(;!q.empty();) {
            int size = q.size();
            for (; size-- > 0;) {
                int curr = q.front().first;
                int color = q.front().second;
                q.pop();
                ans[curr] = ans[curr] == -1 ? steps : ans[curr];
                auto& edges = color == 0 ? edges_b : edges_r;
                auto& seen = color == 0 ? seen_b : seen_r;
                for (int nxt : edges[curr]) {
                    if (seen.count(nxt)) continue;
                    seen.insert(nxt);
                    q.push({nxt, 1 - color});
                }
            }
            steps++;
        }
        return ans;
    }
};