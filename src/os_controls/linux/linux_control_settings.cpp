#include "linux_control_settings.hpp"

#include <ncurses.h>

using biv::LinuxControlSettings;

LinuxControlSettings::LinuxControlSettings(const int height, const int width)
: height(height), width(width) {}

void LinuxControlSettings::init() {
	initscr();

	ESCDELAY = 0;

	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	curs_set(0);
	getmaxyx(stdscr, height, width);
}

void LinuxControlSettings::set_cursor_start_position() {
	move(0, 0);
}
