/*
 *  brho.c
 *  conversion
 *
 *  Created by JB Lagrange.
 *  Copyright 2014 Imperial College. All rights reserved.
 *
 */


#include "brho.h"


int main(int argc, char *argv[]) {
	
	double m0, z, q, momentum, etot, ekin, beta, gamma, brho;
	
	printf("\n");
	//printf("%s\n", argv[0]);
	//printf("%s\n", argv[1]);
	//printf("%s\n", argv[2]);
	//printf("%s\n", argv[3]);
	//printf("%s\n", argv[4]);
	//printf("%s\n", argv[5]);
	
	if(strcmp(argv[1], "doc") == 0 || strcmp(argv[1], "Doc") == 0 || strcmp(argv[1], "DOC") == 0) {
		COLOR("42");
		printf("Conversion from rigidity\t\t\n");
		printf("Created by JB Lagrange\t\t\t\n");
		printf("Use at your own risk.\t\t\t\n");
		printf("Instructions:\t\t\t\t\n");
		printf("argument 1: type of particle \t\t\n(electron, proton, muon, pion, tau)\t\n");
		printf("argument 2: rigidity value\t\t\n");
		printf("argument 3: unit of rigidity value\t\n");
		printf("!!!IF argument 1 is 'ion'!!!\t\t\n");
		printf("argument 2: number of atomic mass\t\n");
		printf("argument 3: number of charges\t\t\n");
		printf("argument 4: rigidity value\t\t\n");
		printf("argument 5: unit of rigidity value\t\n");
		COLOR("0");
	}
	else {
		printf("Use 'doc' in argument 1 for information\t\n\n");
		if(strcmp(argv[1], "ion") == 0 || strcmp(argv[1], "Ion") == 0 || strcmp(argv[1], "ION") == 0) {
			z = atof(argv[2]);
			//printf("z = %lf", z);
			m0 = z*ATOMICMASS;
			q = atof(argv[3]);
			//printf("q = %lf", q);
			brho = atof(argv[4]); // momentum per nucleon
			if(strcmp(argv[5], "tm") == 0 || strcmp(argv[5], "T.m") == 0 || strcmp(argv[5], "TM") == 0 || strcmp(argv[5], "T.M") == 0 || strcmp(argv[5], "t.m") == 0) {
				brho *=1.;
			}
			else {
				COLOR("1;31");
				printf("\nkeyword: %s", argv[5]);
				errorstop(" unrecognized. \nOnly 'T.m' is OK.");
			}
		}
		
		else {
			if(strcmp(argv[1], "muon") == 0 || strcmp(argv[1], "Muon") == 0 || strcmp(argv[1], "MUON") == 0) {
				m0 = MUONM;
				q = 1.;
			}
			
			else if(strcmp(argv[1], "proton") == 0 || strcmp(argv[1], "Proton") == 0 || strcmp(argv[1], "PROTON") == 0) {
				m0 = PROTONM;
				q = 1.;
			}
			else if(strcmp(argv[1], "electron") == 0 || strcmp(argv[1], "Electron") == 0 || strcmp(argv[1], "ELECTRON") == 0) {
				m0 = ELECTRONM;
				q = 1.;
			}
			else if(strcmp(argv[1], "pion") == 0 || strcmp(argv[1], "Pion") == 0 || strcmp(argv[1], "PION") == 0) {
				m0 = PIONM;
				q = 1.;
			}
			else if(strcmp(argv[1], "tau") == 0 || strcmp(argv[1], "Tau") == 0 || strcmp(argv[1], "TAU") == 0) {
				m0 = TAUM;
				q = 1.;
			}
			else {
				COLOR("1;31");
				printf("\nkeyword: %s", argv[1]);
				errorstop(" unrecognized. \nOnly 'muon', 'pion', 'proton', 'electron', 'tau' and 'ion' are OK.");
			}	
			brho = atof(argv[2]);
			if(strcmp(argv[3], "tm") == 0 || strcmp(argv[3], "T.m") == 0 || strcmp(argv[3], "TM") == 0 || strcmp(argv[3], "T.M") == 0 || strcmp(argv[3], "t.m") == 0) {
				brho *=1.;
			}
			else {
				COLOR("1;31");
				printf("\nkeyword: %s", argv[3]);
				errorstop(" unrecognized. \nOnly 'T.m' is OK.");
			}	
		}
		momentum = fabs(brho)*CLIGHT*q;
		etot = sqrt(momentum*momentum + m0*m0);
		ekin = etot - m0;
		gamma = etot/m0;
		beta = sqrt(1-1/(gamma*gamma));
		
		COLOR("42");
		if(strcmp(argv[1], "ion") == 0 || strcmp(argv[1], "Ion") == 0 || strcmp(argv[1], "ION") == 0) {
			if(m0 < 1.e3) printf("E0 = %lf eV\t\n", m0);
			else if(m0 < 1.e6) printf("E0 = %lf KeV\t\n", m0*1.e-3);
			else if(m0 < 1.e9) printf("E0 = %lf MeV\t\n", m0*1.e-6);
			else if(m0 < 1.e12) printf("E0 = %lf GeV\t\n", m0*1.e-9);
			else printf("E0 = %lf TeV\t\n", m0*1.e-12);
			
			if(ekin < 1.e3) printf("Ekin = %lf eV ", ekin);
			else if(ekin < 1.e6) printf("Ekin = %lf KeV ", ekin*1.e-3);
			else if(ekin < 1.e9) printf("Ekin = %lf MeV ", ekin*1.e-6);
			else if(ekin < 1.e12) printf("Ekin = %lf GeV ", ekin*1.e-9);
			else printf("Ekin = %lf TeV ", ekin*1.e-12);
			
			if(ekin/z < 1.e3) printf("(%lf eV/u)\t\n", ekin/z);
			else if(ekin/z < 1.e6) printf("(%lf KeV/u)\t\n", ekin/z*1.e-3);
			else if(ekin/z < 1.e9) printf("(%lf MeV/u)\t\n", ekin/z*1.e-6);
			else if(ekin/z < 1.e12) printf("(%lf GeV/u)\t\n", ekin/z*1.e-9);
			else printf("(%lf TeV/u)\t\n", ekin/z*1.e-12);
			
			if(etot < 1.e3) printf("Etot = %lf eV ", etot);
			else if(etot < 1.e6) printf("Etot = %lf KeV ", etot*1.e-3);
			else if(etot < 1.e9) printf("Etot = %lf MeV ", etot*1.e-6);
			else if(etot < 1.e12) printf("Etot = %lf GeV ", etot*1.e-9);
			else printf("Etot = %lf TeV ", etot*1.e-12);
			
			if(etot/z < 1.e3) printf("(%lf eV/u)\t\n", etot/z);
			else if(etot/z < 1.e6) printf("(%lf KeV/u)\t\n", etot/z*1.e-3);
			else if(etot/z < 1.e9) printf("(%lf MeV/u)\t\n", etot/z*1.e-6);
			else if(etot/z < 1.e12) printf("(%lf GeV/u)\t\n", etot/z*1.e-9);
			else printf("(%lf TeV/u)\t\n", etot/z*1.e-12);
			
			if(momentum < 1.e3) printf("P = %lf eV/c ", momentum);
			else if(momentum < 1.e6) printf("P = %lf KeV/c ", momentum*1.e-3);
			else if(momentum < 1.e9) printf("P = %lf MeV/c ", momentum*1.e-6);
			else if(momentum < 1.e12) printf("P = %lf GeV/c ", momentum*1.e-9);
			else printf("P = %lf TeV/c ", momentum*1.e-12);
			
			if(momentum/z < 1.e3) printf("(%lf eV/c/u)\t\n", momentum/z);
			else if(momentum/z < 1.e6) printf("(%lf KeV/c/u)\t\n", momentum/z*1.e-3);
			else if(momentum/z < 1.e9) printf("(%lf MeV/c/u)\t\n", momentum/z*1.e-6);
			else if(momentum/z < 1.e12) printf("(%lf GeV/c/u)\t\n", momentum/z*1.e-9);
			else printf("(%lf TeV/c/u)\t\n", momentum/z*1.e-12);
			
			printf("gamma = %lf\t\n", gamma);
			printf("beta = %lf\t\t\n", beta);
			printf("brho = %lf T.m\t\n", brho);
		}	
		
		else {
			if(m0 < 1.e3) printf("E0 = %lf eV\t\n", m0);
			else if(m0 < 1.e6) printf("E0 = %lf KeV\t\n", m0*1.e-3);
			else if(m0 < 1.e9) printf("E0 = %lf MeV\t\n", m0*1.e-6);
			else if(m0 < 1.e12) printf("E0 = %lf GeV\t\n", m0*1.e-9);
			else printf("E0 = %lf TeV\t\n", m0*1.e-12);
			
			if(ekin < 1.e3) printf("Ekin = %lf eV\t\n", ekin);
			else if(ekin < 1.e6) printf("Ekin = %lf KeV\t\n", ekin*1.e-3);
			else if(ekin < 1.e9) printf("Ekin = %lf MeV\t\n", ekin*1.e-6);
			else if(ekin < 1.e12) printf("Ekin = %lf GeV\t\n", ekin*1.e-9);
			else printf("Ekin = %lf TeV\t\n", ekin*1.e-12);
			
			if(etot < 1.e3) printf("Etot = %lf eV\t\n", etot);
			else if(etot < 1.e6) printf("Etot = %lf KeV\t\n", etot*1.e-3);
			else if(etot < 1.e9) printf("Etot = %lf MeV\t\n", etot*1.e-6);
			else if(etot < 1.e12) printf("Etot = %lf GeV\t\n", etot*1.e-9);
			else printf("Etot = %lf TeV\t\n", etot*1.e-12);
			
			if(momentum < 1.e3) printf("P = %lf eV/c\t\n", momentum);
			else if(momentum < 1.e6) printf("P = %lf KeV/c \t\n", momentum*1.e-3);
			else if(momentum < 1.e9) printf("P = %lf MeV/c \t\n", momentum*1.e-6);
			else if(momentum < 1.e12) printf("P = %lf GeV/c \t\n", momentum*1.e-9);
			else printf("P = %lf TeV/c \t\n", momentum*1.e-12);
			
			printf("gamma = %lf\t\n", gamma);
			printf("beta = %lf\t\t\n", beta);
			printf("brho = %lf T.m\t\n", brho);
		}	
	}
	COLOR("0");
	printf("\n");
	return 0;
}	

extern void errorstop(char *error_text)
{
	COLOR("1;31");
	printf("%s\n", error_text);
	printf("\nerrorstop procedure...\n");
	printf("...now exiting to system...\n");
	COLOR("0");
	exit(1);
}

//get total energy, beta, gamma of a given Particle
//static void get_ebg_part(double *e_tot, double *beta, double *gamma, struct Particle *part)
//{
//	*e_tot	= sqrt(pow(part->m0*CLIGHT2, 2) + (part->brho*part->q*part->brho*part->q)*CLIGHT2);
//	*gamma	= *e_tot/(part->m0*CLIGHT2);
//	*beta	= sqrt((*gamma)*(*gamma) - 1)/(*gamma);
//}
