//
//  relaxation.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "relaxation.h"

// Constructor initialization with MIL
Relaxation::Relaxation(string name, int energy_gain) :
  name(name), energy_gain(energy_gain), next(NULL){}

string Relaxation::get_name() const{
  return name;
}

int Relaxation::get_energy_gain() const{
  return energy_gain;
}

Relaxation* Relaxation::get_next() const{
  return next;
}

//set member pointer "next" (this->next) = param. next
void Relaxation::set_next(Relaxation* next){
  this->next = next;
}
