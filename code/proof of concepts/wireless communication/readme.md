# draadloze communicatie proof of concept
minimale hard- en software waarmee aangetoond wordt dat duplex kan gecommuniceerd worden tussen de microcontroller en een laptop, gebruik makend van Arduino IDE Serial Monitor en PuTTY 
<br />

### gebruiksaanwijzing
Benodigdheden : ESP32, USB-kabel om de ESP32 aan te sluiten op je computer, PC met Arduino IDE geïnstalleerd.

- Verbind de ESP32 met je computer via de USB-kabel. Zorg ervoor dat bovenaan de juise COM-poort is geselecteerd in de arduino IDE. Kies hierbij ook het juiste board (ESP32 Dev Module)
- Verbind de ESP32 met je computer via de USB-kabel. Zorg ervoor dat de juiste COM-poort is geselecteerd in de Arduino IDE: Ga naar Hulpmiddelen (Tools) → Poort (Port) → Selecteer de poort waarop je ESP32 is aangesloten. Kies in Hulpmiddelen ook het juiste board (bijvoorbeeld: ESP32 Dev Module).

-Kopieer de bovenstaande code in de Arduino IDE. Controleer of de bibliotheek "BluetoothSerial.h" is geïnstalleerd: Ga naar Schets (Sketch) → Bibliotheek gebruiken (Include Library) → Bibliotheken beheren (Manage Libraries). Zoek naar "BluetoothSerial" en installeer deze indien nodig. Upload de code naar de ESP32: Klik op de Upload-knop in de Arduino IDE. Wacht tot de upload is voltooid.

-Verbinding maken via Bluetooth: Activeer Bluetooth op je PC. Zoek naar beschikbare apparaten en selecteer ESP32_BT. Maak verbinding. Als er om een code wordt gevraagd, gebruik 1234 of 0000.

-Gebruik de Bluetooth-terminalapp : PuTTY. Klik op de windows toets en zoek "aparaatbeheer". Ga daar naar "Poorten". Hier zie je (normaal) 3 verschillende poorten. Je hebt de "standaard seriële verbinding via Bluetooth" nodig. Normaal heb je dit 2 keer staan maar met een verschillend COM poort. Kies hiervoor de hoogste nummer (bij mij COM9). Open nu PuTTY, klik bij "connection type" op "Serial". Als COM-poort kies je nu de die van daarnet (bij mij COM9). Zet nog de "speed" op 115200. Klik nu op "open".


-Open de seriële monitor in de Arduino IDE (115200 baudrate). Controleer wat de ESP32 via Bluetooth ontvangt en terugstuurt.
