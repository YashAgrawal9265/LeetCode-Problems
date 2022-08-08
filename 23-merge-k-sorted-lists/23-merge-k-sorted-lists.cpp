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
struct cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(auto &it: lists){
            if(it) pq.push(it);
        }
        if(pq.size() == 0) return NULL;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            temp->next = node;
            temp = temp->next;
            if(node->next) pq.push(node->next);
        }
        return dummy->next;
    }
};