/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        unordered_map<int, RandomListNode*> m;
        queue<pair<int, int>> q;
        RandomListNode *res = new RandomListNode(0);
        RandomListNode *tmp = res;
        while (head) {
            RandomListNode *nxt = new RandomListNode(head->label);
            m[head->label] = nxt;
            if (head->random)
                q.push(make_pair(head->label, head->random->label));
            tmp->next = nxt;
            tmp = tmp->next;
            head = head->next;
        }
        while (!q.empty()) {
            m[q.front().first]->random = m[q.front().second];
            q.pop();
        }
        return res->next;
    }
};