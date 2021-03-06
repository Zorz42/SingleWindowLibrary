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
    _window = SDL_CreateWindow(window_caption.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, _window_flags);
    if_dev(!_window)
        std::cout << "[Swl::init] Failed to create window!" << std::endl;
    
    if(_window_flags & SDL_WINDOW_FULLSCREEN_DESKTOP) {
        SDL_DisplayMode display_mode;
        if_dev(SDL_GetCurrentDisplayMode(0, &display_mode)) std::cout << "[Swl::init] Could not get display mode!" << std::endl;
        window_width = display_mode.w;
        window_height = display_mode.h;
    }
    
    _renderer = SDL_CreateRenderer(_window, -1, _renderer_flags);
    if_dev(!_renderer)
        std::cout << "[Swl::init] Failed to create renderer!" << std::endl;
    
#define IMG_FLAGS IMG_INIT_PNG
    int result = IMG_Init(IMG_FLAGS);
    if_dev(!(result & IMG_FLAGS)) std::cout << "[Swl::init] SDL_image failed to initialize!" << std::endl;
    
    result = TTF_Init();
    if_dev(result == -1) std::cout << "[Swl::init] SDL_ttf failed to initialize!" << std::endl;
    
    if(load_font) {
        _font = TTF_OpenFont(font_path.c_str(), font_size);
        if_dev(!_font)
            std::cout << "[Swl::init] Failed to load font!" << std::endl;
    }
}

void Swl::quit() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
    IMG_Quit();
}

void Swl::stop() {
    _running = false;
}

int main(int argv, char** args) {
    if_dev(true) std::cout << "Developer mode enabled. This text should not show up in released app, only in developer testing!" << std::endl;
    if_dev(SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "[main] SDL failed to initialize!" << std::endl;
    preInit();
    swl.init();
    postInit();
    swl.runScenes();
    swl.quit();
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

void Swl::goFullscreen() {
    _window_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
}

void Swl::enableVsync() {
    _renderer_flags |= SDL_RENDERER_PRESENTVSYNC;
}
