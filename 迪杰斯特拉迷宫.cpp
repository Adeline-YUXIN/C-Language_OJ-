#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 200
#define MAXVEX 200
#define GRAPH_INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */ 
int maze[10][10]={{0,-1,-1,-1,-1,0,5,0,0,-1},{0,-1,-1,2,3,4,-1,-1,0,-1/*1,1,1,1,1,1,1,1,1,1*/},{0,-1,4,2,-1,-1,-1,-1,8,-1/*1,1,1,1,1,1,1,1,1,1*/},{0,-1,3,-1,-1,-1,-1,-1,1,1},{0,-1,2,-1,0,0,0,-1,2,-1},{0,-1,1,-1,2,-1,4,-1,3,-1},{0,0,0,1,0,0,0,-1,1,1},{-1,-1,-1,0,-1,-1,-1,-1,2,-1},{-1,0,0,0,0,0,-1,0,0,1},{-1,0,-1,-1,-1,-1,-1,0,-1,0}};
//int maze[10][2]={{0,0},{-1,0/*1,1,1,1,1,1,1,1,1,1*/},{-1,0/*1,1,1,1,1,1,1,1,1,1*/},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,1},{-1,1}};
typedef struct Box
{
	int i;
	int j;
	int di;
}Box;

typedef struct
{
	Box vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];    /* 用于存储最短路径下标的数组 */
typedef int ShortPathTable[MAXVEX];/* 用于存储到各点最短路径的权值和 */

/* 构图 */
//void CreateMGraph(MGraph *G)
//{
//	int i, j;
//
//	/* printf("请输入边数和顶点数:"); */
//	G->numEdges=16;
//	G->numVertexes=9;
//
//	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
//	{
//		G->vexs[i]=i;
//	}
//
//	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
//	{
//		for ( j = 0; j < G->numVertexes; j++)
//		{
//			if (i==j)
//				G->arc[i][j]=0;
//			else
//				G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
//		}
//	}
//
//	G->arc[0][1]=1;
//	G->arc[0][2]=5; 
//	G->arc[1][2]=3; 
//	G->arc[1][3]=7; 
//	G->arc[1][4]=5; 
//
//	G->arc[2][4]=1; 
//	G->arc[2][5]=7; 
//	G->arc[3][4]=2; 
//	G->arc[3][6]=3; 
//	G->arc[4][5]=3;
//
//	G->arc[4][6]=6;
//	G->arc[4][7]=9; 
//	G->arc[5][7]=5; 
//	G->arc[6][7]=2; 
//	G->arc[6][8]=7;
//
//	G->arc[7][8]=4;
//
//
//	for(i = 0; i < G->numVertexes; i++)
//	{
//		for(j = i; j < G->numVertexes; j++)
//		{
//			G->arc[j][i] =G->arc[i][j];
//		}
//	}
//
//}

