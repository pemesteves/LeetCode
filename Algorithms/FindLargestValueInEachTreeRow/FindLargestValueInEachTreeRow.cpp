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
    vector<int> values;
    
    void findLargestValues(TreeNode* node, int row) {
        if(values.size() == row) {
            values.push_back(node->val);
        } else if(node->val > values[row]) {
            values[row] = node->val;
        }
        
        if(node->left != NULL) {
            findLargestValues(node->left, row + 1);
        }
        if(node->right != NULL) {
            findLargestValues(node->right, row + 1);
        }
    }
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return vector<int>();
        
        findLargestValues(root, 0);
        
        return values;
    }
};