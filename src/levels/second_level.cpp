#include "second_level.hpp"
#include "third_level.hpp"

using biv::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
    init_data();
}

bool SecondLevel::is_final() const noexcept {
    return false;
}

biv::GameLevel* SecondLevel::get_next() {
    if (!next) {
        clear_data();
        next = new biv::ThirdLevel(ui_factory);
    }
    return next;
}

void SecondLevel::init_data() {
    ui_factory->create_mario({39, 10}, 3, 3);

    ui_factory->create_ship({10, 25}, 40, 2);
    ui_factory->create_enemy({20, 5}, 3, 2);
    ui_factory->create_enemy({35, 5}, 3, 2);

    ui_factory->create_box({50, 26}, 1, 1);
    ui_factory->create_box({84, 26}, 1, 1);

    ui_factory->create_moving_ship({55, 25}, 15, 2);

    ui_factory->create_ship({85, 25}, 45, 2);
    ui_factory->create_jumpable_enemy({90, 10}, 3, 2);
    ui_factory->create_jumpable_enemy({105, 10}, 3, 2);
    ui_factory->create_enemy({100, 5}, 3, 2);
    ui_factory->create_enemy({120, 5}, 3, 2);

    ui_factory->create_flyable_enemy({20, 12}, 3, 2);
    ui_factory->create_flyable_enemy({120, 17}, 3, 2);

    ui_factory->create_ship({140, 20}, 10, 7);
    ui_factory->create_jumpable_enemy({142, 5}, 3, 2);

    ui_factory->create_ship({160, 25}, 40, 2);
    ui_factory->create_enemy({170, 5}, 3, 2);
    ui_factory->create_enemy({180, 5}, 3, 2);

    ui_factory->create_ship({210, 20}, 15, 7);
}