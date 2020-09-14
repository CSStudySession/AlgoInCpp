//
// link: https://leetcode.com/problems/score-of-parentheses/
//
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        for (char i : S) {
            if (i == '(') {
              s.push(0);
            } else {
                int cur = 0;
                while (s.top() != 0) {
                    cur += s.top();
                    s.pop();
                }
                s.pop(); // 把栈顶的0:'(' 弹出
                if (cur == 0) { // 一对'()'
                    s.push(1);
                } else { // '( () () () )'
                    s.push(cur * 2);
                }
            }
        }
        int ret = 0;
        while (!s.empty()) {
            ret += s.top();
            s.pop();
        }
        return ret;
    }
};
