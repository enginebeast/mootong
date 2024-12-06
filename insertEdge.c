#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

typedef struct link_node {
	int data;
	struct link_node* link;
}link_node;

typedef link_node* node_ptr;
node_ptr graph[MAX_VERTICES];


//udf
void insertEdge(int u, int v);


int main(void) {
	for (int i = 0; i < MAX_VERTICES; i++) {
		graph[i] = NULL;
	}

	//Input components
	int vertexNum, edgeNum, startNum;
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

	//Print graph
	printf("The input graph is as follows\n");
	for (int i = 1; i <= vertexNum; i++) {
		link_node* ptr = graph[i];
		printf("%d : ", i);
		while (ptr != NULL) {
			printf("%d ", ptr->data);
			ptr = ptr->link;
		}
		printf("\n");
	}

	return 0;
}


void insertEdge(int u, int v) {
	link_node* new_ptr = (link_node*)malloc(sizeof(link_node));
	new_ptr->data = v;
	if (graph[u] == NULL) {
		new_ptr->link = NULL;
	}
	else {
		new_ptr->link = graph[u];
	}
	graph[u] = new_ptr;
}