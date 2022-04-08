#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

class Array {
public :
    int *vec;
    int length;
    int capacity;


    Array(int *A, int length, int size){
        this->length = length;
        this->capacity = size;
        this->vec=new int[size];
        this->vec = A;
        if(A==NULL){
            cout<<"Allocation unsuccessfull.";
        } 
    }
    
    Array(int size){
        capacity = size;
        vec = new int[capacity];
        length=0;
    }

    void increase_size(){

    }

    void display(){
        for(int i=0; i<this->length; i++)
            cout<<this->vec[i]<<" ";
    }

    int len(){
        return length;
    }

    int size(){
        return capacity;
    }

    int get(int index){
        return vec[index];
    }

    void set(int index, int x){
        vec[index]=x;
    }

    int pop(int index){
        int temp = vec[index];
        for(int i=index; i<length-1; i++)
            vec[i]=vec[i+1];
        
        return temp;   
    }

    int pop(){
        int temp = vec[length-1];
        length--;
        return temp;
    }

    void append(int x){
        vec[length]=x;
        length++;
    }

    void insert(int index, int x){
        for(int i=length; i>index; i--)
            vec[i]=vec[i-1];
    
        vec[index]=x;
        length++;
    }

    int linSearch(int key){
        for(int i=0; i<length; i++){
            if(vec[i]==key){
                return key;
            }
        }
        return -1;
    }

    int binSearch(int key, int l, int r){
        
        int mid = (l+r)/2;
        if(l<=r){
            if(vec[mid]==key)
                return mid;
            else if(vec[mid]<key)
                binSearch(key, mid+1, r);
            else if(vec[mid]>key)
                binSearch(key, l, mid-1);
        }
        else
            return -1;
    }


    int linCache(int key){
        int index = linSearch(key);
        swap(vec[index], vec[index-1]);
        return index-1;
    }

    int max(){
        int max=vec[0];
        for(int i=1; i<length; i++)
            if(vec[i]>max)
                max=vec[i];
        
        return max;
    }

    int min(){
        int min=vec[0];
        for(int i=1; i<length; i++)
            if(vec[i]<min)
                min=vec[i];
        
        return min;
    }

    int sum(){
        int temp=0;
        for(int i=0; i<length; i++){
            temp+=vec[i];
        }
        return temp;
    }

    void bSort(){
        for(int i=0; i<length-1; i++)
            for(int j=0; j<length-i-1; j++)
                if(vec[j]>vec[j+1])
                    swap(vec[j], vec[j+1]);
    }

    int isSorted(){
        for(int i=0; i<length-1; i++)
            if(vec[i]>vec[i+1])
                return 0;
        
        return 1;
    }


    void reverse(){
        for(int i=0, j=length-1; i<j; i++, j--){
            swap(vec[i], vec[j]);
        }
    }

    // Set Operations, using this will sort arrays in place.
        // merge
        // setUnion
        // setIntersect
        // setDifference

    Array merge(Array B){
        this->bSort();
        B.bSort();
        int *temp;
        temp = new int[B.length + this->length];
        int i=0, j=0, k=0;
        while(i < this->length && j<B.length){
            if(this->vec[i]<B.vec[j]){
                temp[k++]=this->vec[i++];
            }
            else{
                temp[k++]=B.vec[j++];
            }
        }

        for(;i<this->length; i++){
            temp[k++]=this->vec[i];
        }
        
        for(;j<this->length; j++){
            temp[k++]=B.vec[i];
        }

        Array to_return(temp, k, k);
        return to_return;
    }
    
    Array setUnion(Array B){
        this->bSort();
        B.bSort();
        int *temp = new int[this->length + B.length];
        int i=0,j=0,k=0;
        while(i<length && j<B.length){
            if(this->vec[i]<B.vec[j]){
                temp[k++]=this->vec[i++];
            }
            else if(this->vec[i]>B.vec[j]){
                temp[k++]=B.vec[j++];
            }
            else{
                temp[k++]=this->vec[i++];
                j++;
            }
        }

        for(;i<this->length; i++){
            temp[k++]=this->vec[i];
        }
        
        for(;j<this->length; j++){
            temp[k++]=B.vec[i];
        }

        Array to_return(temp, k, k);
        return to_return;
    }

    // Array setIntersect(Array B){

    // }

    // Array setDifference(Array B){

    // }

    ~Array(){
        delete []vec;
    }

};


int main(int argc, char const *argv[])
{   
    system("CLS");
    int a[10] = {78,43,68,98,24,56,79,21,12,13};
    Array V(a, 10, 10);
    V.bSort();
    V.display();
    cout<<endl;
    cout<<V.binSearch(98, 0, V.length-1);
}
