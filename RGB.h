#include "Arduino.h"

#ifndef RGB_h
#define RGB_h

class RGB {
	public: 
		RGB(unsigned long rgbValue);
		RGB(int red, int green, int blue);
		int getRed();
		int getGreen();
		int getBlue();
		unsigned long getRGB();
	private:
		int _red;
		int _green;
		int _blue;
};

class RGBLED {
	public:
		RGBLED(int redPin, int greenPin, int bluePin);
		void begin();
		void setColor(RGB rgb);
	private:
		int _redPin;
		int _greenPin;
		int _bluePin;
};

#endif