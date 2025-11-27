# H-Bridge proof of concept

Minimale hard- & software die aantoont dat 2 motoren onafhankelijk van elkaar kunnen draaien, en (traploos) regelbaar zijn in snelheid en draairichting. Hiervoor wordt gebruik gemaakt van 2 "Mini Micro Metal Gear Motor 6V DC" motoren en als H-brug gebruiken we de "DRV8833".

## Functionaliteit : 
Het programma laat in een lus zien hoe de motoren geleidelijk versnellen tot hun maximale snelheid en daarna weer terug afremmen naar nul. Vervolgens wordt gedemonstreerd dat de motoren ook in de omgekeerde richting kunnen draaien, en dat elke motor afzonderlijk een eigen draairichting kan krijgen.

## Arduino code:
De code staat in het bestand .ino

In de setup worden de pinnen die verbonden zijn met de H-brug als OUTPUT ingesteld en worden de motoren uitgeschakeld. Daarna start de void loop-functie, waarin volgende stappen uitgevoerd worden:
1. De motoren versnellen geleidelijk van stilstand naar hun maximale snelheid.
2. Ze draaien 2 seconden op maximale snelheid.
3. De motoren vertragen opnieuw tot stilstand.
4. Ze blijven 2 seconden uitgeschakeld.
5. Beide motoren draaien 2 seconden op maximale snelheid in de omgekeerde richting.
6. Ze blijven opnieuw 2 seconden uit.
7. De motoren draaien 2 seconden op volle snelheid, maar elk in een andere draairichting.
8. Daarna blijven ze 1 seconde uit.
9. Vervolgens draaien ze opnieuw 2 seconden op maximale snelheid, maar nu allebei in de tegenovergestelde richting van de vorige stap.
10. De motoren blijven nog 1 seconde uit.
Daarnaast zijn er nog drie extra functies geïmplementeerd. Via de spin_and_wait-functie kan overzichtelijk een snelheid aan beide motoren worden toegekend. In deze functies wordt ook bepaald dat de draairichting moet omkeren wanneer een negatieve snelheid wordt ingegeven, en wordt de ingestelde snelheid naar de seriële monitor geschreven

## Elektronisch schema:
De aansluiting van de H-brug & motoren staat in het bestand .PDF
