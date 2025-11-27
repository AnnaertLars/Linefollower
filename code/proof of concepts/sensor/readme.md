# Sensoren proof of concept

Minimale hard- en software die aantoont dat minimaal 6 sensoren onafhankelijk van elkaar kunnen uitgelezen worden (geen calibratie, normalisatie of interpolatie). Hierbij moet een zo groot mogelijk bereik van de AD converter benut worden (indien van toepassing). Hiervoor wordt de QTR-8A gebruikt, waarbij de laatste 2 sensoren van de printplaat niet worden gebruikt.

## Arduino code:
De arduino code staat in het .ino bestand.

Hierbij maken we gebruik van de QTRSensors.h library. Deze maakt het mogelijk om de sensor evenvoudig te configureren en de waardes uit te lezen. Vervolgens worden deze 6 sensorwaardes naast elkaar geprint op de seriële monitor. 

## Elektrisch schema:
De aansluitng van de sensor staat in het bestand .png bovenaan.
