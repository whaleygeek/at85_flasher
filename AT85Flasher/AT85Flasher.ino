/* AT85Flasher  29/05/2015  D.J.Whale
 *
 * Flashes LEDs on an AT85, at a rate set by a pot.
 */
 
#define POT A3  // pin 2 ADC3
#define LED1 1  // pin 6 PB1
#define LED2 2  // pin 7 PB2
#define LED3 0  // pin 5 PB0
#define LED4 4  // pin 3 PB4

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

byte pattern = 0;

void loop()
{
  // Read the pot and delay proportional to it's position
  int potPos = analogRead(POT); // 10 bits (0..1023)
  //int potPos = 100;
  delay(potPos); // 1..1023ms i.e. 1ms to about 1 sec

  // Binary count on the 4 LEDs, so LED1 will run 4 times faster than LED4
  digitalWrite(LED1, (pattern & 1) ? true : false);
  digitalWrite(LED2, (pattern & 2) ? true : false);
  digitalWrite(LED3, (pattern & 4) ? true : false);
  digitalWrite(LED4, (pattern & 8) ? true : false);
  
  // Choose next pattern
  pattern += 1;
}

