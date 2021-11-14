//
// https://leetcode.com/problems/split-bst/
//

#include <TreeNode.h>
#include <vector>

using namespace std;

class LC776 {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> ret{nullptr, nullptr};
        if (root == nullptr) return ret;

        if (root->val <= V) {
            ret = splitBST(root->right, V);
            root->right = ret[0];
            ret[0] = root;
        } else {
            ret = splitBST(root->left, V);
            root->left = ret[1];
            ret[1] = root;
        }

        return ret;
    }
};