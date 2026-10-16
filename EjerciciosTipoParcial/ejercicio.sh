#!/bin/bash

#usar shift para el bucle
#usar operador de direccionamiento >> agrega

RUTA = $1

argCant = $# <-cantidad de parámetros indefinidos

if ![[ -f $Ruta]]; then
	echo "Error: la ruta es inválida";
	exit 1;
fi

mkdir -p $(cifras"RUTA")

touch 3cifras.txt

open 3cifras.txt

for[$#]{ 
	if[[regex[0-9]{3}]]; then
		grabar en archivo
	fi
}


