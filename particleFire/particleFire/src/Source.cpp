#include<stdio.h>
#include<SDL.h>
#include<iostream>


int main(int argc, char* argv[]) {
    // screen Dimenstion 
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    // this is the window 
    SDL_Window* window = NULL; 
    // renderder for the window 
    SDL_Renderer* renderer = NULL;

    // texture for the render 
    SDL_Texture* tex = NULL; 

    // surface contained by the window 
    SDL_Surface* screenSurface = NULL; 

    // we need an array for every pixal on the screen . each pixple is 32 bits , 4 bytes 
    Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL could not be initilized : %s\n", SDL_GetError());
    }
    else {
       // create the window here 
        window = SDL_CreateWindow("SDL Tutorual",
                            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); 

        if (window == NULL) {
           
            printf("Window Could not be created: %s", SDL_GetError()); // from stdio.h
            SDL_Quit(); // clean up 
            return 2; 
        }
        else {

            // this variable holds SDL ents 
            SDL_Event event; 
            bool gameOver = false; 


            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC); 

            if (renderer == NULL) {
                printf("renderer could not be created %s", SDL_GetError()); 
                SDL_Quit(); 
                return 3; 
            }

            tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);


            if (tex == NULL) {
                printf("texture could not be created %s", SDL_GetError());
                SDL_Quit();
                return 3;
            }


            
            memset(buffer, 0x00, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32)); 
            // buffer[105000] = 0xFFFFFFFF; 
            for (int i = 0l; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
                buffer[i] = 0xFF80FFFF; 
            }

            SDL_UpdateTexture(tex, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
            
            // clear the renderer 
            SDL_RenderClear(renderer); 

            // set the texture to the renderer 
            SDL_RenderCopy(renderer, tex, NULL, NULL); 

            // present the Render
            SDL_RenderPresent(renderer);

            // game loop 
            while (!gameOver) {
                //screenSurface = SDL_GetWindowSurface(window); // get the surface of the window
                //// fill it with a rectange
                //SDL_FillRect(screenSurface,
                //    NULL, 
                //     SDL_MapRGB(screenSurface->format, 0x43, 0x0b, 0x22));
                //// update the window 
                //SDL_UpdateWindowSurface(window);




                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        gameOver = true; 
                    }
                }
            }      
        }

    }

    delete[] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(tex);
    SDL_DestroyWindow(window); 
    SDL_Quit();
    return 0;
}
