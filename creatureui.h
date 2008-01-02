//////////////////////////////////////////////////////////////////////
// Yet Another Tibia Client
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#ifndef __CREATUREUI_H
#define __CREATUREUI_H

#include "thingui.h"
#include "objects.h"
class CreatureUI : virtual public ThingUI {
public:

	CreatureUI();
	~CreatureUI();
	virtual void Blit(int x, int y, float scale = 1., int map_x = 0, int map_y = 0) const;
	void loadOutfit();
	void drawName(int x, int y, float scale) const;
	void startWalk() { m_preWalk = true; m_walkState = 0.f; }
	void confirmWalk() { m_preWalk = false; }
	void advanceWalk(int groundspeed);
	void getWalkOffset(float &walkoffx, float &walkoffy, float scale=1.f) const;
	bool isPreWalking() {return m_preWalk;}
	float getWalkState() {return m_walkState;}
protected:
	void unloadGfx();

private:
	ObjectType *m_obj;

	bool m_preWalk;
	float m_walkState;

};

#endif