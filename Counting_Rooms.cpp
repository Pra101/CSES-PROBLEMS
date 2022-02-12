int m,n;
void dfs(int x,int y,vector<string>& grid){
	grid[x][y]='#';
	if(x>0&&grid[x-1][y]!='#')dfs(x-1,y,grid);
	if(x<n-1&&grid[x+1][y]!='#')dfs(x+1,y,grid);
	if(y>0&&grid[x][y-1]!='#')dfs(x,y-1,grid);
	if(y<m-1&&grid[x][y+1]!='#')dfs(x,y+1,grid);
}
void Counting_Rooms(){
	cin>>n>>m;
	vector<string> grid(n);
	for(int i=0;i<n;i++)cin>>grid[i];
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]=='.'){
				dfs(i,j,grid);
				ans++;
			}
		}
	}
	cout<<ans;
}
