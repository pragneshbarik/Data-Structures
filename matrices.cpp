#include<iostream>
#include<stdlib.h>

using namespace std;
/*
template <typename T>
class Diagonal{
public :
    T *elements;
    int order;

    Diagonal(int size){
        this->order = size;
        elements = new T[size];
    }

    Diagonal(T A[], int size){
        this->order = size;
        elements = new T[size];
        for(int i=0; i<this->order; i++)
            elements[i]=A[i];
    }

    void display(){
        for(int i=0; i<this->order; i++){
            for(int j=0; j<this->order; j++){
                if(i==j)
                    cout<<elements[i]<<" ";
                else
                    cout<<"0 ";

            }
            cout<<endl;
        }
    }
};

template <typename T>
class LowerTriangle{
public :
    T* elements;
    T** elements_2d;
    int order;
    int size;
    
    LowerTriangle(T **A, int order){
        this->order = order;
        this->size = (order*(order+1))/2;
        elements = new T[size];
        elements_2d = new T*[order];
        for(int i=0; i<order; i++)
            elements_2d[i]=new T[order];
        elements_2d = new T[order];
        for(int i=0; i<this->order; i++){
            for(int j=0; j<this->order; j++){
                if(i>=j)
                    elements_2d[i][j]=A[i][j];
                    elements[(i*(i+1))/2 + j] = A[i][j];
                else
                    elements_2d[i][j]=0;
            }
        }
    


    }

    void display(){
        for(int i=0; i<order; i++){
            for(int j=0; j<order; j++){
                cout<<elements_2d[i][j]<<" ";
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    system("cls");
    int **A;
    A = new int*[5];
    for(int i=0; i<5; i++){
        A[i] = new int[5];
    }

    LowerTriangle<int> D(A, 5);
    D.display();
}
*/
class Element{
public :    
    int i;
    int j;
    int x;
};


class Sparse{
public :    
    int m;
    int n;
    int num;
    Element *E;
    
    Sparse(int x, int y, int number){
        m=x;
        n=y;
        num=number;
        E=new Element[num];
    }

    void read(){
        for(int k=0; k<num; k++)
            cin>>E[k].i>>E[k].j>>E[k].x;
    }
    void display(){
        int k=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(E[k].i==i && E[k].j==j)
                    cout<<E[k++].x<<" ";
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }
    }
};


int main(int argc, char const *argv[])
{
    system("cls");
    Sparse S(8,9,8);
    S.read();
    S.display();

    return 0;
}
