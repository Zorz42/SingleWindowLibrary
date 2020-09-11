/*
 uncomment this enable developer mode which makes it easier to look for mistakes, but
 will cost some performance, because it will print to stdout
 */
//#define SWL_DEVEL

#include "swl.h"

void preInit() {
    /* this runs before window is being creates and is used to pass window parameters */
}

void postInit() {
    /* this function is ran after window and renderer is created and is used to create and load images, textures, surfaces, fonts... */
}
