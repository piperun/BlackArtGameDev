#ifndef ASSIGNMENTS_H_INCLUDED
#define ASSIGNMENTS_H_INCLUDED



#include "../../SDL_initalizer/headers/init.h"



// Example code from book

//randompixel.cpp
void drawPixel(SDL_Surface *surface, int x, int y, colors colors);


//rect.cpp
void drawFullRectangle(SDL_Surface *surface, int x, int y, int width, int height, colors colors);
void drawEmptyRectangle(SDL_Surface *surface, int x, int y, int width, int height, colors colors);

#endif // ASSIGNMENTS_H_INCLUDED
