#!/bin/bash
arg1=$1
arg2=$2

argCant=$#

if [ $argCant -ne 2 ]; then
    echo "Error: Se requieren exactamente 2 argumentos."
    exit 1
fi


if ! [[ -f $arg1  ]]; then 
    echo "Error: El primer argumento debe ser una ruta a un archivo valida"
    exit 1
fi

if ! [[ $arg2 =~ ^[0-9]+$ ]]; then
    echo "Error: El segundo argumento debe ser un múmero entero positivo."
    exit 1
fi

echo "Esta es la ruta del archivo: $arg1"
echo "Segundo argumento, numero entero positivo: $arg2"
echo "Cantidad de argumentos: $argCant"  





