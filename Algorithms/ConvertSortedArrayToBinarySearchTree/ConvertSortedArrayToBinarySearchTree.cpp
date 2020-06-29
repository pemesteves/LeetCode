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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        
        int m = nums.size()/2;
        
        TreeNode* node = new TreeNode;
        node->val = nums[m];
        if(m != 0){
            vector<int> left(nums.begin(), nums.begin()+m);
            node->left = sortedArrayToBST(left);
        }else node->left = NULL;
        
        if(nums.size()-1 != m){
            vector<int> right(nums.begin()+m+1, nums.end());
            node->right = sortedArrayToBST(right);
        }else node->right = NULL;
        
        return node;
    }
};