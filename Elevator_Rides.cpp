void Elevator_Rides(){
	int n,lim;
	cin>>n>>lim;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	   
	vector<pair<int,int>> dp(1<<n);
	dp[0].first=0,dp[0].second=0;
	
	for(int i=1;i<(1<<n);i++){
		dp[i].first=n;
		dp[i].second=lim;
		for(int k=0;k<n;k++){
			if(i&(1<<k)){
				int tp1=dp[i^(1<<k)].first;
				int tp2=dp[i^(1<<k)].second;
				if(tp2+arr[k]>lim){
					tp1++;
					tp2=arr[k];
				}
				else tp2+=arr[k];
				if(dp[i].first>tp1){
					dp[i].first=tp1;
					dp[i].second=tp2;
				}
				else if(dp[i].first==tp1&&dp[i].second>tp2){
					dp[i].first=tp1;
					dp[i].second=tp2;
				}
			}
		}
	}
	int ans=dp[(1<<n)-1].first;
	if(dp[(1<<n)-1].second>0)ans++;
	cout<<ans;
    return ;
}
