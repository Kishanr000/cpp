#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head){
    if(head == NULL)
        cout<<"Empty list";
    
    Node* temp = head;

    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAthead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtanypoint(Node* &head, Node* &tail, int position, int d){
    // if insertiona is at head
    if(position == 1){
        insertAthead(head,d);
        return;
    }

    // insertion at any position 
    // first to traverse at postion -1
    Node* temp = head;
    int count = 0;
    while(count < position -1){
        temp = temp->next;
    }

    // if position at last or at tail 
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    // create a node of given data
    Node* newnode = new Node(d);
    
    newnode->next = temp->next;
    temp->next = newnode;

}


int main(){
    
    Node* node1 = new Node(8);
    Node* head = node1;
    Node* tail = node1;
    insertAthead(head,9);
    insertAthead(head,10);
    insertAthead(head,11);
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    print(head);
    cout<<endl;

    insertAtTail(tail, 12);

    print(head);
}