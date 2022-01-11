// Exploited the property that numbers form 1 to n can be used to form any number from 1 to n*(n-1)/2
// .. So it must ensure that next number formed must be less then next number is less then sum till that point for MEX.
// For more information visit GFG.
void Missing_Coin_Sum(){
    int n;
    cin>>n;
    vector<int> arr(n);
    enter(arr);
    sort(all(arr));
    int ans=1;
    for(int i=0;i<n&&ans>=arr[i];i++){
	        ans+=arr[i];
    }
    cout<<ans;
    return ;
}
