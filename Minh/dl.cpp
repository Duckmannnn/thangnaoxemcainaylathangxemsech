#include <bits/stdc++.h>

#define int long long
using namespace std;
    
int test_case,n;
string s;

void solve() {
    //read
    cin >> n >> s;
    int mmax=0,mmin=0,c=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='>') c++;
        else c--;
        mmax=max(mmax,c);
        mmin=min(mmin,c);
    }
    cout<<mmax-mmin+1;
    //solve
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> test_case;
    while(test_case--) {
        solve();
        cout << '\n';
    }
}