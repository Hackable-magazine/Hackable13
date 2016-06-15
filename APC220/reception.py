#!/usr/bin/python
# -*- coding: utf-8 -*-

# utilisation du module Python Serial
import serial

# ouverture du port en 2400 bps
ser = serial.Serial('/dev/ttyUSB0', 2400, timeout=4)

# Astuce pour intercepter un Ctrl+C
try:
  # boucle infinie
  while 1:
    # lecture des données ligne par ligne
    line = ser.readline()
    # suppression du CRLF
    line = line.replace('\r\n', '')
    # affichage de la ligne reçue
    print line
# capture du Ctrl+c et sortie de boucle
except KeyboardInterrupt:
  print "CTRL+C !"

# fermeture du port série
print "Fermeture"
ser.close()
