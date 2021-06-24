ADT Graph{
CreateGraph(G)
CreatAdjlist(ga)
DestroyGraph(G)
InsertVex(G,v)
DeleteVex(G,v)
DFSA(G,i)
DFSL(ga, i)
BFSA(G, k)
BFSL(ga, k)
} ADT Graph

#define N 8 
#define E 10
typedef char Vextype;
typedef float Adjtype;
typedef struct {
	Vextype vexs[N];
	Adjtype arcs[N][N];
} Graph;

void
CreateGraph(Graph *g)
{
	int i, j, k;
	float w;
	
	for (i = 0; i < N; i++)
		g->vexs[i] = getchar();
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			g->arcs[i][j] = 0;

	for (k = 0; k < E; k++) {
		scanf("%d%d%f", &i, &j, &w);
		g->arcs[i][j] = w;
		g->arcs[j][i] = w;
	}
} 

typedef struct node {
	int adjvex;
	struct node *next;
} Edgenode;

typedef struct {
	Vextype vertex;
	Edgenode *link;
} Vexnode;
Vexnode ga[n];
