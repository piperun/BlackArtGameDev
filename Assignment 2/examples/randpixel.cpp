#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include "../headers/assignments.h"
#include "../../SDL_initalizer/headers/init.h"

void drawPixel(SDL_Surface *surface, int x, int y, colors colors);




void drawPixel(SDL_Surface *surface, int x, int y, colors colors)
{
    if(SDL_MUSTLOCK(surface))
        if(SDL_LockSurface(surface) < 0)
            return;

    if(x >= surface->w || x < 0 || y >= surface->h || y < 0)
        return;

    Uint32 *buffer;
    Uint32 color;

    color = SDL_MapRGB(surface->format, colors.red, colors.green, colors.blue);
    buffer = (Uint32 *) surface->pixels + y * surface->pitch/4 + x;

    (*buffer) = color;

    if(SDL_MUSTLOCK(surface))
        SDL_UnlockSurface(surface);

}
