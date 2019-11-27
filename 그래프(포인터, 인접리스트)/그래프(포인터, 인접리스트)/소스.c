#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define TRUE 1
#define FASLSE 0

//��������Ʈ(������)�� �̿��� �׷��� ����
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
	g->n = 0; //���������� 0����
	for (v = 0; v < MAX_VERTICES; v++)
	{
		g->adj_list[v] = NULL;//������ �迭 ���� �η� �ʱ�ȭ
	}
}

void insert_vertex(GraphType*g, int v)
{
	if (((g->n) + 1)>MAX_VERTICES) //���� ������ ������ +1�� �Ѱ��� �迭�� ������� ũ�� ����. ��,�迭�� �ε����� 49������ ����.
	{
		fprintf(stderr, "���������ʰ�����");
		return;
	}
	g->n++;
}

void insert_edge(GraphType*g, int u, int v)//u�� ������ v�� ������ �� �ڵ忡���� ���� ���� ���ö����� ���� ���� �� Ŀ���ٰ� ����.
{
	GraphNode*node;
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "������ȣ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];  //���� �տ� �����ϴ� ��
	g->adj_list[u] = node;        //���� �տ� �����ϴ� �� �׸����� �����Ұ�!!!

}

//dfs ���̿켱Ž��
int visited[MAX_VERTICES];
void dfs_list(GraphType*g, int v)
{
	GraphNode*w;
	visited[v] = TRUE;
	printf("%d", v);
	for (w = g->adj_list[v]; w; w = w->link)
		if (!visited[w->vertex]) //�湮���� �ʾ����� 0�� ���̰� !������ 1�� �ٲ�. ���� �� ���.
			dfs_list(g, w->vertex);
}
//bfs�� ť�׸� ���� ���õ�??

//���Ἲ�� ã�� �Լ�. ���� dfs�� visited[v] = TRUE�� �ƴ� 
//visited[v] = count�� �ٲپ����
int count = 0; //�������� count
void find_connected_component(GraphType*g)
{
	int i;
	count = 0;
	for (i = 0; i < g->n; i++)
		if (!visited[i])
		{
			count++;
			dfs_mat(g, i, count); //�� �κ� ���谢!!!
		}
}

//ũ�罺Į�� ���� ���� �� ��� ������ ��� ����Ŭ �Ȼ���� ã�ư��� ��. ��������. ������ n���� n-1������.
//������ ���� ������. �������� ������ ������ ������ �߿� �ּҰ������� ����� ������ �����ؼ� Ʈ�� Ȯ���� ����. ������ Ʈ������ Ȯ���� ����.