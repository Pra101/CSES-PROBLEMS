//Greedy, Ans=max(2*Max_element,overall_sum);
void Reading_Books(){
    int n;cin>>n;
    vector<int> arr(n);enter(arr);
    int sum=0,mx_ele=arr[0];
    for(int i=0;i<n;i++){
	sum+=arr[i];
	mx_ele=max(mx_ele,arr[i]);
    }
    int ans=max(2*mx_ele,sum);
    cout<<ans<<"\n";
    return ;
}
