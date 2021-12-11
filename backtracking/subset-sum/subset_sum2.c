#include <stdio.h>
#include <stdbool.h>

#define SUM_MAX 65535
#define N_MAX 64

unsigned n;
unsigned set[N_MAX];
unsigned t;

bool subset_sum(unsigned k, unsigned sum);

int main(void) {
	scanf("%u", &n);
	for (int i=0;i<n;i++) {
		scanf("%u", &set[i]);
	}
	scanf("%u", &t);
	subset_sum(n-1, t)?puts("Yes"):puts("No");
	return 0;
}

bool subset_sum(unsigned k, unsigned sum) {
	printf("k=%u, sum=%u\n", k, sum);
	if (!sum) return true;
	if (sum>SUM_MAX || k>N_MAX) return false;
	bool with=subset_sum(k-1, sum-set[k]);
	bool wout=subset_sum(k-1, sum);
	return with || wout;
}
