//
// link: https://leetcode.com/problems/largest-bst-subtree/
//

#include <TreeNode.h>
#include <algorithm>
#include <climits>

using namespace std;

class LC333 {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        int mn = INT_MIN, mx = INT_MAX; // 赋值给新变量 INT_MIN是常量 不能修改
        helper(root, mn, mx, res);
        return res;
    }

private:
    bool helper (TreeNode* root, int& mn, int& mx, int& res) {
        if (root == nullptr) return true;
        int l_min = INT_MIN, l_max = INT_MAX, l_res = 0;
        int r_min = INT_MIN, r_max = INT_MAX, r_res = 0;

        bool isLeft = helper(root->left, l_min, l_max, l_res);
        bool isRight = helper(root->right, r_min, r_max, r_res);

        if (isLeft && isRight) {
            if ((root -> left == nullptr || root -> val > l_max) &&
                    (root -> right == nullptr || root -> val <= r_min)) {
                res = l_res + r_res + 1;
                // 更新mn,mx 返回给上层 上层对比的时候需要用更新后的值
                mn = root -> left == nullptr ? root -> val : l_min;
                mx = root -> right == nullptr ? root -> val : r_max;
                return true;
            }
        }

        res = max(l_res, r_res);
        return false;
    }

};