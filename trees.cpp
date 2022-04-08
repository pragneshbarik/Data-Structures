#include<iostream>
#include<queue>
#include<stack>
#include<string>

using namespace std;


class Tree {

public :
    struct Node
    {
        Node *left;
        int data;
        Node *right;
    };

    Node *root;
    Tree(){
        root = new Node;
        root->data = 0;
        root->left = NULL;
        root->right = NULL;
    }

    Tree(int x){
        root = new Node;
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    }

    void create(){
        queue<Node*> address_q;
        Node* temp, *first;
        string x;
        //cout<<"Enter data for Root : ";
        cin>>x;
        root->data = stoi(x);
        address_q.push(root);
        while (x!="END"){   
            first = address_q.front();
            address_q.pop();
            //cout<<"Enter data for Left child of "<<first->data<<" : ";
            cin>>x;
            if(x=="END") break;
            if(x!="NULL"){
                temp = new Node;
                temp->data = stoi(x);
                temp->left = NULL;
                temp->right = NULL;
                first->left = temp;
                address_q.push(temp);
            }
            //cout<<"Enter data for Right child of "<<first->data<<" : ";
            cin>>x;
            if(x=="END") break;
            if(x!="NULL"){
                temp = new Node;
                temp->data = stoi(x);
                temp->left = NULL;
                temp->right = NULL;
                first->right = temp;
                address_q.push(temp);
            }

        }
        cout<<endl<<endl;
    }

    void printBT(const string& prefix, const Node* node, bool isLeft){
        if(node!=NULL){
            cout << prefix;
            cout << (isLeft ? "├── " : "└── " );
            cout << node->data << std::endl;
            printBT( prefix + (isLeft ? "├   " : "    "), node->left, true);
            printBT( prefix + (isLeft ? "├   " : "    "), node->right, false);
        }
    }

    void pretty_display(){
        printBT("", root, false);    
    }

    void recursive_preorder(Node *p){
        if(p!=NULL){
            cout<<p->data<<" ";
            recursive_preorder(p->left);
            recursive_preorder(p->right);
        }
    }

    void iterative_preorder(){
        Node* p=root;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            p = stk.top();
            cout<<p->data<<" ";
            stk.pop();
            if(p->right) stk.push(p->right);
            if(p->left) stk.push(p->left);
        }
    }

    void iterative_preorder(int x){
        Node *p = root;
        stack<Node *> stk;
        while(p!=NULL || !stk.empty()){
            if(p){
                cout<<p->data<<" ";
                stk.push(p);
                p=p->left;
            }
            else{
                p=stk.top();
                stk.pop();
                p=p->right;
            }
        }
    }

    void iterative_inorder(){
        Node *p = root;
        stack<Node*> stk;
        while(p!=NULL || !stk.empty()){
            if(p){
                stk.push(p);
                p=p->left;
            }
            else{
                p=stk.top();
                stk.pop();
                cout<<p->data<<" ";
                p=p->right;
            }
        }
    }

    void iterative_levelorder(){
        Node *p = root;
        queue<Node*> q;
        cout<<p->data<<" ";
        q.push(p);
        while(!q.empty()){
            p=q.front();
            q.pop();
            if(p->left){
                cout<<p->left->data<<" ";
                q.push(p->left);
            }
            if(p->right){
                cout<<p->right->data<<" ";
                q.push(p->right);
            }
        }
    }

};
// pass the root node of your binary tree

int main()
{
    Tree T;
    T.create();
    //T.pretty_display();
    T.iterative_preorder(1);
    cout<<'\n';
    T.iterative_levelorder();
    return 0;
}
