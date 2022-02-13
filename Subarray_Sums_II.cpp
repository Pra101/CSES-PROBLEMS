void Subarray_Sums_II(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    enter(arr);
    int ans=0;
    map<int,int> umap;
    if(arr[0]!=0)umap[0]++;
    for(int i=0;i<n;i++){
	if(i>0) arr[i]+=arr[i-1];
	umap[arr[i]]++;
	ans+=umap[arr[i]-x];
    }
    cout<<ans<<"\n";
    return ;
}
