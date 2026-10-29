#!/bin/bash
path=$1
fileName=$2

if [[ -d $path ]]; then
    echo "Ruta válida"
    echo "Comprimiendo archivos..."
    tar -cjvf "$fileName.tar.bz2" "$path"
    echo "Tamaño del directorio antes de comprimir: " 
    du -sh $path
    echo "Tamaño luego de comprimir: "
    ls -lsh "$fileName.tar.bz2"
    else
    echo "ERROR: el primer argumento debe ser una ruta valida"
    exit 1
fi


