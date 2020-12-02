/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        
        vector<int> v;
        ListNode* tmpPnt = head;
        do {
            v.push_back(tmpPnt->val);
            tmpPnt = tmpPnt->next;
        }while(tmpPnt != NULL);
        
        for(size_t i = 0, j = v.size()-1; i < j; i++, j--) {
            if(v[i] != v[j]) return false;
        }
        return true;
    }
};