#include "Screen.h"

Screen::Screen() : m_window(NULL),
m_renderer(NULL),
m_tex(NULL),
m_buffer(NULL)

{

}

bool Screen::init()
{

    // we need an array for every pixal o the screen . each pixple is 32 bits , 4 bytes of RGB and Alpha
     m_buffer = new Uint32[SCREEN_WIDTH  * SCREEN_HEIGHT];

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

            // this variable holds SDL  
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
            
        }
    }
    return true; 
}

void Screen::update()
{
    SDL_UpdateTexture(m_tex, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
    // clear the renderer 
    SDL_RenderClear(m_renderer);
    // set the texture to the renderer 
    SDL_RenderCopy(m_renderer, m_tex, NULL, NULL);
    // present the Render
    SDL_RenderPresent(m_renderer);
}

bool Screen::processEvent() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void Screen::setPixle(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
    if (x < 0 || x >= SCREEN_WIDTH  || y < 0 || y >= SCREEN_HEIGHT  ) {
        return; 
    }
    
    Uint32 color = 0; 
    color += red; 
    color <<= 8; 
    color += green; 
    color <<= 8; 
    color += blue; 
    color <<= 8;
    color += 0xFF; 
    
    m_buffer[(y * SCREEN_WIDTH) + x] = color; 

}

void Screen::clear()
{
    memset(m_buffer, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

void Screen::close() {
    delete[] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_tex);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

