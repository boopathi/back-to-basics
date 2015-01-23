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
	int t = 10;
	while(t--) {
		int c=0;
		char a[25]="\0";
		scanf("%s",a);
		int len = strlen(a);
		FOR(i,len) switch(a[i]) {
			case 'F':
			case 'L':
			case 'D':
			case 'T': c++;
		}
		printf("%d\n", 1<<c);
	}
}
