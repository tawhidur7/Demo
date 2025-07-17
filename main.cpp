#include <iostream>

using namespace std;
struct Node{
    int value;
    Node* next;
};
Node* front1=nullptr;
Node* front2=nullptr;
Node* rear1=nullptr;
Node* rear2=nullptr;

bool isFull(){
    if(front1!=nullptr && front1==rear1){
        return true;
    }
    else{
        return false;
    }
}
bool isEmpty(){
    if(front1==nullptr){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int item){
    Node* newnode=new Node();
    newnode->value=item;
    newnode->next=nullptr;

    if(isEmpty()){
        front1=rear1=newnode;
    }
    rear1->next=newnode;
    rear1=newnode;

}
void dequeue(){
    if(isEmpty()){
        cout<<"Nothing to dequeue"<<endl;
        exit(1);
    }
    int val=front1->value;
    Node* temp=front1;
    front1=front1->next;
    delete temp;
    cout<<"New front is: "<<front1->value<<endl;
}
void display(){
    Node* temp=front1;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
}
int main()
{
    int size;
    cout<<"Enter the number of items you want to enter: ";
    cin>>size;
    int item;
    cout<<"Enter the items below"<<endl;
    for(int i=0;i<size;i++){
        cin>>item;
        enqueue(item);
    }
    display();
    return 0;
}
