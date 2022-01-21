#define int long long
void Counting_Towers(){   
	int n;
	cin>>n;
	int data;
	while(n--){
		cin>>data;
		cout<<(arr[data][1]+arr[data][5])%mod<<"\n";
	}
	return;
}
int32_t main(){
    // Preprocessing
    for(int i=0;i<6;i++)arr[1][i]=1;
    int tp1,tp2;
    for(int i=2;i<=maxn;i++){
		tp1=(arr[i-1][0]+arr[i-1][1]+arr[i-1][5])%mod;
		tp2=(arr[i-1][1]+arr[i-1][2]+arr[i-1][3]+arr[i-1][4]+arr[i-1][5])%mod;
		arr[i][0]=tp1;
		arr[i][1]=tp1;
		arr[i][2]=tp2;
		arr[i][3]=tp2;
		arr[i][4]=tp2;
		arr[i][5]=tp2;
	}
    Counting_Towers();
    return 0;
}
