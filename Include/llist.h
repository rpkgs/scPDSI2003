/*
 * llist.h
 *
 *  Created on: 11 May, 2018
 *      Author: kongdd
 */

#ifndef LLIST_H_
#define LLIST_H_


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// This defines the type number as a double.  This is used to easily change
// the PDSI's variable types.
typedef double number;
typedef int flag;

//-----------------------------------------------------------------------------
//**********   START OF STRUCTURE DEFINITION FOR STRUCT:  node        *********
//-----------------------------------------------------------------------------
// The node struct is used specifically in the linked list class and is not
// relevant to the actual PDSI.
//-----------------------------------------------------------------------------
struct node {            // A structure for a node
public:
  number key;            // Where the data is stored
  struct node *next;     // Where the next node is
  struct node *previous; // Where the previous node is
};

// The llist class is a dynamic storage class.  It is used in the PDSI to
// eliminate problems with filling static arrays.
//-----------------------------------------------------------------------------
class llist {            // A linked list class
private:
  node *head;            // A pointer to the head of the linked-list
  int size;
  number kthLargest(int k);  //returns the kth largest number in the list
  number long_select(int k); //returns the kth largest number in the list
                             //without using an array or sorting.  Used when
                             //there is not enough memory to place the entire
                             //list in a new array.
  number percentile(double percentage); //returns the specified percentile

public:
  llist();               // The constructor
  ~llist();              // The destructor
  // The insert function takes an argument of type number and places it on
  // the head of the linked list.
  void insert(number x);
  // The remove functions remove from either the head (head_remove) or the
  // tail (tail_remove) of the linked list.
  number head_remove();  // remove the first node and returns its key
  number tail_remove();  // remove the last node and returns its key
  // These are other useful functions used in dealing with linked lists
  int is_empty();// Returns 1 if the llist is empty 0 otherwise
  int get_size();
  number sumlist();  // Sums the items in list
  void sumlist(number &prev_sum, int sign);//sums items in list into prev_sum
  number maxlist();
  number minlist();
  number quartile(int q);        //returns the qth quartile
  number safe_percentile(double percentage); //safe version

  number* returnArray();

  // The set_node function sets the key of the node pointed to by set.  It
  // checks the linked list to make sure set is in the node to prevent
  // runtime errors from occuring.  It was written specifically for the PDSI
  // program and its backtracking function.
  node *set_node(node *set=NULL, number x=0);
  friend void copy(llist &L1,const llist &L2); // Copies L2 to L1
};


#endif /* LLIST_H_ */
