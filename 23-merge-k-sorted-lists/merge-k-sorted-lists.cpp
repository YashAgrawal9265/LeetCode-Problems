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
        if(lists.size() == 0) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto it: lists){
            if(it)
                pq.push(it);
        }
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(!pq.empty()){
            ListNode* node = pq.top();
            temp->next = node;
            temp = temp->next;
            pq.pop();
            if(node->next)
                pq.push(node->next);
            
        }
        return dummyNode->next;
    }
};