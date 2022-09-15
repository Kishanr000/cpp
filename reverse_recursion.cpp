#include<bits/stdc++.h>
using namespace std;

void reverse(string &s, int start, int size){
    if(start > size)
        return ;
    swap(s[start],s[size]);
    start++; size--;
    reverse(s,start,size);
    
}

int main(){
    string str = "Kishan";
    reverse(str,0,str.length() - 1);
    cout<< "Reverse string is " << str ;
}