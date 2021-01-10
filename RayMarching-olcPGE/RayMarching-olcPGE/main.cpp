#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine/olcPixelGameEngine.h"


#include <cstdlib>

#include "libs/globals.hpp"
#include "libs/vecs.h"
#include "libs/shapes.h"
#include "libs/glsl_emulated.h"


const vec resolution_2d = vec(640, 480);
double _ratio = resolution_2d._y / resolution_2d._x;


class ShaderEngine : public olc::PixelGameEngine
{
public:
	ShaderEngine()
	{
		sAppName = "RayMarching";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
			{
				vec color = renderXY(vec(x, y));
				Draw(x, y, olc::Pixel((uint8_t)color._x, (uint8_t)color._y, (int)color._z));
			}

		return true;
	}
};


int main()
{
	ShaderEngine shaderEngine;
	if (shaderEngine.Construct((int32_t)resolution_2d._x, (int32_t)resolution_2d._y, 3, 3))
		shaderEngine.Start();

	return 0;
}
