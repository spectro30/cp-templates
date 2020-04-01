#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 100005
#define mod 998244353
#include <bits/stdc++.h>
using namespace std;

const ll inf = 1e15;
typedef pair<ll, int> pii;
int n, m;
vector<pii> edge[maxn];
ll d[maxn], p[maxn];


void dijkstra(int root){
    for(int i=2;i<=n;i++) d[i] = inf;

    priority_queue <pii, vector<pii>, greater<pii> > pq;
    pq.push({0, root});
    while(!pq.empty()){
        int node = pq.top().ss;
        pq.pop();
        for(auto x: edge[node]){
            int to = x.ff;
            int w = x.ss;
            if(d[to] > d[node] + w){
                d[to] = d[node] + w;
                pq.push({d[to], to});
                p[to] = node;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x, y, w;
        cin >> x >> y >> w;
        edge[x].pb({y, w});
        edge[y].pb({x, w});
    }
    dijkstra(1);


    return 0;
}
