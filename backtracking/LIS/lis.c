#include <stdio.h>
#include <limits.h>

#define N_MAX 64

#define max(x,y) ((x)>(y)?(x):(y))

int ary[N_MAX];
int n;

unsigned lis(int x, unsigned k);

int main(void) {
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &ary[i]);
	}
	printf("%u\n", lis(INT_MIN, 0));
	return 0;
}

unsigned lis(int x, unsigned k) {
	if (k==n) {
		return 0;
	}
	if (ary[k]<=x) {
		return lis(x, k+1);
	}
	unsigned skip=lis(x, k+1);
	unsigned keep=lis(ary[k], k+1)+1;
	return max(skip, keep);
}
