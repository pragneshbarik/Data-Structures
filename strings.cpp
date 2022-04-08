#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

void permuter(string str, int l, int h){
    if(l==h)
        cout<<str<<endl;
    else{
        for(int i=l; i<=h; i++){
            swap(str[l], str[i]);
            permuter(str, l+1, h);
            swap(str[l], str[i]);
        }
    }
}

void permute(string str){
    permuter(str, 0, str.length()-1);
}

int count_words(string s){
    int words = 0;
    for(int i = 0; s[i]!='\0'; i++){
        if(s[i]==' ' && s[i+1]!=' ' && s[i+1]!='\0'){
            words++;
        }
    }
    return words+1;
}

void count_duplicates(string s){
    int x = 1, H = 0;
    for(int i = 0; s[i]!='\0'; i++, x=1){
        x = x<<s[i]-97;
        if((x&H)>0)
            cout<<s[i]<<" is duplicate"<<endl;
        else    
            H = x|H;
    }
}

int bithash(string s){
    int x = 1, H = 0;
    for(int i=0; s[i]!='\0'; i++, x=1){
        x = x<<s[i]-97;
        H = x|H;
    }
    return H;
}

int if_anagram(string s1, string s2){
    if(bithash(s1)==bithash(s2))
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    system("CLS");
    permute("boat");
}
