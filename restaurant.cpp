//
//  restaurant.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "restaurant.h"

Restaurant::Restaurant(string name) :
  name(name), list_start_index(0), list_end_index(4), curr_num_of_meals(0){}

string Restaurant::get_name() const{
  return name;
}

bool Restaurant::add_meal(Food food){
  /**********Test 1***********
  if(curr_num_of_meals < 5){
    meals_list[curr_num_of_meals] = food;
    list_end_index = curr_num_of_meals;
    curr_num_of_meals++;
    return true;
  }
  return false;
  */

  /**********Test 2***********/
  if(curr_num_of_meals < 5){
    //check if negative, then make positive by adding 5
    while(list_end_index < 0)
      list_end_index += 5;
    //add 1 to list_end_index and take mod 5, to make sure its in [0,4]
    list_end_index = (list_end_index+1)%5;
    //list_end_index is now the new index for food;
    meals_list[list_end_index] = food;
    //increment curr_num_of_meals
    curr_num_of_meals++;
    return true;
  }
  return false;
}

bool Restaurant::remove_first_meal(){
  if(curr_num_of_meals > 0){
    while(list_start_index > 5)
      list_start_index -= 5;
    list_start_index++;
    curr_num_of_meals--;
    return true;
  }
  return false;
}

bool Restaurant::remove_last_meal(){
  if(curr_num_of_meals > 0){
    while(list_end_index < 0)
      list_end_index += 5;
    list_end_index--;
    curr_num_of_meals--;
    return true;
  }
  return false;
}

bool Restaurant::serve_meal(Buddy* buddy, int meal_index) const{
  //check if buddy has enough money to buy meal at meal_index
  if(buddy->get_money() >= meals_list[meal_index].get_price()){
    //Deduct money, add/remove fat and muscle
    buddy->set_money(buddy->get_money() - meals_list[meal_index].get_price());
    buddy->set_fat(buddy->get_fat() + meals_list[meal_index].get_fat_gain());
    buddy->set_muscle(buddy->get_muscle() + meals_list[meal_index].get_protein_gain());
    return true;
  }
  return false;
}
