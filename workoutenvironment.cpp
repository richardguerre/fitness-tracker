//
//  workoutenvironment.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//
#include <iostream>
#include "workoutenvironment.h"

WorkoutEnvironment::WorkoutEnvironment(string name, int entry_fee, int MAX_NUM_OF_WORKOUTS) :
  name(name),
  entry_fee(entry_fee),
  available_workouts(new Workout[MAX_NUM_OF_WORKOUTS]),
  MAX_NUM_OF_WORKOUTS(MAX_NUM_OF_WORKOUTS),
  current_num_of_workouts(0),
  participants(NULL),
  current_num_of_participants(0)
  {}

WorkoutEnvironment::~WorkoutEnvironment(){
  delete [] available_workouts;
  /*for(int i=0; i<current_num_of_participants; i++){
    delete participants[i];
  }*/
  delete [] participants;
  participants = NULL;
}

string WorkoutEnvironment::get_name() const{
  return name;
}
int WorkoutEnvironment::get_entry_fee() const{
  return entry_fee;
}
bool WorkoutEnvironment::add_workout(const Workout& workout, int add_index){
  if(add_index >= 0
    && add_index <= current_num_of_workouts
    && current_num_of_workouts < MAX_NUM_OF_WORKOUTS){
      if(available_workouts[add_index].get_name() == "")
        available_workouts[add_index] = workout;
      else{
        for(int i=current_num_of_workouts; i>add_index; i--){
          available_workouts[i] = available_workouts[i-1];
        }
        available_workouts[add_index] = workout;
      }
      current_num_of_workouts++;
      return true;
  }
  return false;
}
bool WorkoutEnvironment::remove_workout(int remove_index){
  if(remove_index >= 0
    && remove_index < current_num_of_workouts
    && current_num_of_workouts > 0){
      for(int i=remove_index; i<current_num_of_workouts-1; i++)
        available_workouts[i] = available_workouts[i+1];
      current_num_of_workouts--;
      return true;
  }
  return false;
}
int WorkoutEnvironment::participant_index(const Buddy* buddy) const{
  //look through the whole participants array
  for(int i=0; i<current_num_of_participants; i++){
    //check if address is the same
    if(participants[i] == buddy){
      return i;
    }
  }
  return -1;
}

bool WorkoutEnvironment::register_participant(Buddy* buddy){
  if(participant_index(buddy) > -1)
    return false;
  if(participant_index(buddy) == -1 && entry_fee <= buddy->get_money()){
    //deduct money
    buddy->set_money(buddy->get_money() - entry_fee);
    {
      //make dynamic array of pointers with size current_num_of_participants+1
      Buddy **array = new Buddy*[current_num_of_participants+1];
      //copy allelements of old dynamic array (participants) into new array.
      for(int i=0; i<current_num_of_participants; i++){
        array[i] = participants[i];
      }
      //add buddy to the new array
      array[current_num_of_participants] = buddy;
      //make participants point to array
      participants = array;
    }
    //increment current_num_of_participants
    current_num_of_participants++;
    return true;
  }
  //catch all remaining edge cases
  return false;
}

bool WorkoutEnvironment::start_workout(int participant_index, int workout_index) const{
  //check if participant_index and workout_index are valid, and check that participant has enough energy
  if(participant_index >= 0
    && participant_index <= current_num_of_participants
    && workout_index >= 0
    && workout_index <= current_num_of_workouts
    && participants[participant_index]->get_energy() >= -1*available_workouts[workout_index].get_energy_change()){
      //seting participants fat, muscle and energy
      participants[participant_index]->set_fat(participants[participant_index]->get_fat() + available_workouts[workout_index].get_fat_change());
      participants[participant_index]->set_muscle(participants[participant_index]->get_muscle() + available_workouts[workout_index].get_muscle_change());
      participants[participant_index]->set_energy(participants[participant_index]->get_energy() + available_workouts[workout_index].get_energy_change());
      return true;
  }
  return false;
}
