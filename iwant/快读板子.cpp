#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
const long long inf = 0x3f3f3f3f3f3f3f3f;
typedef long long ll;
const ll INF_LL  = 1e18;
using namespace std;
inline ll read(){
	ll x=0;
	char c;
	bool flag=false;
	c=getchar();
	while(c<'0'||c>'9'){
		flag=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	if(flag) return -x;
	else return x;
} 
int main(){
	int a=-1;
	 int b=0; 
	cout<<(a<b);
return 0;
}
//dp?
