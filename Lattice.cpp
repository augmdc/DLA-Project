//
//  Lattice.cpp
//  Project1
//
//  Created by Augustin Marks de Chabris on 2020-10-12.
//  Copyright © 2020 Augustin Marks de Chabris. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Lattice.hpp"

//Default constructor that initializes the lattice system (marks all sites as empty)
Lattice::Lattice() {
    for(int nx = 0; nx < LATTICE_WIDTH; ++nx) {
        for (int ny = 0; ny < LATTICE_HEIGHT; ++ny) {
            system[nx][ny] = Lattice::Site::Empty;
        }
    }
    num_open_sites=0;
    num_occupied_sites=0;
}

//Gets number of open sites
int Lattice::getOpenSites() { return num_open_sites;}

//Gets number of occupied sites
int Lattice::getOccupiedSites() { return num_occupied_sites;}


