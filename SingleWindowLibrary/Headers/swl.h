//
//  swl.h
//  SingleWindowLibrary
//
//  Created by Jakob Zorz on 11/09/2020.
//

#ifndef swl_h
#define swl_h

#include <iostream>
#include "SDL2/SDL.h"
#include "settings.h"

void preInit();
void postInit();

int main(int argv, char** args);

class Swl {
public:
    struct color {
        uint8_t r, g, b;
    };
    
    struct scene {
        scene(void (*loopFn)() = nullptr, void (*eventFn)(SDL_Event&) = nullptr, void (*initFn)() = nullptr, void (*closeFn)() = nullptr);
        void (*loopFunction)();
        void (*eventFunction)(SDL_Event&);
        void (*initFunction)();
        void (*closeFunction)();
        color background_color{0, 0, 0};
    };
    
    struct rect {
        int x, y, w, h;
        bool filled{true};
    };
    
    struct rect_c : rect {
        color c;
    };
    
    class texture;
    void draw(texture& obj);
    class texture {
    public:
        ~texture();
        void loadFromImage(const std::string path);
        unsigned short x{0}, y{0};
    private:
        void _free();
        SDL_Texture* _texture{nullptr};
        unsigned short w, h;
        friend void Swl::draw(texture& obj);
    };
    
    unsigned short window_width{640}, window_height{400};
    std::string window_caption{"Untitled"};
    
    void switchScene(scene& scene_);
    
    void setDrawColor(color draw_color);
    
    void pushDrawColor(color draw_color);
    void popDrawColor();
    
    void setPixel(int x, int y, color pixel_color);
    void setPixel(int x, int y);
    
    void draw(rect& obj);
    void draw(rect_c& obj);
    
    void draw_rect(int x, int y, int w, int h, bool fill=true);
    void draw_rect(int x, int y, int w, int h, color c, bool fill=true);
    
private:
    void runScenes();
    SDL_Window* _window{nullptr};
    SDL_Renderer* _renderer{nullptr};
    
    scene* _current_scene{nullptr};
    
    void init();
    void quit();
    friend int main(int argv, char** args);
    
    color _draw_color, _prev_draw_color;
};

inline Swl swl;

#define main _swl_main

#ifdef SWL_DEVEL
#define if_dev(condition) if(condition)
#else
#define if_dev(condition) if(false)
#endif

#endif /* swl_h */
