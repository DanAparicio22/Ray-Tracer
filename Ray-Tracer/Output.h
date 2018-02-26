#pragma once
#include "ColorRGB.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

class Output 
{
	public:
		Output();
		~Output();
		void saveBmp(const char*, int, int, int, ColorRGB*);
};