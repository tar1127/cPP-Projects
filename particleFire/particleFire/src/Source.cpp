#include<stdio.h>
#include<SDL.h>

int main(int argc, char* argv[]) {
    // screen Dimenstion 
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    // this is the window 
    SDL_Window* window = NULL; 

    // surface contained by the window 
    SDL_Surface* screenSurface = NULL; 

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not be initilized : %s\n", SDL_GetError());
    }
    else {
       // create the window here 
        window = SDL_CreateWindow("SDL Tutorual",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); 

        if (window == NULL) {
            printf("Window Could not be created: %s", SDL_GetError());
        }
        else {


            SDL_Event event; 
            bool gameOver = false; 

            // game loop 
            while (!gameOver) {
                screenSurface = SDL_GetWindowSurface(window);
                // fill it with a rectange
                SDL_FillRect(screenSurface,
                    NULL, 
                     SDL_MapRGB(screenSurface->format, 0x43, 0x0b, 0x22));
                // update the window 
                SDL_UpdateWindowSurface(window);

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        gameOver = true; 
                    }
                }
            }      
        }

    }
    SDL_DestroyWindow(window); 
    SDL_Quit();
    return 0;
}
