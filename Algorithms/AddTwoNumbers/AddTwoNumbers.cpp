/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        int res;
        ListNode* tmp = l1;
        while(true){
            res = l1->val + l2->val + c;    
            if(res > 9){
                res -= 10;
                c = 1;
            }else{ 
                c = 0;
            }
            l1->val = res;
            
            if(l1->next == NULL && l2->next == NULL){
                if(c == 1){
                    l1->next = new ListNode;
                    l1->next->val = c;
                }
                break;
            }else if(l1->next == NULL){
                l1->next = new ListNode;
                l1->next->val = 0;
            }else if(l2->next == NULL){
                l2->next = new ListNode;
                l2->next->val = 0;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        return tmp;
    }
};