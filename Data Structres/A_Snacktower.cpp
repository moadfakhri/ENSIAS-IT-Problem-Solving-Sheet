#include <iostream>
#include <queue>
using namespace std;
 
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n; cin>>n;
    int a[n];
    for (int i=0 ; i< n;i++) cin>>a[i];
    priority_queue<int> q;
    int target=n;
    for (int i=0 ; i<n; i++){
        q.push(a[i]);
        if (a[i]!=target){
            cout<<'\n';
        }
        else {
            while (target == q.top()){
                cout<<q.top()<<' ';
                q.pop();
                target--;
            }
            cout<<'\n';
        }
    }
    return 0;
}