void ChangeAdjMaxGraph(MGraph *G)
{
 int ROW,COL;
 ROW=10;
 COL=10;
 G->numEdges = 0;
 G->numVertexes = 0;
 int K=0;
 for (int i = 0; i<ROW; i++)
 {
 	for (int j = 0; j < COL; j++)
  {
   G->vexs[K].i = i;
   G->vexs[K].j = j;
   G->vexs[K].di = maze[i][j];
   K++;
   G->numVertexes++;
  }
 }//邻接矩阵顶点坐标初始化
  
 //初始化边；
 for (int i = 0; i<G->numVertexes; i++)
 {
	for (int j = 0; j<G->numVertexes; j++)
  {
   if (i == j) G->arc[i][j] = 0;
   else G->arc[i][j] = GRAPH_INFINITY;
  }
 }//初始化边值为0
  
 //边赋值,arc的值为边的权重，此时都设置为1
 //for(int i=0;i<amg.vertexnum;i++)
 for (int j = 0; j < G->numVertexes; j++)
 {
  if (G->vexs[j].di != -1 && G->vexs[j + 1].di != -1 && ((j + 1) % COL) != 0)//左右链接，设置邻接矩阵的弧
  	{
  	 	G->arc[j][j + 1] = maze[(j + 1)%10+(j+1)/10][j%10+j/10];
   		G->arc[j + 1][j] = maze[j/10][j%10];
   		G->numEdges = G->numEdges + 2;
  	}
  if(G->vexs[j].di != -1 && G->vexs[j + COL].di != -1 && ((j + 1) % COL) == 0)
  	{
  		G->arc[j][j + COL] = maze[(j + COL)%10+(j+COL)/10][j%10+j/10];
    	G->arc[j + COL][j] = maze[j/10][j%10];
		G->numEdges = G->numEdges + 2;
    }
  if (G->vexs[j].di != -1 && G->vexs[j + COL].di != -1 && ((j + 1) % COL) != 0)//上下链接，设置邻接矩阵的弧
 	{
   		G->arc[j][j + COL] = maze[(j + COL)%10+(j+COL)/10][j%10+j/10];
   		G->arc[j + COL][j] = maze[j/10][j%10];
   		G->numEdges = G->numEdges + 2;
    }

 }
 //printf("%d\n",G->numVertexes);
}
/*  Dijkstra算法，求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v] */    
/*  P[v]的值为前驱顶点下标,D[v]表示v0到v的最短路径长度和 */  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1表示求得顶点v0至vw的最短路径 */
	for(v=0; v<G.numVertexes; v++)    /* 初始化数据 */
	{        
		final[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
		(*D)[v] = G.arc[v0][v];/* 将与v0点有连线的顶点加上权值 */
		(*P)[v] = -1;				/* 初始化路径数组P为-1  */       
	}

	(*D)[v0] = 0;  /* v0至v0路径为0 */  
	final[v0] = 1;    /* v0至v0不需要求路径 */        
	/* 开始主循环，每次求得v0到某个v顶点的最短路径 */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=GRAPH_INFINITY;    /* 当前所知离v0顶点的最近距离 */        
		for(w=0; w<G.numVertexes; w++) /* 寻找离v0最近的顶点 */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w顶点离v0顶点更近 */            
			}        
		}        
		final[k] = 1;    /* 将目前找到的最近的顶点置为1 */
		for(w=0; w<G.numVertexes; w++) /* 修正当前最短路径及距离 */
		{
			/* 如果经过v顶点的路径比现在这条路径的长度短的话 */
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  说明找到了更短的路径，修改D[w]和P[w] */
				(*D)[w] = min + G.arc[k][w];  /* 修改当前路径长度 */               
				(*P)[w]=k;        
			}       
		}   
	}
}

int main(void)
{   
	int i,j,v0,ROW=10,COL=10,end;
	int sum=0;
	MGraph G;    
	Patharc P;    
	ShortPathTable D; /* 求某点到其余各点的最短路径 */   
	v0=0;
	end=99;
	Box temp[MAXVEX];
	ChangeAdjMaxGraph(&G);
	//printf("%d\n",G.numVertexes);
	ShortestPath_Dijkstra(G, v0, &P, &D);  

	printf("最短路径如下:\n");    
	    
		printf("(%d,%d) - (%d,%d) : ",G.vexs[0].i,G.vexs[0].j,G.vexs[end].i,G.vexs[end].j);
		j=end;
		int pp=0;
		while(P[j]!=-1)
		{
			temp[pp].i=G.vexs[P[j]].i;
			temp[pp].j=G.vexs[P[j]].j;
			temp[pp].di=0;
			//printf("(%d,%d) ",G.vexs[P[j]].i,G.vexs[P[j]].j);
			j=P[j];
			pp++;
		}
		printf("\n");
		printf("(%d,%d) -> ",G.vexs[0].i,G.vexs[0].j);
	   for(int k=pp-1;k>=0;k--)
	   {
	   		printf("(%d,%d)",temp[k].i,temp[k].j);
	   		sum=sum+maze[temp[k].i][temp[k].j];
	   		if(k!=0) printf(" -> ");
	   		if(k==pp-4) printf("\n");
			if((pp-1-k+7)%5==0&&k<=pp-5) printf("\n");
	   }
	   printf(" -> (%d,%d)",G.vexs[end].i,G.vexs[end].j);
    	printf("\n源点到各顶点的最短路径长度为:\n");  
	//for(i=1;i<G.numVertexes;++i)        
		printf("(%d,%d) - (%d,%d) : %d \n",G.vexs[0].i,G.vexs[0].j,G.vexs[end].i,G.vexs[end].j,sum);     
	return 0;
}
