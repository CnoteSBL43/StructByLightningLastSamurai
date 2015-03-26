#pragma once

#include "../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_Color.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include <map>


struct BitmapAtt
{
	int right;
	int left;
	int width;
	int height;
};

class BitmapFont
{
	SGD::HTexture m_image = SGD::INVALID_HANDLE;
	std::map<char, BitmapAtt> m_loopUpChart;
	int m_spacing;

public:
	BitmapFont() = default;
	~BitmapFont() = default;

	void Initialize();
	void Terminate();

	void LoadLookUpChart(const char* _fileName);

	void Draw(const char * _output, SGD::Point _position, float _scale, SGD::Color _color);
	void ChangeBitmap(SGD::HTexture _image){ m_image = _image; };
};

