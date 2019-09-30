//
//  buddy.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//
#include <string>
#include "buddy.h"

//Constructor, initialization with MIL
Buddy::Buddy(string name, int fat, int muscle, int energy, int money) :
  name(name), fat(fat), muscle(muscle), energy(energy), money(money){}

string Buddy::get_name() const {
  return name;
}

int Buddy::get_fat() const {
  return fat;
}

int Buddy::get_muscle() const {
  return muscle;
}

int Buddy::get_energy() const {
  return energy;
}

int Buddy::get_money() const {
  return money;
}

//set member var "fat" (this->fat) to fat;
void Buddy::set_fat(int fat) {
  this->fat = fat;
}

//set member var "muscle" (this->muscle) to muscle;
void Buddy::set_muscle(int muscle) {
  this->muscle = muscle;
}

//set member var "energy" (this->energy) to energy;
void Buddy::set_energy(int energy) {
  this->energy = energy;
}

//set member var "money" (this->money) to money;
void Buddy::set_money(int money) {
  this->money = money;
}

//set member var "money" (this->money) = prev_money + money*times
void Buddy::earn_money(int money, int times){
  this->money += money*times;
}


void Buddy::gain_energy(RelaxPlan plan){
  //start of plan energyGain = 0
  int energyGain = 0;
  //get head of linked list
  Relaxation* current = plan.get_head();

  //traversing linked list
  while(current != NULL){
    //adding up the energy gain of whole linked list
    energyGain += current->get_energy_gain();
    current = current->get_next();
  }
  //set member var "energy" = prev_energy + energyGain
  set_energy(get_energy() + energyGain);
}
