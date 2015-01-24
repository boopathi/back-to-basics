#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define REP(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REV(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define IT(i,v) for(vector<int>::iterator (i)=(v).begin();(i)!=(v).end(); ++i)
#define GI ({int t;scanf("%d",&t);t;})
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))

using namespace std;

bool desc(pair<int,int> a, pair<int,int> b) { return a.second>b.second; }

int main() {
	int n = GI, sum[2] = {0,0};
	vector<pair<int,int> > a;
	vector<int> s[2];
	FOR(i,n) a.push_back(make_pair(i, GI));
	sort(a.begin(), a.end(), desc);
	FOR(i,n) {
		s[sum[0]>sum[1]].push_back(a[i].first+1);
		sum[sum[0]>sum[1]]+=a[i].second;
	}
	//display least values
	IT(i,s[s[0].size()>s[1].size()]) printf("%d\n",*i);
}
