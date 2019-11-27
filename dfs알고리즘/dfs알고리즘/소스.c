#include<stdio.h>
#define MAX_VERTICES 4
int visited[MAX_VERTICES];

typedef struct GraphNode
{
	int vertex;
	struct GraphNode * link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode *adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void graph_init(GraphType*g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; c++)
		for (c = 0; c < MAX_VERTICES; r++)
			g->adj_mat[r][c] = 0;
}
void insert_vertex(GraphType*g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType*g, int start, int end)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "그래프: 정점번호 오류");
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}


void dfs_mat(GraphType* g, int v)
{
	int w;
	visited[v] = 1;
	printf("%d ", v);
	for (w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);

}


int main()
{
	GraphType arr;
	insert_vertex(arr, 1);
	/*int arr[4][4] = {
		{0,1,1,0},
		{1,0,0,0},
		{1,0,0,0},
		{0,0,0,0}
	};*/
	dfs_mat(arr, 0);
}