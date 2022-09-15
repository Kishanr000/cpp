#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
};

void display(Node* node){
    while(node!=NULL){
        cout<<node->val <<" ";
        node = node->next;
    }
}

void addbegining(Node** head, int val){
    Node* temp = new Node();

    temp->val = val;
    temp->next = *head;
    
    *head = temp;

    cout<< temp->val << "inserted"<<endl;
}

void addlast(Node** head, int val){
    Node* newnode = new Node();

    newnode->val = val;
    newnode->next = NULL;

    if(*head==NULL){
        *head = newnode;
        cout<<newnode->next <<"inserted\n"<<endl;
        return;
    }

    Node* tempnode = *head;
    while (tempnode->next!=NULL)
    {
        tempnode = tempnode->next;
    }
    tempnode->next = newnode;
    cout<<newnode->val << "inserted\n" ;
    
}

int main(){
    Node* head = NULL;

    addbegining(&head,10);
    addbegining(&head, 9);
    addbegining(&head, 8);

    display(head);

    addlast(&head, 12);
    addlast(&head, 13);

    display(head);
}