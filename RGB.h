#include "Arduino.h"
//#include "stdio.h"

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
		char* toString();
//		std::string str();
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
		void off();
		void gradient(RGB startColor, RGB endColor, int durationInMS, int steps);
		void gradient(RGB startColor, RGB endColor);
		void gradient(unsigned long startColor, unsigned long endColor);
	private:
		int _redPin;
		int _greenPin;
		int _bluePin;
};

#endif