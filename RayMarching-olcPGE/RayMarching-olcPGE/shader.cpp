#include "render.hpp"


const int MAX_STEPS = 32;
const double MAX_DISTANCE = 10000.0;
const double EPSILON = 0.0001;


/*    renderXY() takes care of each pixel rendering                   */
/*    WRITE YOUR CODE HERE                                            */
/*    currently it calls the methods defined in render.hpp            */
vec renderXY(vec gl_FragCoord_2d) {
	// gl_FragCoord_2d are current coordinates 
	// uv_2d are our modified screen coordinates        
	vec uv_2d = (gl_FragCoord_2d / resolution_2d) * 2.0 - vec(1.0, 1.0);
	uv_2d._x *= _ratio;

	static vec cameraPosition_3d(0.0, 0.0, -10.0);
	static vec lightPosition_3d(3.0, 4.5, -10.0);
	vec cameraDirection_3d = vec(uv_2d._x, uv_2d._y, 1.0).normalize();

	vec pointOnSurface_3d(0.0, 0.0, 0.0);
	double distanceToClosestPointInScene = trace(cameraPosition_3d, cameraDirection_3d, pointOnSurface_3d);

	vec finalColor_c(0.0, 0.0, 0.0);

	if (distanceToClosestPointInScene > 0.0) {
		vec surfaceNormal_3d = getNormal(pointOnSurface_3d);
		finalColor_c = calculateLighting(pointOnSurface_3d, surfaceNormal_3d, lightPosition_3d, cameraPosition_3d);
	}

	return finalColor_c;
}
