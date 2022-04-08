#include<iostream>
#include<stdio.h>

using namespace std;

class LinkedList{
    private :
    struct Node {
        int data;
        Node *next; 
    };

    Node *first = NULL, *last;
    public:

    Node* begin(){
        return first;
    }

    Node* end(){
        Node *p=first;
        while(p->next){
            p=p->next;
        }
        last = p;
        return last;
    }

    void push_back(int x){
        Node *temp;
        temp = new Node;
        temp->data = x;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    void push_front(int x){
        Node *temp;
        temp = new Node;
        temp->data = x;
        temp->next = first;
        first = temp;
    }

    LinkedList(int A[], int n){
        Node *temp;
        
        first = new Node;
        first->data = A[0];
        first->next = NULL;
        last = first;
        
        for(int i=1; i<n; i++){
            push_back(A[i]);
        }

    }
    
    LinkedList(int x){
        first = new Node;
        first->data = x;
        first->next = NULL;
        last = first;
    }

    LinkedList(){
        first = new Node;
        first->data = NULL;
        first->next = NULL;
        last = first;
    }

    void insert(int pos, int x){
        if(pos==0)
            push_front(x);
        
        else{
            Node *temp, *p;
            p = first;
            temp = new Node;
            temp->data = x;
            
            for(int i=1; i<pos && p; i++)
                p=p->next;
            
            if(p){
                temp->next = p->next;
                p->next = temp;
            }
        }
    }

    void sorted_insert(int x){
        Node *p, *q, *temp;
        
        p=first;
        q=NULL;
        temp = new Node;
        temp->data = x;
    
        /*  First check for p and then for p->data, 
            reversing the order of expression (p && p->data) 
            does not produce correct output.    */ 
        
        while(p && p->data<x){ 
            q = p;
            p = p->next;
        }
        if(p==first){
            temp->next = first;
            first = temp;
        }
        else{
            temp->next = q->next;
            q->next = temp;
        }
    }

    bool if_sorted(){
        int x = INT_MIN;
        Node *p = first;
        while(p){
            if(p->data < x)
                return false;
            x = p->data;
            p = p->next; 
        }
        return true;
    }

    void linkify(int A[], int n){
        for(int i=0; i<n; i++)
            sorted_insert(A[i]);
        
    }

    void driver_reverser(Node *a, Node*b){
        if(b){
            driver_reverser(b, b->next);
            b->next = a;
        }
        else{
            first = a;
        }
    }

    void iterative_reverse(){
        Node *a, *b, *c;
        c=first;
        a=NULL;
        b=NULL;
        while(c!=NULL){
            a=b;
            b=c;
            c=c->next;
            b->next = a;
        }
        first=b;
        end();
    }

    void recursive_reverse(){
        driver_reverser(NULL, first);
        end();
    }

    void display(){
        Node *p = first;
        cout<<p->data;
        p=p->next;
        do cout<<"-->"<<p->data; while(p=p->next);
    }

    int length(){
        int count;
        Node *p=first;
        while(p!=NULL){
            p=p->next;
            count++;
        }
        return count;
    }

    void concat(LinkedList second){
        last->next = second.first;
        end();
    }

    void merge(LinkedList second){
        if(this->if_sorted() && second.if_sorted()){
            Node *p1 = first, *p2 = second.first, *dummy, *p3;
            dummy = new Node;
            p3 = dummy;
            
            while(p1 && p2){
                if(p1->data < p2->data){
                    p3->next = p1;
                    p1 = p1->next;
                }
                else{
                    p3->next = p2;
                    p2=p2->next;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    system("cls");
    int A[4] = {2, 4, 1, 2};
    int B[4] = {8, 3, 5, 6};
    LinkedList list_1(A, 4);
    LinkedList list_2(B, 4);
    list_1.concat(list_2);
    list_1.display();
    //L.display();
    // cout<<L.length();
    // return 0;
}
