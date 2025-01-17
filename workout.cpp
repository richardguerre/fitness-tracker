//
//  workout.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "workout.h"

Workout::Workout(string name, int fat_change, int muscle_change, int energy_change) :
  name(name), fat_change(fat_change), muscle_change(muscle_change),
  energy_change(energy_change){}

string Workout::get_name() const{
  return name;
}

int Workout::get_fat_change() const{
  return fat_change;
}

int Workout::get_muscle_change() const{
  return muscle_change;
}

int Workout::get_energy_change() const{
  return energy_change;
}
