#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 10


typedef struct Edge
{
    int data;
    struct Edge *next;
}Edge;


typedef struct Vertex{
    int data;
    struct Edge *firstEdge;
}Vertex;


typedef struct AdjacencyList
{
    Vertex *vertexs;             //记录顶点集
    int vertexsNum,edgeNum;      //记录顶点数和边数
}AdjacencyList;



/**
 * @brief 初始化一个邻接表
 * 
 * @return AdjacencyList* 
 */
AdjacencyList *initAdjacencyList(){

    Vertex *vertexs = (Vertex*)malloc(sizeof(Vertex)*INITSIZE);
    AdjacencyList *adjacencyList = (AdjacencyList*)malloc(sizeof(AdjacencyList));

    adjacencyList->vertexs = vertexs;
    adjacencyList->edgeNum = adjacencyList->vertexsNum = 0;

    return adjacencyList;
}


/**
 * @brief 给定顶点和边构造邻接表
 * 
 * @param adjacencyList 
 * @param vertexNum 顶点的数量
 * @param edgeNum   边的数量
 * @param indexs    存储顶点边数据的数组，比如[0,1,4,6]就是顶点0与顶点1有边，顶点4与顶点6有边
 */
void addVertexAndEdge(AdjacencyList *adjacencyList , int vertexNum , int edgeNum , int *indexs){

     int i=0;
     for(i=0; i<vertexNum; i++){
        adjacencyList->vertexs[i].data = i;
        adjacencyList->vertexs[i].firstEdge = NULL;
     } 
     adjacencyList->vertexsNum = vertexNum;
     adjacencyList->edgeNum = edgeNum; 

     for ( i = 0; i < edgeNum; i++)
     {
        Edge *edgeIToJ = (Edge*)malloc(sizeof(Edge));
        edgeIToJ->data = indexs[2*i+1];
        edgeIToJ->next = NULL;

        Edge *edgeJToI = (Edge*)malloc(sizeof(Edge));
        edgeJToI->data = indexs[2*i];
        edgeJToI->next = NULL;

        edgeIToJ->next = adjacencyList->vertexs[indexs[2*i]].firstEdge;
        adjacencyList->vertexs[indexs[2*i]].firstEdge = edgeIToJ;

        edgeJToI->next = adjacencyList->vertexs[indexs[2*i+1]].firstEdge;
        adjacencyList->vertexs[indexs[2*i+1]].firstEdge = edgeJToI;

     }
     

}




/**
 * @brief 深度优先遍历的具体实现
 * 
 * @param adjacencyList 
 * @param i        访问对应顶点
 * @param visited 
 */
void DFS(AdjacencyList *adjacencyList,int i,int *visited){

    printf("%d ",i);
    visited[i] = 1;
    Edge *edge = adjacencyList->vertexs[i].firstEdge;

    while(edge){
        if(visited[edge->data]==0){
            DFS(adjacencyList,edge->data,visited);
        }
        edge = edge->next;
    }
}

/**
 * @brief 深度优先遍历的入口
 * 
 * @param adjacencyList 
 */
void DFSTraverse(AdjacencyList *adjacencyList){

      int vertexsNum = adjacencyList->vertexsNum;
      int *visited = (int*)malloc(sizeof(int)*(vertexsNum)); 

      for (int i = 0; i < vertexsNum; i++)
      {
        visited[i] = 0;
      }

      for (int i = 0; i < vertexsNum; i++)
      {
        if(visited[i]==0){
            DFS(adjacencyList,i,visited);
        }
      }
       
}














