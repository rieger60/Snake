#include "window.h"

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