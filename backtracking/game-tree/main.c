#include <stdio.h>
#include <stdbool.h>

#define BDSIZE 3

typedef unsigned char player[BDSIZE+2];
struct g_stat {
	player p[2];
	unsigned char turn;
};
typedef struct g_stat g_stat;

enum turn {
	A, B
};

bool play (g_stat*, int step);
bool iswin(g_stat* s);

int main (void) {
	g_stat inl;
	for (int i=0;i<BDSIZE;i++) {
		inl.p[0][i]=0;
		inl.p[1][i]=0;
	}
	inl.turn=A;
	if (play(&inl, 1)) {
		printf("A win\n");
	} else {
		printf("B win\n");
	}
	return 0;
}

bool play (g_stat* s, int step) {
	if (iswin(s)) return true;
	unsigned char x=s->turn;
	for (int i=0;i<BDSIZE;i++) {
		unsigned char pos=s->p[x][i];
		if (pos==BDSIZE+1 ||
				pos<BDSIZE-1 && s->p[!x][pos]==i+1 && s->p[!x][pos+1]==i+1) {
			printf("%c[%d] cannot move.\n", 'A'+x, i);
			continue;
		}
		unsigned char m=1;
		if (s->p[!x][pos]==i+1) {
			m=2;
		}
		g_stat st=*s;
		printf("turn %d: %c[%d] moves %hhd\n", step, 'A'+x, i, m);
		st.p[x][i]+=m;
		st.turn=!x;
		if (!play(&st, ++step)) {
			return true;
		}
	}
	return false;
}

bool iswin(g_stat* s) {
	for (int i=0;i<BDSIZE;i++) {
		if (s->p[s->turn][i] != BDSIZE+1) {
			return false;
		}
	}
	return true;
}
