#include "swl.h"
#include <iostream>

void main();
Swl::scene main_scene(&main);

void preInit() {
    /* This runs before window is being creates and is used to pass window parameters */
}

void postInit() {
    /* This function is ran after window and renderer are created and is used to create or load images, textures, surfaces, fonts... */
    
    swl.switchScene(main_scene);
}

void main() {
}
