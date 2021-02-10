#include "layout.h"

void win_params(WIN *p_win)
{
	p_win->height = BORDER_HEIGHT;
	p_win->width = BORDER_WIDTH;
	p_win->starty = BORDER_STARTY;
	p_win->startx = BORDER_STARTX;

	p_win->border.ls = ACS_VLINE;
	p_win->border.rs = ACS_VLINE;
	p_win->border.ts = ACS_HLINE;
	p_win->border.bs = ACS_HLINE;
	p_win->border.tl = ACS_ULCORNER;
	p_win->border.tr = ACS_URCORNER;
	p_win->border.bl = ACS_LLCORNER;
	p_win->border.br = ACS_LRCORNER;
}

void create_box(WIN *p_win)
{
	int x, y, w, h;

	x = p_win->startx;
	y = p_win->starty;
	w = p_win->width;
	h = p_win->height;

	mvaddch(y, x, p_win->border.tl);
	mvaddch(y, x + w, p_win->border.tr);
	mvaddch(y + h, x, p_win->border.bl);
	mvaddch(y + h, x + w, p_win->border.br);
	mvhline(y, x + 1, p_win->border.ts, w - 1);
	mvhline(y + h, x + 1, p_win->border.bs, w - 1);
	mvvline(y + 1, x, p_win->border.ls, h - 1);
	mvvline(y + 1, x + w, p_win->border.rs, h - 1);

	refresh();

}