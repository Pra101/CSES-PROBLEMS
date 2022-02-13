// By iteration and two Pointers
void Subarray_Sums_I(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    enter(arr);
    int ans=0,tp=0,l=0,r=0;
    for(int i=1;i<n;i++)arr[i]+=arr[i-1];
    while(r<n){
	tp=arr[r];
	if(l>0)tp-=arr[l-1];
	if(tp==x){
	    ans++;
	    l++;r++;
	}
	else if(tp<x)r++;
	else l++;
    }
    cout<<ans<<"\n";
    return ;
}

// Using Unordered Maps
void Subarray_Sums_I(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    enter(arr);
    int ans=0;
    map<int,int> umap;
    umap[0]++;
    for(int i=0;i<n;i++){
	if(i>0) arr[i]+=arr[i-1];
	umap[arr[i]]++;
	ans+=umap[arr[i]-x];
    }
    cout<<ans<<"\n";
    return ;
}
