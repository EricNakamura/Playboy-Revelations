cmake_minimum_required (VERSION 3.8)
add_executable (PlayboyRevelations "PlayboyRevelations.cpp" "Player/Player.cpp" "Player/Atributes.cpp")


target_include_directories(PlayboyRevelations PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(PlayboyRevelations PRIVATE ${CMAKE_SOURCE_DIR}/library/sfml-graphics.lib)
target_link_libraries(PlayboyRevelations PRIVATE ${CMAKE_SOURCE_DIR}/library/sfml-audio.lib)
target_link_libraries(PlayboyRevelations PRIVATE ${CMAKE_SOURCE_DIR}/library/sfml-network.lib)
target_link_libraries(PlayboyRevelations PRIVATE ${CMAKE_SOURCE_DIR}/library/sfml-system.lib)
target_link_libraries(PlayboyRevelations PRIVATE ${CMAKE_SOURCE_DIR}/library/sfml-window.lib)