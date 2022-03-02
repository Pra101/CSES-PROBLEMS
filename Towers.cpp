// Applied Greedy Approach
// Tried finding the next biggest(upper_bound) element in my present state(initially empty but later is going to be sorted){Binary search}
// if(upperbound--> state.end()) then updated the state by appending that element
// Else update that iterated value
void Towers(){
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
