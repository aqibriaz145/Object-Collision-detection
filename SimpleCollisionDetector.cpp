#include "SimpleCollisionDetector.h"           // Include the header for SimpleCollisionDetector
#include <cmath>                                 // Include the cmath library for mathematical functions

unsigned SimpleCollisionDetector::scanCollisions(Particle* particles, unsigned numParticles, ParticleContact* contacts, unsigned maxContacts)
{
    const float restitutionCoefficient = 1.0f;   // Define the restitution coefficient (bounciness)
    unsigned contactCount = 0;                   // Initialize the collision contact counter to zero

    // Loop over all particles with index i (outer loop)
    for (unsigned i = 0; i < numParticles; ++i)
    {
        // Inner loop: Compare particle i with every subsequent particle j to avoid redundant checks
        for (unsigned j = i + 1; j < numParticles; ++j)
        {
            // Calculate the Euclidean distance between the centers of particles i and j
            float distance = (particles[i].getPosition() - particles[j].getPosition()).magnitude();
            // Calculate the sum of the radii of particles i and j
            float sumRadii = particles[i].getRadius() + particles[j].getRadius();

            // If the distance is less than the sum of the radii, a collision is detected
            if (distance < sumRadii)
            {
                // Calculate the penetration depth (how much the particles overlap)
                float penetrationDepth = sumRadii - distance;

                // Record the collision details in the contacts array:
                contacts[contactCount].particle[0] = &particles[i];  // Pointer to the first colliding particle
                contacts[contactCount].particle[1] = &particles[j];  // Pointer to the second colliding particle
                // Calculate and assign the contact normal (unit vector from particle j to particle i)
                contacts[contactCount].contactNormal = (particles[i].getPosition() - particles[j].getPosition()).unit();
                contacts[contactCount].restitution = restitutionCoefficient;  // Set the restitution coefficient
                contacts[contactCount].penetration = penetrationDepth;          // Set the penetration depth

                ++contactCount;   // Increment the counter for recorded collision contacts

                // If the maximum number of contacts is reached, return the count immediately
                if (contactCount >= maxContacts)
                {
                    return contactCount;  // Early exit if the contact array is full
                }
            }
        }
    }
    return contactCount;  // Return the total number of collisions recorded
}
