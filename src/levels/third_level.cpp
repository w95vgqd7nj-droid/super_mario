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

    // Остров 1
    ui_factory->create_ship({40, 25}, 20, 2);
    ui_factory->create_box({60, 26}, 1, 1); // Стопор для левого края пропасти

    // Скейт 1
    ui_factory->create_moving_ship({65, 25}, 8, 2);
    ui_factory->create_flyable_enemy({75, 16}, 3, 2);

    // Остров 2
    ui_factory->create_box({89, 26}, 1, 1); // Стопор для правого края пропасти
    ui_factory->create_ship({90, 25}, 15, 2);
    ui_factory->create_jumpable_enemy({95, 10}, 3, 2);
    ui_factory->create_box({105, 26}, 1, 1); // Стопор для следующей пропасти

    // Скейт 2 и 3
    ui_factory->create_moving_ship({110, 25}, 8, 2);
    ui_factory->create_flyable_enemy({122, 12}, 3, 2);

    // ЛИШНИЙ МИНУС УБРАН! Эти два скейта будут отталкиваться друг от друга.

    ui_factory->create_moving_ship({135, 25}, 8, 2);

    // Финальный остров
    ui_factory->create_box({154, 26}, 1, 1); // Стопор перед островом
    ui_factory->create_ship({155, 20}, 25, 7);
    ui_factory->create_jumpable_enemy({158, 5}, 3, 2);
    ui_factory->create_enemy({170, 5}, 3, 2);
}