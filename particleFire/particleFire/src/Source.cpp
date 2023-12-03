
#include"Screen.h"


int main(int argc, char* argv[]) {


    // we need an array for every pixal on the screen . each pixple is 32 bits , 4 bytes 
            SDL_Event event;
            bool gameOver = false;

            // declear the screen 
            Screen screen; 

            // call initilization 
            if (screen.init() == false) {
                std::cout << "Error initilizing SDL" << std::endl; 
            }

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

            screen.close(); 

    return 0;
}
