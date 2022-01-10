// Key learnings : Concept of Monotonic stack
// generally used when previous values computed has a little importance
// but some times the before values can do the work
void Nearest_Smaller_Values(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
	    cin>>arr[i];
    }
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
	    while(1){
	      if((int)st.size()==0){
		      cout<<"0 ";
		      st.push({arr[i],i+1});
		      break;
	      }
	      else{
		      pair<int,int> tp=st.top();
		      if(tp.first<arr[i]){
		      cout<<tp.second<<" ";
		      st.push({arr[i],i+1});
		      break;
		      }
		      else {
		        st.pop();
		      }
	      }
	    }
    }
    cout<<"\n";
    return ;
}
