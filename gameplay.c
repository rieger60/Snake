#include "gameplay.h"


bool border_limit(struct snake *head)
{
	if (head == NULL) {
		return FALSE;
	} else if (head->y == BORDER_STARTY | head->y == BORDER_HEIGHT + BORDER_STARTY |
		head->x == BORDER_STARTX | head->x == BORDER_WIDTH + BORDER_STARTX) {
		return TRUE;
	}

	return FALSE;
}

bool autocannibalism(struct snake *head, int snakey, int snakex)
{
	if (head == NULL) {
		return FALSE;
	} else {
		head = head->next;
	}

	while (head) {
		if (snakey == head->y && snakex == head->x) {
			return TRUE;
		}
		head = head->next; 
	}

	return FALSE;
}

void generate_cheese(struct food *cheese)
{
	cheese->y = (rand() % (BORDER_HEIGHT - 1)) + BORDER_STARTY + 1; 
	cheese->x = (rand() % (BORDER_WIDTH - 1)) + BORDER_STARTX + 1;

	mvprintw(cheese->y, cheese->x, ".");

}

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

void clear_window(struct food cheese)
{
	for (int i = BORDER_STARTX + 1; i < BORDER_HEIGHT + 2; i++) {
		for (int j = BORDER_STARTY + 1; j < BORDER_WIDTH + 2; j++) {
				mvprintw(i, j, " ");
		}
	}
	mvprintw(cheese.y, cheese.x, ".");
}

void print_window(struct snake *head, struct food cheese)
{
	clear_window(cheese);

	while (head) {
		mvaddch(head->y, head->x, head->body);
		head = head->next;
	}

	refresh();
}