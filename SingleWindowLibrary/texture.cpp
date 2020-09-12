//
//  texture.cpp
//  SingleWindowLibrary
//
//  Created by Jakob Zorz on 12/09/2020.
//

#include "swl.h"
#include "SDL2_image/SDL_image.h"

Swl::texture::~texture() {
    _free();
}

void Swl::texture::_free() {
    if(_texture)
        SDL_DestroyTexture(_texture);
}

void Swl::texture::loadFromImage(const std::string path) {
    _free();
    SDL_Surface* temp_surface = IMG_Load(path.c_str());
    if_dev(!temp_surface) std::cout << "[Swl::texture::loadFromImage] Image did not load to surface!" << std::endl;
    
    w = temp_surface->w;
    h = temp_surface->h;
    
    _texture = SDL_CreateTextureFromSurface(swl._renderer, temp_surface);
    if_dev(!_texture) std::cout << "[Swl::texture::loadFromImage] Surface did not convert to texture!" << std::endl;
    
    SDL_FreeSurface(temp_surface);
}

void Swl::draw(texture& obj) {
    SDL_Rect temp_rect = {obj.x, obj.y, obj.w, obj.h};
    SDL_RenderCopy(_renderer, obj._texture, nullptr, &temp_rect);
}
