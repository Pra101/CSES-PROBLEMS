// sort and Two pointers approach
void Ferris_Wheel(){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        enter(arr);
        sort(all(arr));
        int l,r,ans=0;
        l=0,r=n-1;
        while(l<=r){
            if(arr[r]>=k||arr[l]+arr[r]>k){
                    ans++;
                    r--;
            }
            else {
                    ans++;
                    l++;
                    r--;
            }
        }
        cout<<ans;
        return ;
}
