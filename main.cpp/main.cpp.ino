#include <LiquidCrystal.h>

#include <LiquidCrystal.h>

#include <dht.h>
#include <LiquidCrystal.h>

#define DHTPIN 2
//7 Because we connected the DHT22 to the pin 2
//Connect negative pin DHT to ground pin arduino
//Connect the middle/signal pin to the a digital pin
//Last connect the positive pin of the arduino to the 5V pin

#define HUMIDIFIER_EN_PIN 3
int humidifier_status = 0;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
//Decaration of liquidcrystal class lcd, that is connected to the indicated pins

dht DHT;
//We declare the dht class, that contains the variables temperature and humidity and the function read22(uint8_t pin), that sets those variables

//Setup function is always executed first and one time, while the loop function is executed an infinite amount of times
void setup()
{
  delay(10000);
  Serial.begin(9600);
  /*
    Passes the value 9600 to the speed parameter. This tells the Arduino to get ready to exchange messages with the Serial Monitor at a data rate of 9600 bits per second.
    The serial monitor is the connexion between the computer and your Arduino - it lets you send and receive text messages, handy for debugging and also controlling the Arduino from a keyboard.
  */
  //Set up the LCDs number of columns and rows
  lcd.begin(16, 2);
  //Activates the enable pin for the humidifier as an output pin
  pinMode(HUMIDIFIER_EN_PIN, OUTPUT);
}

void print_lcd()
{
  lcd.print("temperature: ");
  lcd.print(DHT.temperature);
  lcd.print("°C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
}

void print_serial()
{
  Serial.print("Temperature: ");
  Serial.print(DHT.temperature);
  Serial.println("°C");
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity);
  Serial.println("%");
  Serial.println("-----");
}

void humidifier()
{
 //Activate the enable pin of the humidifier with HIGH and de-activate with LOW, Warning DO NOT TOUCH 64V
 if (DHT.humidity < 80 && humidifier_status == 0)
 {
  humidifier_status = 1;
  digitalWrite(HUMIDIFIER_EN_PIN, HIGH);
 }
 else if (DHT.humidity < 90)
   int i = 1;
 else if (humidifier_status == 1)
 {
  humidifier_status = 0;
  digitalWrite(HUMIDIFIER_EN_PIN, LOW);
 }
}

void loop()
{
  // Set the variables temperature and humidity
  int read_data = DHT.read22(DHTPIN);
  print_serial();
  print_lcd();
  humidifier();
  //Wait 5seconds
  delay(5000);
}

//To compile click on upright arrow in the screen upper left corner
