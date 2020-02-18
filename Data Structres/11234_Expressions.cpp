#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct tree tree;

struct tree{
    char val;
    tree* left;
    tree* right;
};


int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t; cin>>t;
    while (t--){
        string s; cin>>s;
        stack<tree*> v;
        for (char c : s){
            tree* n = new tree;
            n->val = c;
            if ('a'<=c && c<='z') {
                n->left=NULL;
                n->right = NULL;
            }
            else {
                n->left=v.top(); v.pop();
                n->right=v.top(); v.pop();
            }
            v.push(n);
        }
        tree t = *v.top();v.pop();
        vector<char> ans;
        queue<tree> q;
        q.push(t);
        while (!q.empty()){
            tree t=q.front(); q.pop();
            ans.push_back(t.val);
            if (t.left!=NULL){
                q.push(*t.right);
                q.push(*t.left);
            }
        }
        reverse(ans.begin(),ans.end());
        for (char c : ans) cout<<c;cout<<'\n';
    }
    return 0;
}
