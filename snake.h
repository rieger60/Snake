#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include "layout.h"

struct snake {
	chtype body;
	int x;
	int y;
	struct snake *next;
};

void push_to_snake(struct snake **head, int y, int x, chtype body);
void pop_from_snake(struct snake **head);

#endif