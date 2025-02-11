#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 40050
#define MAX_NODES 40000

typedef struct {
	int source, destination, weight;
} Edge;

Edge graph[MAX_SIZE];
int parents[MAX_NODES];

int compare_edges(Edge *, Edge *);

int kruskal(int);

int find_component(int);

int main(int argc, char **argv)
{
	int routers, edges, i;

	while (scanf("%d %d", &routers, &edges), routers && edges)
	{
		memset(graph, 0, sizeof(graph));
		memset(parents, 0, sizeof(parents));

		for (i = 0; i < edges; ++i)
			scanf("%d %d %d", &graph[i].source, &graph[i].destination, &graph[i].weight);

		qsort(graph, edges, sizeof(Edge), compare_edges);

		for (i = 1; i <= routers; ++i)
			parents[i] = i;

		printf("%d\n", kruskal(edges));
	}

	return 0;
}

int compare_edges(Edge *a, Edge *b)
{
	return a->weight - b->weight;
}

int find_component(int i)
{
	if (i == parents[i])
		return i;
	return find_component(parents[i]);
}

int kruskal(int edges)
{
	int i, total_cost, component_v, component_u;
	total_cost = 0;

	for (i = 0; i < edges; ++i)
	{
		component_v = find_component(graph[i].source);
		component_u = find_component(graph[i].destination);

		if (component_v != component_u)
		{
			parents[component_v] = parents[component_u];
			total_cost += graph[i].weight;
		}
	}

	return total_cost;
}
