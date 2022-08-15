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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* fast = head->next, *slow = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        while(slow){
            st.push(slow);
            slow = slow->next;
        }
        ListNode* cur = head;
        ListNode* node;
        while(!st.empty()){
            node = st.top();
            st.pop();
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur->next = NULL;
    }
};