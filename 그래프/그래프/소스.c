#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

//인접행렬(배열)을 이용한 그래프 구현
typedef struct GraphType
{
	int n; //정점개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; //인접행렬
}GraphType;

void graph_init(GraphType*g)
{
	int r, c;
	g->n = 0; //정점개수 0으로 만들고
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0; //연결성도 0으로 만들기.
}

void insert_vertex(GraphType*g, int v)
{
	if (((g->n)+1)>MAX_VERTICES) //현재 정점의 개수에 +1을 한것이 배열의 사이즈보다 크면 오류. 즉,배열의 인덱스인 49까지만 가능.
	{
		fprintf(stderr, "정점개수초과오류");
		return;
	}
	g->n++;
}

void insert_edge(GraphType*g, int start, int end)
{
	if ((start >= g->n) || (end >= g->n))
	{
		fprintf(stderr, "정점번호오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
