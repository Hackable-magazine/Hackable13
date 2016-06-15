#!/usr/bin/env python
# -*- coding: utf-8 -*-

# module Adafruit
from Adafruit_Thermal import *

# module Python Imaging
import Image

# configuration
printer = Adafruit_Thermal("/dev/ttyUSB0", 9600, timeout=5)
printer.begin(140)

# un texte
printer.println("Voici une image :")
printer.feed(1)

# une image
printer.printImage(Image.open('image.png'), True)
printer.feed(2)
