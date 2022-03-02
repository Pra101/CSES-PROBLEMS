void Mamba_Mentality(){
    int n;cin>>n;
    vector<int>arr(n);enter(arr);
    vector<int> state;
    for(int i=0;i<n;i++){
	auto it=upper_bound(state.begin(),state.end(),arr[i]);
	if(it==state.end())state.push_back(arr[i]);
	else *it=arr[i];
    }
    cout<<state.size()<<"\n";
    return ;
}
