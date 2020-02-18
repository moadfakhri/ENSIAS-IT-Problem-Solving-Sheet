#include <iostream>
using namespace std;

int bs(int i, int j,int x,int arr[]){
    if (x<arr[i] ) return -1;
    if (arr[j]<x) return j+1;
    while (i<j){
        int m = (i+j)>>1;
        if (arr[m] < x) i=m+1;
        else j=m;
    }
    return j;
}
//8 5 3 50 45 .. 10
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n; cin>>n;
    int arr[n];
    for (int i=0; i <n; i++) cin>>arr[i];
    int m[n];
    m[n-1]=arr[n-1];
    for (int i=n-2; i>=0; i--) m[i]=min(m[i+1],arr[i]);
    for (int i=0; i<n-1; i++){
        int k = bs(i+1,n-1,arr[i],m);
        //cout<<k <<' ';
        if (k==-1) cout<<"-1 ";
        else cout<<k-i-2<<' ';
    }
    cout<<-1;
    return 0;
}

