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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* oldhead = head;
        ListNode* newhead = head->next;
        while (newhead) {
            ListNode* tmp = newhead->next;
            newhead->next = head;
            head = newhead;
            newhead = tmp;
        }
        oldhead->next = NULL;
        return head;
    }
};