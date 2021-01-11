# RayMarching olcPGE

 Using olc's PixelGameEngine as a base for rendering raymarching with shadertoy similar semantics.

## Explanation
 I thought it would be fun if I could manage to compile some shaders from ShaderToy website in a C++ app. The main goal was to just be able to copy-paste the code and run it, however it seems that minor adjustments are mostly needed.
 
 The only code that should be changed is `renderXY(vec gl_FragCoord_2d)` function in the __shader.cpp__ file.
 
## Build
 Do not forget to clone this repository recursively.
```
$ git clone --recursive $(THIS_REPOSITORY_URL)
```
Once cloned use VisualStudio (2017 and 2019 should work fine) to build. Since the olcPGE is cross-platform you could also compile it yourself by compiling __shader.cpp__, __main.cpp__ and  __geometry.cpp__ sources into a single executable. 

### Build on linux
There  is a __Makefile__ in the root folder of the project that you should be able to use to compile by simply using the `make` command.

Prerequisites are to install the required development libraries:
```
$sudo apt install g++ mesa-common-dev freeglut3-dev
```

You will be able to find your executable in the ___./build___ folder

## Other
 Big Thanks to Javidx9 for the engine

