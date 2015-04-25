#include "BitmapFont.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../resource/TinyXML/tinystr.h"
#include "../resource/TinyXML/tinyxml.h"

void BitmapFont::Initialize()
{

}


void BitmapFont::Terminate()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_image);
}

void BitmapFont::LoadLookUpChart(const char* _fileName)
{
	double id, attribute, charCount = 0;

	TiXmlDocument doc;
	if (doc.LoadFile(_fileName) == false)
		return;

	TiXmlElement* root = doc.RootElement();

	TiXmlElement* children = root->FirstChildElement("page");

	std::string imgName = "../resource/graphics/";
	imgName += children->Attribute("file");
	m_image = SGD::GraphicsManager::GetInstance()->LoadTexture(imgName.c_str());
	children->Attribute("scaleW", &attribute);

	m_avgWidth = (int)attribute;

	children = children->NextSiblingElement("chars");
	children->Attribute("count", &charCount);

	TiXmlElement* charElement = children->FirstChildElement("char");
	for (size_t i = 0; i < charCount; i++)
	{

		charElement->Attribute("id", &id);

		charElement->Attribute("x", &attribute);
		m_lookUpChart[(char)id].s_x = (int)attribute;
		charElement->Attribute("y", &attribute);
		m_lookUpChart[(char)id].s_y = (int)attribute;

		charElement->Attribute("width", &attribute);
		m_lookUpChart[(char)id].s_width = (int)attribute;
		charElement->Attribute("height", &attribute);
		m_lookUpChart[(char)id].s_height = (int)attribute;

		if (attribute > m_highestHeight)
			m_highestHeight = (int)attribute;

		charElement->Attribute("xoffset", &attribute);
		m_lookUpChart[(char)id].s_xOffset = (int)attribute;
		charElement->Attribute("yoffset", &attribute);
		m_lookUpChart[(char)id].s_yOffset = (int)attribute;


		charElement = charElement->NextSiblingElement("char");
	}

}

void BitmapFont::Draw(const char * _output, SGD::Point _position, float _scale, SGD::Color _color)
{

	SGD::Point currPt = _position;
	float x = currPt.x;
	float y = currPt.y;

	// Is this string invisible?
	if (_output[0] == '\0'			// string is empty?
		|| _scale == 0.0f			// scale is invisible?
		|| _color.alpha == 0)		// color is invisible?
		return;

	for (int i = 0; _output[i]; i++)
	{
		// Get the current character
		char ch = _output[i];

		if (ch == ' ')
		{
			currPt.x += m_avgWidth * _scale;
			continue;
		}
		else if (ch == '\n')
		{
			currPt.x = x;
			currPt.y = y + m_highestHeight * _scale;
			y = currPt.y;
			continue;
		}


		SGD::Point pt;
		pt.x = (float)m_lookUpChart[ch].s_x;
		pt.y = (float)m_lookUpChart[ch].s_y;

		SGD::Size sz;
		sz.width = (float)m_lookUpChart[ch].s_width;
		sz.height = (float)m_lookUpChart[ch].s_height;

		SGD::Rectangle rect = { pt, sz };

		currPt.y = y + m_lookUpChart[ch].s_yOffset * _scale;

		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_image, currPt, rect, 0.0f, {}, _color, { _scale, _scale });

		currPt.x += (m_lookUpChart[ch].s_width + m_lookUpChart[ch].s_xOffset) * _scale;
	}
}

void BitmapFont::Draw(const wchar_t * _output, SGD::Point _position, float _scale, SGD::Color _color)
{

	SGD::Point currPt = _position;
	float x = currPt.x;
	float y = currPt.y;

	// Is this string invisible?
	if (_output[0] == '\0'			// string is empty?
		|| _scale == 0.0f			// scale is invisible?
		|| _color.alpha == 0)		// color is invisible?
		return;

	for (int i = 0; _output[i]; i++)
	{
		// Get the current character
		char ch = (char)_output[i];

		if (ch == ' ')
		{
			currPt.x += m_avgWidth * _scale;
			continue;
		}
		else if (ch == '\n')
		{
			currPt.x = x;
			currPt.y = y + m_highestHeight * _scale;
			y = currPt.y;
			continue;
		}


		SGD::Point pt;
		pt.x = (float)m_lookUpChart[ch].s_x;
		pt.y = (float)m_lookUpChart[ch].s_y;

		SGD::Size sz;
		sz.width = (float)m_lookUpChart[ch].s_width;
		sz.height = (float)m_lookUpChart[ch].s_height;

		SGD::Rectangle rect = { pt, sz };

		currPt.y = y + m_lookUpChart[ch].s_yOffset * _scale;

		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_image, currPt, rect, 0.0f, {}, _color, { _scale, _scale });

		currPt.x += (m_lookUpChart[ch].s_width + m_lookUpChart[ch].s_xOffset) * _scale;
	}

}