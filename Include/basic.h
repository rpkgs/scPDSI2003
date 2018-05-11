/*
 * basic.h
 *
 *  Created on: 11 May, 2018
 *      Author: kongdd
 */

#ifndef BASIC_H_
#define BASIC_H_

#include <stdio.h>
typedef double number;

int numEntries(FILE *in);
int partition(number a[], int left, int right);
void select(number a[], int l, int r, int k);
void exch(number &x, number &y);
int dir_exists(char *dir);
int create_dir(char *path);


#endif /* BASIC_H_ */
