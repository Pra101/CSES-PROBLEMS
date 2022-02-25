void Sum_of_Two_Values(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> arr;
    int data;
    for(int i=0;i<n;i++){
	cin>>data;
	arr.push_back({data,i+1});
    }
    sort(all(arr));
    int l=0,r=n-1;
    while(l<r){
	if(arr[l].first+arr[r].first==x){
	    if(arr[l].second>arr[r].second)swap(arr[l].second,arr[r].second);
	    cout<<arr[l].second<<" "<<arr[r].second;
	    return;
	}
	else if(arr[l].first+arr[r].first<x)l++;
	else r--;
    }
    cout<<"IMPOSSIBLE";
    return ;
}
