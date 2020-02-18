#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N= 2e5+10;
int t[2*N];
int n,q;

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

void push() {
  for (int i = 1; i < n; ++i) {
    t[i<<1] += t[i];
    t[i<<1|1] += t[i];
    t[i] = 0;
  }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>q;
    int arr[n+1];
    for (int i=1; i<=n; i++) cin>>arr[i];
    for (int i=0; i<n; i++) t[i+n]=0;
    for (int i =0; i<q; i++){
        int l,r; cin>>l>>r; l--;
        modify(l,r,1);
    }
    push();
    sort(t+n,t+2*n);
    sort(arr+1,arr+n+1);
    long long ans=0;
    for (int i=0; i<n; i++){
        ans += t[i+n]*1ll*arr[i+1];
    }
    cout<<ans;
    return 0;
}