//
// Created by root on 22/05/21.
//
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tar=head,*temp=head,*prev;
        int i=0;
        while(tar != nullptr && i++ < n){
            tar = tar->next;
        }
        while(tar != nullptr){
            prev = temp;
            temp = temp->next;
            tar = tar->next;
            i++;
        }

        if(i >= n) {
            if(head == prev && prev->next == nullptr)
                prev->next = nullptr;
            else if(head == temp)
                head = temp->next;
            else
                prev->next = temp->next;
        }

        return head;
    }
};

int main_remove_nth_node(){
    Solution s;
    ListNode *lstNode = new ListNode(1);
    lstNode->next = new ListNode(2);
    lstNode->next->next = new ListNode(3);
    /*lstNode->next->next->next = new ListNode(4);
    lstNode->next->next->next->next = new ListNode(5);
    lstNode->next->next->next->next->next = new ListNode(6);
    lstNode->next->next->next->next->next->next = new ListNode(7);
    lstNode->next->next->next->next->next->next->next = new ListNode(8);*/

    s.removeNthFromEnd(lstNode,2);
    return 0;
}
