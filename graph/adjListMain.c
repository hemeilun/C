#include"LinkedQueue.c"

//非递归方式深度优先遍历
void DFSNonrecursive(AdjacencyList *adjacencyList,int j){

    printf("\n");
    int vertexsNum = adjacencyList->vertexsNum;
    int *visited = (int*)malloc(sizeof(int)*(vertexsNum)); 

    for (int i = 0; i < vertexsNum; i++)
    {
        visited[i] = 0;
    }

    LinkedStackList L = initStack();
    visited[j] = 1;
    push(L,&adjacencyList->vertexs[j]);
    printf("%d ",adjacencyList->vertexs[j].data);

    Edge *edge;
    
    while(isStackEmpty(L)){

        Vertex *vex = stackTop(L);
        edge = vex->firstEdge;
        while(edge){
            if(!visited[edge->data]){
                push(L,&adjacencyList->vertexs[edge->data]);
                visited[edge->data] = 1;
                printf("%d ",edge->data);
                edge = adjacencyList->vertexs[edge->data].firstEdge;
            }else{
                edge = edge->next;
            }
        }
        if(!edge){
            pop(L);
        }

    }


}



void BFS(AdjacencyList *adjacencyList,int i,int *visited){
    LinkedQueueList L = initQueue();
    enQueue(L,&adjacencyList->vertexs[i]);
    visited[i] = 1;
    printf("%d ",i);

    while(isQueueEmpty(L)){
        Vertex* vex = deQueue(L);
        //printf("%d ",vex->data);
        Edge *edge = vex->firstEdge;

        while(edge){
           if(!visited[edge->data]){
               enQueue(L,&adjacencyList->vertexs[edge->data]);
               visited[edge->data] = 1;
               printf("%d ",edge->data);
           }
           edge = edge->next;
        }

    }


}

void BFSTraverse(AdjacencyList *adjacencyList){
    int vertexsNum = adjacencyList->vertexsNum;
    int *visited = (int*)malloc(sizeof(int)*(vertexsNum)); 

    for (int i = 0; i < vertexsNum; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < vertexsNum; i++)
    {
        if(!visited[i]){
            BFS(adjacencyList,i,visited);
        }
    }
    

}


void showAdjacencyList(AdjacencyList *adjacencyList){
    for (int i = 0; i < adjacencyList->vertexsNum; i++)
    {
        Edge *edge = adjacencyList->vertexs[i].firstEdge;
        while(edge){
            printf("%d ",edge->data);
            edge = edge->next;
        }
        printf("\n");

    }
    

}


int main(){

    //初始化邻接表
    AdjacencyList *adjacencyList = initAdjacencyList();

    int index[16] = {0,1,0,2,0,3,1,2,1,3,1,4,2,3,0,4};
    int edgeNum = 8;
    int vertexNum = 5;
    addVertexAndEdge(adjacencyList,vertexNum,edgeNum,index);

    //DFSTraverse(adjacencyList);
    //DFSNonrecursive(adjacencyList,0);
    //showAdjacencyList(adjacencyList);

    BFSTraverse(adjacencyList);

}