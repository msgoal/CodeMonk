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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(),*r = head;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                r->next = new ListNode(l1->val);
                r = r->next;
                l1 = l1->next;
            }

            if(l1 != nullptr && l1->val > l2->val){
                r->next = new ListNode(l2->val);
                r = r->next;
                l2 = l2->next;
            }
        }
        if(l1 != nullptr)
            r->next = l1;
        if(l2 != nullptr)
            r->next = l2;

        return head->next;
    }
};

int main(){
    Solution s;

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    //lstNode->next->next->next = new ListNode(4);
    //lstNode->next->next->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *v = s.mergeTwoLists(l1,l2);
    while(v != nullptr){
        cout<<"\t"<<v->val;
        v = v -> next;
    }
}