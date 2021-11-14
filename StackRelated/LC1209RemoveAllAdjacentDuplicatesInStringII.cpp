//
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
//

#include <vector>
#include <stack>
#include <string>
using namespace std;

class LC907 {
public:
    string removeDuplicates(string s, int k) {
        int i = 0, n = s.length();
        vector<int> count(n);
        for (int j = 0; j < n; ++j, ++i) {
            s[i] = s[j];
            if (i > 0 && s[i - 1] == s[j]) {
                count[i] = count[i - 1] + 1;
            } else {
                count[i] = 1;
            }

            if (count[i] == k) i -= k;
        }
        return s.substr(0, i);
    }

};