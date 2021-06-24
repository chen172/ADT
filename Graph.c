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

void
CreateAdjlist(Vexnode ga[]) { // 建立无向图的邻接表
	int i, j, k;
	Edgenode *s;
	for (i = 0; i < N; i++) {
		ga[i].vertex = getchar(); //读入顶点信息和边表头指针初始化
		ga[i].link = NULL;
	}
	for (k = 0; k < E; k++) { //建立边表
		scanf("%d%d", &i, &j); //读入边(vi, vj)的顶点序号
		s = (Edgenode*)malloc(sizeof(Edgenode)); //生成邻接点序号为j的边表结点*s
		s->adjvex = j;
		s->next = NULL;
		ga[i].link = s; // 将*s插入顶点vi的边表头部
		s = (Edgenode*)malloc(sizeof(Edgenode)); //生成邻接点序号为i的边表结点*s
		s->adjvex = i;
		s->next = NULL;
		ga[j].link = s; // 将*s插入顶点vi的边表头部
	}
}
		
