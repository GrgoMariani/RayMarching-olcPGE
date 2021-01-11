MAKEFILE_BUILDER = make -f makefile_builder.mk --no-print-directory


all: build run

CPP_FILES := RayMarching-olcPGE/RayMarching-olcPGE/main.cpp RayMarching-olcPGE/RayMarching-olcPGE/geometry.cpp RayMarching-olcPGE/RayMarching-olcPGE/shader.cpp

compile:
	@$(MAKEFILE_BUILDER) CPP_TO_COMPILE="$(CPP_FILES)" EXE_TARGET="olgShader" CC="gcc" CXX="g++" LL="g++"

run: compile
	./build/olgShader

clean:
	@$(MAKEFILE_BUILDER) clean
