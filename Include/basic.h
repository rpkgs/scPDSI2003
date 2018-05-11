/*
 * basic.h
 *
 *  Created on: 2018Äê5ÔÂ11ÈÕ
 *      Author: kongdd
 */

#ifndef BASIC_H_
#define BASIC_H_

#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <direct.h>


typedef double number;

int numEntries(FILE *in);
int partition(number a[], int left, int right);
void select(number a[], int l, int r, int k);
void exch(number &x, number &y);
int dir_exists(char *dir);
int create_dir(char *path);


#endif /* BASIC_H_ */
