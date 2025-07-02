/*********************************************************************
* Filename:   ddt.h
* Author:     David Carcaño Ventura (carvendavid@gmail.com)
* Data:       Nov 27, 2023, actualizado el 19 de febrero
* Using:      To create the DDT table for getting the CarD1 property
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
//const size_t filas = 256; 
//const size_t columnas = 256;
//const size_t planos = 256;
//void asignar_ceros(int **tabla, int n);

//void print_table(int **tabla, int n);

int get_max_ddt(int **tabla, int n);
int get_card1(int **tabla, int n);
void DDT(unsigned char *S_box, int n, int band);