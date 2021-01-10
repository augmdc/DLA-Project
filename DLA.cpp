//
//  DLA.cpp
//  Project1
//
//  Created by Augustin Marks de Chabris on 2020-10-12.
//  Copyright © 2020 Augustin Marks de Chabris. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Lattice.hpp"
#include "DLA.hpp"
using namespace std;

    //Default constructor; declares a lattice structure for DLA object
    DLA::DLA() {}
    
    // Enter a new particle and move it until it sticks or leaves the system through an open Site
    bool     DLA::enterParticle(int positionx,int positiony) {
        //Check if site is actually empty
        if(the_lattice.system[positionx][positiony] != Lattice::Site::Empty)
           return false;
        
        //Move particle until it leaves system, meets another particle or moves to an open spot
        while(not hasOccupiedNeighbour(positionx,positiony) && the_lattice.system[positionx][positiony] != Lattice::Site::Open) {
          
            //Random walk: 0 is move left, 1 is move right, 2 is move up, and 3 is move down
            int random_move = (rand() % 4);
            
            //Move randomly
            switch (random_move) {
                case 0:
                    --positionx;
                    break;
                    
                case 1:
                    ++positionx;
                break;
                    
                case 2:
                   ++positiony;
                break;
                    
                default:
                    --positiony;
                    break;
            }
            //Boundary check for periodic simulations:
            positionx = ((positionx - 1 < 0) ? LATTICE_WIDTH - 1:((positionx >= LATTICE_WIDTH) ? 0 : positionx));
            positiony = ((positiony - 1 < 0) ? LATTICE_HEIGHT - 1: ((positiony >= LATTICE_HEIGHT) ? 0 : positiony));
            
        }
        
        //Particle leaves system
        if (the_lattice.system[positionx][positiony] == Lattice::Site::Open)
            return false;
        
        //If not, set final position to Occupied
        the_lattice.system[positionx][positiony] = Lattice::Site::Occupied;
        ++the_lattice.num_occupied_sites;
        
        //Meaning Particle is stuck on another particle
        return true;
        }

    //Checks if any neighbour is occupied
    bool DLA::hasOccupiedNeighbour(int positionx, int positiony) {
        //Establishing bounded indices for neighbours
        int left = (positionx - 1 < 0) ? LATTICE_WIDTH - 1: positionx - 1;
        int right = (positionx + 1 > LATTICE_WIDTH) ? 0 : positionx + 1;
        int top = (positiony - 1 < 0) ? LATTICE_HEIGHT - 1 : positiony - 1;
        int bottom = (positiony + 1 > LATTICE_HEIGHT) ? 0 : positiony + 1;
        
        if( the_lattice.system[left][positiony] == Lattice::Site::Occupied || the_lattice.system[right][positiony] == Lattice::Site::Occupied || the_lattice.system[positionx][top] == Lattice::Site::Occupied ||the_lattice.system[positionx][bottom] == Lattice::Site::Occupied)
            return true;
        return false;
    }

    // Set a seed particle at a given position
    void    DLA::setSeed(int positionx,int positiony) {
        the_lattice.system[positionx][positiony] = Lattice::Site::Occupied;
        ++the_lattice.num_occupied_sites;
    }
    
    // Declare a lattice site as open (particles escape from there)
    void    DLA::makeOpen(int positionx,int positiony) {
        the_lattice.system[positionx][positiony] = Lattice::Site::Open;
        ++the_lattice.num_open_sites;
    }
    
    // Get the number of particles in the system.
    int     DLA::numParticles() {
        return the_lattice.num_occupied_sites;
    }
    
    // Print contents of the system lattice to cout
    void    DLA::printWorld() {
        for(int nx = 0; nx < LATTICE_WIDTH; ++nx) {
            for (int ny = 0; ny < LATTICE_HEIGHT; ++ny) {
                //if (ny < LATTICE_HEIGHT-1)
                std::cout << static_cast<int>(the_lattice.system[nx][ny]) << " ";
            }
            std::cout << "\n";
        }
    }
    

