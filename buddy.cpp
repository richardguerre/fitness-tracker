//
//  buddy.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//
#include <string>
#include "buddy.h"

Buddy::Buddy(string name, int fat, int muscle, int energy, int money) :
  name(name),
  fat(fat),
  muscle(muscle),
  energy(energy),
  money(money)
  {}

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

void Buddy::set_fat(int fat) {
  this->fat = fat;
}

void Buddy::set_muscle(int muscle) {
  this->muscle = muscle;
}

void Buddy::set_energy(int energy) {
  this->energy = energy;
}

void Buddy::set_money(int money) {
  this->money = money;
}
