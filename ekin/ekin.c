/*
 *  ekin.c
 *  conversion
 *
 *  Created by JB Lagrange.
 *  Copyright 2014 Imperial College. All rights reserved.
 *
 */


#include "ekin.h"


int main(int argc, char *argv[]) {
	
	double m0, z, q, momentum, etot, ekin, beta, gamma, brho;
	
	printf("\n");
	if(strcmp(argv[1], "doc") == 0 || strcmp(argv[1], "Doc") == 0 || strcmp(argv[1], "DOC") == 0) {
		COLOR("42");
		printf("Conversion from kinetic energy\t\t\n");
		printf("Created by JB Lagrange\t\t\t\n");
		printf("Use at your own risk.\t\t\t\n");
		printf("Instructions:\t\t\t\t\n");
		printf("argument 1: type of particle \t\t\n(electron, proton, muon, pion, tau)\t\n");
		printf("argument 2: kinetic energy value\t\n");
		printf("argument 3: unit of kinetic energy value\n");
		printf("!!!IF argument 1 is 'ion'!!!\t\t\n");
		printf("argument 2: number of atomic mass\t\n");
		printf("argument 3: number of charges\t\t\n");
		printf("argument 4: kinetic energy value per nucleon\n");
		printf("argument 5: unit of kinetic energy value\n");
		COLOR("0");
	}
	//printf("%s\n", argv[0]);
	//printf("%s\n", argv[1]);
	//printf("%s\n", argv[2]);
	//printf("%s\n", argv[3]);
	//printf("%s\n", argv[4]);
	
	else {
		printf("Use 'doc' in argument 1 for information\t\n\n");
		if(strcmp(argv[1], "ion") == 0 || strcmp(argv[1], "Ion") == 0 || strcmp(argv[1], "ION") == 0) {
			z = atof(argv[2]);
			//printf("z = %lf", z);
			m0 = z*ATOMICMASS;
			q = atof(argv[3]);
			//printf("q = %lf", q);
			ekin = atof(argv[4]); // momentum per nucleon
			ekin *= z;
			if(strcmp(argv[5], "ev") == 0 || strcmp(argv[5], "eV") == 0 || strcmp(argv[5], "EV") == 0) {
				ekin *=1.;
			}
			else if(strcmp(argv[5], "mev") == 0 || strcmp(argv[5], "MeV") == 0 || strcmp(argv[5], "MEV/c") == 0 || strcmp(argv[5], "Mev/c") == 0) {
				ekin *=1.e6;
			}
			else if(strcmp(argv[5], "kev") == 0 || strcmp(argv[5], "KeV") == 0 || strcmp(argv[5], "KEV/c") == 0 || strcmp(argv[5], "Kev/c") == 0) {
				ekin *=1.e3;
			}
			else if(strcmp(argv[5], "gev") == 0 || strcmp(argv[5], "GeV") == 0 || strcmp(argv[5], "GEV/c") == 0 || strcmp(argv[5], "Gev/c") == 0) {
				ekin *=1.e9;
			}
			else if(strcmp(argv[5], "tev") == 0 || strcmp(argv[5], "TeV") == 0 || strcmp(argv[5], "TEV/c") == 0 || strcmp(argv[5], "Tev/c") == 0) {
				ekin *=1.e12;
			}
			else {
				COLOR("1;31");
				printf("\nkeyword: %s", argv[5]);
				errorstop(" unrecognized. \nOnly 'eV/c', 'KeV/c', 'MeV/c', 'GeV/c' and 'TeV/c' are OK.");
			}
			if(ekin < 0.) errorstop("ekin < 0");
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
			ekin = atof(argv[2]);
			if(strcmp(argv[3], "ev") == 0 || strcmp(argv[3], "eV") == 0 || strcmp(argv[3], "EV") == 0) {
				ekin *=1.;
			}
			else if(strcmp(argv[3], "mev") == 0 || strcmp(argv[3], "MeV") == 0 || strcmp(argv[3], "MEV") == 0 || strcmp(argv[3], "Mev") == 0) {
				ekin *=1.e6;
			}
			else if(strcmp(argv[3], "kev") == 0 || strcmp(argv[3], "KeV") == 0 || strcmp(argv[3], "KEV") == 0 || strcmp(argv[3], "Kev") == 0) {
				ekin *=1.e3;
			}
			else if(strcmp(argv[3], "gev") == 0 || strcmp(argv[3], "GeV") == 0 || strcmp(argv[3], "GEV") == 0 || strcmp(argv[3], "Gev") == 0) {
				ekin *=1.e9;
			}
			else if(strcmp(argv[3], "tev") == 0 || strcmp(argv[3], "TeV") == 0 || strcmp(argv[3], "TEV") == 0 || strcmp(argv[3], "Tev") == 0) {
				ekin *=1.e12;
			}
			else {
				COLOR("1;31");
				printf("\nkeyword: %s", argv[3]);
				errorstop(" unrecognized. \nOnly 'eV', 'KeV', 'MeV', 'GeV' and 'TeV' are OK.");
			}	
			if(ekin < 0.) errorstop("ekin < 0");
		}
		
		etot = ekin + m0;
		momentum = sqrt(etot*etot-m0*m0);
		gamma = etot/m0;
		beta = sqrt(1-1/(gamma*gamma));
		brho = momentum/CLIGHT/q;
		
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
			printf("beta = %lf\t\n", beta);
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
