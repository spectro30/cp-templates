#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 10000007
#include <bits/stdc++.h>
using namespace std;


ll read_int(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg)
        return ret;
    else
        return -ret;
}

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

void shift_solution(ll &x, ll &y, ll a, ll b, ll cnt){
    x += cnt * b;
    y -= cnt * a;
}



ll find_all_solution(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy){
    ll x, y, g;
    if(!find_any_solution(a, b, c, x, y, g)){
        return 0;
    }
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx-x) / b);
    if(x < minx){
        shift_solution(x, y, a, b, sign_b);
    }
    if(x > maxx){
        return 0;
    }
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx-x) / b);
    if(x > maxx){
        shift_solution(x, y, a, b, -sign_b);
    }
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if(y < miny){
        shift_solution(x, y, a, b, -sign_a);
    }
    if(y > maxy){
        return 0;
    }
    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy-y)/a);
    if(y > maxy){
        shift_solution(x, y, a, b, sign_a);
    }

    ll rx2 = x;

    if(lx2 > rx2){
        swap(lx2, rx2);
    }
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if(lx > rx){
        return 0;
    }
    return (rx - lx) / abs(b) + 1;
}

int main() {
    //freopen("0uput.txt","w",stdout);

    ll TC = read_int();
    for(int ii=1;ii<=TC;ii++){
        ll A, B, C, x1, x2, y1, y2;
        ll res;
        A = read_int();
        B = read_int();
        C = read_int();
        x1 = read_int();
        x2 = read_int();
        y1 = read_int();
        y2 = read_int();
        C = -C;
        if(!A && !B){
            if(!C){
                res = (x2-x1+1) * (y2-y1+1);
            }
            else{
                res = 0;
            }
        }
        else if(!A){
            ll y = C / B;
            if(C%B == 0 && y>=y1 && y <=y2){
                res = x2 - x1 + 1;
            }
            else{
                res = 0;
            }
        }
        else if(!B){
            ll x = C / A;
            if(C%A == 0 && x>=x1 && x<=x2){
                res = y2 - y1 + 1;
            }
            else{
                res = 0;
            }
        }
        else{
            res = find_all_solution(A, B, C, x1, x2, y1, y2);
        }
        printf("Case %d: %lld\n", ii, res);
    }
    return 0;
}
