#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 10000007
#include <bits/stdc++.h>
using namespace std;

/*
    ax + by = c
    Given a, b, c, minx, maxx, miny, maxy.
    Find no of solution in the given range

    For all solution:
    If (SolCount != 0) ,save lx and rx
    Iterate through x = lx + k(b/g);
    for all k >= 0 until x = rx;
    for each x, find y from:
    ax + by = c
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

void shift_solution(int &x, int &y, int a, int b, int cnt){
    x += cnt * b;
    y -= cnt * a;
}



int find_all_solution(int a, int b, int c, int minx, int maxx, int miny, int maxy){
    int x, y, g;
    if(!find_any_solution(a, b, c, x, y, g)){
        return 0;
    }
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx-x) / b);
    if(x < minx){
        shift_solution(x, y, a, b, sign_b);
    }
    if(x > maxx){
        return 0;
    }
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx-x) / b);
    if(x > maxx){
        shift_solution(x, y, a, b, -sign_b);
    }
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if(y < miny){
        shift_solution(x, y, a, b, -sign_a);
    }
    if(y > maxy){
        return 0;
    }
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy-y)/a);
    if(y > maxy){
        shift_solution(x, y, a, b, sign_a);
    }

    int rx2 = x;

    if(lx2 > rx2){
        swap(lx2, rx2);
    }
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if(lx > rx){
        return 0;
    }
    return (rx - lx) / abs(b) + 1;
}


int main() {

    return 0;
}
