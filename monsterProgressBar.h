#pragma once
#include"gameNode.h"

class monsterProgressBar : public gameNode
{

private:

	RECT _rcProgress;		// ü�¹� ��Ʈ
	int _x, _y;
	int _width;				//���α���(��༮���� ������)
	int progressBarCount;
	image* _progressBarFront;		//ü�¹� ���̹���
	image* _progressBarBack;		//ü�¹� ���̹���


public:
	monsterProgressBar();
	~monsterProgressBar();
	HRESULT init(char* frontImage, char* backImage, float x, float y, int width, int height);
	void release();
	void update();
	void render();
	//������ ����
	void setGauge(float currentGauge, float maxGauge);

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

	RECT getRect() { return _rcProgress; }
};
