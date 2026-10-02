#include "moving_ship.hpp"

using biv::MovingShip;

MovingShip::MovingShip(const Coord& top_left, const int width, const int height)
    : Movable(top_left, width, height, 0.0f, 0.15f) {}

biv::Rect MovingShip::get_rect() const noexcept { return {top_left, width, height}; }
biv::Speed MovingShip::get_speed() const noexcept { return {vspeed, hspeed}; }

void MovingShip::process_mario_collision(Collisionable* mario) noexcept {}

void MovingShip::process_horizontal_static_collision(Rect* obj) noexcept {
    if (static_cast<Rect*>(this) == obj) return;

    hspeed = -hspeed;
    top_left.x += hspeed;
}

void MovingShip::process_vertical_static_collision(Rect* obj) noexcept {}
void MovingShip::move_vertically() noexcept {}

void MovingShip::move_horizontally() noexcept {
    top_left.x += hspeed;
}

// Методы для работы скроллинга камеры (MapMovable)
void MovingShip::move_map_left() noexcept {
    top_left.x -= 1;
}

void MovingShip::move_map_right() noexcept {
    top_left.x += 1;
}