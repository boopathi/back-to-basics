#include <cstdio>
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define REP(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REV(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define GI ({int t;scanf("%d",&t);t;})
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))

using namespace std;

int main() {
	int n = GI;
	while(n != -1) {
		int sum=0, a[10010];
		FOR(i,n) a[i]=GI;
		FOR(i,n) sum+=a[i];
		if(sum % n) {
			printf("-1\n");
		} else {
			int res =0, avg;
			avg = sum/n;
			FOR(i,n) if(a[i]<avg) res += avg-a[i];
			printf("%d\n", res);
		}
		n=GI;
	}
}
