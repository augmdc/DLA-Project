//
//  DLA.hpp
//  DLA
//
#include "Lattice.hpp"
#ifndef DLA_hpp
#define DLA_hpp

//
//  Class:  DLA
//
//  Objects of type DLA are used to run a two-dimenional DLA simulation. The
//  centre of the class is a function that moves a particle from a starting
//  position until it sticks to the existing particles or leaves the system.
//  In addition, functions are provided to set seed particles and open cells
//  where particles can escape. Details of the simulation such as the position
//  of initial seed particles, boundary conditions or the number of particles
//  to be added are not handled by this class.
//
class DLA{
public:
    DLA();
    // Enter a new particle and move it until it sticks or leaves the system
    bool     enterParticle(int,int);

    // Set a seed particle at a given position
    void    setSeed(int,int);
    
    // Declare a lattice site as open (particles escape from there)
    void    makeOpen(int,int);

    // Get the number of particles (including seeds) in the system.
    int     numParticles();
    
    // Print contents of the system lattice to cout
    void    printWorld();
    
    int     moveParticle(int,int);
    
    
    
private:
    bool hasOccupiedNeighbour(int,int);
    Lattice the_lattice;
};

#endif /* DLA_hpp */
