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
    ListNode* removeElements(ListNode* head, int val) {
        // A null linked list
        if (head == nullptr)
            return nullptr;
    
        // A linked list whose head node needs delete
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Delete other node who has the same value
        ListNode* current = head;
        while (current != nullptr) {
            if (current->val == val) {
                ListNode* temp = current;
                current = current->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
