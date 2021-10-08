### By Kevin Tran

# R3 - Software Task 1

For the project, I had setup an Arduino which is is connected to both the decoder and potentiometer. 
The Arduino reads input from the potentiometer which is converted into a integer value and outputted
to the decoder which converts the BCD values into a format to be displayed to the seven segment 
displays which show the first 2 digits of the value as converted by the Arduino.

## Arduino & Potentiometer

The Arduino is connected to the Potentiometer with a 5V power supply with the wiper connected to pin
A0. The arduino converts the signal to an integer which, as written in the code for the Arduino, is
converted into a BCD value to be later outputted to the decoder.

The algorithm used to convert the integer into a BCD value takes the integer value read from the
signal and is divided into two digits for the tens and ones. These digits are then converted into
binary which is stored as 1s and 0s into an array where the values are then passed through checks as
to whether out 1 or 0 for each pin. These values are then sent to the decoder where from pins A2-A5
represent the first digit and pins A6-A9 represent the second digit.

## Decoder & Seven Segment Display

For the decoder, it is wired to take the inputs from the Arduino which each decoder takes 4 inputs
from the Arduino for each digit. Following information regarding the CD4511 decoder, the pins are
wired appropriately with the lamp test and blanking pins supplied to 5V as well as with the latch 
enable pin being grounded for normal operation.

The seven segment display is also connected appropriately to the decoder with the associated pins
mapped to the 7 segment decoder pins with the decimal pin grounded (since it is not being used).

## Appendix

Project: https://www.tinkercad.com/things/e5OWF9QprYq-project

![Alt text](https://i.gyazo.com/6b311f2052b39cec8508ddbc812f8a20.png)
<br />
A1: The Arduino and potentiometer

![Alt text](https://i.gyazo.com/48236cc841c6b16b5d02351cdaa3a774.png)
<br />
A2: The decoder and seven segment display 
