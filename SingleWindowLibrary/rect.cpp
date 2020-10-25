//
//  draw.cpp
//  SingleWindowLibrary
//
//  Created by Jakob Zorz on 12/09/2020.
//

#include "swl.h"
#include <SDL2_gfx/SDL2_gfxPrimitives.h>

void Swl::draw(rect& obj) {
    if(obj.corner_radius) {
        if(obj.filled) {
            filledPieRGBA(swl._renderer, obj.x + obj.corner_radius, obj.y + obj.corner_radius, obj.corner_radius, 180, 270, _draw_color.r, _draw_color.g, _draw_color.b, 255);
            filledPieRGBA(swl._renderer, obj.x + obj.w - obj.corner_radius, obj.y + obj.corner_radius, obj.corner_radius, 270, 0, _draw_color.r, _draw_color.g, _draw_color.b, 255);
            filledPieRGBA(swl._renderer, obj.x + obj.corner_radius, obj.y + obj.h - obj.corner_radius, obj.corner_radius, 90, 180, _draw_color.r, _draw_color.g, _draw_color.b, 255);
            filledPieRGBA(swl._renderer, obj.x + obj.w - obj.corner_radius, obj.y + obj.h - obj.corner_radius, obj.corner_radius, 0, 90, _draw_color.r, _draw_color.g, _draw_color.b, 255);
            draw_rect(obj.x + obj.corner_radius, obj.y, obj.w - obj.corner_radius * 2, obj.corner_radius);
            draw_rect(obj.x + obj.corner_radius, obj.y + obj.h - obj.corner_radius, obj.w - obj.corner_radius * 2, obj.corner_radius);
            draw_rect(obj.x, obj.y + obj.corner_radius, obj.w, obj.h - obj.corner_radius * 2);
        }
        else {
            
        }
    }
    else {
        if(obj.filled)
            SDL_RenderFillRect(_renderer, (SDL_Rect*)((void*)&obj));
        else
            SDL_RenderDrawRect(_renderer, (SDL_Rect*)((void*)&obj));
    }
}

void Swl::draw(rect_c& obj) {
    swl.pushDrawColor(obj.c);
    draw(*(rect*)(void*)&obj);
    swl.popDrawColor();
}

void Swl::draw_rect(int x, int y, int w, int h, bool fill) {
    SDL_Rect temp_rect = {x, y, w, h};
    if(fill)
        SDL_RenderFillRect(_renderer, &temp_rect);
    else
        SDL_RenderDrawRect(_renderer, &temp_rect);
}

void Swl::draw_rect(int x, int y, int w, int h, color c, bool fill) {
    swl.pushDrawColor(c);
    SDL_Rect temp_rect = {x, y, w, h};
    if(fill)
        SDL_RenderFillRect(_renderer, &temp_rect);
    else
        SDL_RenderDrawRect(_renderer, &temp_rect);
    swl.popDrawColor();
}
