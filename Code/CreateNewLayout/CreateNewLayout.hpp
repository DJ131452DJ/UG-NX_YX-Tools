﻿//==============================================================================
//  WARNING!!  This file is overwritten by the Block Styler while generating
//  the automation code. Any modifications to this file will be lost after
//  generating the code again.
//
//       Filename:  D:\YX_Tools\Code\layout\CreateNewLayout.hpp
//
//        This file was generated by the NX Block Styler
//        Created by: Yang
//              Version: NX 11
//              Date: 04-25-2017  (Format: mm-dd-yyyy)
//              Time: 16:37
//
//==============================================================================

#ifndef CREATENEWLAYOUT_H_INCLUDED
#define CREATENEWLAYOUT_H_INCLUDED
//------------------------------------------------------------------------------
//These includes are needed for the following template code
//------------------------------------------------------------------------------
#include <uf_defs.h>
#include <uf_ui_types.h>
#include <iostream>
#include <NXOpen/Session.hxx>
#include <NXOpen/UI.hxx>
#include <NXOpen/NXMessageBox.hxx>
#include <NXOpen/Callback.hxx>
#include <NXOpen/NXException.hxx>
#include <NXOpen/BlockStyler_UIBlock.hxx>
#include <NXOpen/BlockStyler_BlockDialog.hxx>
#include <NXOpen/BlockStyler_PropertyList.hxx>
#include <NXOpen/BlockStyler_StringBlock.hxx>
#include <NXOpen/BlockStyler_Group.hxx>
#include <NXOpen/BlockStyler_Enumeration.hxx>
#include <NXOpen/BlockStyler_ListBox.hxx>
#include <NXOpen/BlockStyler_DoubleBlock.hxx>
#include <NXOpen/BlockStyler_Toggle.hxx>
#include "uf.h"
#include "uf_ui.h"
#include "uf_layout.h"
#include "limits.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <map>
#include "INIParser.h"

//------------------------------------------------------------------------------
// Namespaces needed for following template
//------------------------------------------------------------------------------
using namespace std;
using namespace NXOpen;
using namespace NXOpen::BlockStyler;

class DllExport CreateNewLayout
{
    // class members
public:
    static Session *theSession;
    static UI *theUI;
    CreateNewLayout();
    ~CreateNewLayout();
    int Show();
    
    //----------------------- BlockStyler Callback Prototypes ---------------------
    // The following member function prototypes define the callbacks 
    // specified in your BlockStyler dialog.  The empty implementation
    // of these prototypes is provided in the CreateNewLayout.cpp file. 
    // You are REQUIRED to write the implementation for these functions.
    //------------------------------------------------------------------------------
    void initialize_cb();
    void dialogShown_cb();
    int apply_cb();
    int update_cb(NXOpen::BlockStyler::UIBlock* block);
    PropertyList* GetBlockProperties(const char *blockID);

	void SetLayoutName();
    
    //int AddCallback (NXOpen::BlockStyler::ListBox* list_box);
    //int DeleteCallback(NXOpen::BlockStyler::ListBox* list_box);
private:
    const char* theDlxFileName;
    NXOpen::BlockStyler::BlockDialog* theDialog;
    NXOpen::BlockStyler::StringBlock* string0;// Block type: String
    NXOpen::BlockStyler::Group* group;// Block type: Group
    NXOpen::BlockStyler::Enumeration* enum0;// Block type: Enumeration
    NXOpen::BlockStyler::ListBox* list_box0;// Block type: List Box
    NXOpen::BlockStyler::Enumeration* enum1;// Block type: Enumeration
    NXOpen::BlockStyler::DoubleBlock* double0;// Block type: Double
    NXOpen::BlockStyler::Group* group1;// Block type: Group
    NXOpen::BlockStyler::Toggle* toggle0;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle01;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle02;// Block type: Toggle
    
};
#endif