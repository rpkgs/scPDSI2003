//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <scPDSI.h>
#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

using namespace std;

//-----------------------------------------------------------------------------
//**********                       MAIN PROGRAM                       *********
//-----------------------------------------------------------------------------
// The main program takes in command line arguments and passes them to the
// constructor of a pdsi variable tester.  It then calls Calcpdsi to calculate
// the pdsi values.  Finally it calls write to output these values to file.
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {
//  cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//
//	char cCurrentPath[FILENAME_MAX];
//
//	GetCurrentDir(cCurrentPath, sizeof(cCurrentPath));
//	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
//	printf ("The current working directory is %s\n", cCurrentPath);

	pdsi PDSI;
	PDSI.set_flags(argc, argv); // Sets the flags of PDSI
	PDSI.WeeklyPDSI();         // Calculates the weekly pdsi values for PDSI
	PDSI.Write((char *)"weekly/1");
	PDSI.WeeklyPDSI(2);
	PDSI.Write((char *)"weekly/2");
	PDSI.WeeklyPDSI(4);
	PDSI.Write((char *)"weekly/4");
	PDSI.WeeklyPDSI(13);
	PDSI.Write((char *)"weekly/13");
	PDSI.MonthlyPDSI();
	PDSI.Write((char *)"monthly/original");
	PDSI.SCMonthlyPDSI();
	PDSI.Write((char *)"monthly/self_cal");
	PDSI.WeeklyCMI();
	PDSI.Write((char *)"weekly/CMI");
	return 0;
}
