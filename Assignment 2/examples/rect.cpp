#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include "../headers/assignments.h"
#include "../../SDL_initalizer/headers/init.h"

// TODO: Fix RGB values

void drawFullRectangle(SDL_Surface *surface, int x, int y, int width, int height, colors colors);
void drawEmptyRectangle(SDL_Surface *surface, int x, int y, int width, int height, colors colors);

void drawFullRectangle(SDL_Surface *surface, int x, int y, int width, int height, colors colors)
{
    Uint32 color;

    color = SDL_MapRGB(surface->format, colors.red, colors.green, colors.blue);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_FillRect(surface, &rect, color);
}


// TODO: Clean this crappy version, into a more readable version.
void drawEmptyRectangle(SDL_Surface *surface, int x, int y, int width, int height, colors colors)
{
    /*
    int temp, mini;
    mini = 1;
    for(int i = 0; i < 4; i += 1)
        switch(i):
        case 1:
            temp = height;
            height = mini;
            break;
        case 2:
            y = y + temp -1;

            break;

            drawFullRectangle(surface, x, y, width, minheight, r, g, b);
    */
    drawFullRectangle(surface, x, y, width, 1, colors);
    drawFullRectangle(surface, x, y + height - 1, width, 1, colors);
    drawFullRectangle(surface, x, y, 1, height, colors);
    drawFullRectangle(surface, x+width-1, y, 1, height, colors);

}
