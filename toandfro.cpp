#include <cstdio>
#include <cstring>
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define REP(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REV(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define GI ({int t;scanf("%d",&t);t;})
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))

using namespace std;

int main() {
	int x = GI;
	while(x != 0) {
		char a[205] = "\0", b[205] = "\0";
		scanf("%s", a);
		int len=strlen(a), r = len/x, k=0;
		FOR(i, r) {
			if(i%2) REV(j, x) b[r*j+i] = a[k++];
			else FOR(j, x) b[r*j+i]=a[k++];
		}
		printf("%s\n",b);
		x=GI;
	}
}
