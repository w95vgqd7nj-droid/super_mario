#pragma once

#include "ship.hpp"
#include "movable.hpp"
#include "collisionable.hpp"

namespace biv {
    class MovingShip : public Ship, public Movable, public Collisionable {
    private:
        double left_bound;
        double right_bound;
    public:
        MovingShip(const Coord& top_left, const int width, const int height);

        Rect get_rect() const noexcept override;
        Speed get_speed() const noexcept override;

        void process_mario_collision(Collisionable* mario) noexcept override;
        void process_horizontal_static_collision(Rect* obj) noexcept override;
        void process_vertical_static_collision(Rect* obj) noexcept override;

        void move_vertically() noexcept override;
        void move_horizontally() noexcept override;
    };
}