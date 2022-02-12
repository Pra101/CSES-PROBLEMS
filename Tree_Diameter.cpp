// max distance form 0 say node _max
// then 
// max distance form node _max
// is the required answer _always
pair<int,int> dfs(int idx,vector<vector<int>>& adj,vector<int>& vis){
    int sz=adj[idx].size();
    pair<int,int> res={idx,-1};
    vis[idx]=1;
    for(int i=0;i<sz;i++){
	if(!vis[adj[idx][i]]){
	    pair<int,int> tp=dfs(adj[idx][i],adj,vis);
	    if(tp.second>res.second){
		res=tp;
	    }
	}
    }
    res.second++;
    return res;
}
int32_t main(){
    fio;
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    int x,y;
    for(int i=0;i<n-1;i++){
	cin>>x>>y;
	adj[y-1].push_back(x-1);
	adj[x-1].push_back(y-1);
    }
    vector<int> vis(n,0);
    pair<int,int> tp=dfs(0,adj,vis);
    for(auto &ele : vis)ele=0;
    tp=dfs(tp.first,adj,vis);
    cout<<tp.second;
    return 0;
}
