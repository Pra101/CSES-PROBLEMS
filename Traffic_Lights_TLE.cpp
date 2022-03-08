// Little inefficient on some test cases TLE
// Works on big radom cases
struct nd{
    int mx_;
    int l,r;
    nd *left,*right;
    int f;
};
int dfs(nd *root,int x){
    if(!(root->f)){
	root->f=1;
	nd *tmp1=new nd,*tmp2=new nd;
	tmp1->left=tmp1->right=NULL;
	tmp2->left=tmp2->right=NULL;
	tmp1->mx_=x-(root->l);
	tmp2->mx_=(root->r)-x;
	tmp1->f=0;tmp2->f=0;
	tmp1->l=(root->l);tmp1->r=x;
	tmp2->l=x;tmp2->r=(root->r);
	root->left=tmp1;
	root->right=tmp2;
	return root->mx_=max((tmp1->mx_),(tmp2->mx_));
    }
    if(x<(root->left->r))root->mx_=max(dfs(root->left,x),root->right->mx_);
    else root->mx_=max(dfs(root->right,x),root->left->mx_);
    return root->mx_;
}
// Memory leakage handling is important
void del(nd *root){
    if(root->f==1){
	del(root->left);
	del(root->right);
    }
    delete root;
}
void Traffic_Lights(){
    int n,q;
    cin>>n>>q;
    nd *head= new nd;
    head->left=head->right=NULL;
    head->mx_=n;
    head->l=0;head->r=n;
    head->f=0;
    
    int data,prev=n;
    unordered_set<int> us;
    while(q--){
	cin>>data;
	if(us.count(data)==0){
	    prev = dfs(head,data);
	    us.insert(data);
	}
	cout<<prev<<" ";
    }
    del(head);
    return ;
}
