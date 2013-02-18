#include "Arduino.h"
#include "RGB.h"

#define DEBUG

RGB::RGB(unsigned long rgbValue) {
	this->_red = (rgbValue & 0xFF0000L) >> 16;
	this->_green = (rgbValue & 0x00FF00L) >> 8;
	this->_blue = rgbValue & 0xFFL;
}

RGB::RGB(int red, int green, int blue) {
	this->_red = red;
	this->_green = green;
	this->_blue = blue;
}

int RGB::getRed() {
	return this->_red;
}

int RGB::getGreen() {
	return this->_green;
}

int RGB::getBlue() {
	return this->_blue;
}

/*
std::string RGB::str() {
	std::stringstream ss << "RGB(" << _red << "," << _green << "," << _blue << ")";
	return ss.str();
}
*/
char* RGB::toString() {
	return "RGB()";
}

RGBLED::RGBLED(int redPin, int greenPin, int bluePin) {
	_redPin = redPin;
	_greenPin = greenPin;
	_bluePin = bluePin;
}

void RGBLED::begin() {
	pinMode(_redPin,   OUTPUT);
	pinMode(_greenPin, OUTPUT);
	pinMode(_bluePin,  OUTPUT);
	digitalWrite(_redPin,   HIGH);
	digitalWrite(_greenPin, HIGH);
	digitalWrite(_bluePin,  HIGH);
}

void RGBLED::setColor(RGB rgb) {
	analogWrite(_redPin,   rgb.getRed());
	analogWrite(_greenPin, rgb.getGreen());
	analogWrite(_bluePin,  rgb.getBlue());
}

void RGBLED::gradient(unsigned long startColor, unsigned long endColor) {
	this->gradient(RGB(startColor), RGB(endColor));
}

void RGBLED::gradient(RGB startColor, RGB endColor) {
	this->gradient(startColor, endColor, 1000, 16);
}

void RGBLED::gradient(RGB startColor, RGB endColor, int durationInMS, int steps) {
#ifdef DEBUG
  Serial.print("In RGBLED::gradient(");
  Serial.print(startColor.toString());
  Serial.print(", ");
  Serial.print(endColor.toString());
  Serial.println(")");
#endif  
  float stepRed = (endColor.getRed() - startColor.getRed()) / steps; // It's ok if these are negative, because they will still get 'added' to the start color.
  float stepGreen = (endColor.getGreen() - startColor.getGreen()) / steps;
  float stepBlue = (endColor.getBlue() - startColor.getBlue()) / steps;
  
  Serial.print("stepRed = ");
  Serial.println(stepRed);
  
  int red = startColor.getRed();
  int green = startColor.getGreen();
  int blue = startColor.getBlue();
  
  for (int i = 0; i <= steps; i++) {
    this->setColor(RGB(red,green,blue));
    red += stepRed;
    green += stepGreen;
    blue += stepBlue;
    delay(durationInMS / steps);
  }
#ifdef DEBUG
//  assertEqual(endRed, startRed, stepRed);
#endif
}

