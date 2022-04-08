#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;
class DoublyLinkedList{
    private:
    struct node
    {
        node *prev;
        int data;
        node *next;
    };
    node *first;
    node *last;
    
    public:

    DoublyLinkedList(int x){
        first->data = x;
        first->prev = NULL;
        first->next = NULL;
        last = first;
    }

    DoublyLinkedList(vector <int> &v){
        first = new node;
        first->data = v[0];
        first->prev = NULL;
        first->next = NULL;
        last = first;
        for(int i=1; i<v.size(); i++){
            push_back(v[i]);
        }
    }

    node* begin(){
        return first;
    }

    node* end(){
        node *p=first;
        while(p->next) p=p->next;
        last = p;
        return last;
    }

    void push_front(int x){
        node *temp;
        temp = new node;
        temp->data = x;
        temp->prev = NULL;
        temp->next = first;
        first->prev = temp;
        first = temp;
    }

    void push_back(int x){
        node *temp;
        temp = new node;
        temp->data = x;
        temp->prev = last;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    void reverse(){
        node *a, *b, *c;
        a=NULL;
        b=NULL;
        c=first;
        while(c){
            a = b;
            b = c;
            c = c->next;
            b->prev = c;
            b->next = a;
        }
        first=b;
        end();
    }

    void insert(int position, int x){
        node *temp, *p;
        p=first;
        if(position){
            for(int i=1; ((p->next) && (i<position)) ; i++){
                p=p->next;
            }
            if(p->next){
                temp = new node;
                temp->data = x;
                temp->next = p->next;
                temp->prev = p;
                p->next->prev = temp;
                p->next=temp;
                end();
            }
            else
                push_back(x);
        }
        else
            push_front(x);
    }

    int pop(int position){
        node *p;
        int x;
        p=first;
        if(position){
            for(int i=1; (i<=position && p->next); i++){
                p=p->next;
            }
            if(p->next){
                p->prev->next = p->next;
                p->next->prev = p->prev;
                x=p->data; 
                delete p;
                return x;
            }
            else{
                return pop_back();
            }
        }
        else{
            x=p->data;
            p=p->next;
            delete p->prev;
            p->prev = NULL;
            first = p;
            return x;
        }

    }

    int pop_back(){
        end();
        int x;
        x = last->data;
        last = last->prev;
        delete last->next;
        last->next = NULL;
        return x;
    }

    void display(){
        node *p;
        p = first;
        cout<<p->data;
        p=p->next;
        while(p){
            cout<<"<->"<<p->data;
            p=p->next;
        }
    }
    
};

int main(int argc, char const *argv[])
{
    system("cls");
    vector<int> v={1,4,2,7,3,5};
    DoublyLinkedList D(v);
    // D.push_back(2);
    // D.push_back(4);
    // D.push_back(7);
    // D.push_front(9);
    D.pop(10);
    D.display();
    return 0;
}

