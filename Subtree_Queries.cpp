int cas=0;
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;
    FenwickTree(int nn) {
        this->n = nn;
        bit.assign(nn, 0);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
    }
    void show(){
	for(int ele :bit)cout<<ele<<" ";
	cout<<"\n";
    }
};
void dfs_tour(int idx,int &st,vector<int>& arr,vector<vector<int>>& adj,vector<int>& vis,vector<pair<int,int>>& tour,FenwickTree &ft){
    vis[idx]=1;
    tour[idx].first=st;
    ft.add(st,arr[idx]);
    st++;
    int sz=adj[idx].size();
    for(int i=0;i<sz;i++){
	if(!vis[adj[idx][i]])dfs_tour(adj[idx][i],st,arr,adj,vis,tour,ft);
    }
    tour[idx].second=st;
    ft.add(st,arr[idx]);
    st++;
}
void Solution(){
    //cout<<"Case #"<<cas<<": ";
    int n,q;
    cin>>n>>q;
    vector<vector<int>> adj(n);
    vector<int> arr(n);
    enter(arr);
    int l,r;
    for(int i=0;i<n-1;i++){
	cin>>l>>r;
	l--;r--;
	adj[l].push_back(r);
	adj[r].push_back(l);
    }
    //cout<<"\n";
    //trace(adj);
    //trace(arr);
    vector<int> vis(n,0);
    vector<pair<int,int>> tour(n,{0,0});
    FenwickTree ft(2*n);
    int st=0;
    dfs_tour(0,st,arr,adj,vis,tour,ft);
    //ft.show();
    //trace(tour);
    //d1(ft.sum(1,2));
    //d1(ft.sum(0,9));
    //d1(ft.sum(3,8));
    int type;
    while(q--){
	cin>>type;
	if(type==1){
	    cin>>l>>r;
	    l--;
	    int delta=r-arr[l];
	    ft.add(tour[l].first,delta);
	    ft.add(tour[l].second,delta);
	    arr[l]=r;
	}
	else {
	    cin>>l;
	    l--;
	    //trace(tour[l]);
	    int ans=ft.sum(tour[l].first,tour[l].second);
	    d1(ans/2);
	}
    }
    return ;
}
