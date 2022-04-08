#include<iostream>
#include<stdlib.h>
#include<vector>


using namespace std;
template <class T>
class Stack{
    public :
    struct Node
    {
        T data;
        Node *next;  
    };

    Node *first, *last;

    Stack(){
        first = new Node;
        first->data = -1;
        first->next = NULL;
    }

    Stack(T x){
        first = new Node;
        first->data = x;
        first->next = NULL;
        last = first;
    }

    T top(){
        if(first!=NULL)
        return first->data;
        else
        return -1;
    }

    void push(T x){
        Node *temp;
        temp = new Node;
        temp->data = x;
        temp->next = first;
        first = temp;
    }

    T pop(){
        if(first->data==-1){
            cout<<"Stack Empty"<<endl;
            return -1;
        }
    
        T temp;
        temp = first->data;
        first = first->next;
        return temp;
    }
    void display(){
        Node *p=first;
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
    
};

int main(int argc, char const *argv[])
{
    Stack<char> S;
    S.push('a');
    S.push('b');
    // S.pop();
    // S.pop();
    S.display();

}

