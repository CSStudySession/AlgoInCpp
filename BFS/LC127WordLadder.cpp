//
// https://leetcode.com/problems/word-ladder/
//
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class LC127 {
public:
    // solution 1: plain BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> que;
        
        unordered_set<string> dict (wordList.begin(), wordList.end());
        unordered_set<string> seen;
        que.emplace(beginWord);
        int cnt = 1;

        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                string cur = que.front();
                que.pop();

                if (cur == endWord) return cnt;

                for (int j = 0; j < cur.size(); j++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == cur[j]) continue;
                        // 位置i的字符换成c, 然后前后部分拼接上
                        string nxt = cur.substr(0, j) + c + cur.substr(j+1);
                        // 与dict 和 seen 对照
                        if (dict.find(nxt) == dict.end() || seen.find(nxt) != seen.end()) continue;
                        seen.emplace(nxt);
                        que.emplace(nxt);
                    }
                }
            }
            // for(len...)结束后,层序遍历的一层结束了.cnt自增,进入下一层
            cnt++;
        }
        return 0;
    }

    // solution 2: bi-direction BFS
    int ladderLengthBibfs(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        queue<string> tic, tac;
        tic.emplace(beginWord);
        tac.emplace(endWord);

        unordered_set<string> ticSeen, tacSeen;
        ticSeen.emplace(beginWord);
        tacSeen.emplace(endWord);

        int cnt = 1;

        /*
         * 优化: 每次开始一层新的拓展时,都从元素个数少的队列开始
         * -> curQue一直指向短的队列,curSeen一直指向短队列的seen
         */
        queue<string>* curQue;
        unordered_set<string>* curSeen;
        unordered_set<string>* otherSeen;
        while (!tic.empty() || tac.empty()) {
            if (tic.size() >= tac.size()) {
                curQue = &tic;
                curSeen = &ticSeen;
                otherSeen = &tacSeen;
            } else {
                curQue = &tac;
                curSeen = &tacSeen;
                otherSeen = &ticSeen;
            }

            int len = curQue -> size();
            for (int k = 0; k < len; k++) {
                string cur = curQue -> front();
                curQue -> pop();
                if (otherSeen -> find(cur) != otherSeen -> end()) return cnt;

                for (int i = 0; i < cur.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == cur[i]) continue;
                        string nxt = cur.substr(0, i) + c + cur.substr(i+1);
                        if (curSeen -> find(nxt) != curSeen -> end() ||
                       dict.find(nxt) == dict.end()) continue;
                        curQue -> emplace(nxt);
                        curSeen -> emplace(nxt);
                    }
                }
            }
            // 这层已经拓展完了 进入下一层
            cnt++;
        }
        return 0;
    }
};