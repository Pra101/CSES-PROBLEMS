void Movie_Festival(){
    int n;
    cin>>n;

    vector<pair<int,int>> arr;
    int x,y;
    for(int i=0;i<n;i++){
	cin>>x>>y;
	arr.push_back({y,x});
    }
    sort(all(arr));

    int ans=0,prev=0;
    for(int i=0;i<n;i++){
	if(arr[i].second>=prev){
	    ans++;
	    prev=arr[i].first;
	}
    }
    cout<<ans;
    return ;
}
