#include <stdio.h>
#include <stdbool.h>

#define MAX_N 512

unsigned q[MAX_N];
unsigned n;

void place_queens(unsigned x);
void print_board(void);

int main(void) {
	scanf("%u", &n);
	place_queens(0);
	return 0;
}

void place_queens(unsigned r) {
	if (r==n) print_board();
	for (int i=0;i<n;i++) {
		bool l=true;
		for (int j=0;j<r;j++) {
			if (q[j]==i || q[j]==i+r-j || q[j]==i-r+j) {
				l=false;
			}
		}
		if (l) {
			q[r]=i;
			place_queens(r+1);
		}
	}
}

void print_board(void) {
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (q[i]==j) {
				putchar('X');
			} else {
				putchar('O');
			}
		}
		putchar('\n');
	}
	printf("------------------\n");
}
