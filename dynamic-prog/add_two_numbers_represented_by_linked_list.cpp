#include<iostream>

#define size(a,b)  sizeof (a) / sizeof (b)

using namespace std;

typedef struct Node{
    int c;
    Node *next;
    int len;
    int carry;
}Node;

Node* _new(int c){
    Node *n = new Node;
    n->c = c;
    n->next = nullptr;
    n->len = 0;
    n->carry = 0;

    return n;
}

Node* createLL(char S[],int size){
    Node *lnk = nullptr,*ptr= nullptr;
    int i;
    fflush(stdout);
    for(i=0;i<size;i++){
        //cout<<endl<<" S[i] "<<S[i]<<" --> "<<S[i]-48;
        if(lnk == nullptr) {
            lnk = _new(S[i] - 48);
            ptr = lnk;
        }else{
            ptr->next = _new(S[i] - 48);
            ptr = ptr->next;
        }
        lnk->len++;
    }
    return lnk;
}

Node* sum(Node *lnk1,Node *lnk2, int diff){
    Node *n = nullptr,*t = nullptr;
    if(lnk1->next == nullptr && lnk2->next == nullptr){
        n = _new((lnk1->c + lnk2->c)%10);
        n->carry = (lnk1->c + lnk2->c)/10;
        n->next = t;
        return n;
    }

    if(diff > 0) {
        t = sum(lnk1->next, lnk2, diff - 1);
        int nval = (lnk1->c + t->carry);
        n = _new( nval % 10);
        n->carry = nval / 10;
        n->next = t;
    }
    else if(diff < 0) {
        t = sum(lnk1, lnk2->next, diff + 1);
        int nval = (lnk2->c + t->carry);
        n = _new( nval % 10);
        n->carry = nval / 10;
        n->next = t;
    }
    else {
        t = sum(lnk1->next, lnk2->next, diff);
        int nval = (lnk1->c + lnk2->c + t->carry);
        n = _new( nval % 10);
        n->carry = nval / 10;
        n->next = t;
    }

    return n;
}

int main_linkedlist_addition(){

    char A[] = "5";
    char B[] = "85459";
    int i=0;
    Node *lnk1 = createLL(A,size(A,char)-1);
    Node *lnk2 = createLL(B,size(B,char)-1);
    Node *temp = lnk1;
    cout<<endl<<" FIrst list : ";
   /* for(i=1;i<=lnk1->len;i++){
        cout<<temp->c<<"->";
        temp = temp->next;
    }
    temp = lnk2;
    cout<<endl<<" Second list : ";
    for(i=1;i<=lnk2->len;i++){
        cout<<temp->c<<"->";
        temp = temp->next;
    }*/

    Node *s = sum(lnk1,lnk2, lnk1->len - lnk2->len);
    cout<<endl;
    if(s -> carry > 0)
        cout<<s->carry<<"->";
    while(s != nullptr){
        cout<<s->c<<"->";
        s = s -> next;
    }
}