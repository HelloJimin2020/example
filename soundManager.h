#pragma once
#include"singletonBase.h"
#include"inc/fmod.hpp"
#pragma comment(lib,"lib/fmodex_vc.lib")
using namespace FMOD;

#define EXTRACHANNELBUFFER 5
#define SOUNDBUFFER 100

#define TOTALSOUNDBUFFER SOUNDBUFFER+ EXTRACHANNELBUFFER
class soundManager : public singletonBase<soundManager>
{
private:

	typedef map<string, Sound**>arrSounds;
	typedef map<string, Sound**>::iterator arrSoundIter;

	string songName[6];
	int currentNum = 0 ;

	System* m_system;		


	Sound** m_sound;		//사운드
	Channel** m_channel;		//채널


	arrSounds m_totalSounds;



public:
	soundManager();
	~soundManager();

	HRESULT init();
	void release();
	void update();
	void render();
	//키값, 파일 이름, BGM, LOOP
	void addSound(string keyName, string soundName, bool bgm = FALSE, bool loop = FALSE);

	//사운드 플레이	(키값, 볼륨 0.0~1.0f)
	void play(string keyName, float volume = 1.0f);

	void stop(string keyName);
	void pause(string keyName);
	void resume(string keyName);

	//플레이 중이냐
	bool isPlaySound(string keyName);
	//일시 정지 중이냐
	bool isPauseSound(string keyName);

	void setSongName() { songName[0] = "인트로브금"; songName[1] = "마을브금"; songName[2] = "던전브금"; 
	songName[3] = "상점브금"; songName[4] = "회복방브금"; songName[5] = "보스방브금";
	}

	int getCurrentNum() { return currentNum; }
	void setCurrentNum(int num) { currentNum = num; }
	string getCurrentSong() { return songName[currentNum]; }
};

