#!/bin/bash
# echo -n "Dirección al archivo de usuarios.txt"
# read usuario
# echo -n "Direccion al archivo de claves.txt"
# read clave

usuarios="/home/matias/SistemasOperativos/Practica_2/usuarios/usuarios.txt"
claves="/home/matias/SistemasOperativos/Practica_2/usuarios/claves.txt"


if [[ ! -f "$usuarios" || ! -s "$usuarios" ]]; then
    echo "El archivo de usuarios no existe o está vacío"
    exit 1
    else 
    lineasUsuarios=$(wc -l < $usuarios)
fi 

if [[ ! -f $claves || ! -s $claves ]]; then
    echo "El archivo de claves no existe o está vacío"
    exit 1
    else
    lineasClaves=$(wc -l < $claves)
fi 

if [[ $lineasUsuarios -eq $lineasClaves ]]; then
        echo "ambos archivos tienen la misma cantidad de lineas"
    else
    echo "Los archivos tienen distinta cantidad de lineas"
fi

lineasUsuarios=$(awk 'END { print NR }' "$usuarios")

lineasClaves=$(awk 'END { print NR }' "$claves")


echo $lineasUsuarios
echo $lineasClaves

paste -d " " $usuarios $claves > /home/matias/SistemasOperativos/Practica_2/usuarios/passwd.txt



read -p "Ingrese Usuario: " usuarioIngresado

read -s -p "Ingrese clave: " claveIngresada 

if awk -v usuario="$usuarioIngresado" -v clave="$claveIngresada" \
    'tolower($1) == tolower(usuario) && $2 == clave { encontrado=1 }
     END { exit !encontrado }' \
    "/home/matias/SistemasOperativos/Practica_2/usuarios/passwd.txt"; then
    echo "Accedido"
else
    echo "Usuario o clave incorrecta"
fi