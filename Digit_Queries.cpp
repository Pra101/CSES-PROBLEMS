void Digit_Queries(){
    int k;
    cin>>k;
    int tp=9,i=1,msk=1;
    int f=(k>9)?1:0;
    for(i=1;k>tp*i;i++){
	k-=tp*i;
	tp*=10;
	msk*=10;
    }
    int d=k/i;
    if(f){
	if(k%i==0)d--;
	d+=msk;
    }
    if(k%i==0){
	cout<<d%10<<"\n";
	return;
    }
    int rem=i-k%i+1;
    while((rem-- -1)>0)d/=10;
    cout<<d%10<<"\n";
    return ;
}
