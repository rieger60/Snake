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