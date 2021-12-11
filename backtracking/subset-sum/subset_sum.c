#include <stdio.h>
#include <stdbool.h>

#define N_MAX 32

unsigned s[N_MAX];
unsigned n;

bool subset_sum(unsigned sig, int sum);

int main(void) {
	int t;
	scanf("%u", &n);
	for (int i=0;i<n;i++) {
		scanf("%u", &s[i]);
	}
	scanf("%d", &t);
	unsigned sig;
	sig=(1<<n)-1;
	subset_sum(sig, t)?puts("Yes"):puts("No");
	return 0;
}

bool subset_sum(unsigned sig, int t) {
	printf("sig=%x, t=%d\n", sig, t);
	if (!t) return true;
	if (!sig || t<0) return false;
	for (int k=1, i=0;k<(1<<n);k=(k<<1)) {
		if (k&sig) {
			unsigned nsig=sig&(~k);
			bool with=subset_sum(nsig, t-s[i]);
			bool wout=subset_sum(nsig, t);
			return with || wout;
		}
		i++;
	}
}
