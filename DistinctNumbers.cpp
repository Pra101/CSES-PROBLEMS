// Here set(Ordered) works faster then the unordered
// set because ordered set guarantees NlogN ops
// but unordered set doesnot because of variant nature 
// Key Learnings : Ordred set is built on avl which is 
// self balancing Binary search tree
// Red black trees are also used for advanced processing
void DistinctNumbers(){
    int n,data;
    cin>>n;
    set<int> us;
    for(int i=0;i<n;i++){
	    cin>>data;
	    us.insert(data);
    }
    int ans=us.size();
    d1(ans);
    return ;
}
