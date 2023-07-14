/*********************************************************************
* Filename:   string_uchar.h
* Authors:     David Carcaño Ventura (carvendavid@gmail.com), 
*              Lil Rodríguez Henríquez (lmrodriguez@inaoep.mx),
*              Saúl Pomares Hernández (spomares@inaoep.mx)
* Data:       June 20, 2023
* Using:      To print u_char strings
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
#include "string_uchar.h"

using namespace std;

void printf_uchar(unsigned char *cadena, int tam, string nombre){
	cout<<"\n"<<nombre<<"\n";        
	for(int i=0; i<tam; i++)
   	{
     	    printf("%2x ", cadena[i]);
   	}
   	printf("\n");
}

void printf_uint8(uint8_t *cadena, int tam, string nombre){
	cout<<"\n"<<nombre<<"\n";        
	for(int i=0; i<tam; i++)
   	{
     	    printf("%2x ", cadena[i]);
   	}
   	printf("\n");
}

void Xor(unsigned char *destino, unsigned char *A, unsigned char *B, int tam){
	 for(int i=0; i<tam; i++)
  	 {
     	     destino[i]=A[i]^B[i];
   	 }
}

