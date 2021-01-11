#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine/olcPixelGameEngine.h"

#include <chrono>
#include <cstdlib>

#include "libs/globals.hpp"
#include "libs/vecs.h"
#include "libs/shapes.h"
#include "libs/glsl_emulated.h"

const int RES_X = 640;
const int RES_Y = 480;

const vec iResolution = vec(RES_X, RES_Y, RES_X / RES_Y);
double iTime = 0.0f;
double iTimeDelta = 0.0f;
int iFrame = 0;
double iFrameRate = 60.0f;

class ShaderEngine : public olc::PixelGameEngine
{
private:
	unsigned __int64 startTime;
	unsigned __int64 lastFrameTime;
public:
	ShaderEngine()
	{
		sAppName = "RayMarching";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		lastFrameTime = startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		unsigned __int64 nowTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		iTime = (nowTime - startTime) / 1000.0f;
		iTimeDelta = (nowTime - lastFrameTime) / 1000.0f;
		lastFrameTime = nowTime;
		iFrame++;
		iFrameRate = 1.0f / iTimeDelta;
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
			{
				vec color(0, 0, 0, 0);
				mainImage(color, vec(x, y));
				Draw(x, y, olc::Pixel((uint8_t)color._x, (uint8_t)color._y, (int)color._z));
			}

		return true;
	}
};


int main()
{
	ShaderEngine shaderEngine;
	if (shaderEngine.Construct((int32_t)iResolution._x, (int32_t)iResolution._y, 2, 2))
		shaderEngine.Start();

	return 0;
}
