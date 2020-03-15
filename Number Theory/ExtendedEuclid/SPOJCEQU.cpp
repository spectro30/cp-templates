#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 10000007
#include <bits/stdc++.h>
using namespace std;

/*
    ax + by = c
    Given a, b, c;
    Find any x, y

*/

ll ExEuclid(ll a, ll b, ll &x, ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = ExEuclid(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){
    g = ExEuclid(abs(a), abs(b), x0, y0);
    if(c % g){
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}

int main() {
    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        ll A, B, C, x, y, g;
        scanf("%lld%lld%lld", &A, &B, &C);
        if(find_any_solution(A, B, C, x, y, g)) printf("Case %d: Yes\n", ii);
        else printf("Case %d: No\n", ii);
        cout << x << " " << y << " " << g << endl;

    }
    return 0;
}
