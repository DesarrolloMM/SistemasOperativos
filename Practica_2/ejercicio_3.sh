#!/bin/bash
fecha=$1

IFS=- read -r dia mes anio <<< $fecha

fecha_iso="$anio-$mes-$dia"

segundos_inicio=$(date -d $fecha_iso +%s)
segundos_fin=$(date +%s)

diferencia=$(($segundos_fin - $segundos_inicio))

dias_transcurridos=$((diferencia / 86400))


echo $segundos_fin
echo $segundos_inicio
echo $dias_transcurridos
echo $(($(($segundos_inicio / 86400)) / 365))
echo $(($dias_transcurridos / 365))