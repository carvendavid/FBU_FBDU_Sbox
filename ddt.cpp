/*********************************************************************
* Filename:   ddt.cpp
* Author:     David Carcaño Ventura (carvendavid@gmail.com)
* Data:       February 19, 2024
* Using:      To create a tool to get CarD1 from an S-box
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



int get_max_ddt(int **tabla, int n){
	int max=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(max<tabla[i][j] && i!=0){
				max=tabla[i][j];
			}
		}
		
	}
	return max;
}

int get_card1(int **tabla, int n){
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




void DDT(unsigned char *S_box, int n, int band){
	int valores_n=pow(2,n);
	int i,j=0, cont=0, max=0, a_int, b_int, X_int,card1;
	unsigned char res,a,b,X;

	//Declarando tabla con apuntadores
	int ** DDT_tabla = new int*[valores_n];
	for (i = 0; i < valores_n; i++){
		DDT_tabla[i] = new int[valores_n];
	}
	i=0;

	//Iniciar matriz con 0's
	asignar_ceros(DDT_tabla,valores_n); 

    for(a_int=0; a_int<valores_n;a_int++){
    	a=(unsigned char)a_int;
		for (b_int = 0; b_int < valores_n; b_int++)
		{
			b=(unsigned char)b_int;
			for (X_int = 0; X_int < valores_n; X_int++)
			{
				X=(unsigned char)X_int;
				res=S_box[X]^S_box[X^a];	
		   		if(res==b){
		   			cont++;
		   		}
			}
		   	DDT_tabla[i][j]=DDT_tabla[i][j]+cont;
		   	j++;
			cont=0;
		}
		j=0;
		i++;

	}
	if(band==1){
		cout<<"DDT= \n";
		print_table(DDT_tabla,valores_n);
		
	}
	max=get_max_ddt(DDT_tabla,valores_n);
	cout<<"DU= "<<max<<	"\n";

	if (n==4)
	{
		card1=get_card1(DDT_tabla,valores_n);
		cout<<"CarD1= "<<card1<<	"\n";
	}
	
	
		
}