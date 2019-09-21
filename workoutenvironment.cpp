//
//  workoutenvironment.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

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
    && current_num_of_workouts <= MAX_NUM_OF_WORKOUTS){
      available_workouts[add_index] = workout;
      current_num_of_workouts++;
      return true;
  }
  return false;
}
bool WorkoutEnvironment::remove_workout(int remove_index){
  if(remove_index >= 0
    && remove_index <= current_num_of_workouts
    && current_num_of_workouts >= 0){
      for(int i=remove_index; i<current_num_of_workouts; i++)
        available_workouts[i] = available_workouts[i+1];
      return true;
  }
  return false;
}
int WorkoutEnvironment::participant_index(const Buddy* buddy) const{
  return 0;
}
bool WorkoutEnvironment::register_participant(Buddy* buddy){
  return false;
}
bool WorkoutEnvironment::start_workout(int participant_index, int workout_index) const{
  return false;
}
