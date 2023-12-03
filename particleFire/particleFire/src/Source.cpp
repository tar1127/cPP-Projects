
#include"Screen.h"


int main(int argc, char* argv[]) {


    // we need an array for every pixal on the screen . each pixple is 32 bits , 4 bytes 
            
  
            // declear the screen 
            Screen screen; 

            // call initilization 
            if (screen.init() == false) {
                std::cout << "Error initilizing SDL" << std::endl; 
            }

            // game loop 
            while (1) {
                //screenSurface = SDL_GetWindowSurface(window); // get the surface of the window
                //// fill it with a rectange
                //SDL_FillRect(screenSurface,
                //    NULL, 
                //     SDL_MapRGB(screenSurface->format, 0x43, 0x0b, 0x22));
                //// update the window 
                //SDL_UpdateWindowSurface(window);

                screen.setPixle(200, 200, 255, 255, 255); 
                screen.setPixle(201, 200, 255, 255, 255); 
                screen.setPixle(202, 200, 255, 255, 255); 
                screen.setPixle(203, 200, 255, 255, 255); 
       

                screen.update(); 
                if (screen.processEvent() == false) {
                    break; 
                }
     
            }

            screen.close(); 

    return 0;
}
