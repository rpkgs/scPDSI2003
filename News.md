### Updates:  
    - Implemented user-defined calibration interval (Jun 5 2006) -- goddard
    - A more intuitive format for the parameter file is accepted:
         AWC Latitude
      The '-n' flag was added to facilitate the old format: AWC TLA (Jul 15 2003)
    - Calculates the Weekly CMI (Jul 1 2003)
    - Works in with southern latitude (Apr 1 2003)
    - Works with the metric flag (Mar 12 2003)

* Self-calibrating, multiple time scale version. Based upon `weekly_pdsi.cpp` 
which is a self-calibrating, weekly PDSI program developed by Nathan Wells. 
This version is capable of calculating a self-calibrating weekly PDSI, 
a self-calibrating monthly PDSI, and the original monthly PDSI.

* Most recently translated to C++ from FORTRAN by Rob Reed and Nate Wells, 
University of Nebraska - Lincoln, advised by Dr. Steve Goddard - July 2001.

    > Methodology based on Research Paper No. 45; Meteorological Drought; by 
    Wayne C. Palmer for the U.S. Weather Bureau, February 1965.

* Based mostly on the source code of pdsi.f, a FORTRAN program that calculates 
monthly PDSI values.  The source code came from NCDC, originally written by 
Tom Karl, and revised by Roger Winchell, Alan McNab, and Richard Heim.

* Slight modifications in the algorithm were made based on the source of 
palmcode.f, a FORTRAN program that calculates weekly PDSI values, received from 
Tom Heddinghaus at NCEP, who is also the original author of that particular code.

    Additional modifications were made to adapt the algorithm to a weekly time 
    scale based on recalculations of several constants as described in Palmer's paper.

* __August 2001__

Additional modifications were made to attempt to make this program completely 
independent of emperically derived formulas. This will allow the program to 
perform accurately in any enviroment. Most changes came in the addition of the 
Calibrate() function.  These changes were made in order to
make comparisions between stations more accurate.  --

* __May 2002__  
The incorporation of a self-calibrating monthly and the oringal monthly PDSI. 

* __Jun 2002__  
Changed the calibration method to calibrate the climatic characteristic based 
on the quartiles instead of the max and min.
