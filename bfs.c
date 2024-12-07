#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

typedef struct link_node {
	int data;
	struct link_node* link;
}link_node;

typedef link_node* node_ptr;
node_ptr queue_front, queue_rear;
node_ptr graph[MAX_VERTICES];
short visited[MAX_VERTICES] = { 0 };

//udf
void enqueue(node_ptr* queue_front, node_ptr* queue_rear, int num);
int dequeue(node_ptr* queue_front);
void insertEdge(int u, int v);
void bfs(int v);

int main(void) {
	for (int i = 0; i < MAX_VERTICES; i++) {
		graph[i] = NULL;
	}

	//Input components
	int vertexNum, edgeNum, startVertex;
	printf("Please input the number of vertices: ");
	scanf("%d", &vertexNum);
	printf("Please input the number of edges: ");
	scanf("%d", &edgeNum);

	int u, v;
	for (int i = 0; i < edgeNum; i++) {
		printf("Please input the two linked vertices: ");
		scanf("%d %d", &u, &v);
		insertEdge(u, v);
		insertEdge(v, u);
	}

	//dfs
	printf("It starts bfs.\n");
	printf("Please input the starting vertex: ");
	scanf("%d", &startVertex);
	printf("These are the results of bfs.\n");
	bfs(startVertex);

	return 0;
}


//udf of queue
void enqueue(node_ptr* queue_front, node_ptr* queue_rear, int num) {
	link_node* new_ptr = (link_node*)malloc(sizeof(link_node));
	new_ptr->data = num;
	new_ptr->link = NULL;

	if (*queue_front == NULL) 
		*queue_front = new_ptr;
	else
		(*queue_rear)->link = new_ptr;
	*queue_rear = new_ptr;
}

int dequeue(node_ptr* queue_front){
	//Empty
	if (*queue_front == NULL) {
		return -1;
	}

	int result;
	node_ptr temp = *queue_front;
	*queue_front = temp->link;
	result = temp->data;
	free(temp);
	return result;
}


//udf of graph
void insertEdge(int u, int v) {
	link_node* new_ptr = (link_node*)malloc(sizeof(link_node));
	new_ptr->data = v;
	if (graph[u] == NULL) 
		new_ptr->link = NULL;
	else 
		new_ptr->link = graph[u];
	graph[u] = new_ptr;
}

void bfs(int v) {
	queue_front = NULL, queue_rear = NULL;
	visited[v] = 1;
	printf("%d ", v);
	enqueue(&queue_front, &queue_rear, v);
	
	while (queue_front != NULL) {
		v = dequeue(&queue_front);

		if (v == -1)
			break;

		for (node_ptr w = graph[v]; w; w = w->link) {
			if (!visited[w->data]) {
				printf("%d ", w->data);
				enqueue(&queue_front, &queue_rear, w->data);
				visited[w->data] = 1;
			}
		}
	}
}