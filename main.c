#define _DEFAULT_SOURCE

#include "layout.h"
#include "controls.h"
#include "gameplay.h"
#include <unistd.h>
#include <ctype.h>

struct snake *head = NULL;
struct food cheese;
chtype body;
int snakey = 5;
int snakex = 5;
int ch;
bool horizontal = true;
bool run = true;


void init_game(void);
int delay(int csec, bool horizontal);
bool check_game(void);
bool eat_cheese();
void change_direction(void);
void update_window(void);

int main(void)
{
	init_game();

	direction = right;
	srand(time(0));
	generate_cheese(&cheese);

	while (true) {

		if (check_game())
			break;

		if (eat_cheese())
			continue;

		ch = delay(10, horizontal);
		if (ch != ERR) {
			delay(7, horizontal);
		}
		if (tolower(ch) == 'q')
			break;

		change_direction();
		update_window();
	}
	delay(100, horizontal);
	endwin();

	return 0;
}

void init_game(void)
{
	WIN win;

	system("resize -s 31 100");
	initscr();
	raw();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	noecho();
	curs_set(false);
	win_params(&win);
	create_box(&win);
	refresh();

}

int delay(int csec, bool horizontal)
{
	int ch;

	for (int i = 0; i < csec; i++) {
		ch = getch();
		if (horizontal == true) {
			if (ch == KEY_UP | ch == KEY_DOWN) {
				return ch;
			}
		} else if (horizontal == false) {
			if (ch == KEY_LEFT | ch == KEY_RIGHT) {
				return ch;
			}
		}
		if (ch == 'q') {
			return ch;
		}
		flushinp();
		usleep(10000);
	}

	return ERR;
}

bool check_game(void)
{
	if (border_limit(head) || autocannibalism(head, snakey, snakex)) {
		mvprintw(head->y, head->x, "*");
		return true;
	}

	return false;

}

bool eat_cheese()
{

	if (cheese.y == snakey && cheese.x == snakex) {
		direction(&snakey, &snakex, &body);
		push_to_snake(&head, snakey, snakex, body);
		generate_cheese(&cheese);
		print_window(head, cheese);
		return true;
		}
	return false;
}

void change_direction(void)
{
	switch(ch) {
		case KEY_UP: 
			 direction = up;
			 horizontal = false;
			 break;
		case KEY_DOWN: 
			 direction = down;
			 horizontal = false;
			break;
		case KEY_LEFT: 
			direction = left;
			horizontal = true;
			break;
		case KEY_RIGHT: 
			direction = right;
			horizontal = true;
			break;
	}
}

void update_window(void)
{
	direction(&snakey, &snakex, &body);
	pop_from_snake(&head);
	push_to_snake(&head, snakey, snakex, body);
	print_window(head, cheese);
}