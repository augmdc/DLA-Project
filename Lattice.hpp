//
//  Lattice.hpp
//  DLA
//

#ifndef Lattice_hpp
#define Lattice_hpp

// Hardcoded lattice dimensions
const int   LATTICE_WIDTH = 65;
const int   LATTICE_HEIGHT = 65;

//
//  Class:  Lattice
//
//  Objects of this class contain a two dimensional array of lattice sites
//  for DLA simulation. The class provides functions to test or modify the
//  state of lattice sites. Encapsulation ensures that all sites are always
//  in one of the three allowed states.
//
class Lattice {
public:
    friend class DLA;
    Lattice();
    // Type for the state of lattice sites.
    enum class Site { Empty=0, Occupied=1, Open=2 };
    int getOpenSites();
    int getOccupiedSites();

 private:
    int num_open_sites;
    int num_occupied_sites;
    Site system[LATTICE_WIDTH][LATTICE_HEIGHT];
};

#endif /* Lattice_hpp */
