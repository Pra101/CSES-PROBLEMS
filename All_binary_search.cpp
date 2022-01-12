void Mamba_Mentality(){
    int n=13;
    vector<int> arr={2,5,6,7,11,14,17,19,23,28,91,99,101};
    cout<<arr<<"\n";
    // binary search exact
    while(1){
	int data;
	cin>>data;
	int l=0,r=n-1,f=0,mid;//Make sure that l and 'r' are exact bounds because if input is just above r or
					   //just below 'l' then could cause out of bondary access
	while(l<=r){
	    mid=l+(r-l)/2;
	    if(arr[mid]==data){
		cout<<"found!! :)\n";
		f=1;
		break;
	    }
	    else if(data<arr[mid])r=mid-1;
	    else l=mid+1;
	}
	if(f==0)cout<<"Not Found :'(\n";
    }
    // binary search Upper bound: also used i range queries

    while(1){
	int data;
	cin>>data;
	if(data>arr[n-1]){
	    cout<<"Values does not exist!!\n";
	    continue;
	}
	int l=0, r=n-1,mid;
	int ans=n-1;
	while(l<=r){
	    mid=l+(r-l)/2;
	    if(data<=arr[mid]){
		if(mid<ans)ans=mid;
		r=mid-1;
	    }
	    else l=mid+1;
	}
	cout<<arr[ans]<<"\n";
    }
    // binary search Lower bound
    while(1){
	int data;
	cin>>data;
	if(data<arr[0]){
	    cout<<"Values does not exist!!\n";
	    continue;
	}
	int l=0, r=n-1,mid;
	int ans=0;
	while(l<=r){
	    mid=l+(r-l)/2;
	    if(data<arr[mid])r=mid-1;
	    else {
		if(mid>ans)ans=mid;
		l=mid+1;
	    }
	}
	cout<<arr[ans]<<"\n";
    }
    
    return ;
}
