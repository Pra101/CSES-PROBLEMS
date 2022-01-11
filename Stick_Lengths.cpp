//Author : pra101
// Inorder to maximise gains take median as pivot Median determines
// All smaller values should be taken as positive difference 
// All greater should be taken as positive difference 
void Mamba_Mentality(){
    int n;
    cin>>n;
    vector<int> arr(n);
    enter(arr);
    sort(all(arr));
    int median=arr[n/2];
    if(n%2==0){
	median+=arr[n/2];
	median/=2;
    }
    int ans=0;
    for(int i=0;i<n;i++) ans+=abs(arr[i]-median);
    cout<<ans;
    return ;
}
