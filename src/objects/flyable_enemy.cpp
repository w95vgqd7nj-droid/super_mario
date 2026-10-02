#include "flyable_enemy.hpp"

using biv::FlyableEnemy;

FlyableEnemy::FlyableEnemy(const Coord& top_left, const int width, const int height)
    : RectMapMovableAdapter(top_left, width, height) {
    vspeed = 0;
    hspeed = 0.3;
}

biv::Rect FlyableEnemy::get_rect() const noexcept { return {top_left, width, height}; }
biv::Speed FlyableEnemy::get_speed() const noexcept { return {vspeed, hspeed}; }

void FlyableEnemy::process_mario_collision(Collisionable* mario) noexcept {
    if (mario->get_speed().v > 0) { kill(); } else { mario->kill(); }
}

void FlyableEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
    hspeed = -hspeed;
    top_left.x += hspeed;
}

void FlyableEnemy::process_vertical_static_collision(Rect* obj) noexcept {}
void FlyableEnemy::move_vertically() noexcept {}

void FlyableEnemy::move_horizontally() noexcept {
    top_left.x += hspeed;
    if (top_left.x > 195 || top_left.x < 5) {
        hspeed = -hspeed;
    }
}