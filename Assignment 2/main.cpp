#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include "headers/assignments.h"
#include "../SDL_initalizer/headers/init.h"
#include <SDL/SDL_image.h>
#include <iostream>
#include <fstream>

/*
    TODO:
    Make a standard lib to do initialization checking
    Make a standard lib for rendering sprites
    Clean this filthy mess once the assignment starts
    Pre-allocate the objects to a fixed amount then overwrite it

    UPDATE: WE GOT A HEADER FILE, WE'RE IN BOYS

*/

SDL_Surface *backbuffer = NULL;

bool execprogram();


void init_SDL();

SDL_Surface *load();


void DrawImage(SDL_Surface* image, SDL_Surface* destSurface, int x, int y)
{
SDL_Rect destRect;
destRect.x = x;
destRect.y = y;
SDL_BlitSurface(image, NULL, destSurface, &destRect);
}

int main ( int argc, char** argv )
{
    init_SDL();
    return 0;
}

void init_SDL()
{
    res r;
    colors colors;

    int bpp;
    r.width = 800;
    r.height = 640;
    bpp = 32;

    char *filenames[4] = {
        "img/car.bmp",
        "img/gabe.bmp",
        "img/hero0.png",
        "img/background.jpg"
    };
    backbuffer = SDL_SetVideoMode(r.width, r.height, bpp, SDL_HWSURFACE);
    //Sprite **carmack = new Sprite *[10];
    //Sprite **gaben = new Sprite *[10];

    Sprite background(filenames[3], 0, 0);
    Sprite cool(filenames[2], 0, 0);

    SDL_Rect geometry;
    geometry.x = 200;
    geometry.y = 200;

        12, 32,     //Frame Width/Height
    //Position of the image
    geometry.x = geometry.y = 300;

    background.setGeo(0, 0);

    /*

    */

    /*
    initialize SDL and check if there's any error, if it is, the program will exit with the EXIT_FAILURE
    as return value.
    */
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }


    SDL_WM_SetCaption("Assignment 2", NULL);
    Animate a;
    int SpriteFrame = 0;
    int FrameCounter = 0;
    const int MaxSpriteFrame = 77;
    const int FrameDelay = 2;
    int BackgroundX = 0;

        /*
        for(int i = 0; i < 10; i+= 1)
        {

            colors.red = rand()%255;
            colors.green = rand()%255;
            colors.blue = rand()%255;
            //carmack[i] = new Sprite(filenames[0], 0, rand()%r.height);
            //gaben[i] = new Sprite(filenames[1], r.width -300, rand()%r.height);
            //SDL_BlitSurface(carmack[i]->getImage(), NULL, backbuffer, &carmack[i]->pos);
            //SDL_BlitSurface(gaben[i]->getImage(), NULL, backbuffer, &gaben[i]->pos);

            //drawPixel(backbuffer, rand()%r.width, rand()%r.height, colors);
            //drawFullRectangle(backbuffer, rand()%r.width, rand()%r.height, rand()%200, rand()%200, colors);
            //drawEmptyRectangle(backbuffer, rand()%r.width, rand()%r.height, rand()%200, rand()%200, colors);

        }
        SDL_BlitSurface(cool.getImage(), NULL, backbuffer, &cool.geometry);
        SDL_FreeSurface(cool.getImage());
        */


    while(execprogram())
    {


        FrameCounter+= 1;
        if(FrameCounter > FrameDelay)
        {
        FrameCounter = 0;
        SpriteFrame++;
        }
        if(SpriteFrame > MaxSpriteFrame)
        SpriteFrame = 0;
        //Updates Background scrolling
        BackgroundX -= 6;
        if(BackgroundX <= -800)
        BackgroundX = 0;
        //Render the scene
        background.geometry.x = BackgroundX;
        SDL_BlitSurface(background.getImage(), NULL, backbuffer, &background.geometry);
        background.geometry.x = BackgroundX+800;
        SDL_BlitSurface(background.getImage(), NULL, backbuffer, &background.geometry);

        a.horizontal(cool.getImage(), backbuffer,

        SpriteFrame); //Frame Number
        SDL_Delay(20);
        SDL_Flip(backbuffer);


    }

}

bool execprogram()
{
  SDL_Event event;
  bool running = true;

  while(SDL_PollEvent(&event))
  {
      if(event.type == SDL_QUIT)
        running = false;
  }

  return running;
}



/*
SDL_Surface *load()
{
    SDL_Surface *imageload = NULL;
    SDL_Surface *alterimage = NULL;

    imageload = IMG_Load("img/hero0.png");

    if(imageload != NULL)
    {
        alterimage = SDL_DisplayFormat(imageload);
        SDL_FreeSurface(imageload);

        if (alterimage != NULL)
        {
            Uint32 color = SDL_MapRGB(alterimage->format, 0, 255, 0);
            SDL_SetColorKey(alterimage, SDL_SRCCOLORKEY, color);
        }
    }
    else
    {

    }

    return alterimage;

}'
*/
