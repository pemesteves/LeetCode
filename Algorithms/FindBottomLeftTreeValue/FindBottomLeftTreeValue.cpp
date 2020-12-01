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
    pair<int, int> row_value;
    
    void getValue(TreeNode* node, int row) {
        if(row_value.first < row) {
            row_value = make_pair(row, node->val);
        }
        
        if(node->left != NULL) {
            getValue(node->left, row + 1);
        }
        
        if(node->right != NULL) {
            getValue(node->right, row + 1);
        }
    }
    
public:
    int findBottomLeftValue(TreeNode* root) {
        row_value = make_pair(0, root->val);
        
        getValue(root, 0);
        
        return row_value.second;
    }
};