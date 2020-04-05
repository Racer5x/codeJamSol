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
        string s;
        cin>>s;

        int n = s.length();

        vi v(n);
        for(int i=0;i<n;i++) v[i] = s[i] - '0';

        vii pos(n);

        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                int mn = MAX;
                for(int k=i;k<=j;k++) mn = min(mn, v[k]);

                if(mn == 0) continue;

                pos[i].x += mn;
                pos[j].y += mn;

                for(int k=i;k<=j;k++) v[k] -= mn;
            }
        }

        cout<<"Case #"<<tt<<": ";
        for(int i=0;i<n;i++){
            for(int j=0;j<pos[i].x;j++) cout<<'(';
            cout<<s[i];
            for(int j=0;j<pos[i].y;j++) cout<<')';
        }
        cout<<endl;
    }
} 