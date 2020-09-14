//
// link: https://leetcode.com/problems/sum-of-subarray-minimums/
//
#include <vector>
#include <stack>
using namespace std;

class LC907 {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<int> s;
        int ret = 0;
        int mod = 1e9 + 7;

        for (int k = 0; k < A.size(); k++) {
            while (!s.empty() && A[s.top()] > A[k]) {
                int mid = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                ret = (ret + A[mid] * (k - mid) * (mid - left)) % mod;
            }
            s.push(k);
        }

        int len = A.size();
        while (!s.empty()) {
            int mid = s.top();
            s.pop();
            int left = s.empty() ? -1 : s.top();
            ret = (ret + A[mid] * (len - mid) * (mid - left)) % mod;
        }

        return ret;
    }
};