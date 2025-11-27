# start/stop interrupt proof of concept
minimale hard- en software die de correcte werking van een start/stop drukknop aantoont, gebruik makend van een hardware interrupt

## Arduino code:
De arduino code staat in het bestand .ino

De code werkt alsvolgt : 
Wanneer de schakelaar wordt ingedrukt om een start- of stopsignaal te genereren, wordt via de functie attachInterrupt() de hoofdloop (loop()) hardwarematig onderbroken. Hierdoor hoeft de software niet voortdurend te controleren (polling) of de knop is ingedrukt. Zodra de interrupt wordt geactiveerd, wordt de functie interrupt() uitgevoerd. In dit voorbeeld wordt de toestand van een LED gewijzigd om de werking te demonstreren, maar dit kan uiteraard vervangen worden door een daadwerkelijke start/stop-functionaliteit.
Binnen deze interrupt voorkomt de millis()-functie dat er ongewenste meerdere triggers ontstaan door contactdender (debouncing). De interrupt moet minstens 100 ms actief blijven voordat de functie wordt uitgevoerd. Hierdoor wordt voorkomen dat de functie meerdere keren na elkaar wordt aangeroepen wanneer de knop kort trilt.

## ELektronisch schema
Het elektronisch schema ziet er als volgt uit : 
<img width="1482" height="630" alt="image" src="https://github.com/user-attachments/assets/d335d09e-95a1-4c41-8741-16a8dcd0b6aa" />
