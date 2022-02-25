void Concert_Tickets(){
    int n,q;
    cin>>n>>q;
    multiset<int> ms;
    int data;
    for(int i=0;i<n;i++){
	cin>>data;
	ms.insert(data);
    }
    //cout<<*ms.begin()<<"\n";
    while(q-->0){
	cin>>data;
	auto it = ms.upper_bound(data);
	if(it==ms.begin())cout<<"-1\n";
	else {
	    cout<<*(--it)<<"\n";
	    ms.erase(it);
	}
    }
    return ;
}
