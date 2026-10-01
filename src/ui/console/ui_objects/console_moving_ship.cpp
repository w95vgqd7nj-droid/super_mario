#include "console_moving_ship.hpp"

using biv::ConsoleMovingShip;

ConsoleMovingShip::ConsoleMovingShip(const Coord& top_left, const int width, const int height) 
    : MovingShip(top_left, width, height) {}

char ConsoleMovingShip::get_brush() const noexcept {
    return '=';
}