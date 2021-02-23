#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "layout.h"

struct food {
	int y;
	int x;
};

struct snake {
	chtype body;
	int x;
	int y;
	struct snake *next;
};

bool border_limit(struct snake *head);
bool autocannibalism(struct snake *head, int snakey, int snakex);
void generate_cheese(struct food *cheese);
void push_to_snake(struct snake **head, int y, int x, chtype body);
void pop_from_snake(struct snake **head);
void clear_window(struct food cheese);
void print_window(struct snake *head, struct food cheese);

#endif