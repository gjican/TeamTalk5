/*
 * Copyright (c) 2005-2014, BearWare.dk
 * 
 * Contact Information:
 *
 * Bjoern D. Rasmussen
 * Skanderborgvej 40 4-2
 * DK-8000 Aarhus C
 * Denmark
 * Email: contact@bearware.dk
 * Phone: +45 20 20 54 59
 * Web: http://www.bearware.dk
 *
 * This source code is part of the TeamTalk 5 Conferencing System
 * owned by BearWare.dk. Unauthorized use is prohibited. No changes
 * are allowed to this file without the copyright owner's written
 * consent. Using this file requires a source code license issued by
 * BearWare.dk.
 *
 */

#include "stdafx.h"
#include "ClientXML.h"
#include "MyStd.h"
#include <assert.h>
#include <sstream>

using namespace std;
namespace teamtalk {


    TiXmlElement* ClientXML::GetRootElement()
    {
        TiXmlElement* root = m_xmlDocument.RootElement();
        if(!root)
        {
            TiXmlElement newroot(m_rootname.c_str());
            newroot.SetAttribute("version", TEAMTALK_XML_VERSION);
            m_xmlDocument.InsertEndChild(newroot);
            root = m_xmlDocument.RootElement();
        }
        return root;
    }


    TiXmlElement* ClientXML::GetMainElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* pMain = root->FirstChildElement("main");
            if(!pMain)
            {
                TiXmlElement newmain("main");
                pMain = root->InsertEndChild(newmain)->ToElement();
            }
            return pMain;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetGeneralElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("general");
            if(!child)
            {
                TiXmlElement newchild("general");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetWindowElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("window");
            if(!child)
            {
                TiXmlElement newchild("window");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetClientElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("clientsetup");
            if(!child)
            {
                TiXmlElement newchild("clientsetup");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetSoundSystemElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("soundsystem");
            if(!child)
            {
                TiXmlElement newchild("soundsystem");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetEventsElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("events");
            if(!child)
            {
                TiXmlElement newchild("events");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetVideoElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("videocapture");
            if(!child)
            {
                TiXmlElement newchild("videocapture");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetAdvancedElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("advanced");
            if(!child)
            {
                TiXmlElement newchild("advanced");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetShortCutsElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("shortcuts");
            if(!child)
            {
                TiXmlElement newchild("shortcuts");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetHostManagerElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("hostmanager");
            if(!child)
            {
                TiXmlElement newchild("hostmanager");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetLatestHostsElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("latesthosts");
            if(!child)
            {
                TiXmlElement newchild("latesthosts");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }

        return NULL;
    }

    TiXmlElement* ClientXML::GetOtherElement()
    {
        TiXmlElement* root = GetRootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("other");
            if(!child)
            {
                TiXmlElement newchild("other");
                child = root->InsertEndChild(newchild)->ToElement();
            }
            return child;
        }
        return NULL;
    }



    /****************************/
    /********* <main> ***********/
    /****************************/

    bool ClientXML::SetWindowPlacement(int x, int y, int cx, int cy)
    {
        TiXmlElement element("windowplacement");
        PutInteger(element, "left", x);
        PutInteger(element, "top", y);
        PutInteger(element, "width", cx);
        PutInteger(element, "height", cy);

        TiXmlElement* pMain = GetMainElement();
        if(pMain)
            return ReplaceElement(*pMain, element)? true : false;
        else
            return false;
    }

    bool ClientXML::GetWindowPlacement(int& x, int& y, int& cx, int& cy)
    {
        TiXmlElement* item=m_xmlDocument.RootElement();
        if(item)
        {
            if(item = item->FirstChildElement("main"))
            {
                TiXmlElement* target = item->FirstChildElement("windowplacement");
                if(target)
                {
                    GetInteger(*target, "left", x);
                    GetInteger(*target, "top", y);
                    GetInteger(*target, "width", cx);
                    GetInteger(*target, "height", cy);
                    return true;
                }
            }
        }
        return false;
    }

    bool ClientXML::SetWindowExtended(bool bExtended)
    {
        TiXmlElement* pParent = GetMainElement();
        if(pParent)
        {
            PutBoolean(*pParent, "extended", bExtended);
            return true;
        }
        return false;
    }

    bool ClientXML::GetWindowExtended()
    {
        TiXmlElement* pParent = GetMainElement();
        if(pParent)
        {
            bool bEnabled = true;
            GetBoolean(*pParent, "extended", bEnabled);
            return bEnabled;
        }
        return true;
    }

    /**************************************/
    /*****************         ************/

    bool ClientXML::AddHostManagerEntry(const HostEntry& entry)
    {
        TiXmlElement element("host");
        element.SetAttribute("name", entry.szEntryName.c_str());

        PutString(element, "address", entry.szAddress);
        PutInteger(element, "tcpport", entry.nTcpPort);
        PutInteger(element, "udpport", entry.nUdpPort);
        PutString(element, "username", entry.szUsername);
        PutString(element, "password", entry.szPassword);
        PutString(element, "channel", entry.szChannel);
        PutString(element, "cpassword", entry.szChPasswd);

        TiXmlElement* pParent = GetHostManagerElement();
        if(pParent)
            return pParent->InsertEndChild(element)?true:false;
        else
            return false;
    }

    bool ClientXML::GetHostManagerEntry(string entryname, HostEntry& entry)
    {
        bool found = false;
        for(int i=0;i<GetHostManagerEntryCount() && !found;i++)
        {
            GetHostManagerEntry(i, entry);
            if(entry.szEntryName==entryname)
                found = true;
        }
        return found;
    }

    bool ClientXML::RemoveHostManagerEntry(const string entryname)
    {
        TiXmlElement* item=m_xmlDocument.RootElement();

        if(item)
        {
            TiXmlElement* parent = item->FirstChildElement("hostmanager");
            if(item)
                for(TiXmlElement* child = parent->FirstChildElement("host");
                    child;
                    child = child->NextSiblingElement("host"))
                {
                    string szName = child->Attribute("name");
                    if(strcmpnocase(szName, entryname))
                    {
                        parent->RemoveChild(child);
                        break;
                    }
                }
                return true;
        }
        return false;
    }

    int ClientXML::GetHostManagerEntryCount()
    {
        TiXmlNode* item=m_xmlDocument.RootElement();
        int count = 0;

        if(item)
        {
            item = item->FirstChildElement("hostmanager");
            if(item)
                for(TiXmlNode* child = item->IterateChildren("host",0);
                    child;
                    child = item->IterateChildren("host",child))
                {
                    count++;
                }
        }
        return count;
    }

    bool ClientXML::GetHostManagerEntry(int index, HostEntry& entry)
    {
        TiXmlElement* item=m_xmlDocument.RootElement();
        bool found = false;
        if(item)
        {
            int i = 0;
            item = item->FirstChildElement("hostmanager");
            if(item)
            {
                TiXmlElement* child = NULL;
                for(child = item->FirstChildElement("host");
                    child;
                    child = child->NextSiblingElement("host"))
                    if(i==index)
                        break;
                    else
                        i++;

                if(child && i==index)
                {
                    found = true;
                    HostEntry tmp;
                    tmp.szEntryName = child->Attribute("name");
                    found &= GetString(*child, "address", tmp.szAddress);
                    found &= GetInteger(*child, "tcpport", tmp.nTcpPort);
                    found &= GetInteger(*child, "udpport", tmp.nUdpPort);
                    GetBoolean(*child, "encrypted", tmp.bEncrypted);
                    found &= GetString(*child, "username", tmp.szUsername);
                    found &= GetString(*child, "password", tmp.szPassword);
                    found &= GetString(*child, "channel", tmp.szChannel);
                    found &= GetString(*child, "cpassword", tmp.szChPasswd);
                    if(found)
                        entry = tmp;
                }
                else found = false;
            }

        }

        return found;
    }

    /************** <general> ****************/

    bool ClientXML::SetNickname(string szNickname)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutString(*pParent, "nickname", szNickname);
            return true;
        }
        else
            return false;
    }

    string ClientXML::GetNickname(std::string def_nickname/* = std::string()*/)
    {
        TiXmlElement* root=m_xmlDocument.RootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("general");
            if(child)
                GetString(*child, "nickname", def_nickname);
        }
        return def_nickname;
    }

    bool ClientXML::SetGender(int nGender)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutInteger(*pParent, "gender", nGender);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetGender(int nDefGender /*= DEFAULT_GENDER*/)
    {
        TiXmlElement* root=m_xmlDocument.RootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("general");
            if(child)
            {
                GetInteger(*child, "gender", nDefGender);
            }
        }
        return nDefGender;
    }

    bool ClientXML::SetStartMinimized(bool bEnable)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutBoolean(*pParent, "start-minimized", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetStartMinimized()
    {
        TiXmlElement* root=m_xmlDocument.RootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("general");
            if(child)
            {
                bool bEnabled = false;
                GetBoolean(*child, "start-minimized", bEnabled);
                return bEnabled;
            }
        }
        return false;
    }

    bool ClientXML::SetMinimizeToTray(bool bEnable)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutBoolean(*pParent, "minimize-to-tray", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetMinimizeToTray()
    {
        TiXmlElement* root=m_xmlDocument.RootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("general");
            if(child)
            {
                bool bEnabled = false;
                GetBoolean(*child, "minimize-to-tray", bEnabled);
                return bEnabled;
            }
        }
        return false;
    }

    bool ClientXML::SetPushToTalk(bool bEnable)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutBoolean(*pParent, "push-to-talk", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetPushToTalk(bool bDefEnable /*= DEFAULT_PUSHTOTALK*/)
    {
        TiXmlElement* root=m_xmlDocument.RootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("general");
            if(child)
                GetBoolean(*child, "push-to-talk", bDefEnable);
        }
        return bDefEnable;
    }

    bool ClientXML::SetPushToTalkKey(const HotKey& hotkey)
    {
        TiXmlElement* general = GetGeneralElement();
        if(general)
        {
            TiXmlElement newhotkey("hotkey");
            PutHotKey(newhotkey, hotkey);

            return ReplaceElement(*general, newhotkey)? true : false;
        }
        return false;
    }

    bool ClientXML::GetPushToTalkKey(HotKey& hotkey)
    {
        TiXmlElement* root=m_xmlDocument.RootElement();
        if(root)
        {
            TiXmlElement* general = root->FirstChildElement("general");
            if(general)
            {
                TiXmlElement* hkElement = general->FirstChildElement("hotkey");
                if(hkElement)
                {
                    GetHotKey(*hkElement, hotkey);
                    return true;
                }
            }
        }
        return false;
    }

    bool ClientXML::SetVoiceActivated(bool bEnable)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutBoolean(*pParent, "voice-activated", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetVoiceActivated(bool bDefVoiceAct /*= DEFAULT_VOICEACTIVATED*/)
    {
        TiXmlElement* root=m_xmlDocument.RootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("general");
            if(child)
            {
                GetBoolean(*child, "voice-activated", bDefVoiceAct);
            }
        }
        return bDefVoiceAct;
    }

    bool ClientXML::SetVoiceActivationLevel(int nLevel)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutInteger(*pParent, "voice-activation-level", nLevel);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetVoiceActivationLevel(int nDefVoxLevel/* = DEFAULT_VOICEACTIVATE_LEVEL*/)
    {
        TiXmlElement* root=m_xmlDocument.RootElement();
        if(root)
        {
            TiXmlElement* child = root->FirstChildElement("general");
            if(child)
                GetInteger(*child, "voice-activation-level", nDefVoxLevel);
        }
        return nDefVoxLevel;
    }

    int ClientXML::SetInactivityDelay(int nDelay)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutInteger(*pParent, "inactivity-delay", nDelay);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetInactivityDelay()
    {
        int nValue = 0;
        TiXmlElement* pGeneral = GetGeneralElement();
        if(pGeneral)
        {
            GetInteger(*pGeneral, "inactivity-delay", nValue);
        }
        return nValue;
    }

    bool ClientXML::SetDisableVadOnIdle(bool bEnable)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutBoolean(*pParent, "idle-disable-vad", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetDisableVadOnIdle()
    {
        bool bEnabled = false;
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
            GetBoolean(*pParent, "idle-disable-vad", bEnabled);
        return bEnabled;
    }

    bool ClientXML::SetDesktopShareMode(int nMode)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutInteger(*pParent, "desktop-share-mode", nMode);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetDesktopShareMode()
    {
        int nValue = UNDEFINED;
        TiXmlElement* pGeneral = GetGeneralElement();
        if(pGeneral)
        {
            GetInteger(*pGeneral, "desktop-share-mode", nValue);
        }
        return nValue;
    }

    bool ClientXML::SetDesktopShareRgbMode(int nMode)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutInteger(*pParent, "desktop-share-rgbmode", nMode);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetDesktopShareRgbMode()
    {
        int nValue = UNDEFINED;
        TiXmlElement* pGeneral = GetGeneralElement();
        if(pGeneral)
        {
            GetInteger(*pGeneral, "desktop-share-rgbmode", nValue);
        }
        return nValue;
    }

    bool ClientXML::SetDesktopShareUpdateInterval(int nInterval)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutInteger(*pParent, "desktop-share-interval", nInterval);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetDesktopShareUpdateInterval()
    {
        int nValue = UNDEFINED;
        TiXmlElement* pGeneral = GetGeneralElement();
        if(pGeneral)
        {
            GetInteger(*pGeneral, "desktop-share-interval", nValue);
        }
        return nValue;
    }

    bool ClientXML::SetFirewallInstall(bool bAsked)
    {
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
        {
            PutBoolean(*pParent, "firewall-install", bAsked);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetFirewallInstall(bool bDefValue)
    {
        bool bEnabled = bDefValue;
        TiXmlElement* pParent = GetGeneralElement();
        if(pParent)
            GetBoolean(*pParent, "firewall-install", bEnabled);
        return bEnabled;
    }


    /*************************************************/
    /***************** <window> **********************/
    /*************************************************/
    bool ClientXML::SetFont(string szFontName, int nSize, bool bBold, bool bUnderline, bool bItalic)
    {
        TiXmlElement element("font");
        PutString(element, "name", szFontName);
        PutInteger(element, "size", nSize);
        PutBoolean(element, "bold", bBold);
        PutBoolean(element, "underline", bUnderline);
        PutBoolean(element, "italic", bItalic);

        TiXmlElement* window = GetWindowElement();
        if(window)
            return ReplaceElement(*window, element)?true:false;
        else
            return false;
    }

    bool ClientXML::GetFont(string& szFontName, int& nSize, bool& bBold, bool& bUnderline, bool& bItalic)
    {
        TiXmlElement* window=GetWindowElement();
        if(window)
        {
            TiXmlElement* font = window->FirstChildElement("font");
            if(font)
            {    
                GetString(*font, "name", szFontName);
                GetInteger(*font, "size", nSize);
                GetBoolean(*font, "bold", bBold);
                GetBoolean(*font, "underline", bUnderline);
                GetBoolean(*font, "italic", bItalic);
                return true;
            }
        }
        return false;
    }

    bool ClientXML::SetPopupOnMessage(bool bEnable)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutBoolean(*pParent, "message-popup", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetPopupOnMessage()
    {
        TiXmlElement* child = GetWindowElement();
        if(child)
        {
            bool bEnabled = true;
            GetBoolean(*child, "message-popup", bEnabled);
            return bEnabled;
        }
        return true;
    }

    bool ClientXML::SetAlwaysOnTop(bool bEnable)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutBoolean(*pParent, "always-on-top", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetAlwaysOnTop()
    {
        TiXmlElement* child = GetWindowElement();
        if(child)
        {
            bool bEnabled = false;
            GetBoolean(*child, "always-on-top", bEnabled);
            return bEnabled;
        }
        return false;
    }

    bool ClientXML::SetShowUserCount(bool bEnable)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutBoolean(*pParent, "show-user-count", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetShowUserCount()
    {
        bool bEnabled = true;
        TiXmlElement* child = GetWindowElement();
        if(child)
            GetBoolean(*child, "show-user-count", bEnabled);

        return bEnabled;
    }

    bool ClientXML::SetJoinDoubleClick(bool bEnable)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutBoolean(*pParent, "join-dbclick", bEnable);
            return true;
        }
        else
            return false;
    }
    bool ClientXML::GetJoinDoubleClick()
    {
        bool bEnabled = true;
        TiXmlElement* child = GetWindowElement();
        if(child)
            GetBoolean(*child, "join-dbclick", bEnabled);

        return bEnabled;
    }
    bool ClientXML::SetQuitClearChannels(bool bEnable)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutBoolean(*pParent, "quit-clear-channels", bEnable);
            return true;
        }
        else
            return false;
    }
    bool ClientXML::GetQuitClearChannels()
    {
        bool bEnabled = true;
        TiXmlElement* child = GetWindowElement();
        if(child)
            GetBoolean(*child, "quit-clear-channels", bEnabled);

        return bEnabled;
    }

    bool ClientXML::SetMessageTimeStamp(bool bEnable)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutBoolean(*pParent, "message-timestamp", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetMessageTimeStamp()
    {
        bool bEnabled = false;
        TiXmlElement* child = GetWindowElement();
        if(child)
            GetBoolean(*child, "message-timestamp", bEnabled);

        return bEnabled;
    }

    bool ClientXML::SetLanguageFile(std::string szLanguageFile)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutString(*pParent, "language-file", szLanguageFile);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetLanguageFile()
    {
        std::string szLanguageFile;
        TiXmlElement* child = GetWindowElement();
        if(child)
            GetString(*child, "language-file", szLanguageFile);

        return szLanguageFile;
    }

    bool ClientXML::SetCloseTransferDialog(bool bEnable)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutBoolean(*pParent, "close-transferdlg", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetCloseTransferDialog()
    {
        bool bEnabled = false;
        TiXmlElement* child = GetWindowElement();
        if(child)
            GetBoolean(*child, "close-transferdlg", bEnabled);

        return bEnabled;
    }

    bool ClientXML::SetVuMeterUpdate(bool bEnable)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutBoolean(*pParent, "update-vu-meter", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetVuMeterUpdate()
    {
        bool bEnabled = true;
        TiXmlElement* child = GetWindowElement();
        if(child)
            GetBoolean(*child, "update-vu-meter", bEnabled);

        return bEnabled;
    }

    bool ClientXML::SetCheckApplicationUpdates(bool bEnable)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutBoolean(*pParent, "check-for-updates", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetCheckApplicationUpdates()
    {
        bool bEnabled = true;
        TiXmlElement* child = GetWindowElement();
        if(child)
            GetBoolean(*child, "check-for-updates", bEnabled);

        return bEnabled;
    }

    bool ClientXML::SetMaxTextLength(int nLength)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutInteger(*pParent, "max-text-length", nLength);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetMaxTextLength(int nDefault)
    {
        TiXmlElement* child = GetWindowElement();
        if(child)
            GetInteger(*child, "max-text-length", nDefault);

        return nDefault;
    }

    bool ClientXML::SetShowPublicServers(bool bEnable)
    {
        TiXmlElement* pParent = GetWindowElement();
        if(pParent)
        {
            PutBoolean(*pParent, "show-public-servers", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetShowPublicServers()
    {
        bool bEnabled = true;
        TiXmlElement* child = GetWindowElement();
        if(child)
            GetBoolean(*child, "show-public-servers", bEnabled);

        return bEnabled;
    }

    /***********************************/
    /*********** <client> **************/
    /***********************************/
    bool ClientXML::SetClientTcpPort(int nPort)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutInteger(*pParent, "tcpport", nPort);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetClientTcpPort(int nDefPort)
    {
        TiXmlElement* child = GetClientElement();
        if(child)
            GetInteger(*child, "tcpport", nDefPort);
        return nDefPort;
    }

    bool ClientXML::SetClientUdpPort(int nPort)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutInteger(*pParent, "udpport", nPort);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetClientUdpPort(int nDefPort)
    {
        TiXmlElement* child = GetClientElement();
        if(child)
            GetInteger(*child, "udpport", nDefPort);
        return nDefPort;
    }

    bool ClientXML::SetAutoConnectToLastest(bool bEnable)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutBoolean(*pParent, "auto-connect", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetAutoConnectToLastest()
    {
        TiXmlElement* child = GetClientElement();
        if(child)
        {
            bool bEnabled = false;
            GetBoolean(*child, "auto-connect", bEnabled);
            return bEnabled;
        }
        return false;
    }

    bool ClientXML::SetReconnectOnDropped(bool bEnable)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutBoolean(*pParent, "reconnect", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetReconnectOnDropped()
    {
        TiXmlElement* child = GetClientElement();
        if(child)
        {
            bool bEnabled = true;
            GetBoolean(*child, "reconnect", bEnabled);
            return bEnabled;
        }
        return true;
    }

    bool ClientXML::SetAutoJoinRootChannel(bool bEnable)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutBoolean(*pParent, "auto-join-root", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetAutoJoinRootChannel()
    {
        TiXmlElement* child = GetClientElement();
        if(child)
        {
            bool bEnabled = true;
            GetBoolean(*child, "auto-join-root", bEnabled);
            return bEnabled;
        }
        return false;
    }

    bool ClientXML::SetAudioLogStorageMode(int mode)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutInteger(*pParent, "audio-mode", mode);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetAudioLogStorageMode()
    {
        TiXmlElement* child = GetClientElement();
        if(child)
        {
            int nValue = 0;
            GetInteger(*child, "audio-mode", nValue);
            return nValue;
        }
        return 0;
    }

    bool ClientXML::SetAudioLogStorageFormat(int aff)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutInteger(*pParent, "audio-format", aff);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetAudioLogStorageFormat()
    {
        TiXmlElement* child = GetClientElement();
        if(child)
        {
            int nValue = 0;
            GetInteger(*child, "audio-format", nValue);
            return nValue;
        }
        return 0;
    }

    bool ClientXML::SetAudioLogStorage(const std::string& folder)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutString(*pParent, "audio-folder", folder);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetAudioLogStorage()
    {
        TiXmlElement* child = GetClientElement();
        if(child)
        {
            string s;
            GetString(*child, "audio-folder", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetChanTextLogStorage(const std::string& folder)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutString(*pParent, "channel-text-folder", folder);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetChanTextLogStorage()
    {
        TiXmlElement* child = GetClientElement();
        if(child)
        {
            string s;
            GetString(*child, "channel-text-folder", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetUserTextLogStorage(const std::string& folder)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutString(*pParent, "user-text-folder", folder);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetUserTextLogStorage()
    {
        TiXmlElement* child = GetClientElement();
        if(child)
        {
            string s;
            GetString(*child, "user-text-folder", s);
            return s;
        }
        return "";
    }


    bool ClientXML::SetDefaultSubscriptions(int subs)
    {
        TiXmlElement* pParent = GetClientElement();
        if(pParent)
        {
            PutInteger(*pParent, "default-subscriptions", subs);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetDefaultSubscriptions()
    {
        TiXmlElement* child = GetClientElement();
        int nValue = UNDEFINED;
        if(child)
        {
            GetInteger(*child, "default-subscriptions", nValue);
        }
        return nValue;
    }

    /****************************************/
    /************** <soundsystem> ***********/
    /****************************************/
    bool ClientXML::SetSoundInputDevice(int nDevice)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutInteger(*pParent, "input-driver", nDevice);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetSoundInputDevice(int nDefDeviceId)
    {
        TiXmlElement* child = GetSoundSystemElement();
        if(child)
            GetInteger(*child, "input-driver", nDefDeviceId);
        return nDefDeviceId;
    }

    bool ClientXML::SetSoundOutputDevice(int nDevice)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutInteger(*pParent, "output-driver", nDevice);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetSoundOutputDevice(int nDefDeviceId)
    {
        TiXmlElement* child = GetSoundSystemElement();
        if(child)
            GetInteger(*child, "output-driver", nDefDeviceId);
        return nDefDeviceId;
    }

    bool ClientXML::SetSoundMixerDevice(int nDevice)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutInteger(*pParent, "mixer-input", nDevice);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetSoundMixerDevice()
    {
        TiXmlElement* child = GetSoundSystemElement();
        if(child)
        {
            int nValue = UNDEFINED;
            GetInteger(*child, "mixer-input", nValue);
            return nValue;
        }
        return UNDEFINED;
    }

    bool ClientXML::SetSoundOutputVolume(int nVolume)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutInteger(*pParent, "volume", nVolume);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetSoundOutputVolume(int def_vol)
    {
        TiXmlElement* child = GetSoundSystemElement();
        if(child)
            GetInteger(*child, "volume", def_vol);
        return def_vol;
    }

    bool ClientXML::SetAutoPositioning(bool bEnable)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutBoolean(*pParent, "auto-positioning", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetAutoPositioning()
    {
        bool bEnable = false;
        TiXmlElement* child = GetSoundSystemElement();
        if(child)
        {
            GetBoolean(*child, "auto-positioning", bEnable);
        }
        return bEnable;
    }

    bool ClientXML::SetSoftwareGainLevel(int nLevel)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutInteger(*pParent, "soft-gain-level", nLevel);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetSoftwareGainLevel()
    {
        TiXmlElement* child = GetSoundSystemElement();
        if(child)
        {
            int nValue = UNDEFINED;
            GetInteger(*child, "soft-gain-level", nValue);
            return nValue;
        }
        return UNDEFINED;
    }

    bool ClientXML::SetAGC(bool bEnable)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutBoolean(*pParent, "agc", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetAGC(bool bDefValue)
    {
        TiXmlElement* child = GetSoundSystemElement();
        bool bEnabled = bDefValue;
        if(child)
            GetBoolean(*child, "agc", bEnabled);
        return bEnabled;
    }

    bool ClientXML::SetDenoise(bool bEnable)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutBoolean(*pParent, "denoise", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetDenoise(bool bDefValue)
    {
        TiXmlElement* child = GetSoundSystemElement();
        bool bEnabled = bDefValue;
        if(child)
            GetBoolean(*child, "denoise", bEnabled);
        return bEnabled;
    }

    bool ClientXML::SetVoiceGain(bool bEnable)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutBoolean(*pParent, "voice-gain", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetVoiceGain()
    {
        TiXmlElement* child = GetSoundSystemElement();
        if(child)
        {
            bool bEnabled = false;
            GetBoolean(*child, "voice-gain", bEnabled);
            return bEnabled;
        }
        return false;
    }

    bool ClientXML::SetVoiceGainLevel(int nGain)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutInteger(*pParent, "gain-level", nGain);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetVoiceGainLevel(int nDefGain)
    {
        TiXmlElement* child = GetSoundSystemElement();
        if(child)
            GetInteger(*child, "gain-level", nDefGain);
        return nDefGain;
    }

    bool ClientXML::SetDuplexMode(bool bEnable)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutBoolean(*pParent, "duplex-mode", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetDuplexMode(bool bDefValue)
    {
        TiXmlElement* child = GetSoundSystemElement();
        bool bEnabled = bDefValue;
        if(child)
            GetBoolean(*child, "duplex-mode", bEnabled);
        return bEnabled;
    }

    bool ClientXML::SetEchoCancel(bool bEnable)
    {
        TiXmlElement* pParent = GetSoundSystemElement();
        if(pParent)
        {
            PutBoolean(*pParent, "echo-cancel", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetEchoCancel(bool bDefValue)
    {
        TiXmlElement* child = GetSoundSystemElement();
        bool bEnabled = bDefValue;
        if(child)
            GetBoolean(*child, "echo-cancel", bEnabled);
        return bEnabled;
    }

    /**************** <events> ****************/
    bool ClientXML::SetEventNewUser(string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "newuser", szPath);
            return true;
        }
        else
            return false;
    }

    string ClientXML::GetEventNewUser()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "newuser", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventNewMessage(string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "newmessage", szPath);
            return true;
        }
        else
            return false;
    }

    string ClientXML::GetEventNewMessage()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "newmessage", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventRemovedUser(string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "removeduser", szPath);
            return true;
        }
        else
            return false;
    }

    string ClientXML::GetEventRemovedUser()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "removeduser", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventServerLost(string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "serverlost", szPath);
            return true;
        }
        else
            return false;
    }

    string ClientXML::GetEventServerLost()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "serverlost", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventUserReturned(string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "userreturned", szPath);
            return true;
        }
        else
            return false;
    }

    string ClientXML::GetEventUserReturned()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "userreturned", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventUserStoppedTalking(std::string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "userstoppedtalking", szPath);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetEventUserStoppedTalking()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "userstoppedtalking", s);
            return s;
        }
        return "";
    }


    bool ClientXML::SetEventHotKey(string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "hotkeypressed", szPath);
            return true;
        }
        else
            return false;
    }

    string ClientXML::GetEventHotKey()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "hotkeypressed", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventChannelMsg(string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "channelmessage", szPath);
            return true;
        }
        else
            return false;
    }

    string ClientXML::GetEventChannelMsg()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "channelmessage", s);
            return s;
        }
        return "";
    }


    bool ClientXML::SetEventFilesUpd(string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "filesupdates", szPath);
            return true;
        }
        else
            return false;
    }

    string ClientXML::GetEventFilesUpd()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "filesupdates", s);
            return s;
        }
        return "";
    }


    bool ClientXML::SetEventTransferEnd(string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "transferend", szPath);
            return true;
        }
        else
            return false;
    }

    string ClientXML::GetEventTransferEnd()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "transferend", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventVideoSession(std::string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "new-video-session", szPath);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetEventVideoSession()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "new-video-session", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventDesktopSession(std::string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "new-desktop-session", szPath);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetEventDesktopSession()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "new-desktop-session", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventQuestionMode(std::string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "question-mode", szPath);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetEventDesktopAccessReq()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "desktop-access-req", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventDesktopAccessReq(std::string szPath)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutString(*pParent, "desktop-access-req", szPath);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetEventQuestionMode()
    {
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            string s;
            GetString(*child, "question-mode", s);
            return s;
        }
        return "";
    }

    bool ClientXML::SetEventSpeechEvents(bool bEnable)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutBoolean(*pParent, "speech-events", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetEventSpeechEvents()
    {
        bool bRet = false;
        TiXmlElement* child = GetEventsElement();
        if(child)
        {
            GetBoolean(*child, "speech-events", bRet);
        }
        return bRet;
    }

    bool ClientXML::SetEventVibrateOnMsg(int nIndex)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutInteger(*pParent, "msg-vibrate", nIndex);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetEventVibrateOnMsg()
    {
        int ret = UNDEFINED;
        TiXmlElement* child = GetEventsElement();
        if(child)
            GetInteger(*child, "msg-vibrate", ret);

        return ret;
    }

    bool ClientXML::SetEventFlashOnMsg(int nIndex)
    {
        TiXmlElement* pParent = GetEventsElement();
        if(pParent)
        {
            PutInteger(*pParent, "msg-flash", nIndex);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetEventFlashOnMsg()
    {
        int ret = UNDEFINED;
        TiXmlElement* child = GetEventsElement();
        if(child)
            GetInteger(*child, "msg-flash", ret);

        return ret;
    }


    /********* <advanced> ************/
    bool ClientXML::SetMixerAutoSelection(bool bEnable)
    {
        TiXmlElement* pParent = GetAdvancedElement();
        if(pParent)
        {
            PutBoolean(*pParent, "mixer-auto-select", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetMixerAutoSelection()
    {
        TiXmlElement* child = GetAdvancedElement();
        if(child)
        {
            bool bEnabled = false;
            GetBoolean(*child, "mixer-auto-select", bEnabled);
            return bEnabled;
        }
        return false;
    }

    bool ClientXML::SetMixerAutoSelectInput(int nIndex)
    {
        TiXmlElement* pParent = GetAdvancedElement();
        if(pParent)
        {
            PutInteger(*pParent, "mixer-select-input", nIndex);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetMixerAutoSelectInput()
    {
        TiXmlElement* child = GetAdvancedElement();
        if(child)
        {
            int nIndex = UNDEFINED;
            GetInteger(*child, "mixer-select-input", nIndex);
            return nIndex;
        }
        return UNDEFINED;
    }

    bool ClientXML::SetMixerBoostBugCompensation(bool bEnable)
    {
        TiXmlElement* pParent = GetAdvancedElement();
        if(pParent)
        {
            PutBoolean(*pParent, "mixer-boost-bug", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetMixerBoostBugCompensation()
    {
        TiXmlElement* child = GetAdvancedElement();
        if(child)
        {
            bool bEnabled = false;
            GetBoolean(*child, "mixer-boost-bug", bEnabled);
            return bEnabled;
        }
        return false;
    }

    bool ClientXML::SetLowLevelMouseHook(bool bEnable)
    {
        TiXmlElement* pParent = GetAdvancedElement();
        if(pParent)
        {
            PutBoolean(*pParent, "lowlevel-mousehook", bEnable);
            return true;
        }
        else
            return false;
    }

    bool ClientXML::GetLowLevelMouseHook()
    {
        TiXmlElement* child = GetAdvancedElement();
        if(child)
        {
            bool bEnabled = false;
            GetBoolean(*child, "lowlevel-mousehook", bEnabled);
            return bEnabled;
        }
        return false;
    }

    /*********** </advanced> ***************/

    /********* <shortcuts> **********/
    bool ClientXML::SetHotKeyVoiceAct(const HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child)
        {
            TiXmlElement newhotkey("voice-act");
            PutHotKey(newhotkey, hotkey);
            return ReplaceElement(*child, newhotkey)?true:false;
        }
        return false;
    }

    bool ClientXML::GetHotKeyVoiceAct(HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child && (child = child->FirstChildElement("voice-act")))
        {
            return GetHotKey(*child, hotkey);
        }
        return false;
    }

    bool ClientXML::SetHotKeyVolumePlus(const HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child)
        {
            TiXmlElement newhotkey("increase-volume");
            PutHotKey(newhotkey, hotkey);
            return ReplaceElement(*child, newhotkey)?true:false;
        }
        return false;
    }

    bool ClientXML::GetHotKeyVolumePlus(HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child && (child = child->FirstChildElement("increase-volume")))
        {
            return GetHotKey(*child, hotkey);
        }
        return false;
    }

    bool ClientXML::SetHotKeyVolumeMinus(const HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child)
        {
            TiXmlElement newhotkey("lower-volume");
            PutHotKey(newhotkey, hotkey);
            return ReplaceElement(*child, newhotkey)?true:false;
        }
        return false;
    }

    bool ClientXML::GetHotKeyVolumeMinus(HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child && (child = child->FirstChildElement("lower-volume")))
        {
            return GetHotKey(*child, hotkey);
        }
        return false;
    }

    bool ClientXML::SetHotKeyMuteAll(const HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child)
        {
            TiXmlElement newhotkey("mute-all");
            PutHotKey(newhotkey, hotkey);
            return ReplaceElement(*child, newhotkey)?true:false;
        }
        return false;
    }

    bool ClientXML::GetHotKeyMuteAll(HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child && (child = child->FirstChildElement("mute-all")))
        {
            return GetHotKey(*child, hotkey);
        }
        return false;
    }

    bool ClientXML::SetHotKeyVoiceGainPlus(const HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child)
        {
            TiXmlElement newhotkey("increase-gain");
            PutHotKey(newhotkey, hotkey);
            return ReplaceElement(*child, newhotkey)?true:false;
        }
        return false;
    }

    bool ClientXML::GetHotKeyVoiceGainPlus(HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child && (child = child->FirstChildElement("increase-gain")))
        {
            return GetHotKey(*child, hotkey);
        }
        return false;
    }

    bool ClientXML::SetHotKeyVoiceGainMinus(const HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child)
        {
            TiXmlElement newhotkey("lower-gain");
            PutHotKey(newhotkey, hotkey);
            return ReplaceElement(*child, newhotkey)?true:false;
        }
        return false;
    }

    bool ClientXML::GetHotKeyVoiceGainMinus(HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child && (child = child->FirstChildElement("lower-gain")))
        {
            return GetHotKey(*child, hotkey);
        }
        return false;
    }

    bool ClientXML::SetHotKeyMinRestore(const HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child)
        {
            TiXmlElement newhotkey("min-restore");
            PutHotKey(newhotkey, hotkey);
            return ReplaceElement(*child, newhotkey)?true:false;
        }
        return false;
    }

    bool ClientXML::GetHotKeyMinRestore(HotKey& hotkey)
    {
        TiXmlElement* child = GetShortCutsElement();
        if(child && (child = child->FirstChildElement("min-restore")))
        {
            return GetHotKey(*child, hotkey);
        }
        return false;
    }

    /********* </shortcuts> *********/

    /********* <videocapture> *********/
    bool ClientXML::SetVideoCaptureDevice(const std::string& viddev)
    {
        TiXmlElement* pParent = GetVideoElement();
        if(pParent)
        {
            PutString(*pParent, "videodevice", viddev);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetVideoCaptureDevice()
    {
        TiXmlElement* child = GetVideoElement();
        string s;
        if(child)
            GetString(*child, "videodevice", s);
        return s;
    }

    bool ClientXML::SetVideoCaptureFormat(int index)
    {
        TiXmlElement* pParent = GetVideoElement();
        if(pParent)
        {
            PutInteger(*pParent, "capture-format", index);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetVideoCaptureFormat(int nDefIndex)
    {
        TiXmlElement* child = GetVideoElement();
        if(child)
            GetInteger(*child, "capture-format", nDefIndex);
        return nDefIndex;
    }

    bool ClientXML::SetVideoCaptureFormat(const VideoFormat& capformat)
    {
        TiXmlElement* child = GetVideoElement();
        if(child && capformat.nWidth)
        {
            TiXmlElement capfmt("videoformat");
            PutInteger(capfmt, "fourcc", capformat.picFourCC);
            PutInteger(capfmt, "width", capformat.nWidth);
            PutInteger(capfmt, "height", capformat.nHeight);
            PutInteger(capfmt, "fps-numerator", capformat.nFPS_Numerator);
            PutInteger(capfmt, "fps-denominator", capformat.nFPS_Denominator);

            TiXmlElement* vidcap = child->FirstChildElement("videoformat");
            if(vidcap)
                child->ReplaceChild(vidcap, capfmt);
            else
                child->InsertEndChild(capfmt);
            return true;
        }
        return false;
    }

    bool ClientXML::GetVideoCaptureFormat(VideoFormat& capformat)
    {
        TiXmlElement* child = GetVideoElement();
        TiXmlElement* capElem = child->FirstChildElement("videoformat");
        if(capElem)
        {
            int c = 0;
            GetInteger(*capElem, "fourcc", c);
            capformat.picFourCC = (FourCC)c;
            GetInteger(*capElem, "width", capformat.nWidth);
            GetInteger(*capElem, "height", capformat.nHeight);
            GetInteger(*capElem, "fps-numerator", capformat.nFPS_Numerator);
            GetInteger(*capElem, "fps-denominator", capformat.nFPS_Denominator);
            return true;
        }
        return false;
    }

    bool ClientXML::SetVideoCodecBitrate(int bitrate)
    {
        TiXmlElement* pParent = GetVideoElement();
        if(pParent)
        {
            PutInteger(*pParent, "webm-vp8-bitrate", bitrate);
            return true;
        }
        else
            return false;
    }

    int ClientXML::GetVideoCodecBitrate(int nDefBitrate)
    {
        TiXmlElement* child = GetVideoElement();
        if(child)
            GetInteger(*child, "webm-vp8-bitrate", nDefBitrate);
        return nDefBitrate;
    }

    /********* </videocapture> *********/


    /******** <latesthosts> ************/
    bool ClientXML::AddLatestHostEntry(const HostEntry& entry)
    {
        TiXmlElement element("host");
        PutString(element, "address", entry.szAddress);
        PutInteger(element, "tcpport", entry.nTcpPort);
        PutInteger(element, "udpport", entry.nUdpPort);
        PutBoolean(element, "encrypted", entry.bEncrypted);
        PutString(element, "username", entry.szUsername);
        PutString(element, "password", entry.szPassword);
        PutString(element, "channel", entry.szChannel);
        PutString(element, "cpassword", entry.szChPasswd);

        TiXmlElement* latest = GetLatestHostsElement();
        if(latest)
            return latest->InsertEndChild(element)?true:false;
        else
            return false;
    }

    bool ClientXML::RemoveLatestHostEntry(const HostEntry& entry)
    {
        TiXmlElement* parent = GetLatestHostsElement();
        if(parent)
        {
            for(TiXmlElement* child = parent->FirstChildElement("host");
                child;
                child = child->NextSiblingElement("host"))
            {
                string address, srvpasswd, username, password, channel, chpasswd;
                int soundport, port;
                bool encrypted;
                GetString(*child, "address", address);
                //GetString(*child, "password", password);
                GetInteger(*child, "tcpport", port);
                GetInteger(*child, "udpport", soundport);
                GetBoolean(*child, "encrypted", encrypted);
                GetString(*child, "username", username);
                GetString(*child, "password", password);
                GetString(*child, "channel", channel);
                GetString(*child, "cpassword", chpasswd);
                if(address == entry.szAddress &&
                    //password == entry.szPassword &&
                    port == entry.nTcpPort &&
                    soundport == entry.nUdpPort &&
                    encrypted == entry.bEncrypted &&
                    username == entry.szUsername &&
                    password == entry.szPassword &&
                    channel == entry.szChannel &&
                    chpasswd == entry.szChPasswd )
                {
                    parent->RemoveChild(child);
                    break;
                }
            }
            return true;
        }
        return false;
    }

    int ClientXML::GetLatestHostEntryCount()
    {
        int count = 0;
        TiXmlElement* item = GetLatestHostsElement();
        if(item)
            for(TiXmlNode* child = item->IterateChildren("host",0);
                child;
                child = item->IterateChildren("host",child))
            {
                count++;
            }

            return count;
    }

    bool ClientXML::GetLatestHostEntry(int index, HostEntry& entry)
    {
        bool found = false;
        int i = 0;
        TiXmlElement* item = GetLatestHostsElement();
        if(item)
        {
            TiXmlElement* child = NULL;
            for(child = item->FirstChildElement("host");
                child;
                child = child->NextSiblingElement("host"))
                if(i==index)
                    break;
                else
                    i++;

            if(child && i==index)
            {
                found = true;
                HostEntry tmp;
                found &= GetString(*child, "address", tmp.szAddress);
                found &= GetInteger(*child, "tcpport", tmp.nTcpPort);
                found &= GetInteger(*child, "udpport", tmp.nUdpPort);
                GetBoolean(*child, "encrypted", tmp.bEncrypted);
                found &= GetString(*child, "username", tmp.szUsername);
                found &= GetString(*child, "password", tmp.szPassword);
                found &= GetString(*child, "channel", tmp.szChannel);
                found &= GetString(*child, "cpassword", tmp.szChPasswd);

                if(found)
                    entry = tmp;
            }
            else found = false;
        }

        return found;
    }

    /**** </latest-hosts> *****/

    /********** <other> *********/
    bool ClientXML::SetLastMediaFile(const std::string& filename)
    {
        TiXmlElement* pParent = GetOtherElement();
        if(pParent)
        {
            PutString(*pParent, "last-media-file", filename);
            return true;
        }
        else
            return false;
    }

    std::string ClientXML::GetLastMediaFile()
    {
        TiXmlElement* child = GetOtherElement();
        string s;
        if(child)
            GetString(*child, "last-media-file", s);
        return s;
    }
    /********** </other> *********/

    void ClientXML::PutHotKey(TiXmlElement& parent, const HotKey& hotkey)
    {
        for(size_t i=0;i<hotkey.size();i++)
            PutInteger(parent, string("key") + i2str((int)i), hotkey[i]);
    }

    bool ClientXML::GetHotKey( const TiXmlElement& parent, HotKey& hotkey)
    {
        assert(hotkey.empty());
        bool b = true;
        int i = 0;
        int key = 0;
        while(GetInteger(parent, string("key") + i2str(i++), key))
            hotkey.push_back(key);
        return hotkey.size()?true:false;
    }



    /************************/
    /* Parsing of .tt files */
    /************************/
    TiXmlElement* TTFile::GetRootElement()
    {
        return m_xmlDocument.RootElement();
    }


    void TTFile::SetHostEntry(const HostEntry& entry)
    {
        TiXmlElement hostElement("host");
        PutString(hostElement, "name", entry.szEntryName);
        PutString(hostElement, "address", entry.szAddress);
        PutInteger(hostElement, "tcpport", entry.nTcpPort);
        PutInteger(hostElement, "udpport", entry.nUdpPort);
        PutBoolean(hostElement, "encrypted", entry.bEncrypted);

        TiXmlElement auth("auth");
        PutString(auth, "username", entry.szUsername);
        PutString(auth, "password", entry.szPassword);
        ReplaceElement(hostElement, auth);

        TiXmlElement join("join");
        PutString(join, "channel", entry.szChannel);
        PutString(join, "password", entry.szChPasswd);
        ReplaceElement(hostElement, join);

        TiXmlElement client("clientsetup");
        if(entry.szNickname.size())
            PutString(client, "nickname", entry.szNickname);
        if(entry.nGender)
            PutInteger(client, "gender", entry.nGender);
        if(entry.hotkey.size())
        {
            TiXmlElement hotkey("win-hotkey");
            for(int i=0;i<entry.hotkey.size();i++)
            {
                TiXmlElement newelement("key");
                TiXmlText text(i2str(entry.hotkey[i]).c_str());
                newelement.InsertEndChild(text);

                hotkey.InsertEndChild(newelement);
            }
            client.InsertEndChild(hotkey);
        }
        PutInteger(client, "voice-activated", entry.nVoiceAct);

        if(entry.capformat.nWidth)
        {
            TiXmlElement capfmt("videoformat");
            PutInteger(capfmt, "fourcc", entry.capformat.picFourCC);
            PutInteger(capfmt, "width", entry.capformat.nWidth);
            PutInteger(capfmt, "height", entry.capformat.nHeight);
            PutInteger(capfmt, "fps-numerator", entry.capformat.nFPS_Numerator);
            PutInteger(capfmt, "fps-denominator", entry.capformat.nFPS_Denominator);

            client.InsertEndChild(capfmt);
        }

        if(entry.vidcodec.nCodec != NO_CODEC)
        {
            TiXmlElement vidcodec("videocodec");
            PutInteger(vidcodec, "codec", entry.vidcodec.nCodec);
            PutInteger(vidcodec, "webm-vp8-bitrate", entry.vidcodec.webm_vp8.nRcTargetBitrate);
            client.InsertEndChild(vidcodec);
        }

        if(client.FirstChildElement())
            hostElement.InsertEndChild(client);

        TiXmlElement* item=m_xmlDocument.RootElement();
        if(item)
            item->InsertEndChild(hostElement);
    }

    bool TTFile::GetHostEntry(HostEntry& entry, int i)
    {
        TiXmlElement* item=m_xmlDocument.RootElement();
        bool found = false;
        if(item)
        {
            item = item->FirstChildElement("host");
            while(item && i >= 0)
            {
                bool ok = true;
                ok &= GetString(*item, "name", entry.szEntryName);
                ok &= GetString(*item, "address", entry.szAddress);
                ok &= GetInteger(*item, "tcpport", entry.nTcpPort);
                ok &= GetInteger(*item, "udpport", entry.nUdpPort);
                GetBoolean(*item, "encrypted", entry.bEncrypted);

                //check auth settings
                TiXmlElement* auth = item->FirstChildElement("auth");
                if(auth)
                {
                    GetString(*auth, "username", entry.szUsername);
                    GetString(*auth, "password", entry.szPassword);
                }
                TiXmlElement* join = item->FirstChildElement("join");
                if(join)
                {
                    GetString(*join, "channel", entry.szChannel);
                    GetString(*join, "password", entry.szChPasswd);
                }
                TiXmlElement* client = item->FirstChildElement("clientsetup");
                if(client)
                {

                    GetString(*client, "nickname", entry.szNickname);
                    GetInteger(*client, "gender", entry.nGender);

                    TiXmlElement* hotkey = client->FirstChildElement("win-hotkey");
                    if(hotkey)
                    {
                        TiXmlElement* key = hotkey->FirstChildElement("key");
                        while(key)
                        {
                            string v;
                            GetElementText(*key, v);
                            entry.hotkey.push_back(str2i(v));
                            key = key->NextSiblingElement("key");
                        }
                    }
                    GetInteger(*client, "voice-activated", entry.nVoiceAct);

                    TiXmlElement* capformat = client->FirstChildElement("videoformat");
                    if(capformat)
                    {
                        int c = 0;
                        GetInteger(*capformat, "fourcc", c);
                        entry.capformat.picFourCC = (FourCC)c;

                        GetInteger(*capformat, "width", entry.capformat.nWidth);
                        GetInteger(*capformat, "height", entry.capformat.nHeight);
                        GetInteger(*capformat, "fps-numerator", entry.capformat.nFPS_Numerator);
                        GetInteger(*capformat, "fps-denominator", entry.capformat.nFPS_Denominator);
                    }

                    TiXmlElement* vidcodec = client->FirstChildElement("videocodec");
                    if(vidcodec)
                    {
                        int c = NO_CODEC;
                        GetInteger(*vidcodec, "codec", c);
                        entry.vidcodec.nCodec = (Codec)c;
                        switch(entry.vidcodec.nCodec)
                        {
                        case WEBM_VP8_CODEC :
                            GetInteger(*vidcodec, "webm-vp8-bitrate", entry.vidcodec.webm_vp8.nRcTargetBitrate);
                            break;
                        }
                    }
                }
                
                found = ok && i == 0;
                item = item->NextSiblingElement("host");
                i--;
            }
        }
        return found;
    }
    
    bool TTFile::HasClientSetup()    {
        TiXmlElement* item=m_xmlDocument.RootElement();
        if(item)
        {
            item = item->FirstChildElement("host");
            TiXmlElement* client = item->FirstChildElement("clientsetup");
            return client != NULL;
        }
        return false;
    }

}
