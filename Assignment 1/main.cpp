#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>


class Sprite
{
    public:
        SDL_Rect pos;
        SDL_Surface *image = NULL;
        Sprite(char *filename, int posx, int posy)
        {
            this->setFilename(filename);
            this->setPos(posx, posy);
            this->loadImage();
        }
        SDL_Surface *getImage()
        {
            return this->image;
        }
        SDL_Rect getPos()
        {
            return this->pos;
        }
    private:
        char *_filename;


        void setFilename(char *filename)
        {
            this->_filename = filename;
        }
        void setPos(int posx, int posy)
        {
            pos.x = posx;
            pos.y = posy;
        }
        void loadImage()
        {
            if(this->_filename != NULL)
                this->image = SDL_LoadBMP(this->_filename);
            else
            SDL_Quit();
        }
};

bool loadimage(SDL_Surface **image, char *filename);
//void freeimages()
int main ( int argc, char **argv )
{
    char *filenames[2] = {
        "img/car.bmp",
        "img/gabe.bmp"
    };
    int width, height, bpp;
    width = 800;
    height = 640;
    bpp = 32;
    SDL_Surface *image = NULL, *backbuffer;
    image = backbuffer = NULL;
    SDL_Rect pos;
    Sprite **carmack = new Sprite *[10];
    Sprite **gaben = new Sprite *[10];

    /*
    loadimage(&image, filenames[0]);
    if(image == NULL)
    {
        SDL_Quit();
        return 2;
    }
    */
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Quit();
        return 1;
    }
    backbuffer = SDL_SetVideoMode(width, height, bpp, SDL_HWSURFACE);
    SDL_WM_SetCaption("Assignment 1", NULL);


    for (int i = 0; i < 10; i += 1)
    {
        carmack[i] = new Sprite(filenames[0], (rand() -100) % width, (rand() -100) % height);
        gaben[i] = new Sprite(filenames[1], (rand() -100) % width, (rand() -100) % height);
        SDL_BlitSurface(carmack[i]->getImage(), NULL, backbuffer, &carmack[i]->pos);
        SDL_BlitSurface(gaben[i]->getImage(), NULL, backbuffer, &gaben[i]->pos);
    }
    SDL_Flip(backbuffer);
    SDL_Delay(3000);

    SDL_FreeSurface(image);
    SDL_Quit();
    return 0;
}

bool loadimage(SDL_Surface **image, char *filename)
{
    if(image != NULL)
        *image = SDL_LoadBMP(filename);
    else
        return false;
    return true;
}
