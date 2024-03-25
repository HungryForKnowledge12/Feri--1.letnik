#!/bin/bash

# sprazni datoteke, ce je bilo kaj noter napisano
> izhod.txt
> rezultati.txt

# regex emaila
email_regex='[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}'

# pregled vseh datotek
for file in Datoteka_1.txt Datoteka_2.txt Datoteka_3.txt; do
    grep -Eo $email_regex $file >> izhod.txt

    count=$(grep -Eo $email_regex $file | wc -l)

    echo "Število poštnih naslovov $file: $count" >> rezultati.txt
done

# presteje skupno stevilo emailov
total_count=$(cat izhod.txt | wc -l)

# zapise stevilo emailov na zacetek rezultati.txt
echo "Število poštnih naslovov: $total_count" >> rezultati.txt

# Zdruzi datoteki izhod.txt in rezultati.txt
cat izhod.txt >> rezultati.txt
