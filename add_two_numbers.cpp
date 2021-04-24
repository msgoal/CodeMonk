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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *curr= nullptr,*ptr;
        while(l1 || l2 || carry){
            ListNode *new_node;

            if(l1 != nullptr){
                carry += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                carry += l2->val;
                l2 = l2->next;
            }

            if(curr == nullptr){
                curr = new ListNode(carry%10);
                ptr = curr;
            }else{
                ptr->next = new ListNode(carry%10);
                ptr = ptr->next;
            }

            carry = carry / 10;
        }
        return curr;
    }

};

int mainadd_two_numbers(){ //add_two_numbers

    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode *x = solution.addTwoNumbers(l1,l2);

    while(x != nullptr){
        cout<<x->val<<" -> ";
        x = x -> next;
    }

    return 0;
}

