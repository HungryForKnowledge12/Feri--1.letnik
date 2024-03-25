#!/bin/bash

echo "To je Linux!"

echo "Trenutna mapa:"
pwd

mkdir -v ~/TMapa
cd ~/TMapa
echo "Nahajas se v: $(pwd)"

touch datoteka1.txt datoteka2.txt
echo "Testne datoteke ustvarjene."

echo "Vsebina trenutne mape:"
ls -d

mkdir -v NovaMapa
mv datoteka2.txt NovaMapa/
echo "Datoteka 'datoteka2.txt' premaknjena v 'NovaMapa'."

echo "Vsebina 'NovaMapa':"
ls -d NovaMapa/

cd ..
rm -r TMapa
echo "Testa mapa je izbrisana."

echo "Skripta zaključena."