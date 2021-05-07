#include<stdio.h>
using namespace std;
const int mod=1e9+7;
#define ll long long
inline int mul(ll x,ll y){
    return (x*1ll*y)%mod;
}
inline int add(ll x,ll y){
    x+=y;
    if (x>=mod) return x-mod;
    return x;
}
inline int sub(ll x,ll y){
    x-=y;
    if (x<0) return x+mod;
    return x;
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==1)printf("0");
    else {
	ll ans=((n%2)?-1:1),f=((n%2)?0:1),mult=1;
	for(int i=n;i>2;i--){
	    mult=mul(mult,i);
	    ans=(f)?sub(ans,mult):add(ans,mult);
	    f=1-f;
	}
	printf("%lld",ans);
    }
    return 0;
}
