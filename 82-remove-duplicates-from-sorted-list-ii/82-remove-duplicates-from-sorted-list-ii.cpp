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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head;
        ListNode* pre = dummy;
        while(cur and cur->next){
            if(cur->val != cur->next->val){
                pre = cur;
                cur = cur->next;
            }
            else{
                int x = cur->val;
                while(cur and cur->val == x){
                    cur = cur->next;
                }
                pre->next = cur;
            }
        }
        return dummy->next;
    }
};