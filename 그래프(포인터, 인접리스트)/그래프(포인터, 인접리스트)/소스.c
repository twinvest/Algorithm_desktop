#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define TRUE 1
#define FASLSE 0

//인접리스트(포인터)를 이용한 그래프 구현
typedef struct GraphNode
{
	int vertex;
	GraphNode*link;
}GraphNode;

typedef struct GraphType
{
	int n;
	GraphNode*adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType*g)
{
	int v;
	g->n = 0; //정점개수는 0으로
	for (v = 0; v < MAX_VERTICES; v++)
	{
		g->adj_list[v] = NULL;//포인터 배열 전부 널로 초기화
	}
}

void insert_vertex(GraphType*g, int v)
{
	if (((g->n) + 1)>MAX_VERTICES) //현재 정점의 개수에 +1을 한것이 배열의 사이즈보다 크면 오류. 즉,배열의 인덱스인 49까지만 가능.
	{
		fprintf(stderr, "정점개수초과오류");
		return;
	}
	g->n++;
}

void insert_edge(GraphType*g, int u, int v)//u는 시작점 v는 도착점 이 코드에서는 정점 새로 들어올때마다 숫자 점점 더 커진다고 가정.
{
	GraphNode*node;
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "정점번호오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];  //제일 앞에 삽입하는 것
	g->adj_list[u] = node;        //제일 앞에 삽입하는 것 그림으로 이해할것!!!

}

//dfs 깊이우선탐색
int visited[MAX_VERTICES];
void dfs_list(GraphType*g, int v)
{
	GraphNode*w;
	visited[v] = TRUE;
	printf("%d", v);
	for (w = g->adj_list[v]; w; w = w->link)
		if (!visited[w->vertex]) //방문하지 않았으면 0일 것이고 !에의해 1로 바뀜. 따라서 또 재귀.
			dfs_list(g, w->vertex);
}
//bfs는 큐그림 시험 나올듯??

//연결성분 찾는 함수. 위에 dfs의 visited[v] = TRUE가 아닌 
//visited[v] = count로 바꾸어야함
int count = 0; //전역변수 count
void find_connected_component(GraphType*g)
{
	int i;
	count = 0;
	for (i = 0; i < g->n; i++)
		if (!visited[i])
		{
			count++;
			dfs_mat(g, i, count); //이 부분 시험각!!!
		}
}

//크루스칼은 정점 복사 후 계속 최저만 골라서 싸이클 안생기게 찾아가는 것. 간선위주. 정점이 n개면 n-1개까지.
//프림은 정점 위주임. 시작정점 선택후 인접한 정점들 중에 최소간선으로 연결된 정점만 선택해서 트리 확장해 나감. 기존의 트리에서 확장해 나감.