#include "ship.hpp"
#include "movable.hpp"
#include "collisionable.hpp"

namespace biv {
    class MovingShip : public Ship, public Movable, public Collisionable {
    public:
        MovingShip(const Coord& top_left, const int width, const int height) 
            : Ship(top_left, width, height) {
            hspeed = 0.15;
            vspeed = 0;
        }

        Speed get_speed() const noexcept override { return {vspeed, hspeed}; }
        
        void process_mario_collision(Collisionable* mario) noexcept override {
        }

        void process_horizontal_static_collision(Rect* obj) noexcept override {
            hspeed = -hspeed;
        }

        void process_vertical_static_collision(Rect* obj) noexcept override {
        }
    };
}