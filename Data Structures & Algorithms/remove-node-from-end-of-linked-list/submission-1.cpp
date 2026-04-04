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
    int findLen(ListNode* head) {
        ListNode* temp = head;
        int cnt=0;

        while(temp) {
            cnt++;
            temp=temp-> next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            1-> 2-> 3-> 4-> null
        */

        if(!head || !head-> next) return nullptr;
        int len = findLen(head);
        int pos = len - n;
         if(n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* temp = head;
        int i=1;
        while(i<pos) {
            temp = temp-> next;
            i++;
        }
        cout<<temp-> val;
        ListNode* toDelete = temp-> next;
        temp-> next = temp-> next-> next;
        delete(toDelete);

        return head; 
    }
};
