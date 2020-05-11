//
// link: https://leetcode.com/problems/bus-routes/
//

#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        int res = 0;
        unordered_map<int, vector<int>> stop2Bus;
        queue<int> que{{S}};
        unordered_set<int> visited;

        for (int i = 0 ; i < routes.size(); i++) {
            for (int j : routes[i]) {
                stop2Bus[j].push_back(i);
            }
        }

        while (!que.empty()) {
            res++;
            int len = que.size();
            for (; len-- > 0; ) {
                int st = que.front();
                que.pop();
                for (int bus : stop2Bus[st]) {
                    if (visited.count(bus)) continue;
                    visited.insert(bus);
                    for (int stop : routes[bus]) {
                        if (stop == T) return res;
                        que.push(stop);
                    }
                }
            }
        }
        return -1;
    }
};

