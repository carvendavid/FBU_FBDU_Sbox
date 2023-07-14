/*********************************************************************
* Filename:   fbct.cpp
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
#include "fbct.h"

using namespace std;
void asignar_ceros(int **tabla, int n){
	for (int i = 0; i < n; ++i)
	{
		memset(*tabla,0,n*sizeof (int));
	}
}

void print_table(int **tabla, int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<tabla[i][j]<<" ,";
		}
		cout<<"\n";
	}
}

int get_max(int **tabla, int n){
	int max=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(max<tabla[i][j] && i!=0 && j!=0 && i!=j){
				max=tabla[i][j];
			}
		}
		
	}
	return max;
}


void FBCT(unsigned char *S_box, int n){
	int valores_n=pow(2,n);
	int i,j=0, cont=0, max=0, a_int, b_int, X_int;
	unsigned char res,a,b,X;

	//Declarando tabla con apuntadores
	int ** FBCT_tabla = new int*[valores_n];
	for (i = 0; i < valores_n; i++){
		FBCT_tabla[i] = new int[valores_n];
	}
	i=0;

	//Iniciar matriz con 0's
	asignar_ceros(FBCT_tabla,valores_n); 

    for(a_int=0; a_int<valores_n;a_int++){
    	a=(unsigned char)a_int;
		for (b_int = 0; b_int < valores_n; b_int++)
		{
			b=(unsigned char)b_int;
			for (X_int = 0; X_int < valores_n; X_int++)
			{
				X=(unsigned char)X_int;
				res=S_box[X]^S_box[X^a]^S_box[X^b]^S_box[(X^a)^b];	
		   		if(res==0){
		   			cont++;
		   		}
			}
		   	FBCT_tabla[i][j]=FBCT_tabla[i][j]+cont;
		   	j++;
			cont=0;
		}
		j=0;
		i++;

	}
	print_table(FBCT_tabla,valores_n);



	max=get_max(FBCT_tabla,valores_n);
	cout<<"Max FBCT= "<<max<<	"\n";
}