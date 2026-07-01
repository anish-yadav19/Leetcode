/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxS = INT_MIN;

    int solve(TreeNode* root)
    {
        if(root == NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);

        int thr = l + r + root->val;
        int koi_ak = max(l, r) + root->val;
        int ak = root->val;

        maxS = max({maxS, thr, koi_ak, ak});
        return max(koi_ak, ak);
    }
    int maxPathSum(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }
        solve(root);
        return maxS;
    }
};