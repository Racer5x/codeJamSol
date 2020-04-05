/*
Author: Racer5x
 ***************************************   UNAUTHORISED COPYING OF CODE PROHIBITED   **********************************
*/
 
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include<bits/stdc++.h>
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
 
signed main()
{
    tezz
    
    int t;
    cin>>t;

    for(int tt=1;tt<=t;tt++){
        int n;
        cin>>n;

        int mat[n+1][n+1];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>mat[i][j];

        int k = 0, r = 0, c = 0;
        for(int i=0;i<n;i++) k += mat[i][i];

        for(int i=0;i<n;i++){
            set<int> s;
            for(int j=0;j<n;j++) s.insert(mat[i][j]);

            if(s.size() < n) r++;
        }

        for(int i=0;i<n;i++){
            set<int> s;
            for(int j=0;j<n;j++) s.insert(mat[j][i]);

            if(s.size() < n) c++;
        }

        cout<<"Case #"<<tt<<": "<<k<<' '<<r<<' '<<c<<endl;
    }
} 