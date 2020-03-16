#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 300005
#include <bits/stdc++.h>
using namespace std;

vector<int>sum[(4*maxn)];
int A[maxn], prv[maxn], last[1000006];

vector<int> merge(vector<int>m1,vector<int>m2){
    vector<int>temp;
    merge( m1.begin(), m1.end(), m2.begin(), m2.end(), back_inserter( temp ) );
    return temp;
}

void build(int node, int start, int end){
    if(start == end){
        sum[node].pb(prv[start]);
        return ;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = merge(sum[node*2],sum[(node*2)+1]);
}

int query(int node, int start, int end, int i, int j, int k){
    if(start>j || end<i || start>end)return 0;
    if(i<=start && end<=j){
        int idx = lower_bound(sum[node].begin(),sum[node].end(),k) - sum[node].begin();
        return idx;
    }
    int p,q;
    int mid = (start+end) / 2;
    p = query(node*2 ,start, mid, i, j, k);
    q = query((node*2)+1, mid+1, end, i, j, k);
    return p+q;
}


int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);

    int n, q;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    for(int i=1;i<=n;i++){
        prv[i] = last[A[i]];
        last[A[i]] = i;
    }
    build(1, 1, n);
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        auto x =  query(1, 1, n, l, r, l);
        cout << x << endl;
    }
    return 0;
}
