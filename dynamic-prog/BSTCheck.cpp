#include<iostream>

using namespace std;

struct NODE{
    int d;
    NODE *l;
    NODE *r;
};

NODE* new_node(int data){
    NODE *node = new NODE;
    node->d = data;
    node->l = NULL;
    node->r = NULL;

    return node;
}

NODE* insert(NODE *root,int data){
    NODE *node = new_node(data);
    if(root == NULL)
    {
        root = node;
        return root;
    }else{
        NODE *temp = root,*prev = NULL;
        while(temp != NULL) {
            prev = temp;
            if (temp->d < data){
                temp = temp->r;
            }
            else {
                temp = temp->l;
            }
        }

        if(prev->d < data)
            prev->r = node;
        else
            prev->l = node;
    }
    return root;
}

void inorder(NODE *root)
{
    if(root == NULL){
        return ;
    }else{
        inorder(root->l);
        printf(" %d",root->d);
        inorder(root->r);
    }
}

bool update(NODE *root,int data){
    if(root == nullptr)
        return false;

    NODE *temp = root,*prev= nullptr;

    while(temp != nullptr || temp->d != data){
        if(temp->d < data)
            temp = temp->r;
        else
            temp = temp->l;
    }
    if(temp != nullptr)
    {
        temp->d = data;
        return true;
    }

    return false;
}

bool isBST(NODE *root,int l,int u){

    if(root == nullptr)
        return true;
    if(!(root->d >= l && root->d <= u))
        return false;

    return isBST(root->l,l,root->d) && isBST(root->r,root->d,u);
}

int main_BST(){

    int x[] = {5,2,7,9,4,1,8,21,13};
    NODE *root = insert(nullptr,15);

    for(int i=0;i<9;i++){
        insert(root,x[i]);
    }

    if(isBST(root,INT16_MIN,INT16_MAX)){
        cout<<endl<<"Valid BST.";
    }
}
