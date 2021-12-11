#include <stdio.h>

#define N 9

#define ld(k) printf("ld %u -> ", k);total++
#define ui(k) printf("ui %u -> ", k);total++

unsigned total;

void i(unsigned k);
void d(unsigned k);

void d(unsigned k) {
	if (k==1) {
		ld(1);
		return;
	}
	ld(k);
	i(k-2);
	d(k-1);
}

void i(unsigned k) {
	if (!k) return;
	if (k==1) {
		ui(1);
		return;
	}
	i(k-1);
	ui(k);
	i(k-2);
	d(k-1);
}

int main(void) {
	for (int s=1;s<N+1;s+=2) {
		d(s);
	}
	putchar('\n');
	printf("total: %u\n", total);
	return 0;
}
