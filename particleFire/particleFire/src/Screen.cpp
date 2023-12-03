#include "Screen.h"

Screen::Screen() : m_window(NULL),
m_renderer(NULL),
m_tex(NULL),
m_buffer(NULL)

{

}

bool Screen::init()
{

    // we need an array for every pixal on the screen . each pixple is 32 bits , 4 bytes 
    Uint32* m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false; 
    }
    else {
        // create the window here 
        m_window = SDL_CreateWindow("SDL Tutorual",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (m_window == NULL) {

            SDL_Quit(); // clean up 
            return false;
        }
        else {

            // this variable holds SDL ents 



            m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

            if (m_renderer == NULL) {
                
                SDL_Quit();
                return false;
            }

            m_tex = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);


            if (m_tex == NULL) {
                
                SDL_Quit();
                return false;
            }



            memset(m_buffer, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
            // buffer[105000] = 0xFFFFFFFF; 
            for (int i = 0l; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
                m_buffer[i] = 0xFF80FFFF;
            }

            SDL_UpdateTexture(m_tex, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));

            // clear the renderer 
            SDL_RenderClear(m_renderer);

            // set the texture to the renderer 
            SDL_RenderCopy(m_renderer, m_tex, NULL, NULL);

            // present the Render
            SDL_RenderPresent(m_renderer);
            return false;
        }
    }
}

bool Screen::processEvent() {
    return false;
}

void Screen::close() {
    delete[] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_tex);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

