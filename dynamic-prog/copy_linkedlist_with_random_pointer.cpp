#include <iostream>
#include <map>

using namespace std;

typedef struct RPNode{
    int n;
    RPNode *next;
    RPNode *random;
}Node;
typedef Node* Nod;

Node* _newrpnode(int val){
    Node *ptr = new Node;
    ptr->n = val;
    ptr->next = nullptr;
    return ptr;
}

Nod clone(Nod head){
    Nod copy= nullptr,ptr = head;

    while(ptr != nullptr){
        Nod _new = _newrpnode(ptr->n);
        _new->next = ptr->next;
        ptr->next = _new;

            ptr = _new->next;
    }

    ptr = head;
    while(ptr != nullptr){

        ptr->next->random = (ptr->random)? ptr->random->next : nullptr;

        ptr = ptr->next->next;
    }

    ptr = head,copy = head->next;
    Nod mov = copy;

    while(mov->next){
      ptr->next = mov->next;
      ptr = ptr->next;

      mov->next = ptr->next;
      mov = mov->next;
    }
    ptr->next = nullptr;

    return copy;
}

Nod clone_hash_map(Nod head){
    Nod copy = nullptr,ptr = head,mov;
    map<int,Nod> hash;

    while(ptr){
        if(!copy){
            copy = _newrpnode(ptr->n);
            mov = copy;
            hash.insert(pair<int,Nod>(ptr->n,mov));
            if(ptr->random->n)
        }else{
            mov->next = _newrpnode(ptr->n);

            if(!(hash.find(ptr->random->n) == hash.end())){

            }
        }

        ptr = ptr->next;
    }

}


int main(){
    Node *head = _newrpnode(7);
    head->next = _newrpnode(13);
    head->next->next = _newrpnode(11);
    head->next->next->next = _newrpnode(10);
    head->next->next->next->next = _newrpnode(1);
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Nod copy = clone(head);
}
