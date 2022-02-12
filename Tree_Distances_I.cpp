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
void dfs2(int idx,vector<vector<int>>& adj,vector<int>& vis,vector<int>& mx,int ans){
    vis[idx]=1;
    int sz=adj[idx].size();
    mx[idx]=ans;
    for(int i=0;i<sz;i++){
	if(!vis[adj[idx][i]]) dfs2(adj[idx][i],adj,vis,mx,ans+1);
    }
    return;
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
    int a,b;
    pair<int,int> tp=dfs(0,adj,vis);
    a=tp.first;
    for(auto &ele : vis)ele=0;
    tp=dfs(tp.first,adj,vis);
    b=tp.first;
    for(auto &ele : vis)ele=0;
    vector<int> mxa(n,0),mxb(n,0);
    dfs2(a,adj,vis,mxa,0);
    for(auto &ele : vis)ele=0;
    dfs2(b,adj,vis,mxb,0);
    for(int i=0;i<n;i++)cout<<max(mxa[i],mxb[i])<<" ";
    return 0;
}
