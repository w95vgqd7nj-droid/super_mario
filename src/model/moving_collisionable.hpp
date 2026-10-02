#pragma once
#include "collisionable.hpp"
#include "speed.hpp"

namespace biv {
    class MovingCollisionable : public virtual Collisionable {
    public:
        virtual Speed get_speed() const noexcept = 0;
        virtual ~MovingCollisionable() = default;
    };
}