void Number_Spiral(){
    int x,y;
    cin>>x>>y;
    int ans=0,res;
    if(x>=y){
	res=x-1;
	if(res%2==1)ans=((res+1)*(res+1))-y+1;
	else ans=res*res+y;
	    
    }
    else {
	res=y-1;
	if(res%2==0)ans=((res+1)*(res+1))-x+1;
	else ans=res*res+x;
    }
    cout<<ans<<"\n";
    return ;
}
