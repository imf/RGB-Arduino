#include "Arduino.h"
#include "RGB.h"

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
