//IMPLEMENTATION FILE

#include "Castro.h"

double Castro::feetToMeter(double feet) {
	double meter = feet * 0.3048;
	return meter;
}

double Castro::meterToFeet(double meter) {
	double feet = meter / 0.3048;
	return feet;
}