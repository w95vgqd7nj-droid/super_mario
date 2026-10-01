namespace biv {
    class FlyableEnemy : public RectMapMovableAdapter, public Movable, public Collisionable {
    public:
        FlyableEnemy(const Coord& top_left, const int width, const int height) 
            : RectMapMovableAdapter(top_left, width, height) {
            vspeed = 0;
            hspeed = 0.3;
        }

        Rect get_rect() const noexcept override { return {top_left, width, height}; }
        Speed get_speed() const noexcept override { return {vspeed, hspeed}; }

        void process_mario_collision(Collisionable* mario) noexcept override {
            if (mario->get_speed().v > 0) { kill(); } else { mario->kill(); }
        }

        void process_horizontal_static_collision(Rect* obj) noexcept override {
            hspeed = -hspeed;
        }

        void process_vertical_static_collision(Rect* obj) noexcept override {
        }
    };
}