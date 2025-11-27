# basis programma

volgende zaken werken samen in dit template project  

* instelbare parameters mbv. SerialCommands 
  * cyclus tijd
  * debug on/off
  * start/stop
* parameters worden opgeslagen in eeprom geheugen
* start/stop kan ook geactiveerd worden mbv. een externe interrupt
* draadloze communicatie

Met behulp van de cyclus kan je bvb. een knipperende led programmeren.


## Arduino code:
De code van de arduino staat in het bestand .ino

Dit is de werking van de code:
De code zorgt ervoor dat een LED kan knipperen op een instelbare snelheid.
Via Bluetooth kunnen instellingen worden doorgestuurd en aangepast, en deze worden automatisch opgeslagen in de EEPROM.
Daarnaast kan een drukknop (via een interrupt) het systeem meteen starten of stoppen, ongeacht wat de hoofdloop op dat moment aan het doen is.
