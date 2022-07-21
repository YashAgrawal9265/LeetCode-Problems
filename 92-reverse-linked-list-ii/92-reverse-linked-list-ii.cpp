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
    ListNode* reverse(ListNode* head, int left, int right){
        int k = right - left + 1;
        ListNode* pre = NULL, *cur = head, *nex;
        int count = 0;
        while(cur and count < k){
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
            count++;
        }
        head->next = cur;
        return pre;
        
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == 1){
            return reverse(head,left,right);
        }
        ListNode* cur = head, *pre = NULL;
        int count = 0;
        while(cur and count < left-1){
            pre = cur;
            cur = cur->next;
            count++;
        }
        pre->next = reverse(cur,left,right);
        return head;
    }
};