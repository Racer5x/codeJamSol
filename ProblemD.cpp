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
// #define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX         2000000000000000000
#define M           1000000007
using namespace std;
 
signed main()
{
    int t, b;
    cin>>t>>b;

    while(t--){
        string s = "";
        for(int i=0;i<b;i++) s+='@';

        for(int i=0;i<5;i++){
            cout<<i + 1<<endl;
            int val;
            cin>>val;

            s[i] = val + '0';
        }

        for(int i=b-5;i<b;i++){
            cout<<i + 1<<endl;
            int val;
            cin>>val;

            s[i] = val + '0';
        }

        pii same = {0, 0}, change = {0, 0};
        for(int i=0;i<5;i++){
            int end = b - i - 1;

            if(s[i] != s[end] && (change.x + change.y == 0)) change = {i, end};
            else if(s[i] == s[end] && (same.x + same.y == 0)) same = {i, end};
        }

        int curr = 4, end = b - 6;

        int query = 11;

        // cout<<s<<endl;

        // cout<<change.x<<' '<<change.y<<" --> "<<endl;
        // cout<<same.x<<' '<<same.y<<" --> "<<endl;

        while(curr + 1 < end){
            if(query % 10 == 1){ // when the system bahaves disrespectfully
                if((change.x + change.y) && (same.x + same.y)){
                    pii diff, eq;

                    cout<<change.x + 1<<endl;
                    cin>>diff.x;

                    cout<<same.x + 1<<endl;
                    cin>>eq.x;

                    query += 2;

                    // cout<<" ==> "<<diff.x<<' '<<diff.y<<endl;
                    // cout<<" ==> "<<eq.x<<' '<<eq.y<<endl;
                    // cout<<endl;

                    //then 4 conditions
                    //if it is a negation
                    if(s[change.x] != diff.x + '0' && s[same.x] != eq.x + '0'){
                        // cout<<'f';
                        for(int i=0;i<=curr;i++) s[i] = ((s[i] - '0')^1) + '0';
                        for(int i=end;i<b;i++) s[i] = ((s[i] - '0')^1) + '0';
                    } //if it is a reversal
                    else if(s[change.x] != diff.x + '0' && s[same.x] == eq.x + '0'){
                        // cout<<'t';
                        for(int i=0;i<=curr;i++) swap(s[i], s[b - i - 1]);
                    } //if it is both
                    else if(s[change.x] == diff.x + '0' && s[same.x] != eq.x + '0'){
                        for(int i=0;i<=curr;i++) s[i] = ((s[i] - '0')^1) + '0';
                        for(int i=end;i<b;i++) s[i] = ((s[i] - '0')^1) + '0';

                        for(int i=0;i<=curr;i++) swap(s[i], s[b - i - 1]);
                    }
                } //only diff one remain
                else if(change.x + change.y){
                    pii diff;

                    cout<<change.x + 1<<endl;
                    cin>>diff.x;
                    cout<<change.y + 1<<endl;
                    cin>>diff.y;

                    query += 2;

                    // if there is a reversal or a negation
                    if(s[change.x] != diff.x + '0'){
                        for(int i=0;i<=curr;i++) swap(s[i], s[b - i - 1]);
                    } // if there is both or nothing, do nothing :P
                }
                else{ //onlu same one remains
                    pii eq;

                    cout<<same.x + 1<<endl;
                    cin>>eq.x;
                    cout<<same.y + 1<<endl;
                    cin>>eq.y;

                    query += 2;

                    //if there is a negation or both
                    if(s[change.x] != eq.x + '0'){
                        for(int i=0;i<=curr;i++) s[i] = ((s[i] - '0')^1) + '0';
                        for(int i=end;i<b;i++) s[i] = ((s[i] - '0')^1) + '0';
                    }
                }
            }
                
            curr++;

            while(curr < end && query % 10 != 1){
                cout<<curr + 1<<endl;
                int val;
                cin>>val;

                s[curr] = val + '0';

                cout<<end + 1<<endl;
                cin>>val;

                s[end] = val + '0';

                if(s[curr] != s[end] && (change.x + change.y == 0)) change = {curr, end};
                else if(s[curr] == s[end] && (same.x + same.y == 0)) same = {curr, end};

                query += 2;

                curr++;
                end--;
            }

            curr--;

            // cout<<s<<endl;
        }

        cout<<s<<endl;

        char verdict;
        cin>>verdict;

        if(verdict == 'N'){
            cout<<"!WRONG"<<endl;
            return 0;
        }
    }
} 