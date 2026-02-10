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
/*
    COmpany Tags : Amazon, Cadence India, Directi, MakeMyTrip, Microsoft, Oracle, OYO Rooms,      Philips, Salesforce, Snapdeal, VMWare
*/


//T.C : O(n)
//S.C : O(depth of tree) - Recursion System Stack Space
class Solution {
public:
    
    int diameter(TreeNode* root, int& result) {
        if(!root)
            return 0;
        
        int left  = diameter(root->left, result);
        int right = diameter(root->right, result);
        
        result = max(result, left + right); //What if I longest diamenter passes through left -> me -> right
        
        return max(left, right) + 1; //But I will return max I can afford if (left -> me -> right) was not answer
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        int result = INT_MIN;
        
        diameter(root, result);
        
        return result;
    }
};