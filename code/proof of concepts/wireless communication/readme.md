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
