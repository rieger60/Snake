#ifndef CONTROLS_H
#define CONTROLS_H

#include "layout.h"

void (*direction)(int *snakey, int *snakex, chtype *body);
void left(int *snakey, int *snakex, chtype *body);
void right(int *snakey, int *snakex, chtype *body);
void up(int *snakey, int *snakex, chtype *body);
void down(int *snakey, int *snakex, chtype *body);

#endif