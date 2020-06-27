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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        vector<int> list;
        for(int i = 0; i < lists.size(); i++){
            ListNode* node = lists[i];
            while(node != NULL){
                list.push_back(node->val);
                node = node->next;
            }
        }
        
        if(list.size() == 0)
            return NULL;
        
        sort(list.begin(), list.end());
        
        ListNode* node = new ListNode;
        ListNode* prev = NULL;
        ListNode* init = node;
        for(int i = 0; i < list.size(); i++){
            node->val = list[i];
            if(i == list.size()-1)
                break;
            node->next = new ListNode;
            prev = node;
            node = node->next;
        }
        
        return init;
    }
};