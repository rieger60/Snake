#include "snake.h"

void push_to_snake(struct snake **head, int y, int x, chtype body)
{
	struct snake *new_snake;

	new_snake = malloc(sizeof(struct snake));
	if (new_snake == NULL) {
		printf("Error: malloc failed in %s", __func__);
		exit(EXIT_FAILURE);

	}

	new_snake->body = body;
	new_snake->y = y;
	new_snake->x = x;
	new_snake->next = *head;
	*head = new_snake;

	//mvaddch(new_snake->y, new_snake->x, new_snake->body);
}

void pop_from_snake(struct snake **head)
{
	struct snake *tail = *head;

	while (tail != NULL) {
		if (tail->next == NULL) {
			*head = tail->next;
			//mvprintw(tail->y, tail->x, " ");
			free(tail);
			break;
		}
		head = &tail->next;
		tail = tail->next;
	}
}