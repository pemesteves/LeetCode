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
    unordered_map<int, int> um;
    
    void getFrequencies(TreeNode* root) {
        auto it = um.find(root->val);
        if(it == um.end()) {
            um.insert(make_pair(root->val, 1));    
        }else{
            (*it).second++;
        }
        
        if(root->left != NULL){
            getFrequencies(root->left);
        }
        if(root->right != NULL){
            getFrequencies(root->right);
        }        
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        if(root == NULL) return vector<int>();
        
        getFrequencies(root);
        
        int maxFreq = 0;
        vector<int> modes;
        for(auto it = um.begin(); it != um.end(); it++) {
            if((*it).second > maxFreq) {
                maxFreq = (*it).second;
                modes = vector<int>(1, (*it).first);
            } else if ((*it).second == maxFreq) {
                modes.push_back((*it).first);
            }
        }
        
        return modes;
    }
};