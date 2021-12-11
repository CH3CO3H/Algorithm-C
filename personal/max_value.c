#include <stdio.h>

#define MAX_N 32
#define max(a, b) ((a)>(b))?(a):(b)

int solve (int k, int l);

struct thing {
	int w;
	int v;
};
typedef struct thing thing;

int n;
thing all[MAX_N];
int w_limit;

int main (void) {
	printf ("input n: ");
	scanf ("%d", &n);
	for (int i=0;i<n;i++) {
		scanf ("%d%d", &all[i].w, &all[i].v);
	}
	printf ("input weight limit: ");
	scanf ("%d", &w_limit);

	int ret = solve (0, w_limit);
	printf ("%d\n", ret);

	return 0;
}

int solve (int k, int l) {
	if (k==n) return 0;
	if (all[k].w>l) return solve (k+1, l);
	return max(all[k].v + solve (k+1, l-all[k].w), solve (k+1, l));
}
