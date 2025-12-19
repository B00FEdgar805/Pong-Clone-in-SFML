cmake_minimum_required(VERSION 3.16)
project(Pong LANGUAGES CXX)

# ---- C++ standard ----
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- Your sources ----
add_executable(${PROJECT_NAME}
    main.cpp
    Game.cpp
    Paddle.cpp
    Game.hpp
    Paddle.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# ---- Pull SFML 2.6.2 ----
include(FetchContent)

# Speed up SFML build
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC      OFF CACHE BOOL "" FORCE)

FetchContent_Declare(sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.2
)
FetchContent_MakeAvailable(sfml)

# ---- Link SFML (works whether SFML exposes SFML:: or sfml- targets) ----
if (TARGET SFML::graphics)
    target_link_libraries(${PROJECT_NAME} PRIVATE SFML::graphics SFML::window SFML::system)
elseif (TARGET sfml-graphics)
    target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
else()
    message(FATAL_ERROR "SFML targets not found. FetchContent added SFML, but no known targets were created.")
endif()

# ---- Copy Assets/ next to the executable ----
set(ASSETS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Assets")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${ASSETS_DIR}"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/Assets"
    COMMENT "Copying Assets/ to output directory"
)
