int dfs(int idx,vector<vector<int>>& adj,vector<int>& ans){
    int sz=adj[idx].size(),res=0;
    for(int i=0;i<sz;i++){
	res+=dfs(adj[idx][i],adj,ans);
    }
    ans[idx]=res;
    return res+1;
}
int32_t main(){
    fio;
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    int data;
    for(int i=0;i<n-1;i++){
	cin>>data;
	adj[data-1].push_back(i+1);
    }
    vector<int> ans(n,0);
    dfs(0,adj,ans);
    for(auto ele : ans)cout<<ele<<" ";
    return 0;
}
