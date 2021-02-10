#include "controls.h"

void left(int *snakey, int *snakex, chtype *body)
{
	(*snakex)--;
	*body = ACS_CKBOARD;
}

void right(int *snakey, int *snakex, chtype *body)
{
	(*snakex)++;
	*body = ACS_CKBOARD;
}

void up(int *snakey, int *snakex, chtype *body)
{
	(*snakey)--;
	*body = ACS_CKBOARD;
}

void down(int *snakey, int *snakex, chtype *body)
{
	(*snakey)++;
	*body = ACS_CKBOARD;
}