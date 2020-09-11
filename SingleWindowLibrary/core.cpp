//
//  core.cpp
//  SingleWindowLibrary
//
//  Created by Jakob Zorz on 11/09/2020.
//

#include "swl.h"

#undef main

void Swl::init() {
    _window = SDL_CreateWindow(window_caption.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
    if_dev(!_window)
        std::cout << "Failed to create window!" << std::endl;
    
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if_dev(!_renderer)
        std::cout << "Failed to create renderer!" << std::endl;
}

int main() {
    if_dev(true) std::cout << "Developer mode enabled. This text should not show up in released app, only in developer testing!" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    preInit();
    swl.init();
    postInit();
    swl.runScenes();
    return 0;
}

void Swl::setDrawColor(Swl::color draw_color) {
    _draw_color = draw_color;
    SDL_SetRenderDrawColor(_renderer, draw_color.r, draw_color.g, draw_color.b, 255);
}

void Swl::pushDrawColor(Swl::color draw_color) {
    _prev_draw_color = _draw_color;
    setDrawColor(draw_color);
}

void Swl::popDrawColor() {
    setDrawColor(_prev_draw_color);
}

void Swl::setPixel(int x, int y, Swl::color pixel_color) {
    pushDrawColor(pixel_color);
    setPixel(x, y);
    popDrawColor();
}

void Swl::setPixel(int x, int y) {
    SDL_RenderDrawPoint(_renderer, x, y);
}
