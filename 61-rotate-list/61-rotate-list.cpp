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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !k) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        }
        k = k % len;
        k = len - k - 1;
        ListNode* cur = head;

        while(cur and k--){
            cur = cur->next;
        }
        
        
        tail->next = head;
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};