## Penman scPDSI

This project didn't modified any sub function in original `scPDSCI.cpp`, except 
ET module. This repository is trying to replace ET module with Penman 
Evapotranspiration. The result is exactly same as the original ones. 

Linux `diff` is used to make sure the result of original version and this one is exactly the same. 

```bash
Debug\scPDSI.exe -idata\example -odata potentials & diff -r data ..\scPDSI-org\data > diff.txt & subl diff.txt
```

### Updates
- 27 July, 2018 (ET module works now)  
    --------- 
    If you need `scPDSI_penman`, just put `weekly_PET` or 
    `monthly_PET`in the input directory. `weekly_PET`(`monthly_PET`) is in the same
    unit and format as `weekly_P` (`monthly_P`). When having no `PET` input, the result
    is the same as original.

    I only checked the weekly outputs with the original one. Using original `PET` 
    from `potentials` file as `weekly_PET` input, 1 and 2 week output are exactly 
    same as original. For other scales, the difference may be due to that, 
    when saving `PET` into txt, the accuracy is loss in some extent. This need 
    to further check in the future.


### Setup Project environment

1. Download [Eclipse IDE for C/C++ Developers](https://www.eclipse.org/downloads/packages/). **Make sure Eclipse path has no special characters**. 
2. Install [Rtools](https://cran.r-project.org/bin/windows/Rtools/). 
3. Now you can run this project in Eclipse.


---
## Document for original [scPDSI V2.0](http://greenleaf.unl.edu/). 

Calculates the Palmer Drought Severity Index for a given station.


## 1.1 Four input files for weekly PDSI calculations:

* `weekly_T` and `weekly_P`  
Weekly temperature and precipitation files; 
each line starts with the year and is followed by 52 data entries. 
It is important to note that only 52 weeks are on each line, even though 52 
weeks is only 364 days. 
This data must be gathered in such a way that the kth week of the year always 
represents the same calendar interval.  For example, the first week should 
always represent Jan 1 through Jan 7.

* `wk_T_normal`  
The average weekly temperature for each week of the year. One line, 52 data entries.
* `parameter` 
contains two numbers specific to each station: 
    - `Su` (in inches) the underlying soil water capacity, and
    - `TLA`: the negative of the tangent of the latitude of the station. 

## 1.2 Four input files for monthly PDSI calculations:

* `monthly_T` and `monthly_P`  
  Monthly temperature and precipitation files; each line starts with the year
  and is followed by 12 data entries.

* `mon_T_normal`  
  The average monthly temperature for each week of the year.  One line, 12
  data entries.

* `parameter`  
  same as above.

## 1.3. Extra notes on input files

The format of these files matches the format of the original FORTRAN program. 
There is no precise need for this format to be used.

The program is able to calculate the weekly PDSI, the original monthly PDSI and 
the monthly self-calibrating PDSI if all the data is in the same directory. 

It is possible to use the filename `T_normal` in place of either `mon_T_normal` 
or `wk_T_normal`.  For example, the program will try to open `mon_T_normal` 
first, and then `T_normal`.  If `T_normal` is opened, it will check to make 
sure it is the right format by counting the number of entries in the file.
This was done to allow the program to work on the exact same input data as the 
original FORTRAN program, allowing comparisons.
  
## 2.1 Output Files

There are two formats of output, table and column, which are selected by
command line options.  The table output files end with .tbl and the column
output files end with .clm.  The table files list a whole year's worth of
resultsing values on each line while the column files list the year and week
followed by the resulting value on each line.

| file         | description | 
| --------     | ----------- |
|`PDSI.tbl` and/or `PDSI.clm`| The Palmer Drought Severity Index values|
|`PHDI.tbl` and/or `PHDI.clm`| The Palmer Hydrological Drought Index values.|
|`WPLM.tbl` and/or `WPLM.clm`| The "Weighted" Palmer Index.  An average of either X1 and X3, or X1 and X2 weighted by the probability of the current spell ending.  For more information, see how the `WPLM` is calculated in the `pdsi::write()` function.|
|`ZIND.tbl` and/or `ZIND.clm` | The Z Index, or the moisture anomaly|

## 2.2 Other possible output files, depending on certain flags

| file         | description | 
| --------     | ----------- |
| `WB.tbl`     |  The water ballance coefficients (Alpha, Beta, Gamma, & Delta) for each week/month.    | 
|`bigTable.tbl`| Z, % Prob(end), X1, X2, and X3 for every week/month.|
|`potentials`  | P, PE, PR, PRO, PL, and P - PE for every week/month. |
|`dvalue`|The moisture departure, d, for every week/month.|


------------
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
