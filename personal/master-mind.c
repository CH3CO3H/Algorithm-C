#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define POS 4
#define COLOR 6
#define TRY 10

struct ans {
	unsigned char x;
	unsigned char y;
};
typedef struct ans ans;

typedef unsigned char state[POS];

state q;

int setq(void) {
	srand(time(0));
	for (int i=0;i<POS;i++) {
		q[i]=rand()%COLOR;
	}
}

ans checka(state m) {
	ans ret={0};
	bool get_x[POS]={0};
	bool get_y[POS]={0};
	for (int i=0;i<POS;i++) {
		if (m[i]==q[i]) {
			ret.x++;
			get_x[i]=true;
		}
	}
	for (int i=0;i<POS;i++) {
		if (get_x[i]) continue;
		for (int j=0;j<POS;j++) {
			if (get_x[j] || get_y[j] || i==j) continue;
			if (q[j]==m[i]) {
				ret.y++;
				get_y[j]=true;
				break;
			}
		}
	}
	return ret;
}

int main(void) {
	setq();
	for (int i=0;i<POS;i++) {
		printf("%hhu\t", q[i]);
	}
	putchar('\n');
	state k={ 0, 1, 2, 3 };
	ans r=checka(k);
	printf("%hhu\t%hhu\n", r.x, r.y);
	return 0;
}
