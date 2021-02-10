#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"
#include "layout.h"

struct food {
	int y;
	int x;
};

bool border_limit(struct snake *head);
bool autocannibalism(struct snake *head, int snakey, int snakex);
void generate_cheese(struct food *cheese);

#endif