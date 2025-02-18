#pragma once                                  // Ensure the header is included only once
#ifndef SIMPLE_COLLISION_DETECTOR_H           // Check if SIMPLE_COLLISION_DETECTOR_H is not defined
#define SIMPLE_COLLISION_DETECTOR_H           // Define SIMPLE_COLLISION_DETECTOR_H

#include "particle.h"                         // Include the Particle class definition
#include "pcontacts.h"                        // Include the ParticleContact structure definition

// SimpleCollisionDetector: Implements a brute-force collision detection algorithm
// that scans an array of Particle objects and records collision details.

class SimpleCollisionDetector
{
public:
    // scanCollisions: Scans the provided particles for collisions.
    // Parameters:
    //   particles   - Pointer to an array of Particle objects.
    //   numParticles- Total number of particles in the array.
    //   contacts    - Pointer to a ParticleContact array for storing collision data.
    //   maxContacts - Maximum number of collision contacts to record.
    // Returns:
    //   The number of collision contacts recorded.
    static unsigned scanCollisions(Particle* particles, unsigned numParticles, ParticleContact* contacts, unsigned maxContacts);
};

#endif // SIMPLE_COLLISION_DETECTOR_H      // End of SIMPLE_COLLISION_DETECTOR_H definition
