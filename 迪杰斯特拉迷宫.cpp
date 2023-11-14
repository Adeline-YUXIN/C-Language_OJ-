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

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */ 
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

typedef int Patharc[MAXVEX];    /* ���ڴ洢���·���±������ */
typedef int ShortPathTable[MAXVEX];/* ���ڴ洢���������·����Ȩֵ�� */

/* ��ͼ */
//void CreateMGraph(MGraph *G)
//{
//	int i, j;
//
//	/* printf("����������Ͷ�����:"); */
//	G->numEdges=16;
//	G->numVertexes=9;
//
//	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
//	{
//		G->vexs[i]=i;
//	}
//
//	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
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
 }//�ڽӾ��󶥵������ʼ��
  
 //��ʼ���ߣ�
 for (int i = 0; i<G->numVertexes; i++)
 {
	for (int j = 0; j<G->numVertexes; j++)
  {
   if (i == j) G->arc[i][j] = 0;
   else G->arc[i][j] = GRAPH_INFINITY;
  }
 }//��ʼ����ֵΪ0
  
 //�߸�ֵ,arc��ֵΪ�ߵ�Ȩ�أ���ʱ������Ϊ1
 //for(int i=0;i<amg.vertexnum;i++)
 for (int j = 0; j < G->numVertexes; j++)
 {
  if (G->vexs[j].di != -1 && G->vexs[j + 1].di != -1 && ((j + 1) % COL) != 0)//�������ӣ������ڽӾ���Ļ�
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
  if (G->vexs[j].di != -1 && G->vexs[j + COL].di != -1 && ((j + 1) % COL) != 0)//�������ӣ������ڽӾ���Ļ�
 	{
   		G->arc[j][j + COL] = maze[(j + COL)%10+(j+COL)/10][j%10+j/10];
   		G->arc[j + COL][j] = maze[j/10][j%10];
   		G->numEdges = G->numEdges + 2;
    }

 }
 //printf("%d\n",G->numVertexes);
}
/*  Dijkstra�㷨����������G��v0���㵽���ඥ��v�����·��P[v]����Ȩ����D[v] */    
/*  P[v]��ֵΪǰ�������±�,D[v]��ʾv0��v�����·�����Ⱥ� */  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1��ʾ��ö���v0��vw�����·�� */
	for(v=0; v<G.numVertexes; v++)    /* ��ʼ������ */
	{        
		final[v] = 0;			/* ȫ�������ʼ��Ϊδ֪���·��״̬ */
		(*D)[v] = G.arc[v0][v];/* ����v0�������ߵĶ������Ȩֵ */
		(*P)[v] = -1;				/* ��ʼ��·������PΪ-1  */       
	}

	(*D)[v0] = 0;  /* v0��v0·��Ϊ0 */  
	final[v0] = 1;    /* v0��v0����Ҫ��·�� */        
	/* ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·�� */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=GRAPH_INFINITY;    /* ��ǰ��֪��v0������������ */        
		for(w=0; w<G.numVertexes; w++) /* Ѱ����v0����Ķ��� */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w������v0������� */            
			}        
		}        
		final[k] = 1;    /* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */
		for(w=0; w<G.numVertexes; w++) /* ������ǰ���·�������� */
		{
			/* �������v�����·������������·���ĳ��ȶ̵Ļ� */
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  ˵���ҵ��˸��̵�·�����޸�D[w]��P[w] */
				(*D)[w] = min + G.arc[k][w];  /* �޸ĵ�ǰ·������ */               
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
	ShortPathTable D; /* ��ĳ�㵽�����������·�� */   
	v0=0;
	end=99;
	Box temp[MAXVEX];
	ChangeAdjMaxGraph(&G);
	//printf("%d\n",G.numVertexes);
	ShortestPath_Dijkstra(G, v0, &P, &D);  

	printf("���·������:\n");    
	    
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
    	printf("\nԴ�㵽����������·������Ϊ:\n");  
	//for(i=1;i<G.numVertexes;++i)        
		printf("(%d,%d) - (%d,%d) : %d \n",G.vexs[0].i,G.vexs[0].j,G.vexs[end].i,G.vexs[end].j,sum);     
	return 0;
}
