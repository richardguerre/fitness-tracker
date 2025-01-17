//
//  relaxplan.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 3/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "relaxplan.h"

//constructor initialization using MIL
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
  //initialize current and next pointers to traverse and manipulate linked list
  Relaxation* current = head;
  Relaxation* next;

  //traverse linked list till current == NULL
  while(current != NULL){
    //get next of rp
    next = current->get_next();
    //delete current node in rp (start with head)
    delete current;
    //iterate to next by setting current = next
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

  if(head != NULL){
    //new current used to traverse linked list
    Relaxation* current = head;

    //traverse linked list until end (NULL)
    while(current->get_next() != NULL){ current = current->get_next(); }

    //apend copy of r into linked list's end
    current->set_next(copy);
  }
  else //case of no elements yet
    head = copy;
}

bool RelaxPlan::remove(int remove_index){
  if(head != NULL && remove_index > 0){
    //initialize pointers for traversing and manipulating linked list
    Relaxation* current = head;
    Relaxation* prev = NULL;

    int i = 0;
    while(current != NULL){
      if(i == remove_index){
        //link prev with current->next as to remove element pointed by current from linked list
        //deletion, bypass current and delete current.
        prev->set_next(current->get_next());
        //deallocate the removed element
        delete current;
        return true;
      }
      i++;
      prev = current;
      current = current->get_next();
    }
    return false;
  }
  else if(remove_index == 0){
    //case of removing head, setting pointer to NULL
    Relaxation* temp = head;
    head = temp->get_next();
    delete temp;
  }
  return false;
}
