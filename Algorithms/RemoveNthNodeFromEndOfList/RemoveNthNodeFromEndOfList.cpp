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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes = {head};
        ListNode* next = head->next;
        while(next != NULL){
            nodes.push_back(next);
            next = next->next;
        }
        
        if(n == nodes.size()){
            next = head->next;
            delete head;
            return next;
        }else if(n == 1){
            nodes[nodes.size()-2]->next = NULL;
            delete nodes[nodes.size()-1];
        }else{
            nodes[nodes.size()-n-1]->next = nodes[nodes.size()-n+1];
            delete nodes[nodes.size()-n];
        }
        
        return head;
    }
};