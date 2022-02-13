void Counting_Bits(){
    int n ,ans=0,p=2;
    cin>>n;
    int tp;
    while(p<=2*n){
	tp=n/p;
	ans+=tp*(p/2);
	//trace(ans,tp,p);
	tp=n%p+1;
	ans+=max(tp-p/2,0LL);
	p*=2;
    }
    cout<<ans<<"\n";
    return ;
}
