#include "Swarm.h"

Swarm::Swarm()
{
     m_pParticle = new Particle[NUM_PARTICLES]; 
}

Swarm::~Swarm()
{
    delete[] m_pParticle; 
}

const Particle* const Swarm::getParticle()
{
    return m_pParticle;
}

void Swarm::swarmUpdate()
{
    for (int i = 0; i < NUM_PARTICLES; i++) {
        m_pParticle[i].particleUpdate(); 
    }
}

