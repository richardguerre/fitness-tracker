//
//  relaxplan.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 3/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "relaxplan.h"

RelaxPlan::RelaxPlan(string name) : name(name), head(NULL) {}

// Example solution for copy constructor, you don't have to implement it
RelaxPlan::RelaxPlan(RelaxPlan const & rp): name(rp.name) {
    // empty list
    if (!rp.head) {
        head = NULL;
        return;
    }
    // copy first node, prepare to copy second
    head = new Relaxation(*rp.head);
    Relaxation* curr_copied = head;
    Relaxation* next_to_copy = rp.head->get_next();
    // while next exists, continue copy
    while (next_to_copy) {
        Relaxation* copied = new Relaxation(*next_to_copy);
        curr_copied->set_next(copied);
        // next_to_copy is always a node in rp
        // curr_copied is always a node in self
        next_to_copy = next_to_copy->get_next();
        curr_copied = copied;
    }
}

RelaxPlan::~RelaxPlan(){
  Relaxation* current = head;
  Relaxation* next;

  while(current != NULL){
    next = current->get_next();
    free(current);
    current = next;
  }

  head = NULL;
}

Relaxation* RelaxPlan::get_head() const{
  return head;
}

void RelaxPlan::addToStart(Relaxation r){
  // create copy of r on heap
  Relaxation* copy = new Relaxation(r);

  //using set_next() to insert copy before head
  copy->set_next(head);
  //reassigning head
  head = copy;
}

void RelaxPlan::addToEnd(Relaxation r){
  // create copy of r on heap
  Relaxation* copy = new Relaxation(r);
  //new current used to traverse linked list
  Relaxation* current = head;

  //traverse linked list until end (NULL)
  while(current->get_next() != NULL){ current = current->get_next(); }

  //apend copy of r into linked list's end
  current->set_next(copy);
}

bool RelaxPlan::remove(int remove_index){
  if(head != NULL){
    //initialize indices for traversing and manipulating linked list
    Relaxation* current = head;
    Relaxation* prev = NULL;

    //traversing the linked list up to remove_index
    for(int i=0; i<remove_index; i++, current->set_next(current->get_next())){
      //check if the end of the linked list is reached or not.
      if(current == NULL)
        return false;
      //iteration of prev pointer to point to the element before current
      prev->set_next(current);
    }
    //link prev with next as to remove current from linked list
    prev->set_next(current->get_next());
    //deallocate the removed
    free(current);
  }
  return false;
}
