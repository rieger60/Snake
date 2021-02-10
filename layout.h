#ifndef LAYOUT_H
#define LAYOUT_H

#include <ncurses.h>

#define BORDER_STARTY 2
#define BORDER_STARTX 2
#define BORDER_HEIGHT 27
#define BORDER_WIDTH 96

typedef struct _win_border_struct {
	chtype ls, rs, ts, bs,
		   tl, tr, bl, br;
} WIN_BORDER;

typedef struct _WIN_struct {
	int startx, starty;
	int height, width;
	WIN_BORDER border;
} WIN;

void win_params(WIN *p_win);
void create_box(WIN *p_win);

#endif