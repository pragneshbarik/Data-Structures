#include<iostream>
#include <bits/stdc++.h>
#include<stack>
#include<queue>
#include<vector>

using namespace std;
class BST
{
private:
    class node
    {
    public:
        node *left;
        int data;
        node *right;

        node(){
            this->left = nullptr;
            data = 0;
            this->right = nullptr;
        };

        node(int x){
            this->left = nullptr;
            this->data = x;
            this->right = nullptr;
        };
    };
   

public:
    node *root = NULL;
// Standard Functions of Binary Search
    void insert(int key){
        if (root == NULL){
            root = new node(key);
            return;
        }
        node *p = root;
        node *q, *temp;
        while (p){
            q = p;
            if (key>p->data) p=p->right;
            else if(key<p->data)p=p->left;
            else return;
        }

        temp = new node(key);

        if (key > q->data) q->right = temp;
        else q->left = temp;
    }

    void insert(vector<int> v){
        for(int i=0; i<v.size(); i++){
            this->insert(v[i]);
        }
    }

    void recursive_preorder(node* p){
        if(p){
        cout<<p->data<<" ";
        recursive_preorder(p->left);
        recursive_preorder(p->right);
        }
    }

    void recursive_inorder(node *p){
        if(p){
        recursive_inorder(p->left);
        cout<<p->data<<" ";
        recursive_preorder(p->right);
        }
    }

    void iterative_preorder(){
        stack <node*> stk;
        node* temp=root;
        stk.push(root);
        while(!(temp==NULL && stk.empty())){
            if(temp){
                cout<<temp->data<<" ";
                if(temp->left) 
                stk.push(temp=temp->left);
                else temp=temp->left;
            }
            else{
                temp = stk.top();
                stk.pop();
                if(temp->right) stk.push(temp=temp->right);
                else temp=temp->right;
            }
        }

    }

    int height(node *p){
        if(p==NULL) return 0;
        int L = 1+height(p->left);
        int R = 1+height(p->right);
        return max(L, R);
    }

    void printBT(const string& prefix, const node* node, bool isLeft){
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

    node* recursive_insert(node* p, int key){
        if(p==NULL) return new node(key);
        
        if(key>p->data){
            p->right = recursive_insert(p->right, key);
        }
        else if(key<p->data){
            p->left = recursive_insert(p->left, key);
        }
        return p;
    }

    void recursive_insert(int key){
        if(root==NULL) root = new node(key);
        else recursive_insert(root, key);
    }

    node* recursive_search(node* p, int key){
        if(p->data==key) return p;
        if(key>p->data)
            return recursive_search(p->right, key);
        
        else if (key<p->data)
            return recursive_search(p->left, key);
        
        return 0;
    }

    void levelorder(){
        queue<node *> q;
        node *p;
        q.push(root);
        while (!q.empty()){
            p = q.front();
            cout << p->data << " ";
            q.pop();
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }

    vector<vector<int>> level_view(){
        queue<node*> q;
        node* p=root;
        vector<vector<int>> table;
        vector<int> rows;
        q.push(root);
        q.push(NULL);
        while(q.size()!=1){
            p = q.front();
            q.pop();
            if(p){
                rows.push_back(p->data);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            else{
                table.push_back(rows);
                q.push(NULL);
                rows.clear();
            }
        }
        table.push_back(rows);
        return table;
    }


    vector<int> left_view(){
        queue<node*> q;
        node* p;
        vector<int> sol;
        int k=0;
        q.push(root);
        q.push(NULL);
        while(q.size()!=1){
            p = q.front();
            q.pop();
            if(p){
                if(k==0){
                    sol.push_back(p->data);
                    k=1;
                }
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            else{
                q.push(NULL);
                cout<<endl;
                k=0;
            }
        }
        return sol;
    }

    vector<int> right_view(){
       queue<node*> q;
       node* p;
       vector<int> sol;
       q.push(root);
       q.push(NULL);
       while(q.size()>1){
           p=q.front();
           q.pop();
           if(p){
               if(!q.front()) sol.push_back(p->data);
               if(p->left) q.push(p->left);
               if(p->right) q.push(p->right);
           }
           else{
               q.push(NULL);
           }
       }
       return sol;
    }
    


};

int main(int argc, char const *argv[])
{
    BST t;
    vector<int> v = {23, 12, 54, 67, 24, 18 , 34, 67, 87, 98, 55, 23};
    vector<vector<int>> levels;
    t.insert(v);
    cout<<"Tree View : \n";
    t.pretty_display();
    
    levels = t.level_view();
    cout<<"Level View : \n";
    for(auto level:levels){
        for(auto x: level){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Left View : \n";
    for(auto level : levels){
        cout<<level[0]<<endl;
    }
    cout<<endl;
    cout<<"Right View : \n";
    for(auto level : levels){
        cout<<level[level.size()-1]<<endl;
    }
    cout<<endl;
    cout<<"ZigZag View : \n";
    for(int i=0; i<levels.size(); i++){
        if(i%2){
            reverse(levels[i].begin(), levels[i].end());
        }
    }
    for(auto level:levels){
        for(auto x: level){
            cout<<x<<" ";
        }
        cout<<endl;
    }


}
