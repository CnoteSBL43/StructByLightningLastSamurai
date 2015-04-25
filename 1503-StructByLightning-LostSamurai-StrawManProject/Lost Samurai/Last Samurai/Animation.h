#pragma once
#include <vector>
#include <string>
#include "Frame.h"

class Animation
{
private:
	//Data Members
	std::vector<Frame> m_Frames;
	std::string m_Name;
	bool IsLooping;
	int m_ImageID;

public:
	//Ctor & Dtor
	Animation() = default;
	~Animation();

	//Accessors
	std::vector<Frame>&	GetFrames()				{ return m_Frames; }
	std::string			GetName() const			{ return m_Name; }
	int					GetID() const			{ return m_ImageID; }
	bool				CheckIfLooping() const;

	//Mutators
	void				SetName(std::string _string) { m_Name = _string; }
	void				SetLooping(bool _bool)		{ IsLooping = _bool; }
	void				SetID(int _ID)				{ m_ImageID = _ID; }

	//Methods

	//Adds Frames to Frame Vector
	void AddFrames(Frame _frame);

	//Cleans up the vector
	void Clear();
};

