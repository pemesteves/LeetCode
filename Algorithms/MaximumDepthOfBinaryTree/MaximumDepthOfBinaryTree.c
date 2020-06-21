/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    int max = maxDepth(root->left)+1;
    int maxRight = maxDepth(root->right)+1;
    if(maxRight > max)
        max = maxRight;
    return max;
}