//Two Pointers
void Playlist(){
    int n;cin>>n;
    vector<int>arr(n);enter(arr);
    map<int,int> umap;
    int l=0,r=1;
    int mx_ans=1;
    umap[arr[0]]++;
    while(r<n){
	if(umap[arr[r]]==0){
	    umap[arr[r]]++;
	    r++;
	}
	else if(umap[arr[r]]==1){
	    while(l<n){
		if(arr[l]==arr[r]){
		    umap[arr[r]]--;
		    l++;
		    break;
		}
		else {
		    umap[arr[l]]--;
		    l++;
		}
	    }
	}
	mx_ans=max(mx_ans,r-l);
	//trace(l,r,mx_ans);
    }
    cout<<mx_ans;
    return ;
}
