/*********************************************************************
* Filename:   fbdt.cpp
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
#include "fbdt.h"

using namespace std;

void asignar_ceros(int ***tabla, int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			memset(**tabla,0,n*sizeof (int));
		}
		
	}
}

void print_table(int ***table, int n){
	for (int k=0;k<n;++k){
		printf("Con k=%d \n",k);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<table[i][j][k]<<" ,";
			}
			cout<<"\n";
		}
	}
}

int get_max(int ***table, int n){
	int max=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for(int k=0;k<n; ++k)
			{
				if(max<table[i][j][k] && i!=0 && k!=0){
					max=table[i][j][k];
				}
			}
		}
		
	}
	return max;
}

void FBDT(unsigned char *S_box, int n){
	int valores_n=pow(2,n);

	//Declarando tabla con apuntadores
	int *** FBDT_tabla = new int**[valores_n];
	int i=0,j=0,k=0, cont=0, max=0,a_int, b_int, c_int, X_int;
	unsigned char res,res2,a,b, c, X; 
	for (i = 0; i < valores_n; i++){
		FBDT_tabla[i] = new int*[valores_n];
		for (int j = 0; j < valores_n; j++){
			FBDT_tabla[i][j] = new int[valores_n];
		}
	}
	i=0;
	j=0;
	asignar_ceros(FBDT_tabla,valores_n); 
	for(a_int=0; a_int<valores_n;a_int++){
		a=(unsigned char)a_int;
		printf("a=%2x\n",a);
		for (b_int = 0; b_int < valores_n; b_int++)
		{
			b=(unsigned char)b_int;
			for(c_int=0; c_int < valores_n; c_int++)
			{
				c=(unsigned char)c_int;
				for (X_int = 0; X_int < valores_n; X_int++)
				{
					X=(unsigned char)X_int;
					res=S_box[X]^S_box[X^a]^S_box[X^b]^S_box[(X^a)^b];
					if(res==0){
						res2=S_box[X]^S_box[X^a];
						if(res2==c){
							FBDT_tabla[i][j][k]=FBDT_tabla[i][j][k]+1;

						}
					}
				}
				k++;
			}
		   	j++;
		   	k=0;
		}
		i++;
		j=0;
	}

	//print_table(FBDT_tabla,valores_n);
	max=get_max(FBDT_tabla,valores_n);
	cout<<"Max FBCT= "<<max<<	"\n";
}