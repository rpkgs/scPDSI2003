/*
 * basic.h
 *
 *  Created on: 11 May, 2018
 *      Author: kongdd
 */

#ifndef BASIC_H_
#define BASIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#ifdef _WIN32
#include <direct.h>
#endif

// #include <sstream>

typedef double number;

int numEntries(FILE *in);
int partition(number a[], int left, int right);
void select(number a[], int l, int r, int k);
void exch(number &x, number &y);
int dir_exists(char *dir);
int create_dir(char *path);
void check_dir(char *path);
FILE *file_open(const char *_Filename, bool null_exit = true);
// std::string repeat(const std::string& input, int n);

#endif /* BASIC_H_ */
