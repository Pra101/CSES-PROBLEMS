int dp[20][10][2][2];
string str;
int n;
int count_func(int idx,int last,int st,int tight){
    if(idx==n)return 1;
    if(dp[idx][last][st][tight]!=-1)return dp[idx][last][st][tight];
    int ans=0;
    if(tight){
	for(int i=0;i<=(int)(str[idx]-'0');i++){
	    if(st==0&&i==0)ans+=count_func(idx+1,0,0,0);
	    else if(i!=last){
		if(i!=(int)(str[idx]-'0'))ans+=count_func(idx+1,i,1,0);
		else ans+=count_func(idx+1,i,1,1);
	    }
	}
    }
    else {
	for(int i=0;i<=9;i++){
	    if(st==0&&i==0)ans+=count_func(idx+1,0,0,0);
	    else if(i!=last) ans+=count_func(idx+1,i,1,0);
	}
    }
    return dp[idx][last][st][tight]=ans;
}
int cas=0;
void Counting_Numbers(){
    string a,b;
    int aa,bb;
    cin>>aa>>bb;
    aa--;
    a=to_string(aa);
    b=to_string(bb);
    str=a;n=str.size();
    memset(dp,-1,sizeof(dp));
    int res1=((aa>-1)?count_func(0,0,0,1):0);
    str=b;n=str.size();
    memset(dp,-1,sizeof(dp));
    int res2=count_func(0,0,0,1);
    cout<<res2-res1<<"\n";
    return ;
}
