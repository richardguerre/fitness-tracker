//
//  food.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "food.h"

//constructor initialization with MIL
Food::Food(string name, int fat_gain, int protein_gain, int price) :
  name(name), fat_gain(fat_gain), protein_gain(protein_gain), price(price){}

string Food::get_name() const{
  return name;
}
int Food::get_fat_gain() const{
  return fat_gain;
}
int Food::get_protein_gain() const{
  return protein_gain;
}
int Food::get_price() const{
  return price;
}
