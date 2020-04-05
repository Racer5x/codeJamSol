/*
Author: Racer5x
 ***************************************   UNAUTHORISED COPYING OF CODE PROHIBITED   **********************************
*/
 
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int         long long
#define double      long double
#define pb          emplace_back
#define pf          emplace_front
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define x           first
#define y           second
#define endl        '\n'
#define hell        998244353 
#define PI          3.141592653589
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX         2000000000000000000
#define M           1000000007
using namespace std;

int sqr[60][60], n, k, t;
bool row_safe[60][60], col_safe[60][60], solved;

void solve(int row, int col, int m) {
    if (row == n && col == n + 1 && m == k && !solved) {
        solved = true;
        
        cout<<"Case #"<<t<<": "<<"POSSIBLE"<<endl;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout<<sqr[i][j]<<' ';
            }
            cout<<endl;
        }
        return;
    } 
    else if(row > n) return;
    else if (col > n) solve(row + 1, 1, m);

    for (int i = 1; i <= n && !solved; ++i) {
        if (!row_safe[row][i] && !col_safe[col][i]) {
            row_safe[row][i] = col_safe[col][i] = true;

            if (row == col) {
                m += i;
            }
            sqr[row][col] = i;
            
            solve(row, col + 1, m);

            row_safe[row][i] = col_safe[col][i] = false;
            
            if (row == col) {
                m -= i;
            }
            sqr[row][col] = 0;
        }
    }
}

signed main() {
    int tt;
    cin>>tt;
    
    for (t = 1; t <= tt; ++t) {
        
        cin>>n>>k;
        solve(1, 1, 0);
        
        if (!solved) cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl;

        solved = false;
    }
}