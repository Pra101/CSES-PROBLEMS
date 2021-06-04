// Author: pra101
#include <bits/stdc++.h>
#include<unordered_set>
#include <cstdio>

using namespace std;
#define int long long
#define float long double
#define ll long long
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef priority_queue<ppi> max_heap_ppi;
typedef priority_queue<int> max_heap_int;
typedef priority_queue<int, vector<int>, greater<int>> min_heap_int;
#define F first
#define S seconds
#define pb push_back
#define mp make_pair
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<"\n"
#define d2(x,y) cout<<(x)<<" "<<(y)<<"\n"
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<"\n"
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<"\n"
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()
//for vector input
#define enter(a) for (auto &it : (a)) cin >> it
////////////////////////////////////////////For debugging//////////////////////////////////////////////////
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n";
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif
//============================================
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
/*/-----------------------Modular Arithmetic---------------/*/
const int mod=1e9+7;// 998244353
inline int add(int x,int y){
    x+=y;
    if (x>=mod) return x-mod;
    return x;
}
inline int sub(int x,int y){
    x-=y;
    if (x<0) return x+mod;
    return x;
}
inline int mul(int x,int y){
    return (x*1ll*y)%mod;
}
inline int power(int x,int y){
    int ans=1;
    while(y){
        if (y&1) ans=mul(ans,x);
        x=mul(x,x);
        y>>=1;
    }
    return ans;
}
inline int inv(int x){
    return power(x,mod-2);
}
 //=============LIMITS=====================
const int maxn=1e6+100;
const int INF=1e16+7;
const int MXI = 2e5+5;  
const float PI = acos((float)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};

//-----------------------------Check Points----------------------------
/*
	Lookout for overflows!!
	Check array sizes!!
	Clear buffer before other test cases!!
	Use the correct modulo num!!
	Check for corner-edge cases!!
	Are you forgetting something?!
	Read problem statement carefully!!!
	* floating point precision errors!!
*/
//-_
//int cas=0;//cout<<"Case #"<<cas<<": "<<ans<<"\n";
//when not getting answers: look for constraints or key observatoions;
void Never_give_up(){
    string str;
    cin>>str;
    int n = str.size();
    vi dp(n,0);

    dp[0]=1;
    int last=-1,f=-1;
    if(str[0]=='1'){
	last=0;
	f=1;
    }
    else if(str[0]=='0'){
	last=0;
	f=0;
    }
    for(int i=1;i<n;i++){
	if(str[i]=='0'){
	    if(str[i-1]=='1'){
		dp[i]=dp[i-1]+1;
	    }
	    else if(str[i-1]=='0'){
		dp[i]=1;
	    }
	    else{
		if(last==-1){
		    dp[i]=dp[i-1]+1;
		}
		else if(((i-last)%2==0)&&f==1){
		    dp[i]=i-last;
		}
		else if(((i-last)%2==1)&&f==0){
		    dp[i]=i-last;
		}
		else{
		    dp[i]=dp[i-1]+1;
		}
	    }
	    last=i;
	    f=0;
	}
	else if(str[i]=='1'){
	    if(str[i-1]=='0'){
		dp[i]=dp[i-1]+1;
	    }
	    else if(str[i-1]=='1'){
		dp[i]=1;
	    }
	    else{
		if(last==-1){
		    dp[i]=dp[i-1]+1;
		}
		else if(((i-last)%2==0)&&f==0){
		    dp[i]=i-last;
		}
		else if(((i-last)%2==1)&&f==1){
		    dp[i]=i-last;
		}
		else{
		    dp[i]=dp[i-1]+1;
		}
	    }
	    last=i;
	    f=1;
	}
	else{
	    dp[i]=dp[i-1]+1;
	}
    }
    int ans=0;
    //d1(dp);
    for(auto ele : dp)ans+=ele;
    d1(ans);
    
    return ;
}
int32_t main(){
    fio;//Use "flush" to remove from buffer
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    cin>>t;
    //cout<<PI<<"\n";
    while(t--) {
	//cas++;
        Never_give_up();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    //cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl; 
    return 0;
}
