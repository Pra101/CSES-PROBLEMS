// Solved Using Binary indexed trees.
void solve(){
	int n,q,data;
	cin>>n>>q;
	vector<int> arr(n,0),a(n,0);
	for(int i=0;i<n;i++){
		cin>>data;
		a[i]=data;
		for(int k=i+1;k<=n;k+=k&(-k))arr[k-1]+=data;
	}
	int t,l,r;
	while(q--){
		cin>>t>>l>>r;
		if(t==1){
			int diff=r-a[l-1];
			a[l-1]=r;
			for(int k=l;k<=n;k+=k&(-k))arr[k-1]+=diff;
		}
		else {
			int ans=0;
			for(int k=r;k>0;k-=k&(-k))ans+=arr[k-1];
			for(int k=l-1;k>0;k-=k&(-k))ans-=arr[k-1];
			cout<<ans<<"\n";
		}	
	}
    return ;
}
