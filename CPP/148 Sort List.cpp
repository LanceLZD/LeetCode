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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while (fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return mergesort(left, right);
    }
    
    ListNode* mergesort(ListNode* a, ListNode* b) {
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        while (a && b) {
            if (a->val < b->val) {
                tmp->next = a;
                a = a->next;
                tmp = tmp->next;
            }
            else {
                tmp->next = b;
                b = b->next;
                tmp = tmp->next;
            }
        }
        if (a)
            tmp->next = a;
        if (b)
            tmp->next = b;
        return res->next;
    }
};