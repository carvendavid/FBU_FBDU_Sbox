/*********************************************************************
* Filename:   LAT.cpp
* Author:     David Carcaño Ventura (carvendavid@gmail.com)
* Data:       Nov 27, 2023, actualizado el 19 de febrero
* Using:      To create the LAT table for getting the carl1 property
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

int get_max_lat(int **tabla, int n);
int get_carl1(int **tabla, int n);
void minus_eight(int **tabla, int n, int exp);
void get_array(unsigned char *A_array, unsigned char A);
void LAT(unsigned char *S_box, int n, int band);
unsigned char inner_product(unsigned char *A, unsigned char *B);