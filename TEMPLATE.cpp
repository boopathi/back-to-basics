#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define REP(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REV(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define GI ({int t;scanf("%d",&t);t;})
#define GF ({float t;scanf("%f",&t);t;})
#define GL ({int64 t;scanf("%ld",&t);t;})
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define SWAP(type,a,b) do{type t=a;a=b;b=t;} while(0)
#define XOR_SWAP(a,b) do{a^=b;b^=a;a^=b;} while(0)
typedef long long int int64;
typedef unsigned long long int uint64;
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
inline void frint(int *a){
  register char c=0;while (c<33) c=getchar_unlocked();*a=0;
  while (c>33){*a=*a*10+c-'0';c=getchar_unlocked();}
}

int main() {
	return 0;
}