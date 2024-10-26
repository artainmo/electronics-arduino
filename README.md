# Electronics-arduino
Electronics project, that uses Arduino to:

* Measure temperature, humidity with DHT22

* Display with 16X2 LCD

* Maintain a certain humidity with grove water atomization

See theoretical notes/learnings in 'electronics_notes.txt'.

### Prepare software
* Install arduino IDE: https://www.arduino.cc/en/software
* Open arduino IDE with main.cpp.ino
* Sketch -> include libraries -> liquidcrystal
* Sketch -> include libaraies -> include .zip -> DHTlib.zip
* Verify -> see if compilation succeeds

### Prepare hardware
* Connect prepared arduino to computer
* Upload arduino code on it

#### Caution
Do not touch grove water atomizer middle part

#### Hardware setup
![hardware_front](img/HF.png)
![hardware_back](img/HB.png)

# Electronics notes

## Hardware

### Microcontrollers 
#### GPIO PIC microcontroller
We need a GPIO PIC microcontroller.<br>
GPIO, stands for General purpose input/ouput this means the microcontroller can send and receive electrical signals that you can control from the operating system or through PIC.<br>
PIC microcontrollers ( Programmable Interface Controllers), are electronic circuits that can be programmed to carry out a vast range of tasks.<br>
Both Rasberry Pi or Arduino can be used.

#### Rasberry Pi
Raspberry Pi, is a credit card sized computer, for this project use the GPIO rasberry Pi.<br>
A Rasberry can be used as a GPIO PIC microcontroller, it can do everything a computer can do.<br>
Because it is a micro computer you can directly code into it, after connecting it to a screen, the default language is python.<br>
Rasberry has a higher cost.

#### Arduino
Arduino is an open-source prototyping platform used for building electronics projects.<br>
Arduino contains microcontrollers.<br>
It consists of both a physical programmable circuit board and a software, or IDE (Integrated Development Environment) that runs on your computer, where you can write and upload the computer code to the physical board, the default language is c++.<br>
Arduino is not a microcomputer like the Rasberry Pi thus has less functionalities and less costs.<br>
It has enough functionalities for a simple electonics project and functionalities can be added if necessary.<br>
Arduino Uno is the simplest and cheapest version of the Arduino. Contrary to other Arduino's it does not have wifi, ethernet or bluetooth for example.<br>
Arduino shields are add-ons to your main Arduino circuit board, they allow you to add functionalities like cellphone or mp3 player.

Arduino software development can work on mac, linux or windows, first download the arduino IDE after connect a usb cable to upload your code.<br>
Specific functions and libraries are implemented in the arduino IDE for you to use, you need to download them and include them in the sketch -> include library.<br>
When launching the software make sure it connects to the right arduino type and through the right port in the tools settings.<br>
To debug use serial.printf and the serial monitor upper right screen to look at returned values.<br>
Every Arduino program will have two main functions the setup and loop.<br>
Electrical circuits return volts, that the software can interpret as integer values. With 5V = 1023 and 0V = 0. Those intger values are called analog-to-digital converter value (ADC value).<br>
ADC value = 204.6 * V.

Arduino uses series of microcontrollers, the code you upload is uploaded to the main microcontroller.<br>
Crystal resonator is connected to the microcontrollers to control how fast the microcontroller is running.

The barrel jack with 9V DC power source can be used instead of a computer as battery for the arduino.<br>
Arduino has a built-in voltage regulator that will reduce the voltage to 5V if necessary.<br>
A reset button also exists to reboot the arduino program. Reboot means restarting the operating system, what can be usefull after a computer crash.

Pins are used to connect electronic devices. Different pins can be used differently.<br>
Power pins: connect wire to other circuits with 5 or 3.3V, whatever you power should not dram more than a few miniAmps.<br>
TX & RX or pin 0 & 1: for sending and receivig serial data.<br>
Pins 2 -> 13: for digital inputs and outputs, 0, 1 or interpret one of the two. This is called the  tristate buffer system and makes it easy to switch from input to output in software.<br>
Analog input pins: Measures continuous voltages between 0 and 5V.<br>
Pins with tilde(~), this means you can use them to output pulse width modulated square waves.

Troubleshooting code download, put the arduino app and files in right place, insert correctly the usb...
 
#### Conslusions
Arduino uno is enough to handle this electronics projects and most cost-effective.

### Temperature and humidity sensor
[dht11 dht22 sensors temperature and humidity tutorial using arduino](https://howtomechatronics.com/tutorials/arduino/dht11-dht22-sensors-temperature-and-humidity-tutorial-using-arduino/)<br>
DHT11 is not able to sense negative temperatures and humidity outside the 20-80% range.<br>
while the DHT22 does.<br>
Plus the DHT22, to be able to connect it to the arduino you also need (one mini breadboard or 3 holed jump wires) and 3 pinned jump wires.

### LCD
Can be practical to see if installation is working correctly.<br>
Ideally for temp and humidity use the 16X2 LCD.<br>
To connect to arduino you will need one half breadboard, 15jump wires and one 220Ohms resistor.<br>
Necessary to solder the header pins of the lcd.<br>
[Use tutorial](https://www.arduino.cc/en/Tutorial/HelloWorld)

### Relays
To control high-voltage or high-power circuits with an Arduino, you have to isolate them from the Arduino with a relay.<br>
Circuits that operate at high voltages or at high currents cannot be controlled directly by an Arduino.<br>
Instead, you use a low-voltage control signal from the Arduino to control a relay, which is capable of handling and switching high-voltage or high-power circuits.<br>
A relay consists of an electromagnet that, when energized, causes a switch to close or open.<br>
Relays provide complete electrical isolation between the control circuit and the circuit being controlled.<br>
When using high valotages with an arduino use it correctly or you could make the arduino explode.

### Humidifier
[smart humidifier](https://create.arduino.cc/projecthub/taifur/smart-humidifier-dac66f)
Use Grove - water atomization.<br>
Uses ultrasound to heat water that then vaporizes.<br>
To be able to connect with arduino you also need a grove shield and grove wire. [Or maybe not](https://forum.arduino.cc/index.php?topic=593574.0). I tried without grove shield to reduce costs and it worked.

Look at humidifier outgoing pins:
* gnd -> Needs to be grounded
* vcc -> 5V power input
* nc -> Pin of no use
* en -> enable pin, use digital pins as output pins and activate deactivate using the digitalWrite function

### Breadboard
Used to create electrical circuits by connecting electonics together.<br>
Holes in breadboards allow to connect pins to metalic bars that are interconnected to vertical pins row underneath the breadboard.<br>
Pins in different locations and in different breadboards are interconnected in different ways, it is important to know how your board pins are interconnected to make your electrical circuit work.

### Jumper wire
Is an electrical wire with a pin at the end. The pin at the end is necessary to connect to arduinos or breadboards.<br>
Warning jumper wires with pins or holes to accept pins are sold under the same name, here we are talking about jumper wires with pins at the end.

### Resistors
A resistor is a passive two-terminal electrical component that implements electrical resistance as a circuit element.<br>
In electronic circuits, resistors are used to reduce current flow, adjust signal levels, to divide voltages, bias active elements, and terminate transmission lines, among other uses.

## Algorithm knowledge

### Ohm Law
Ohm's law is a law that states that the voltage across a resistor is directly proportional to the current flowing through the resistance.<br>
V = RI<br>
V = voltage, R = resistance, I = current<br>

### PID controller algorithm
A PID controller is an instrument used in industrial control applications to regulate temperature, flow, pressure, speed and other process variables.<br>
PID (proportional integral derivative) controllers use a control loop feedback mechanism to control process variables.
