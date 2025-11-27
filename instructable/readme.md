# Instructable

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

### stap 1 : bestellen
Bestel alle componenten uit de bill of materials : https://github.com/AnnaertLars/Linefollower/tree/main/bill%20of%20materials

### stap 2 : monteren
- Wat hebben we nodig : sensor, PCB, soldeerbout + tin, meetlat, motoren + motor houder & TEC7
  
- Neem de sensor en soldeer deze aan de PCB ondersteboven waardoor hij vast blijft zitten.

![IMG_5916](https://github.com/user-attachments/assets/58cda5ae-eb91-4dd7-be83-8734283c042e)
![IMG_5917](https://github.com/user-attachments/assets/8912f538-9ea0-45dc-811e-ea858340fc5b)


- 3D-print de houder voor de motor (https://github.com/AnnaertLars/Linefollower/tree/main/technische%20tekeningen/mechanisch). Plaats de motor in de houder en plak hem vast (met TEC7) op een afstand van 10cm vanaf de rand van de sensor.

![IMG_5918](https://github.com/user-attachments/assets/3d692f0e-f3df-4505-9666-01d512926a62)


- Nu is het tijd om de rest te solderen :
      - Draadjes aan de motoren.
      - Draadjes aan de Deans T batterij connector.
      - Draadjes de weerstanden (kijk elektronisch schema).

### stap 3 : aansluiten

Verbind alle componenten zoals op het elektronisch schema wordt weergegeven : https://github.com/AnnaertLars/Linefollower/blob/main/technische%20tekeningen/elektronisch/Elektrisch%20schema.png

### stap 4 : programma

Verbind de arduino met de computer en upload het programma in de arduino : https://github.com/AnnaertLars/Linefollower/tree/main/code/finaal/Finaal







