//
//  core.cpp
//  SingleWindowLibrary
//
//  Created by Jakob Zorz on 11/09/2020.
//

#include "swl.h"

#undef main

int main() {
    preInit();
    // init sdl
    postInit();
    // main loop
    return 0;
}
