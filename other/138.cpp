#include <iostream>
#include <unordered_map>

using namespace std;

// class Node {
//    public:
//     int val;
//     Node* next;
//     Node* random;

//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
   private:
    unordered_map<Node*, int> originalList;
    unordered_map<int, Node*> newList;

   public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        Node* originCurPtr = head;
        Node* newHead;
        Node* newCurPtr;

        int count = 0;
        int newCount = 0;

        while (originCurPtr != NULL) {
            originalList[originCurPtr] = count++;
            originCurPtr = originCurPtr->next;
        }

        // generate to linked list
        originCurPtr = head;

        newHead = new Node(head->val);
        newCurPtr = newHead;
        newList[newCount++] = newCurPtr;

        for (int i = 1; i < count; i++) {
            originCurPtr = originCurPtr->next;
            newCurPtr->next = new Node(originCurPtr->val);
            newCurPtr = newCurPtr->next;
            newList[newCount++] = newCurPtr;
        }

        // process the random pointer
        originCurPtr = head;
        newCurPtr = newHead;
        for (int i = 0; i < count; i++) {
            Node * toNode;
            if (originCurPtr->random == NULL)
                toNode = NULL;
            else
                toNode = newList[originalList[originCurPtr->random]];

            newCurPtr->random = toNode;

            originCurPtr = originCurPtr->next;
            newCurPtr = newCurPtr->next;
        }

        return newHead;
    }
};