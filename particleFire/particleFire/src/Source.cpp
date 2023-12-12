
#include"Screen.h"
#include<stdlib.h>
#include "Swarm.h"


int main(int argc, char* argv[]) {

    
    srand(time(NULL)); 

    // declear the screen 
    Screen screen; 

    // call initilization 
    if (screen.init() == false) {
        std::cout << "Error initilizing SDL" << std::endl; 
    }
    
    Swarm swarm; 



     

    // game loop 
    while (1) {

        int elapsed = SDL_GetTicks();
        //double red = std::sin(elapsed); 
        int red = (1 + std::sin(2 * M_PI * .00003 * elapsed)) * 128;
        int green = (1 + std::sin(2 * M_PI * .00005 * elapsed)) * 128;
        int blue = (1 + std::sin(2 * M_PI * .00009 * elapsed)) * 128;

        const Particle* const particles = swarm.getParticle();
        screen.clear();

        for (int i = 0; i < Swarm::NUM_PARTICLES; i++) {
            Particle p = particles[i];
            
            int posx = (p.m_x + 1 ) * Screen::SCREEN_WIDTH / 2;
            int posy = p.m_y  * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;

            screen.setPixle(posx, posy, red, green, blue);
            
        }
        
        swarm.swarmUpdate(); 
/*  p.particleUpdate();


        //std::cout << green << std::endl;

        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixle(x, y, red, green, blue); 
            }
        }
*/


        screen.update(); 
        if (screen.processEvent() == false) {
            break; 
        }
     
    }

       screen.close(); 

 return 0;
}
