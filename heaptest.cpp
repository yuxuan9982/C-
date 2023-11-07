#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
void adjustdown(int idx){
    int son=idx*2+1;
    while(son<n){
        if(son+1<n&&a[son+1]>a[son])son++;
        if(a[son]>a[idx]){
            swap(a[son],a[idx]);
            idx=son;son=idx*2+1;
        }else{
            break;
        }
    }
}
void adjustup(int idx){
    while(idx>0){
        int fa=(idx-1)/2;
        if(a[fa]<a[idx]){
            swap(a[fa],a[idx]);
            idx=fa;
        }else break;
    }
}
void solve(){
    a={7,8,1,5,3,2,4,9};
    n=a.size();
    for(int i=n/2-1;i>=0;i--)adjustdown(i);
    for(int i=0;i<n;i++)cout<<a[i]<<" \n"[i==n-1];
    a.push_back(11);
    adjustup(a.size()-1);
    cout<<a[0]<<endl;
}
signed main(){
    solve();
    system("pause");
}