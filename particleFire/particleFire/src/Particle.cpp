#include "Particle.h"


Particle::Particle(): m_x(0),m_y(0)
{ 

     m_direction =  (2.0 * M_PI * rand()) / RAND_MAX;
     m_speed = (0.01 * rand()) / RAND_MAX ;
}

Particle::~Particle()
{
}

void Particle::particleUpdate()
{

    double m_xspeed = m_speed * cos(m_direction); 
    double m_yspeed = m_speed * sin(m_direction);

    m_x += m_xspeed;
    m_y += m_yspeed;


}
