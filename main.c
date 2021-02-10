#define _DEFAULT_SOURCE

#include "layout.h"
#include "snake.h"
#include "controls.h"
#include "gameplay.h"
#include "window.h"
#include <stdlib.h>
#include <unistd.h>

//https://www.dosgamesarchive.com/play/nibbles/

int delay(int csec, bool horizontal);

int main(void)
{
	system("resize -s 31 100");
	int ch, keypress;
	int snakey = 5;
	int snakex = 5;
	chtype body;
	struct food cheese;
	bool horizontal = TRUE;

	WIN win;
	struct snake *head = NULL;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(FALSE);
	win_params(&win);
	create_box(&win);
	refresh();

	direction = right;
	bool run = TRUE;
	srand(time(0));
	generate_cheese(&cheese);
	while (run) {

		if (border_limit(head)) {
			mvprintw(head->y, head->x, "*");
			break;
		}
		if (autocannibalism(head, snakey, snakex)) {
			mvprintw(head->y, head->x, "*");
			break;
		}
		if (cheese.y == snakey && cheese.x == snakex) {
			direction(&snakey, &snakex, &body);
			push_to_snake(&head, snakey, snakex, body);
			generate_cheese(&cheese);
			print_window(head, cheese);
			continue;
		}

		timeout(0);
		ch = delay(10, horizontal);
		if (ch != ERR) {
			delay(7, horizontal);
		}

		switch(ch) {
			case KEY_UP: 
				 direction = up;
				 horizontal = FALSE;
				 break;
			case KEY_DOWN: 
				 direction = down;
				 horizontal = FALSE;
				break;
			case KEY_LEFT: 
				direction = left;
				horizontal = TRUE;
				break;
			case KEY_RIGHT: 
				direction = right;
				horizontal = TRUE;
				break;
			case 'q': run = FALSE; break;
		}
			
		direction(&snakey, &snakex, &body);
		pop_from_snake(&head);
		push_to_snake(&head, snakey, snakex, body);
		print_window(head, cheese);

	}
	delay(100, horizontal);
	endwin();

	return 0;
}

int delay(int csec, bool horizontal)
{
	int ch;

	for (int i = 0; i < csec; i++) {
		ch = getch();
		if (horizontal == TRUE) {
			if (ch == KEY_UP | ch == KEY_DOWN) {
				return ch;
			}
		} else if (horizontal == FALSE) {
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