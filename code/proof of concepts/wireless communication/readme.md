# draadloze communicatie proof of concept
minimale hard- en software waarmee aangetoond wordt dat duplex kan gecommuniceerd worden tussen de microcontroller en een laptop, gebruik makend van Arduino IDE Serial Monitor en PuTTY 
<br />

### gebruiksaanwijzing
Benodigdheden : ESP32, USB-kabel om de ESP32 aan te sluiten op je computer, PC met Arduino IDE geïnstalleerd.

- Verbind de ESP32 met je computer via de USB-kabel. Zorg ervoor dat de juiste COM-poort is geselecteerd in de Arduino IDE: Ga naar Hulpmiddelen (Tools) → Poort (Port) → Selecteer de poort waarop je ESP32 is aangesloten. Kies in Hulpmiddelen ook het juiste board (bijvoorbeeld: ESP32 Dev Module).

-Kopieer de bovenstaande code in de Arduino IDE. Controleer of de bibliotheek "BluetoothSerial.h" is geïnstalleerd: Ga naar Schets (Sketch) → Bibliotheek gebruiken (Include Library) → Bibliotheken beheren (Manage Libraries). Zoek naar "BluetoothSerial" en installeer deze indien nodig. Upload de code naar de ESP32: Klik op de Upload-knop in de Arduino IDE. Wacht tot de upload is voltooid.

-Verbinding maken via Bluetooth: Activeer Bluetooth op je PC. Zoek naar beschikbare apparaten en selecteer ESP32_BT. Maak verbinding. Als er om een code wordt gevraagd, gebruik 1234 of 0000.

-Gebruik de Bluetooth-terminalapp : PuTTY. Klik op de windows toets en zoek "aparaatbeheer". Ga daar naar "Poorten". Hier zie je (normaal) 3 verschillende poorten. Je hebt de "standaard seriële verbinding via Bluetooth" nodig. Normaal heb je dit 2 keer staan maar met een verschillend COM poort. Kies hiervoor de hoogste nummer (bij mij COM9). Open nu PuTTY, klik bij "connection type" op "Serial". Als COM-poort kies je nu de die van daarnet (bij mij COM9). Zet nog de "speed" op 115200. Klik nu op "open".


-Open de seriële monitor in de Arduino IDE (115200 baudrate). Controleer wat de ESP32 via Bluetooth ontvangt en terugstuurt.

# Draadloze communicatie proof of concept

Minimale hardware en software waarmee aangetoond wordt dat **duplex-communicatie** mogelijk is tussen de microcontroller en een laptop of tablet, gebruikmakend van **Arduino Leonardo + HC‑05**, de **Arduino IDE Seriële Monitor** en een **Bluetooth-terminalapp**.

---

## Benodigdheden

- Arduino Leonardo  
- HC‑05 Bluetooth-module  
- USB-kabel om de Arduino aan te sluiten  
- PC of tablet met Arduino IDE en/of Bluetooth-terminalapp geïnstalleerd  

---

## Hardware aansluiten

Sluit de HC‑05 module aan op de Arduino Leonardo:

- **VCC → 5V**  
- **GND → GND**  
- **TX → SoftwareSerial RX-pin** (bijv. pin 9) → rechtstreeks verbonden  
- **RX → SoftwareSerial TX-pin** (bijv. pin 8) → via spanningsdeler (1 kΩ + 2 kΩ naar GND)  

> **Opmerking:** De spanningsdeler verlaagt het Arduino 5V-signaal naar ±3,3V voor de HC‑05 RX-pin.

---

## Software installeren en uploaden

1. Sluit de Arduino Leonardo aan via USB.  
2. Open de **Arduino IDE**.  
3. Controleer het board:  
   - Hulpmiddelen → Board → Arduino Leonardo  
4. Controleer de COM-poort:  
   - Hulpmiddelen → Poort → selecteer juiste poort  
5. Kopieer de code in een nieuwe sketch.  
6. Controleer of de benodigde bibliotheek aanwezig is:  
   - Schets → Bibliotheek gebruiken → Bibliotheken beheren → `SoftwareSerial`  
7. Klik op **Upload** en wacht tot de upload voltooid is.

---

## Verbinding maken via Bluetooth

1. Activeer Bluetooth op je tablet of laptop.  
2. Zoek naar beschikbare apparaten en selecteer **HC‑05**.  
3. Als er om een pincode wordt gevraagd, gebruik **1234** of **0000**.  
4. Open een **Bluetooth-terminalapp** of de **Arduino IDE Seriële Monitor**.  
5. Selecteer de juiste verbinding of COM-poort en stel de baudrate in (bijv. **9600**).  

---

## Communicatie testen

- Typ een bericht in de Bluetooth-terminalapp en verstuur het naar de Arduino.  
- Controleer dat de Arduino het bericht ontvangt en een bevestiging terugstuurt.  
- Typ een bericht in de Arduino IDE Seriële Monitor (USB) en controleer dat dit ook via Bluetooth wordt verzonden.  

> Als alles werkt, toont dit dat **duplex-communicatie** functioneert: de Arduino kan tegelijkertijd ontvangen en verzenden via Bluetooth, terwijl debug-output via USB zichtbaar blijft.

---
