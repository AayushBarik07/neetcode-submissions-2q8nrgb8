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
        ListNode* fast = head-> next;
        ListNode* slow = head;

        int len = findLen(head);
        int pos = len - n; 

        if(!head) return nullptr;
        if(!head-> next) {
            delete(head);
            return NULL;
        }
        if(len == n) {
            return head-> next;
        }

        int i=1;
        while(i<pos) {
            if(!fast-> next) {
                delete(fast);
                return head;
            }

            fast = fast-> next;
            slow = slow-> next;
            i++;
        }

        slow-> next = fast-> next;
        fast-> next = NULL;
        delete(fast);
        
        return head;
        // if(!head || !head-> next) return nullptr;
        // int len = findLen(head);
        // int pos = len - n;
        //  if(n == len) {
        //     ListNode* newHead = head->next;
        //     delete head;
        //     return newHead;
        // }
        // ListNode* temp = head;
        // int i=1;
        // while(i<pos) {
        //     temp = temp-> next;
        //     i++;
        // }
        // cout<<temp-> val;
        // ListNode* toDelete = temp-> next;
        // temp-> next = temp-> next-> next;
        // delete(toDelete);

        // return head; 
    }
};
