#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,
less<int>,rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define maxn 100005
#define Left (node*2)
#define Right (node*2+1)
#define mid ((lo+hi)/2)

int A[maxn];
ordered_set tnode[maxn];

void build(int node, int lo, int hi){
    if(lo==hi){
        tnode[node].insert(A[lo]);
        return;
    }
    build(Left,lo,mid);
    build(Right,mid+1,hi);
    for(auto x: tnode[Left]) tnode[node].insert(x);
    for(auto x: tnode[Right]) tnode[node].insert(x);
}

int query(int node, int lo, int hi, int i, int j, int x){
    if(i>hi || j<lo) return 0;
    if(lo>=i && hi<=j) {
        return tnode[node].order_of_key(x);
    }
    int p1 = query(Left,lo,mid,i,j,x);
    int p2 = query(Right,mid+1,hi,i,j,x);
    return p1+p2;
}

void Remove(int node, int lo, int hi, int i, int x){
    if (i>hi || i<lo) return;
    if(lo==hi){
        tnode[node].erase(tnode[node].find(x));
        return;
    }
    Remove(Left,lo,mid,i,x);
    Remove(Right,mid+1,hi,i,x);
    tnode[node].erase(tnode[node].find(x));
}

void Insert(int node, int lo, int hi, int i, int x){
    if (i>hi || i<lo) return;
    if(lo==hi){
        tnode[node].insert(x);
        return;
    }
    Insert(Left,lo,mid,i,x);
    Insert(Right,mid+1,hi,i,x);
    tnode[node].insert(x);
}
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type){
            int l, r, k;
            cin >> l >> r >> k;
            cout << query(1, 1, n, l, r, k) << endl;
        }
        else{
            int pos, val;
            cin >> pos >> val;
            Remove(1, 1, n, pos, A[pos]);
            Insert(1, 1, n, pos, val);
            A[pos] = val;
        }
    }

    return 0;
}
