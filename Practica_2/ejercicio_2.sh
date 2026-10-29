#!/bin/bash
fecha=$1

#se "acomoda" la fecha a formato ISO para pasarla al comando date
IFS=- read -r dia mes anio <<< $fecha
#se asigna para pasarla en una sola variable
fecha_iso="$anio-$mes-$dia"

date -d $fecha_iso '+%A'