//CSES
//Link to this code: https://cses.fi/paste/2034ae2b979da6be1fe6cb/
// Author: pra101 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[101][MaxN];
int32_t main(){
    fio;//Use "flush" to remove from buffer
    int n,m,data;
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    vi arr;
    for(int i=0;i<n;i++){
		cin>>data;
		data--;
		arr.push_back(data);
	}
	//cout<<arr<<"\n";
    for(int i=0;i<n;i++){
		if(i==0){
			if(arr[i]==-1){
				for(int j=0;j<m;j++)dp[j][0]=1;
			}
			else {
				dp[arr[i]][0]=1;
			}
		}
		else {
			if(arr[i]==-1){
				for(int k=0;k<m;k++){
					if(k>0)dp[k][i]=add(dp[k][i],dp[k-1][i-1]);
					dp[k][i]=add(dp[k][i],dp[k][i-1]);
					if(k<m-1)dp[k][i]=add(dp[k][i],dp[k+1][i-1]);
				}
			}
			else{
				int k=arr[i];
				if(k>0)dp[k][i]=add(dp[k][i],dp[k-1][i-1]);
				dp[k][i]=add(dp[k][i],dp[k][i-1]);
				if(k<m-1)dp[k][i]=add(dp[k][i],dp[k+1][i-1]);
			}
		}
	}
    int ans=0;
    for(int i=0;i<m;i++){
		ans=add(ans,dp[i][n-1]);
	}
    d1(ans);
    return 0;
}
