target_sources(${PROJECT_NAME}
		PRIVATE
		full_box.cpp
		enemy.cpp
		mario.cpp
		money.cpp
		jumpable_enemy.cpp
		flyable_enemy.cpp
		moving_ship.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}"
)