/*
 * format.h
 * used to manipulate string variables
 *
 *  Created on: Apr 1, 2017
 *      Author: kong
 */

#ifndef INCLUDE_FORMAT_
#define INCLUDE_FORMAT_

#include <stdarg.h>
#include <stdio.h>
#include <cstring>
#include <string>

//using namespace std;
//#define MAX_SIZE 200
//this is safe and convenient but not exactly efficient
inline std::string format(const char* fmt, ...){
	int size = 512;
	char* buffer = 0;
	buffer = new char[size];
	va_list vl;
	va_start(vl, fmt);
	int nsize = vsnprintf(buffer, size, fmt, vl);
	if(size<=nsize){ //fail delete buffer and try again
		delete[] buffer;
		buffer = 0;
		buffer = new char[nsize+1]; //+1 for /0
		nsize = vsnprintf(buffer, size, fmt, vl);
	}
	std::string ret(buffer);
	va_end(vl);
	delete[] buffer;
	return ret;
}

//Just like sprintf, avoiding unexpected error for char array.
inline void strbind(char *dest, char *str1, const char *str2){
//	char buffer[170];
	// if str1 length is less then 1, then assign to './'
	if (strlen(str1) < 1) strcpy(str1, "./"); //also change str1 value
	strcpy(dest, str1);
	strcat(dest, str2);
//	return buffer;
}
//char *filename = "example/monthly_P";
////should allocate memory before manipulate
//char *cmd2 = new char[200];
//std::sprintf(cmd2, "fread(%s')", filename);
//delete []cmd2;

// test for format function
//string file = "kongdd";
//string mystr;
//mystr = format("%s %d %10.5f", "omg", 1, 10.5);
//cout << mystr << endl;
    
#endif
