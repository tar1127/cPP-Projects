#pragma once

#include "Particle.h"

class Swarm
{

public: 
    const static int NUM_PARTICLES = 5000; 

    Particle*  m_pParticle; 

public:
    Swarm(); 
    ~Swarm(); 
    const Particle* const getParticle(); 
    void swarmUpdate(); 

};

