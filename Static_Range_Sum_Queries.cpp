Static Range Sum Queries

void Static_Range_Sum_Queries(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    enter(arr);
    int l,r,ans=0;
    for(int i=1;i<n;i++)arr[i]+=arr[i-1];
    while(q--){
	cin>>l>>r;
	l--,r--;
	ans=arr[r];
	if(l>0)ans-=arr[l-1];
	cout<<ans<<"\n";
    }
    return ;
}
