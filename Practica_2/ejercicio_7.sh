#!/bin/bash
echo Menu
echo "1 > Tipo"
echo "2 > Tamaño" 
echo "3 > Permisos"
echo "4 > Por Inodo"

read -p "Seleccione una opcion con el numero: " opcion  
read -p "ingrese la ruta donde desea buscar: " ruta
if [[ ! -d $ruta ]]; then
    echo "La ruta no existe"    
else

case "$opcion" in
    1)
    read -p "Ingrese el tipo a buscar: 'f' solo archivos,'d' directorio,'l' enlace simbolico: " type 
    type="${type,,}"
    find "$ruta" -type "$type"
    ;;
    2)
    read -p "Ingrese unidad 'c' para bytes, 'k' kylobytes, 'M' megabytes, 'G' Gygabytes" subOpcion
    read -p "Ingrese tamaño: " size
    find $ruta -size +"$size""$subOpcion"
    ;;
    3)
    ;;
    4)
    ;;
    *)
    echo "Opcion no valida";;
    esac

fi