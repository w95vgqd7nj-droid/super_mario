#include "linux_keyboard.hpp"
#include <ncurses.h>

using biv::LinuxKeyboard;

biv::UserInput LinuxKeyboard::get_user_input() {
    int c;
    biv::UserInput current_action = prev_input;

    while ((c = getch()) != ERR) {
        switch (c) {
            case 'd':
            case 'D':
            case KEY_LEFT:
                current_action = UserInput::MAP_LEFT;
                break;

            case 'a':
            case 'A':
            case KEY_RIGHT:
                current_action = UserInput::MAP_RIGHT;
                break;

            case 's':
            case 'S':
            case KEY_DOWN:
                current_action = UserInput::NO_INPUT;
                break;

            case ' ':
            case KEY_UP:
                return UserInput::MARIO_JUMP;

            case 'q':
            case 'Q':
            case 27:
                return UserInput::EXIT;
        }
    }

    prev_input = current_action;
    return current_action;
}

void LinuxKeyboard::on() {
    prev_input = biv::UserInput::NO_INPUT;
}

void LinuxKeyboard::off() {
    prev_input = UserInput::NO_INPUT;
}