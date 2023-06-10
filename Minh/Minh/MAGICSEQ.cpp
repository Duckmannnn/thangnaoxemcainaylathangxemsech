#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define str string
#define E6 1000001
#define mod 1000000007
using namespace std;
 
ll n,a[E6],le;
str s,dd;
char lee;
map<char,ll>M;
 
void solve(){
    // kiểm tra có bao nhiêu kí tự xuất hiện lẻ lần 
    for(int i=0;i<dd.size();i++){
        if(M[dd[i]]%2!=0){
            lee=dd[i];
            le++;
        }
    }
    // nếu có nhiều hơn 1 kí tự xuất hiện lẻ lần thì xâu đó không đối xứng
    if(le>=2){
        cout<<"NO SOLUTION";
        return;
    }else{
        str sxau="";
        for(int i=0;i<dd.size();i++){
            // nếu kí tự x đó có số lần xuất hiện là chẵn thì in hấn ra 
            if(M[dd[i]]%2==0){
                // in ra M[dd[i]]/2 lần kí tự x  
                for(int j=1;j<=M[dd[i]]/2;j++){
                    sxau.push_back(dd[i]);
                }
            }
        }
        cout<<sxau;
        for(int i=1;i<=M[lee];i++){
            cout<<lee;
        }
        reverse(sxau.begin(),sxau.end());
        cout<<sxau;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s;
    // đếm kí tự khác biệt và nhét vào xâu dd
    for(int i=0;i<s.size();i++){
        M[s[i]]++;
        if(M[s[i]]==1) dd.push_back(s[i]);
    }
    solve();
}