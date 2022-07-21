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
        ListNode* prev = NULL, *cur = head, *nex;
        int count = 0;
        while(cur and count < right - left + 1){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
            count++;
        }
        head->next = cur;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or !head->next) return head;
        ListNode* prev = NULL, *cur = head;
        int count = 0;
        while(cur and count < left-1){
            prev = cur;
            cur = cur->next;
            count++;
        }
        if(prev){
            prev->next = reverse(cur,left,right);
            return head;
        }
        else{
            return reverse(cur,left,right);
        }
    }
};