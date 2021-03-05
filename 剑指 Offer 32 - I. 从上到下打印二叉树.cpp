/*
题目：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> vals;
        queue<TreeNode *> q;
        
        if (!root) {
            return vals;
        }

        q.push(root);

        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            vals.push_back(cur->val);
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }

        return vals;
    }
};