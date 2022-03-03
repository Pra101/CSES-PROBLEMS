void Mamba_Mentality(){
    int n,tar;
    cin>>n>>tar;
    vector<pair<int,int>> arr;
    int data;
    for(int i=0;i<n;i++){
	cin>>data;
	arr.push_back({data,i+1});
    }
    sort(all(arr));
    for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
	    int fin=tar-arr[i].first-arr[j].first;
	    int l=j+1,r=n-1,mid;
	    while(l<=r){
		mid=(l+r)/2;
		if(arr[mid].first==fin){
		    vector<int> ans;
		    ans.push_back(arr[i].second);
		    ans.push_back(arr[j].second);
		    ans.push_back(arr[mid].second);
		    sort(all(ans));
		    for(auto ele : ans)cout<<ele<<" ";
		    return;
		}
		if(arr[mid].first>fin)r=mid-1;
		else l=mid+1;
	    }
	}
    }
    cout<<"IMPOSSIBLE";
    return;
}
