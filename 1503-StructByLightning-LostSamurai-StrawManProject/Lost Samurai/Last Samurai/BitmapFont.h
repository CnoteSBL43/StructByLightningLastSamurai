#pragma once

#include "../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_Color.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include <map>


struct BitmapAtt
{
	int s_xOffset;
	int s_yOffset;
	int s_width;
	int s_height;
	int s_x;
	int s_y;
};

class BitmapFont
{
	SGD::HTexture m_image = SGD::INVALID_HANDLE;
	std::map<char, BitmapAtt> m_lookUpChart; 
	int m_avgWidth;
	int m_highestHeight;

public:
	BitmapFont() = default;
	~BitmapFont() = default;

	void Initialize();
	void Terminate();

	void LoadLookUpChart(const char* _fileName);

	void Draw(const char * _output, SGD::Point _position, float _scale, SGD::Color _color = {});
	void Draw(const wchar_t * _output, SGD::Point _position, float _scale, SGD::Color _color = {});
	void ChangeBitmap(SGD::HTexture _image){ m_image = _image; };
};

