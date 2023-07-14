/*********************************************************************
* Filename:   fbdt.h
* Authors:     David Carcaño Ventura (carvendavid@gmail.com), 
*  			   Lil Rodríguez Henríquez (lmrodriguez@inaoep.mx),
*			   Saúl Pomares Hernández (spomares@inaoep.mx)
* Data:       June 20, 2023
* Using:      To create a tool for analyzing S-box
* Details:    
*********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include <bitset>
#include "math.h"
#include <stdint.h>

using namespace std;



void asignar_ceros(int ***tabla, int n);

void print_table(int ***table, int n);

int get_max(int ***table, int n);

void FBDT(unsigned char *S_box, int n);
//#endif