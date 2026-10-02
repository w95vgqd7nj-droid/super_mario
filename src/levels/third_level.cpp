#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
    init_data();
}

bool ThirdLevel::is_final() const noexcept {
    return true;
}

biv::GameLevel* ThirdLevel::get_next() {
    return nullptr;
}

void ThirdLevel::init_data() {
    ui_factory->create_mario({45, 10}, 3, 3);

    ui_factory->create_ship({40, 25}, 20, 2);
    ui_factory->create_enemy({45, 5}, 3, 2);
    ui_factory->create_jumpable_enemy({52, 10}, 3, 2);

    ui_factory->create_moving_ship({60, 25}, 10, 2);

    ui_factory->create_flyable_enemy({70, 16}, 3, 2);
    ui_factory->create_flyable_enemy({85, 12}, 3, 2);
    ui_factory->create_flyable_enemy({95, 17}, 3, 2);

    ui_factory->create_ship({105, 25}, 60, 2);

    ui_factory->create_jumpable_enemy({107, 10}, 3, 2);

    ui_factory->create_enemy({120, 5}, 3, 2);
    ui_factory->create_jumpable_enemy({135, 10}, 3, 2);
    ui_factory->create_enemy({150, 5}, 3, 2);

    ui_factory->create_ship({170, 20}, 15, 7);
}