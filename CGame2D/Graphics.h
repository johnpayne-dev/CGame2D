#pragma once
#include <stdbool.h>

struct cgTexture;
typedef struct cgTexture * cgTexture;

typedef enum cgCompareMode
{
	cgCompareModeEqual,
	cgCompareModeNotEqual,
	cgCompareModeLess,
	cgCompareModeLessEqual,
	cgCompareModeGreaterEqual,
	cgCompareModeGreater,
	cgCompareModeNever,
	cgCompareModeAlways,
} cgCompareMode;

typedef enum cgFilterMode
{
	cgFilterModeLinear,
	cgFilterModeNearest,
} cgFilterMode;

typedef enum cgPixelFormat
{
	cgPixelFormatR8,
	cgPixelFormatRG8,
	cgPixelFormatRGBA8,
	cgPixelFormatSRGBA8,
	cgPixelFormatR16,
	cgPixelFormatRG16,
	cgPixelFormatRGBA16,
	cgPixelFormatR16F,
	cgPixelFormatRG16F,
	cgPixelFormatRGBA16F,
	cgPixelFormatR32F,
	cgPixelFormatRG32F,
	cgPixelFormatRGBA32F,
	cgPixelFormatLA8,
	cgPixelFormatRGBA4,
	cgPixelFormatRGB5A1,
	cgPixelFormatRGB565,
	cgPixelFormatRGB10A2,
	cgPixelFormatRG11B10F,
	cgPixelFormatStencil8,
	cgPixelFormatDepth16,
	cgPixelFormatDepth24,
	cgPixelFormatDepth32F,
	cgPixelFormatDepth24Stencil8,
	cgPixelFormatDepth32FStencil8,
} cgPixelFormat;

typedef enum cgTextureType
{
	cgTextureType2D,
	cgTextureTypeArray,
	cgTextureTypeCube,
	cgTextureTypeVolume,
} cgTextureType;

typedef enum cgWrapMode
{
	cgWrapModeClamp,
	cgWrapModeRepeat,
	cgWrapModeMirroredRepeat,
	cgWrapModeClampZero,
} cgWrapMode;

typedef enum cgMipmapMode
{
	cgMipmapModeNone,
	cgMipmapModeManual,
	cgMipmapModeAuto,
} cgMipmapMode;

int cgTextureDPIScale(cgTexture texture);
int cgTextureDepth(cgTexture texture);
cgCompareMode cgTextureDepthSampleMode(cgTexture texture);
int cgTextureWidth(cgTexture texture);
int cgTextureHeight(cgTexture texture);
cgFilterMode cgTextureMinFilter(cgTexture texture);
cgFilterMode cgTextureMagFilter(cgTexture texture);
int cgTextureAnisotropy(cgTexture texture);
cgPixelFormat cgTextureFormat(cgTexture texture);
int cgTextureLayerCount(cgTexture texture);
int cgTextureMipmapCount(cgTexture texture);
cgFilterMode cgTextureMipmapFilter(cgTexture texture);
int cgTexturePixelWidth(cgTexture texture);
int cgTexturePixelHeight(cgTexture texture);
cgWrapMode cgTextureWrapMode(cgTexture texture);
bool cgTextureIsReadable(cgTexture texture);
void cgTextureSetDepthSampleMode(cgTexture texture, cgCompareMode mode);
void cgTextureSetFilters(cgTexture texture, cgFilterMode min, cgFilterMode mag);
void cgTextureSetAnisotropy(cgTexture texture, int anisotropy);
void cgTextureSetMipmapFilter(cgTexture texture, cgFilterMode mode);
void cgTextureSetWrapMode(cgTexture texture, cgWrapMode mode);

struct cgCanvas;
typedef struct cgCanvas * cgCanvas;

void cgCanvasGenerateMipmaps(cgCanvas canvas);
int cgCanvasMSAA(cgCanvas canvas);
cgMipmapMode cgCanvasMipmapMode(cgCanvas canvas);
void * cgCanvasCreateImageData(cgCanvas canvas);
void * cgCanvasCreateImageDataSub(cgCanvas canvas, int slice, int mipmap, int x, int y, int width, int height);
cgTexture cgCanvasTexture(cgCanvas canvas);

