#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   private:
    ListNode* merge(ListNode* leftList, ListNode* rightList) {
        ListNode* head = nullptr;
        ListNode* tmp = nullptr;

        if (leftList->val < rightList->val) {
            head = leftList;
            leftList = leftList->next;
        } else {
            head = rightList;
            rightList = rightList->next;
        }
        tmp = head;

        while (leftList != nullptr || rightList != nullptr) {
            if (leftList == nullptr) {
                tmp->next = rightList;
                break;
            }
            if (rightList == nullptr) {
                tmp->next = leftList;
                break;
            }

            if (leftList->val < rightList->val) {
                tmp->next = leftList;
                leftList = leftList->next;
            } else {
                tmp->next = rightList;
                rightList = rightList->next;
            }
            tmp = tmp->next;
            tmp->next = nullptr;
        }

        return head;
    }

   public:
    ListNode* sortList(ListNode* head) {
        // if the length is 1 or 0
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // if the length is 2
        if (head->next->next == nullptr) {
            if (head->next->val < head->val) {
                head->next->next = head;
                head = head->next;
                head->next->next = nullptr;
            }
        }

        ListNode *fasterPointer, *slowerPointer, *temporaryPointer;

        fasterPointer = head;
        slowerPointer = head;

        while (fasterPointer != nullptr && fasterPointer->next != nullptr) {
            temporaryPointer = slowerPointer;
            slowerPointer = slowerPointer->next;
            fasterPointer = fasterPointer->next->next;
        }

        temporaryPointer->next = nullptr;

        ListNode* leftList = sortList(head);
        ListNode* rightList = sortList(slowerPointer);

        return merge(leftList, rightList);
    }
};