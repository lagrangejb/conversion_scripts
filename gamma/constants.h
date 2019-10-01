/*
 *  constant.h
 *  conversion
 *
 *  Copyright 2014 Imperial College. All rights reserved.
 *
 */

#ifndef CONSTANTS
#define CONSTANTS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/* ******************** universal constants - SI Units ******************** */
#define PI				3.1415926535898
#define TWOPI			6.2831853071796
#define UNITCHARGE		1.602177330e-19				/*[C]*/

#define PROTONMSI		1.6726231e-27				/*[kg]*/
#define ELECTRONMSI		9.1093897e-31				/*[kg]*/
#define MUONMSI			1.8835323e-28				/*[kg]*/
#define PIONMSI			2.4880623e-28				/*[kg]*/

#define PROTONM			938.27234e6					/*[eV/c/c]*/
#define ELECTRONM		5.10999e5					/*[eV/c/c]*/
#define MUONM			105.65837e6					/*[eV/c/c]*/
#define PIONM			139.57018e6					/*[eV/c/c]*/
#define ATOMICMASS		931.494e6					/*[eV/c/c]*/
#define TAUM			1.777e9						/*[eV/c/c]*/

#define CLIGHT			2.99792458e8				/*[m/s]*/
#define CLIGHT2			8.987551787368176e16		/*[m*m/s/s]*/

/* ******************** simulation's parameters ******************** */
/* arrays size ------------------------------------------------------------------------------------------ */
#define KEYWORDL		25				/* maximum characters to define keyword string */

/* Input files parameter(s) ______________________________________________________________________________ */
#define MAX_CHARINLINE	200				/* maximum number of characters in each line of input files */
#define FILENAME_L		100				/* maximum number of character to define a name of file, such as a map file name */

/* Very small and very large numbers ______________________________________________________________________________ */
#define TINYLENGTH		1.e-12			/* [m] > 0!!! a very small length (used to check if a particle is right on a boundary for instance)*/
#define TINYDIMLESS		1.e-12			/* [\] */
#define EPS_MAPPOSI		5.e-4			/* [m] maximum allowed discrepancy between the expected node coordinates and its coodrinates in the field map data file */
#define NOOVFLOW_ENGE	100				/* [\] magic number used to avoid overflowing the largest double in field calculations with Enge type fringe field (see get_field.c)*/

/* ******************** Booleans! ******************** */
#define TRUE			1				/* [\int] has to be an integer!! */
#define FALSE			0				/* [\int] has to be an integer!! */
#define YES				1				/* [\int] has to be an integer!! */
#define NO				0				/* [\int] has to be an integer!! */

/* ******************** Colors in terminal ******************** */

// erase screen, and place the cursor on the left
#define CLRSCR() printf("\r")

// colors selection
#define COLOR(param) printf("\033[%sm",param)
//   param has to be const char *, empty (identical to "0") or made by values separated with ; 
// 0  initialize         1  high intensity (font)
// 5  blinking             7 inversed video
// 30, 31, 32, 33, 34, 35, 36, 37 letters color
// 40, 41, 42, 43, 44, 45, 46, 47 background color
// black, red, green, yellow, blue, magenta, cyan and white 

#endif

