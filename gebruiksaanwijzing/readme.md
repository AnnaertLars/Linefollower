# Gebruiksaanwijzing

### opladen / vervangen batterijen
De batterijen kunnen eenvoudig uit de wagen worden gehaald via de batterijconnector. De connector zit stevig vast, je kan deze voorzichtig losmaken met je vingers.
Controleer altijd de spanning van de batterijen met een multimeter. Als de spanning lager is dan 8 V, laad de batterijen dan op met de Liitokala-oplader (te vinden in de BOM).
Wanneer de oplader aangeeft dat de lampjes groen zijn, hebben de batterijen voldoende spanning en kan de wagen weer probleemloos gebruikt worden.

### draadloze communicatie
#### verbinding maken
  1. Zorg dat de wagen voorzien is van voldoende spanning (>8 V).
  2. Download de app Serial Bluetooth Terminal op je Android-smartphone of tablet.
  3. Met deze app kun je via commando’s communiceren met de wagen. De belangrijkste functies zijn:
      - Starten / Stoppen van de wagen
      - Debuggen van de huidige instellingen
      - Weergeven van alle beschikbare commando’s
  4. Ga in de Bluetooth-instellingen van je telefoon/tablet en zoek naar HC-05.
  5. Maak verbinding en gebruik de code 1234 of 0000.
  6. Open de app en selecteer het apparaat. Druk op Connect (rechts bovenaan).
  7. Zodra “Connected” verschijnt, is de verbinding actief en kun je commando’s verzenden.

#### commando's
debug [on/off] : Zet de debug-modus aan of uit zodat je alle instellingen en sensorwaarden kan bekijken.
run [on/off]  : Start/stopt de wagen en laat de motoren draaien/stoppen.
set cycle [µs]  : Stel de cyclustijd van de hoofdloop in om de snelheid van acties te regelen.
set power [0..255]  : Pas het motorvermogen aan om de snelheid van de wagen te regelen.
set diff [0..1]  : Stel de motorbalans in voor een betere stuurcontrole.
set kp [0..]  : Pas de proportionele factor van de PID-regeling aan.
set ki [0..]  : Pas de integrale factor van de PID-regeling aan.
set kd [0..]  : Pas de differentiële factor van de PID-regeling aan.
calibrate black  : Kalibreer de sensoren op een volledig zwart oppervlak.
calibrate white  : Kalibreer de sensoren op een volledig wit oppervlak.

### kalibratie
Om de sensoren goed te laten werken, moet je ze kalibreren op wit en zwart.
  - Calibreer wit: Plaats de wagen op een volledig wit oppervlak en voer **calibrate white** uit.
  - Calibreer zwart: Plaats de wagen op een volledig zwart oppervlak en voer **calibrate black** uit.
Hiermee leren de sensoren het verschil tussen wit en zwart, zodat de wagen de lijn correct kan volgen.

### settings
De robot rijdt stabiel met volgende parameters:  
- Cycle time : 2000
- Power : 250
- Diff : 0.60
- Kp : 15
- Ki : 0
- Kd : 0


