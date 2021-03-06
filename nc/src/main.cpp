#include "registering_enum.h"
#include "game.h"

#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>

#define DEBUG 0

using namespace std;

pair<int,int> start_ncurses(void);
void end_ncurses(void);

int main(int argc, char* argv[])
{
	int num_discs = 5;
	int num_pawns = 3;

	// Parse parameters
	int c;
	while ((c = getopt(argc, argv, "d:p:")) != -1) {
		switch (c) {
			case 'd':
			if (optarg) num_discs = atoi(optarg);
			break;

			case 'p':
			if (optarg) num_pawns = atoi(optarg);
			break;
		}
	}

	pair<int, int> screen_size;
	screen_size = start_ncurses();

	Game* game = NULL;
	game = new Game(screen_size);

	if (game == NULL) {
		printw("Could not start game.");
		 if(DEBUG) fprintf(stderr, "[%p] game variable is null.", (void*) game);
	}
	else {
		game->loop();
		delete(game);
		game = NULL;
	}

	end_ncurses();

	return 0;
}

pair<int, int> start_ncurses(void)
{
	initscr();
	cbreak();
	noecho();

	// Get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	if (has_colors()) {
		start_color();

		if (can_change_color()) {

			//init_color(color, 0~999, 0~999, 0~999);
			init_color(COLOR_BLACK  ,   0,   0,   0);
			init_color(COLOR_RED    , 999,   0,   0);
			init_color(COLOR_GREEN  ,   0, 999,   0);
			init_color(COLOR_YELLOW , 999, 999,   0);
			init_color(COLOR_BLUE   ,   0,   0, 999);
			init_color(COLOR_MAGENTA, 999,   0, 999);
			init_color(COLOR_CYAN   , 500, 500, 500);
			init_color(COLOR_WHITE  , 999, 999, 999);
		}

		//init_pair(#color_pair, Foreground, Background);
		init_pair(Color::Foreground_White,  COLOR_WHITE  , COLOR_BLACK  );
		init_pair(Color::Foreground_Red,    COLOR_RED    , COLOR_BLACK  );
		init_pair(Color::Foreground_Green,  COLOR_GREEN  , COLOR_BLACK  );
		init_pair(Color::Foreground_Blue,   COLOR_BLUE   , COLOR_BLACK  );
		init_pair(Color::Foreground_Yellow, COLOR_YELLOW , COLOR_BLACK  );
		init_pair(Color::Foreground_Purple, COLOR_MAGENTA, COLOR_BLACK  );
		init_pair(Color::Foreground_Black,  COLOR_CYAN   , COLOR_BLACK  );
		init_pair(Color::Background_Black,  COLOR_CYAN   , COLOR_CYAN   );
		init_pair(Color::Background_White,  COLOR_WHITE  , COLOR_WHITE  );
		init_pair(Color::Background_Red,    COLOR_RED    , COLOR_RED    );
		init_pair(Color::Background_Green,  COLOR_GREEN  , COLOR_GREEN  );
		init_pair(Color::Background_Blue,   COLOR_BLUE   , COLOR_BLUE   );
		init_pair(Color::Background_Yellow, COLOR_YELLOW , COLOR_YELLOW );
		init_pair(Color::Background_Purple, COLOR_MAGENTA, COLOR_MAGENTA);
	}
	else {
		printw("Terminal does not support color");
		getch();
	}

	return make_pair(xMax, yMax);
}

void end_ncurses()
{
	endwin();

	return ;
}
