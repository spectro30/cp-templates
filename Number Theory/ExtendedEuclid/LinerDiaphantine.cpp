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

int ExEuclid(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = ExEuclid(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g){
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

    return 0;
}
