#include "moving_ship.hpp"

using biv::MovingShip;

struct RectHacker : public biv::Rect {
    static void ride_skateboard(biv::Collisionable* mario, double dx, double ship_y) {
        if (auto* mario_rect = dynamic_cast<biv::Rect*>(mario)) {
            auto* hacked = static_cast<RectHacker*>(mario_rect);
            double mario_bottom = hacked->top_left.y + hacked->height;
            if (mario_bottom >= ship_y && mario_bottom <= ship_y + 1.5) {
                hacked->top_left.x += dx;
            }
        }
    }
};

MovingShip::MovingShip(const Coord& top_left, const int width, const int height)
    : Ship(top_left, width, height) {
    hspeed = 0.15;
    vspeed = 0;
}

biv::Rect MovingShip::get_rect() const noexcept { return {top_left, width, height}; }
biv::Speed MovingShip::get_speed() const noexcept { return {vspeed, hspeed}; }

void MovingShip::process_mario_collision(Collisionable* mario) noexcept {
    if (mario->get_speed().v >= 0) {
        RectHacker::ride_skateboard(mario, hspeed, top_left.y);
    }
}

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