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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newhead = new ListNode(0);
        ListNode* res = newhead;
        while (head) {
            ListNode* tmp = newhead;
            while (tmp->next && tmp->next->val<head->val)
                tmp = tmp->next;
            ListNode* remain = tmp->next;
            tmp->next = head;
            head = head->next;
            tmp = tmp->next;
            tmp->next = remain;
        }
        return res->next;
    }
};