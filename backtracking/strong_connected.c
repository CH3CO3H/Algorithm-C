#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NODE_MAX 128

typedef struct graph_node graph_node;
struct graph_node {
	unsigned short no;
	graph_node* next;
};

typedef graph_node* graph[NODE_MAX];

void read_graph(void);
static void show_graph(void);
bool is_strong_connected(unsigned no);
void cycle(void);

unsigned n;
unsigned edge;
graph g;
enum mark {
	NONE,
	SOLVED,
	PENDING
};
unsigned short mark[NODE_MAX];

int main(void) {
	read_graph();
	show_graph();
	mark[0]=SOLVED;
	if (is_strong_connected(0)) {
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
}

bool is_strong_connected(unsigned s) {
	bool all_pending=true;
	for (graph_node* t=g[s];t;t=t->next) {
		unsigned short s_mark=mark[t->no];
		if (s_mark==SOLVED) {
			all_pending=false;
			cycle();
		} else if (s_mark==NONE) {
			all_pending=false;
			return is_strong_connected(t->no);
		}
	}
	if (all_pending) return false;
	return true;
}

void cycle(void) {
	for (int i=0;i<n;i++) {
		if (mark[i]==PENDING) mark[i]=SOLVED;
	}
}

void read_graph(void) {
	scanf("%u%u", &n, &edge);
	for (size_t i=0;i<edge;i++) {
		unsigned u, v;
		scanf("%u%u", &u, &v);
		graph_node** tp=NULL;
		for (tp=&g[u];*tp;tp=&((*tp)->next));
		graph_node* t=malloc(sizeof(graph_node));
		t->no=v;
		t->next=NULL;
		*tp=t;
	}
}

static void show_graph(void) {
	for (int i=0;i<n;i++) {
		putchar('0'+i);
		for (graph_node* t=g[i];t;t=t->next) {
			printf(" -> %u", t->no);
		}
		putchar('\n');
	}
}
