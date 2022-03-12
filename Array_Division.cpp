// Binary searched the Answer
void Array_Division(){
    int n,kk;cin>>n>>kk;
    vector<int> arr(n);enter(arr);
    int sum=0;
    int mx=arr[0];
    for(auto ele : arr){
	sum+=ele;
	mx=max(mx,ele);
    }
    int l=mx,r=sum,ans=sum,mid;
    while(l<=r){
	mid=(l+r)/2;
	int tp=1;
	sum=0;
	for(int k=0;k<n;k++){
	    if(sum+arr[k]>mid){
		tp++;
		sum=arr[k];
	    }
	    else sum+=arr[k];
	}
	if(tp<=kk){
	    ans=mid;
	    r=mid-1;
	}
	else l=mid+1;
    }
    cout<<ans;
    return ;
}
