#pragma once

#include "moving_ship.hpp"
#include "console_ui_obj.hpp"

namespace biv {
    class ConsoleMovingShip : public MovingShip, public ConsoleUIObject {
    public:
        ConsoleMovingShip(const Coord& top_left, const int width, const int height);

        char get_brush() const noexcept override;

        int get_left() const noexcept override { return static_cast<int>(this->get_rect().get_left()); }
        int get_right() const noexcept override { return static_cast<int>(this->get_rect().get_right()); }
        int get_top() const noexcept override { return static_cast<int>(this->get_rect().get_top()); }
        int get_bottom() const noexcept override { return static_cast<int>(this->get_rect().get_bottom()); }

        int get_height() const noexcept override { return static_cast<int>(this->get_rect().get_bottom() - this->get_rect().get_top()); }
    };
}