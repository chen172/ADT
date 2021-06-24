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

#define N 8 // 图的顶点数
#define E 10 // 图的边数
typedef char Vextype; // 顶点的数据类型
typedef float Adjtype; // 边权值的数据类型
typedef struct {
	Vextype vexs[N]; // 顶点数组
	Adjtype arcs[N][N]; // 邻接矩阵
} Graph;

// 为一个无向网络建立邻接矩阵
void
CreateGraph(Graph *g) // 建立无向网络
{
	int i, j, k;
	float w;
	
	for (i = 0; i < N; i++)
		g->vexs[i] = getchar(); // 读入顶点信息， 建立顶点表
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			g->arcs[i][j] = 0; // 邻接矩阵初始化

	for (k = 0; k < E; k++) {
		scanf("%d%d%f", &i, &j, &w); // 读入边（vi, vj)上的权w
		g->arcs[i][j] = w; // 写入邻接矩阵
		g->arcs[j][i] = w;
		// 建立无向图
		#if 0
		scanf("%d%d", &i, &j); // 读入边（vi, vj)
		g->arcs[i][j] = 1; 
		g->arcs[j][i] = 1;
		#endif
		// 建立有向网络
		#if 0
		scanf("%d%d%f", &i, &j, &w); // 读入边（vi, vj)上的权w
		g->arcs[i][j] = w; // 写入邻接矩阵
		#endif
		
	}
} 
// Note:
// 上述算法，当邻接矩阵是一个稀疏矩阵时， 会存在储存空间浪费现象。（即顶点很多，边很少）
// 上述算法的时间复杂度为O(n+n^2+e)。因为通常情况下e<<n^2, 所以该算法的时间复杂度为O(n^2)

typedef struct node { // 邻接链表结点
	int adjvex; // 邻接点域
	struct node *next; // 链域
} Edgenode;

typedef struct {
	Vextype vertex;  // 顶点域
	Edgenode *link; // 指针域
} Vexnode;
Vexnode ga[n]; // 顶点表

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
		// also can s->next = ga[i].link ??????
		s->next = NULL;
		ga[i].link = s; // 将*s插入顶点vi的边表头部
		s = (Edgenode*)malloc(sizeof(Edgenode)); //生成邻接点序号为i的边表结点*s
		s->adjvex = i;
		s->next = NULL;
		ga[j].link = s; // 将*s插入顶点vi的边表头部
	}
}
		
