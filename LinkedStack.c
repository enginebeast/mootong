#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
	int data;
	struct list_node* link;
}list_node;


void push(list_node** stack_top, int num);
void pop(list_node** stack_top);


int main(void) {
	list_node* stack_top = NULL;

	while (1) {
		char action;
		int num;

		printf("Please input command: ");
		scanf(" %c", &action);

		//Push
		if (action == 'I') {
			printf("Please input integer: ");
			scanf("%d", &num);
			push(&stack_top, num);
		}

		//Pull
		else if (action == 'O') {
			pop(&stack_top);
		}

		//Exit
		else if (action == 'E') {
			printf("Program will terminate.");
			break;
		}

		//Exception
		else {
			printf("Plese input right command!\n");
		}
	}

	return 0;
}

void push(list_node** stack_top, int num) {
	list_node* new_ptr = (list_node*)malloc(sizeof(list_node));
	new_ptr->data = num;
	if (*stack_top == NULL) {
		new_ptr->link = NULL;
	}
	else {
		new_ptr->link = *stack_top;
	}
	*stack_top = new_ptr;
}

void pop(list_node** stack_top) {
	//Exeption
	if (*stack_top == NULL) {
		printf("stack is empty!\n");
		return;
	}
	else {
		list_node* temp = *stack_top;
		*stack_top = (*stack_top)->link;
		printf("%d\n", temp->data);
		free(temp);
	}
}