#pragma once

#include "movable.hpp"
#include "map_movable.hpp"
#include "moving_collisionable.hpp"

namespace biv {
    class MovingShip : public Movable, public MapMovable, public MovingCollisionable {
    public:
        MovingShip(const Coord& top_left, const int width, const int height);

        Rect get_rect() const noexcept override;
        Speed get_speed() const noexcept override;

        void process_mario_collision(Collisionable* mario) noexcept override;
        void process_horizontal_static_collision(Rect* obj) noexcept override;
        void process_vertical_static_collision(Rect* obj) noexcept override;

        void move_vertically() noexcept override;
        void move_horizontally() noexcept override;

        void move_map_left() noexcept override;
        void move_map_right() noexcept override;
    };
}