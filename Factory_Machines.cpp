// Used Binary search
void Factory_Machines(){
    int n,t;cin>>n>>t;
    vector<int> arr(n);enter(arr);
    int ans=223372036854775807LL;
    if(n==1){
	cout<<arr[0]*t;
	return;
    }
    int l=1,r=ans,mid;
    while(l<=r){
	mid=l+(r-l)/2;
	int tp=0;
	for(auto ele : arr)tp+=mid/ele;
	if(tp>=t){
	    ans=mid;
	    r=mid-1;
	}
	else l=mid+1;
    }
    cout<<ans;
    return ;
}
