#pragma once

#include<SDL.h>
#include<iostream>
class Screen
{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

private: 
    // this is the window 
    SDL_Window* m_window;
    // renderder for the window 
    SDL_Renderer* m_renderer;
    // texture for the render 
    SDL_Texture* m_tex;

    // screen bffer 
    Uint32* m_buffer; 

    //methods 
public:
    Screen(); 
    bool init(); 
    bool processEvent(); 
    void close(); 
};

