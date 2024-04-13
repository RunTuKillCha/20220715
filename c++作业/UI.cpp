#include "UI.h"
#include "Config.h"
#include <string>
UI::UI(){}

void UI::initUI()
{
	loadimage(&m_hp, L"res/ui/card.png");
	//loadimage(&m_bcakhp, L"res/ui/2.png");
}

void UI::showUI(int hp)
{
	putimagePNG(0, 0, &m_hp);
	//putimagePNG(0, 0, &m_hp);

	wstring str = L"HP£º";
	str += to_wstring(hp);
	RECT rect = { 0,0,100,50 };
	settextcolor(YELLOW);
	setbkmode(TRANSPARENT);
	drawtext(str.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
