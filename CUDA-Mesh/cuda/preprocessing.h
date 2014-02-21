#pragma once

#include "math_constants.h"
#include "cuda_runtime.h"
#include "device_structs.h"
#include "RGBDFrame.h"
#include "Calibration.h"
#include <glm/glm.hpp>
#include "Utils.h"
#include <math.h>

#define MAX_FILTER_WINDOW_SIZE			25
#define GAUSSIAN_SPATIAL_FILTER_RADIUS	3
#define GAUSSIAN_SPATIAL_KERNEL_SIZE	(2*GAUSSIAN_SPATIAL_FILTER_RADIUS+1)

__host__ void buildVMapNoFilterCUDA(rgbd::framework::DPixel* dev_depthBuffer, VMapSOA vmapSOA, int xRes, int yRes, 
									rgbd::framework::Intrinsics intr, float maxDepth);


__host__ void rgbAOSToSOACUDA(rgbd::framework::ColorPixel* dev_colorPixels, 
						  RGBMapSOA rgbSOA, int xRes, int yRes);


__host__ void buildVMapPyramidCUDA(VMapSOA dev_vmapSOA, int xRes, int yRes, int numLevels);

__host__ void setGaussianSpatialKernel(float sigma);

__host__ void buildVMapGaussianFilterCUDA(rgbd::framework::DPixel* dev_depthBuffer, VMapSOA vmapSOA, int xRes, int yRes, 
										  rgbd::framework::Intrinsics intr, float maxDepth);

__host__ void buildVMapBilateralFilterCUDA(rgbd::framework::DPixel* dev_depthBuffer, VMapSOA vmapSOA, int xRes, int yRes, 
										  rgbd::framework::Intrinsics intr, float maxDepth, float sigma_t);