#!/bin/bash
counter=1

echo -n "Ingresse direccion: "
read path
echo -n "Ingrese extension:  "
read extension

if [[ -d $path ]]; then
    echo "DIR existe"
    for archivo in $path/*$extension; do
        mv "$archivo" "$path/programa$counter.$extension" 
        echo $archivo    
        ((counter++))
    done
    else
    echo "ERROR: DIR no existe"
fi
