#!/usr/bin/env python
# -*- coding: utf-8 -*-

# utilisation du module
from Adafruit_Thermal import *

# déclaration objet imprimante
printer = Adafruit_Thermal("/dev/ttyUSB0", 9600)

# configuration 
printer.begin(140)
# restauration valeurs pas défaut
printer.setDefault()

# normal
printer.println("Normal")

# Texte inversé
printer.inverseOn()
printer.println("Inversion")
printer.inverseOff()

# tailles double
printer.doubleHeightOn()
printer.println("Double Hauteur")
printer.doubleWidthOn()
printer.println("Double Tout")
printer.doubleHeightOff()
printer.println("Double Largeur")
printer.doubleWidthOff()

# alignement
printer.justify('R')  # Right
printer.println("Droite")
printer.justify('C')  # Center
printer.println("Centre")
printer.justify('L')  # Left
printer.println("Gauche")

# gras
printer.boldOn()
printer.println("En gras")
printer.boldOff()

# souligner 
printer.underlineOn()
printer.println("Souligne")
printer.underlineOff()

# défilement du papier
printer.feed(2)
