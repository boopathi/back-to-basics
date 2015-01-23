#include <cstdio>
#define GI ({int t;scanf("%d",&t);t;})

using namespace std;

int main() {
	int t = GI;
	while(t--) {
		int x = GI, y = GI;
		if(x == y || x-2 == y) {
			printf("%d", x+y - x%2);
		} else {
			printf("No Number");
		}
		printf("\n");
	}
	return 0;
}