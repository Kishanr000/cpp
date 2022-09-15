// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    string arr ;
    cin>> arr;
    int i =0;
    string ans ="";
    while(i<arr.length()){
        if(arr[i] == ';')
            ans = arr[i+1];
    }
    cout<<ans<<endl;;

    return 0;
}