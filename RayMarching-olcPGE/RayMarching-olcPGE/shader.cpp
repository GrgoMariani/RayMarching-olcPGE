#include "render.hpp"



/*    renderXY() takes care of each pixel rendering                   */
/*    WRITE YOUR CODE HERE                                            */
/*    currently it calls the methods defined in render.hpp            */
void mainImage(vec& fragColor, vec fragCoord)
{
	// gl_FragCoord_2d are current coordinates 
	// uv_2d are our modified screen coordinates        
	vec uv_2d = (fragCoord / iResolution) * 2.0 - vec(1.0, 1.0);
	uv_2d._x *= iResolution._z;

	static vec cameraPosition_3d(0.0, 0.0, -10.0);
	static vec lightPosition_3d(3.0, 4.5, -10.0);
	vec cameraDirection_3d = vec(uv_2d._x, uv_2d._y, 1.0).normalize();

	vec pointOnSurface_3d(0.0, 0.0, 0.0);
	double distanceToClosestPointInScene = trace(cameraPosition_3d, cameraDirection_3d, pointOnSurface_3d);

	if (distanceToClosestPointInScene > 0.0)
	{
		vec surfaceNormal_3d = getNormal(pointOnSurface_3d);
		fragColor = calculateLighting(pointOnSurface_3d, surfaceNormal_3d, lightPosition_3d, cameraPosition_3d);
	}
}
