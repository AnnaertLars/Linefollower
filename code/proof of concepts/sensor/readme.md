# Sensoren proof of concept

minimale hard- en software die aantoont dat minimaal 6 sensoren onafhankelijk van elkaar kunnen uitgelezen worden (geen calibratie, normalisatie of interpolatie). Hierbij moet een zo groot mogelijk bereik van de AD converter benut worden (indien van toepassing)

# Arduino code:
De arduino code staat in het .ino bestand.

Hierbij maken we gebruik van de QTRSensors.h library. Deze maakt het mogelijk om de sensor evenvoudig te configureren en de waardes uit te lezen. Vervolgens worden deze 6 sensorwaardes naast elkaar geprint op de seriële monitor. 

# Elektrisch schema:
De aansluitng van de sensor staat in de pdf bovenaan.
