#!/bin/bash
rutaArchivo=$1

if [[ ! -f $rutaArchivo ]];
then
    echo "Solo se permiten rutas"
    exit 1
fi

#Buen ejemplo para leer linea por línea
while IFS= read -r linea || [[ -n "$linea" ]]; do
echo "Linea leída  $linea"

done < $rutaArchivo


(head; tail) < $rutaArchivo

#lee el contenido de un archivo de texto
cat $rutaArchivo

#lee el contenido de un archiuvo de texto de manera invertida 
#y usando el operador de direccionamiento lo guarda en un archivo .out
tac $rutaArchivo > nuevo.out

