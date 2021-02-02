# Whaddy Nightlight

![demo](./pictures/Demo.jpg)

Make A Cool Nightlight in the shape of Whaddy! This wil fit on any phone charger in the EU

## Project description - How Does it work?

### What can this project do?
This project uses an Digital light sensor to measure the ambient light. When a certain light value is reached, the 2 SMD RGB leds will turn on and give your room a purple shine!
The enclosure is designed for 3D printing and is in the shape of our Mascot!
The parts are also designed with a Snap fit connection for the electronic modules and to close it. So you dont have to find screws. 
The nightlight is supported by a bracket (also 3D printed), which is designed for most EU mobile phone chargers.

### You will need to do the following things for the project to work:

### Level of difficulty: Intermediate

## MATERIALS

### Ingredients:
* Arduino Nano or equivalent (e.g. [Whadda Atmega328 Nano Development Board (WPB102)](https://whadda.com/product/atmega328-development-board-wpb102/))
* Light sensor (e.g. [BH1750 dgital light intensity sensor module (VMA341)](https://whadda.com/product/bh1750-digital-light-intensity-sensor-module-vma341/))
* RBG SMD LED modules (e.g. [ARDUINO® COMPATIBLE 3 COLOUR RGB SMD LED MODULE (2 Pcs)(VMA318)](https://whadda.com/product/arduino-compatible-3-colour-rgb-smd-led-module-2-pcs-vma318/))
* PLA naturel (e.g. [1.75 Mm (1/16″) PLA FILAMENT – NATURAL – 750 G](https://whadda.com/product/1-75-mm-1-16-pla-filament-natural-750-g-pla175n07/))
* Soft electrical wires
* Any USB A cable (old one is good enough but it hast to work)
* EU phone charger

### Tools:
* PC with [Arduino IDE](https://www.arduino.cc/en/Main/Software) installed
* Soldering iron
* Solder
* Stripping pliers
* Cutting pliers
* Shrink tubes
* Heat gun of hair dryer
* 3D printer

## 3D printing the NightLight:

The Nightlight consist out of 3 3D printed parts
* Nightlight Top
* Nightlight Bottom
* Nightlight Bracket

Find all the .stl files for the case of this project on our Thingiverse page:

There are no supports needed, Be sure to 3D print Nightlight Top and Bottom in a transparent filament. Otherwise, you won`t be able to see the LEDs inside. 
Also be sure to print it with 100% infill to get the best result.

![Cura](./pictures/3Dprint.JPG)

## PROGRAMMING  the development board

### Dev board: Arduino Nano (compatible)

### Processor: ATMega328P

### Code language: Arduino

### Difficulty: Medium

### Preparations:
#### Installing Arduino Libraries

![Arduino Library manager](./pictures/library_manager.jpg)


Use the Arduino library manager (```Sketch > Include Library > Manage Libraries...```) to install the following libraries:


* [hp_BH1750(by Starmbi)](https://github.com/Starmbi/hp_BH1750)

#### Checking the Arduino sketch

1) Open the ```Whaddy_Nighlight.ino``` Arduino Sketch
2) Select the ```Arduino Nano``` board form the boards menu by going to ```Tools > Board > Arduino AVR Boards > Arduino Nano```
![boardselect](.pictures/Select_Board.jpg)
3) Select the ```ATmega328P (Old Bootloader)``` board form the boards menu by going to ```Tools > Processor >  > ATmega328P (Old Bootloader)```
![Bootloader](.pictures/Bootloader.jpg)
4) Check if the Arduino sketch compiles correctly by hitting the ```Verify``` button (checkmark button left of the upload button). If everything is installed correctly no errors should pop-up and the compilation process should finish with the final message ```Done compiling```. If this process fails, please check if you installed all necessary libraries and selected the correct board.

## Prepping the connections
### Connection Table light sensor
| BH1750 digital light intensity sensor | Arduino Nano |
|:-----------:|:---------------------:|
| G | GND |
| V | 5V |
| SDA | A4 |
| SCL | A5 |

### Connection Table SMD RGB leds 
|3 COLOUR RGB SMD LED MODULE | Arduino Nano |
|:-----------:|:---------------------:|
| - | GND |
| G | A2 |
| R | A1 |
| B | A0 |

## Running the code!

Almost done with the coding part. After this we can start installing the electronics in the 3D printed case.

### Setting the light value

As mentioned earlier, the RGB LEDs will turn on when it gets dark. The value corresponds to the ambient ligt that the senor is measuring (LUX). 
So 0 = DARK
300 = OFFICE LIGHT
100 000 = SUNLIGHT :) 
We`ve set the value that it turns on at twilight (10).
Changing the value van be done here:

```Cpp
// Value to determe at wich value the LEDs should switch on
// The lower the value,the darker 
int Dark = 10;
/////////////////////////////////////////
```

### Changing the color of the RGB LEDS 

You can change the color of the nightlight to whatever you want by changing the setColor value(R, G, B) format. We`ve set it in the Whadda purple. 

```Cpp
  if (Alux < Dark) {      // When Avarage Lux measurement is lower then....
    setColor(210, 0, 210); // Set color to Purple (RGB)
  }
  ```
### Uploading and checking the program
You're now ready to upload the code! Hit the upload button and wait until the program is compiled and uploaded. The nightlight should turn on when you cover the light sensor with your hand. If you're encountering any issue check the serial monitor to see if the board was able to give correct readings from the B1750 dgital light intensity sensor.

## Soldering and assembling the electronics
#### Overview of the Ingredients

![INGREDIENTS](./pictures/1.jpg)

#### Overview of the Tools
![TOOLS](./pictures/2.jpg)

#### Step 1: Cut off or desloder the ICSP pins from the Arduino Nano. We do this to save some space in the 3D printed case.
CUT OFF

![CutOff](./pictures/3.jpg)

DESOLDER

![Desolder](./pictures/4.jpg)

#### Step 2: Place the Arduino Nano in the provided place of bottom case from the Nightlight, like in the picture below.

![ArduinoNano](./pictures/5.jpg)

#### Step 3: Solder 4 wires to the pins of the BH1750 digital light intensity sensor.

![LightSens](./pictures/6.jpg)

#### Finish off the connections by putting heatshrinks around them.

![LightSensHeat](./pictures/7.jpg)

#### Step 4: Place the BH1750 digital light intensity sensor in the provided place of bottom case from the Nightlight.

![LightSensCase](./pictures/8.jpg)

#### Step 5: Measure the aprox length of the cables from the light sensor to the Arduino Nano pins (See connection diagram), and cut them off. 

![LightSensWires](./pictures/9.jpg)

#### Step 6: Remove the arduino and light sensor from the housing. Solder the wires according the connection diagram. Don't forget to put heatshrinks onto the connections!!  DON'T SOLDER DE 5V YET, WE WILL DO THIS LATER ON

![LightSensSolder](./pictures/10.jpg)

#### Step 7: Solder wires to the pins of the SMD RGB LEDs modules. Don't forget to finsh the connections off with heatshrinks!

![LedsWires](./pictures/11.jpg)

#### Step 8: The Leds will be mounted in the TOP part of the nightlight. insert them in the provided place and. Then bring the wires from the 2 LED modules together (color by color) and cut them off like in the picture below (not to short, otherwise the assembly will be difficult). Again do not forget the heatshrinks :)

![LEDsWireLenght](./pictures/12.jpg)

#### Step 9: Start soldering the 2 SMD RGB led modules to the Arduino Nano according the connection diagram. DON'T SOLDER DE GND YET, WE WILL DO THIS LATER ON

![LEDsSolder](./pictures/13.jpg)

#### You should have something like this now:

![Assembly](./pictures/14.jpg)

#### Step 10: Cut off the USB A cable (approx. 25cm) and strip it (approx. 7.5cm)

![USBcut](./pictures/15.jpg)

#### Step 11: Cut away the excess shielding and wires until you only have the + and - wires.

![USBstrip](./pictures/16.jpg)

#### Then strip and solder the ends of these wires

![USBstripends](./pictures/17.jpg)

#### Step 12: Feed the + and - wires trough the hole of the bottom part form the Nightlight.

![USBfeed](./pictures/18.jpg)

#### Step 13: Solder the + wire from the USB cable and the 5V wire from the light sensor the the 5V pin of the arduino Nano

![USBsolder+](./pictures/19.jpg)

#### Step 14: Solder the - from the USB cable and the - wires from RGB SMD LED modules to the GND pin of the arduino Nano

![USBsolder+](./pictures/20.jpg)

#### Step 15: Slide the 2 LED modules in the provided place of TOP part from the Nightlight.

![LEdslide](./pictures/21.jpg)

#### Step 16: Now close the Nightlight TOP and BOTTOM half. The design uses snap fit, so no need for screws!

![CloseAssembly](./pictures/22.jpg)

#### Step 17: The next step is to mount the bracket on the charger, like in the picture below.

![Bracketmount](./pictures/23.jpg)

#### Step 18: Click the bracket in the slot of the BOTTOM part of the Nightlight. BE CAREFULL, DON'T BREAK THE BRACKET (it is a fairly tight fitting)

![Bracketmount2](./pictures/24.jpg)

#### Step 19: WOOHOOO, Last step. Plug the USB A in the Charger. 

![USBplug](./pictures/25.jpg)



