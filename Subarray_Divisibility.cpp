void Subarray_Divisibility(){
    int n;
    cin>>n;
    vector<int> arr(n);
    enter(arr);
    int ans=0;
    map<int,int> umap;
    for(int i=0;i<n;i++){
	arr[i]=(arr[i]+n*1000000007)%n;
	if(i>0) arr[i]=(arr[i]+arr[i-1])%n;
	ans+=umap[arr[i]];
	ans+=((arr[i]==0)?1:0);
	umap[arr[i]]++;
    }
    cout<<ans;
    return ;
}
