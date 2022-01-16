void Line_of_Wines_DP(){
    int n;
    cin>>n;
    vector<int> arr(n),pref(n);
    enter(arr);
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
	pref[i]=arr[i];
	if(i>0)pref[i]+=pref[i-1];
    }
    int s1,s2;
    for(int gap=0;gap<n;gap++){
	for(int i=0,j=gap;i+gap<n;i++,j++){
	    if(gap==0)dp[i][j]=arr[i];
	    else {
		s1=pref[j];
		if(i>=0)s1-=pref[i];
		s2=pref[j-1];
		if(i-1>=0)s2-=pref[i-1];
		dp[i][j]=max(arr[i]+dp[i+1][j] + s1,arr[j]+dp[i][j-1] + s2);
	    }
	}
    }
    cout<<dp[0][n-1];
    return ;
}L
