//
//  core.cpp
//  SingleWindowLibrary
//
//  Created by Jakob Zorz on 11/09/2020.
//

#include "swl.h"

#include "SDL2_image/SDL_image.h"

#undef main

void Swl::init() {
    _window = SDL_CreateWindow(window_caption.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
    if_dev(!_window)
        std::cout << "[Swl::init] Failed to create window!" << std::endl;
    
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if_dev(!_renderer)
        std::cout << "[Swl::init] Failed to create renderer!" << std::endl;
    
#define IMG_FLAGS IMG_INIT_PNG
    if_dev(!(IMG_Init(IMG_FLAGS) & IMG_FLAGS)) std::cout << "SDL_image failed to initialize!" << std::endl;
}

int main(int argv, char** args) {
    if_dev(true) std::cout << "Developer mode enabled. This text should not show up in released app, only in developer testing!" << std::endl;
    if_dev(SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "[main] SDL failed to initialize!" << std::endl;
    preInit();
    swl.init();
    postInit();
    swl.runScenes();
    return 0;
}

void Swl::setDrawColor(color draw_color) {
    _draw_color = draw_color;
    SDL_SetRenderDrawColor(_renderer, draw_color.r, draw_color.g, draw_color.b, 255);
}

void Swl::pushDrawColor(color draw_color) {
    _prev_draw_color = _draw_color;
    setDrawColor(draw_color);
}

void Swl::popDrawColor() {
    setDrawColor(_prev_draw_color);
}

void Swl::setPixel(int x, int y, color pixel_color) {
    pushDrawColor(pixel_color);
    setPixel(x, y);
    popDrawColor();
}

void Swl::setPixel(int x, int y) {
    SDL_RenderDrawPoint(_renderer, x, y);
}
