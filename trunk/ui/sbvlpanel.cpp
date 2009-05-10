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

#include "../skin.h"
#include "sbvlpanel.h"
#include "../gm_gameworld.h"
#include "../net/protocolgame.h"


void sbvlPanel_t::onClick_Logout(glictPos* relmousepos, glictContainer* callerclass)
{
	GM_Gameworld* gameclass = (GM_Gameworld*)g_game;
    //gameclass->getActiveConsole()->insertEntry(ConsoleEntry(PRODUCTSHORT ": Logging out...", TEXTCOLOR_WHITE));
	gameclass->m_protocol->sendLogout();
}


void sbvlPanel_t::btnSkills_onClick(glictPos* relmousepos, glictContainer* callerclass)
{
	glictButton* btn = (glictButton*)callerclass;
	sbvlPanel_t* panel = (sbvlPanel_t*)btn->GetCustomData();
	if(panel->winSkills.window.GetVisible()) {
		panel->closeSkills();
	}
	else {
		panel->openSkills();
	}
}
/*
void sbvlPanel_t::btnBattle_onClick(glictPos* relmousepos, glictContainer* callerclass)
{
	glictButton* btn = (glictButton*)callerclass;
	sbvlPanel_t* panel = (sbvlPanel_t*)btn->getCustomData();
	if(panel->winBattle.window.GetVisible()) {
		panel->closeBattle();
	}
	else {
		panel->openBattle();
	}
}
void sbvlPanel_t::btnVIP_onClick(glictPos* relmousepos, glictContainer* callerclass)
{
	glictButton* btn = (glictButton*)callerclass;
	sbvlPanel_t* panel = (sbvlPanel_t*)btn->getCustomData();
	if(panel->winVIP.window.GetVisible()) {
		panel->closeVIP();
	}
	else {
		panel->openVIP();
	}
}
*/

void sbvlPanel_t::openSkills()
{
	winSkills.window.SetVisible(true);
	btnSkills.SetHold(true);

	glictList* parentlist = dynamic_cast<glictList*>(winSkills.window.GetParent());
    if (parentlist)
        parentlist->RebuildList();
}
void sbvlPanel_t::closeSkills()
{
	winSkills.window.SetVisible(false);
	btnSkills.SetHold(false);

	glictList* parentlist = dynamic_cast<glictList*>(winSkills.window.GetParent());
    if (parentlist)
        parentlist->RebuildList();
}
/*
void sbvlPanel_t::openBattle()
{
	winBattle.window.SetVisible(true);
	btnBattle.SetHold(true);

	glictList* parentlist = dynamic_cast<glictList*>(winBattle.window.GetParent());
    if (parentlist)
        parentlist->RebuildList();
}
void sbvlPanel_t::closeBattle()
{
	winBattle.window.SetVisible(false);
	btnBattle.SetHold(false);

	glictList* parentlist = dynamic_cast<glictList*>(winBattle.window.GetParent());
    if (parentlist)
        parentlist->RebuildList();
}
void sbvlPanel_t::openVIP()
{
	winVIP.window.SetVisible(true);
	btnVIP.SetHold(true);

	glictList* parentlist = dynamic_cast<glictList*>(winVIP.window.GetParent());
    if (parentlist)
        parentlist->RebuildList();
}
void sbvlPanel_t::closeVIP()
{
	winVIP.window.SetVisible(false);
	btnVIP.SetHold(false);

	glictList* parentlist = dynamic_cast<glictList*>(winVIP.window.GetParent());
    if (parentlist)
        parentlist->RebuildList();
}
*/



void winSkills_t::OnClose()
{
	controller->closeSkills();
}
/*
void winBattle_t::onClose()
{
	if(controller) {
		controller->closeBattle();
	}
}
void winVIP_t::onClose()
{
	if(controller) {
		controller->closeVIP();
	}
}
*/
