#include "swl.h"

void main();
Swl::scene main_scene(&main);

Swl::texture text;

void preInit() {
    /* This runs before window is being creates and is used to pass window parameters. */
    
    /*
     Uncomment those to set specific parameters. These are default values.
     */
    //swl.window_width = 640;
    //swl.window_height = 400;
    //swl.window_caption = "Untitled";
    //swl.load_font = false;
    //swl.font_size = 32;
    
    // this library already comes with arial.ttf
    //swl.font_path = "/path/to/font.ttf"
}

void postInit() {
    /* This function is ran after window and renderer are created and is used to create or load images, textures, surfaces, fonts... */

    swl.switchScene(main_scene);
}

void main() {
    /* this is the main loop which executes every frame */
}
