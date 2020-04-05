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
        cout<<"Case #"<<tt<<": ";

        // vii dp(24*60 + 5);

        int n;
        cin>>n;

        vector<pair<pii, int>> work;
        for(int i=0;i<n;i++){
            int s, e;
            cin>>s>>e;

            work.push_back({{s, e}, i});

            // dp[s].x++;
            // dp[e].y++;
        }

        // int mx = 0, count = 0;

        // for(int i=0;i<=24*60;i++){
        //     if(dp[i].x){
        //         count++;
        //     }
        //     else{
        //         mx = max(mx, count);
        //         count = 0;
        //     }
        // }

        // if(mx > 2){
        //     cout<<"IMPOSSIBLE"<<endl;
        //     continue;
        // }
        string s = "";
        for(int i=0;i<n;i++) s += '@';

        vii kaam;

        for(auto it:work){
            kaam.pb(it.x.x, (it.y + 1));
            kaam.pb(it.x.y, -(it.y + 1));
        }

        sort(all(kaam));
        bool c = true, j = true;

        // for(auto it:kaam) cout<<it.x<<" -> "<<it.y<<endl;
        bool flag = true;

        for(auto it:kaam){
            // cout<<it.x<<" -> "<<it.y<<endl;
            if(it.y > 0){
                int index = it.y;
                if(c){
                    s[index - 1] = 'C';
                    c = false;
                    // cout<<"C = "<<index<<endl;
                }
                else if(j){
                    s[index - 1] = 'J';
                    j = false;
                    // cout<<"J = "<<index<<endl;
                }
                else{
                    flag = false; 
                    break;
                }
            }
            else{
                int index = -it.y;
                if(s[index - 1] == 'C'){
                    c = true;
                    // cout<<"END = C"<<endl;
                }
                else if(s[index - 1] == 'J'){
                    j = true;
                    // cout<<"END = J"<<endl;
                }
                else{
                    flag = false;
                    break;
                }
            }
        }

        if(flag) cout<<s<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
} 