/*********************************************************************
* Filename:   lat.cpp
* Author:     David Carcaño Ventura (carvendavid@gmail.com)
* Data:       February 19, 2024
* Using:      To create a tool to get CarL1 from an S-box
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
#include "lat.h"
#include "fbct.h"
#include "string_uchar.h"


using namespace std;


void minus_eight(int **tabla, int n, int exp){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			tabla[i][j]=tabla[i][j]-8;
			if (tabla[i][j]<0)
			{
				tabla[i][j]=tabla[i][j]*(-1);
			}
		}
		
	}
}

int get_max_lat(int **tabla, int n){
	int max=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(max<tabla[i][j] && i!=0 && j!=0){
				max=tabla[i][j];
			}
		}
		
	}
	return max;
}

int get_carl1(int **tabla, int n){
	int cont=0;
	int cont_arreglo[] = {1,2,4,8};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (tabla[cont_arreglo[i]][cont_arreglo[j]] !=0){
				cont=cont+1;
			}
			
		}
	}
	return cont;
}


unsigned char inner_product(unsigned char A, unsigned char B){
	// Perform bitwise AND operation to get the result with set bits where A and B both have 1s
    unsigned char result = A & B;
   
    // Initialize a counter for the number of set bits
    unsigned int count = 0;

    // Count the number of set bits in the result
    while (result!=0) {
        // Increment count if the least significant bit is set
        count ^= result & 1;

        // Right shift the result to check the next bit
        result >>= 1;
    }

    return count;
}



void LAT(unsigned char *S_box, int n, int band){
	int valores_n=pow(2,n);
	int i,j=0, cont=0, max=0, a_int, b_int, X_int,carl1;
	unsigned char res,a,b,X;

	//Declarando tabla con apuntadores
	int ** LAT_tabla = new int*[valores_n];
	for (i = 0; i < valores_n; i++){
		LAT_tabla[i] = new int[valores_n];
	}
	i=0;

	//Iniciar matriz con 0's
	asignar_ceros(LAT_tabla,valores_n); 

    for(a_int=0; a_int<valores_n;a_int++){
    	a=(unsigned char)a_int;
		for (b_int = 0; b_int < valores_n; b_int++)
		{
			b=(unsigned char)b_int;
			for (X_int = 0; X_int < valores_n; X_int++)
			{
				X=(unsigned char)X_int;
				res=inner_product(S_box[X],b);	
		   		if(res==inner_product(a,X)){
		   			cont++;
		   		}
			}
		   	LAT_tabla[i][j]=LAT_tabla[i][j]+cont;
		   	j++;
			cont=0;
		}
		j=0;
		i++;

	}
	minus_eight(LAT_tabla,valores_n,n); 
	if (band==1){
		cout<<"LAT\n";
		print_table(LAT_tabla,valores_n);
	}
	
	if (n==4)
	{
		carl1=get_carl1(LAT_tabla,valores_n);
		cout<<"CarL1= "<<carl1<<	"\n";
	}
	
	

}



