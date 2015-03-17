#pragma once
#include "IGameState.h"
#include "../resource/TinyXML/tinyxml.h"
#include"../SGD Wrappers/SGD_Utilities.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include"../SGD Wrappers/SGD_InputManager.h"
#include"Game.h"
#include"MainMenuState.h"

class OptionState :
	public IGameState
{
private:
	OptionState() = default;
	~OptionState() = default;
	OptionState(const OptionState&) = delete;
	OptionState& operator= (const OptionState&) = delete;
	SGD::HAudio m_Music = SGD::INVALID_HANDLE;
	SGD::HAudio m_SFX = SGD::INVALID_HANDLE;
	int MasterVol=100,MusicVol = 100, SFXVol = 100;
	int m_CursorPos = 0;

public:
	static OptionState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);

	int		GetMusicVol() const { return MusicVol; }
	int		GetSFXVol() const { return SFXVol; }
	int		GetMasterVol() const { return MasterVol; }

	void	SetMusicVol(int _musicvolume) { MusicVol = _musicvolume; }
	void	SetSFXVol(int _sfxvolume) { SFXVol = _sfxvolume; }
	void	SetMasterVol(int _mastervolume) { MasterVol = _mastervolume; }


};

