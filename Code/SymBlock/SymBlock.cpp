﻿//==============================================================================
//  WARNING!!  This file is overwritten by the Block UI Styler while generating
//  the automation code. Any modifications to this file will be lost after
//  generating the code again.
//
//       Filename:  D:\YX_Tools\Application\SymBlock.cpp
//
//        This file was generated by the NX Block UI Styler
//        Created by: Yang
//              Version: NX 11
//              Date: 09-02-2016  (Format: mm-dd-yyyy)
//              Time: 23:37 (Format: hh-mm)
//
//==============================================================================

//==============================================================================
//  Purpose:  This TEMPLATE file contains C++ source to guide you in the
//  construction of your Block application dialog. The generation of your
//  dialog file (.dlx extension) is the first step towards dialog construction
//  within NX.  You must now create a NX Open application that
//  utilizes this file (.dlx).
//
//  The information in this file provides you with the following:
//
//  1.  Help on how to load and display your Block UI Styler dialog in NX
//      using APIs provided in NXOpen.BlockStyler namespace
//  2.  The empty callback methods (stubs) associated with your dialog items
//      have also been placed in this file. These empty methods have been
//      created simply to start you along with your coding requirements.
//      The method name, argument list and possible return values have already
//      been provided for you.
//==============================================================================

//------------------------------------------------------------------------------
//These includes are needed for the following template code
//------------------------------------------------------------------------------
#include "SymBlock.hpp"
using namespace NXOpen;
using namespace NXOpen::BlockStyler;

//------------------------------------------------------------------------------
// Initialize static variables
//------------------------------------------------------------------------------
Session *(SymBlock::theSession) = NULL;
UI *(SymBlock::theUI) = NULL;
//------------------------------------------------------------------------------
// Constructor for NX Styler class
//------------------------------------------------------------------------------
SymBlock::SymBlock()
{
    try
    {
        // Initialize the NX Open C++ API environment
        SymBlock::theSession = NXOpen::Session::GetSession();
        SymBlock::theUI = UI::GetUI();
        theDlxFileName = "SymBlock.dlx";
        theDialog = SymBlock::theUI->CreateDialog(theDlxFileName);
        // Registration of callback functions
        theDialog->AddApplyHandler(make_callback(this, &SymBlock::apply_cb));
        theDialog->AddOkHandler(make_callback(this, &SymBlock::ok_cb));
        theDialog->AddUpdateHandler(make_callback(this, &SymBlock::update_cb));
        theDialog->AddInitializeHandler(make_callback(this, &SymBlock::initialize_cb));
        theDialog->AddDialogShownHandler(make_callback(this, &SymBlock::dialogShown_cb));
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        throw;
    }
}

//------------------------------------------------------------------------------
// Destructor for NX Styler class
//------------------------------------------------------------------------------
SymBlock::~SymBlock()
{
    if (theDialog != NULL)
    {
        delete theDialog;
        theDialog = NULL;
    }
}
//------------------------------- DIALOG LAUNCHING ---------------------------------
//
//    Before invoking this application one needs to open any part/empty part in NX
//    because of the behavior of the blocks.
//
//    Make sure the dlx file is in one of the following locations:
//        1.) From where NX session is launched
//        2.) $UGII_USER_DIR/application
//        3.) For released applications, using UGII_CUSTOM_DIRECTORY_FILE is highly
//            recommended. This variable is set to a full directory path to a file 
//            containing a list of root directories for all custom applications.
//            e.g., UGII_CUSTOM_DIRECTORY_FILE=$UGII_BASE_DIR\ugii\menus\custom_dirs.dat
//
//    You can create the dialog using one of the following way:
//
//    1. USER EXIT
//
//        1) Create the Shared Library -- Refer "Block UI Styler programmer's guide"
//        2) Invoke the Shared Library through File->Execute->NX Open menu.
//
//------------------------------------------------------------------------------
extern "C" DllExport void  ufusr(char *param, int *retcod, int param_len)
{
    SymBlock *theSymBlock = NULL;
    try
    {
        theSymBlock = new SymBlock();
        // The following method shows the dialog immediately
        theSymBlock->Show();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        SymBlock::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    if(theSymBlock != NULL)
    {
        delete theSymBlock;
        theSymBlock = NULL;
    }
}

//------------------------------------------------------------------------------
// This method specifies how a shared image is unloaded from memory
// within NX. This method gives you the capability to unload an
// internal NX Open application or user  exit from NX. Specify any
// one of the three constants as a return value to determine the type
// of unload to perform:
//
//
//    Immediately : unload the library as soon as the automation program has completed
//    Explicitly  : unload the library from the "Unload Shared Image" dialog
//    AtTermination : unload the library when the NX session terminates
//
//
// NOTE:  A program which associates NX Open applications with the menubar
// MUST NOT use this option since it will UNLOAD your NX Open application image
// from the menubar.
//------------------------------------------------------------------------------
extern "C" DllExport int ufusr_ask_unload()
{
    //return (int)Session::LibraryUnloadOptionExplicitly;
    return (int)Session::LibraryUnloadOptionImmediately;
    //return (int)Session::LibraryUnloadOptionAtTermination;
}

//------------------------------------------------------------------------------
// Following method cleanup any housekeeping chores that may be needed.
// This method is automatically called by NX.
//------------------------------------------------------------------------------
extern "C" DllExport void ufusr_cleanup(void)
{
    try
    {
        //---- Enter your callback code here -----
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        SymBlock::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

int SymBlock::Show()
{
    try
    {
        theDialog->Show();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        SymBlock::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return 0;
}

//------------------------------------------------------------------------------
//---------------------Block UI Styler Callback Functions--------------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Callback Name: initialize_cb
//------------------------------------------------------------------------------
void SymBlock::initialize_cb()
{
    try
    {
        grouptype = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("grouptype"));
        blocktype = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("blocktype"));
        groupselectpoint = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("groupselectpoint"));
        selectcenterpoint = dynamic_cast<NXOpen::BlockStyler::SpecifyPoint*>(theDialog->TopBlock()->FindBlock("selectcenterpoint"));
        groupdim = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("groupdim"));
        dimxc = dynamic_cast<NXOpen::BlockStyler::LinearDimension*>(theDialog->TopBlock()->FindBlock("dimxc"));
        dimyc = dynamic_cast<NXOpen::BlockStyler::LinearDimension*>(theDialog->TopBlock()->FindBlock("dimyc"));
        dimzc = dynamic_cast<NXOpen::BlockStyler::LinearDimension*>(theDialog->TopBlock()->FindBlock("dimzc"));
        groupbool = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("groupbool"));
        booltype = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("booltype"));
        separator0 = dynamic_cast<NXOpen::BlockStyler::Separator*>(theDialog->TopBlock()->FindBlock("separator0"));
        boolbodySelect = dynamic_cast<NXOpen::BlockStyler::BodyCollector*>(theDialog->TopBlock()->FindBlock("boolbodySelect"));
        group4 = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group4"));
        preview = dynamic_cast<NXOpen::BlockStyler::Button*>(theDialog->TopBlock()->FindBlock("preview"));
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        SymBlock::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

//------------------------------------------------------------------------------
//Callback Name: dialogShown_cb
//This callback is executed just before the dialog launch. Thus any value set 
//here will take precedence and dialog will be launched showing that value. 
//------------------------------------------------------------------------------
void SymBlock::dialogShown_cb()
{
    try
    {
        //---- Enter your callback code here -----
		previewkey=1;
		Initializationpreview();
		selectbooltype();
/*				createblock();*/
	}

    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        SymBlock::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

//------------------------------------------------------------------------------
//Callback Name: apply_cb
//------------------------------------------------------------------------------
int SymBlock::apply_cb()
{
    int errorCode = 0;
    try
    {
        //---- Enter your callback code here -----
		
		if (previewkey==1)
		{
		createblock();
		}
		 }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        errorCode = 1;
        SymBlock::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return errorCode;
}

//------------------------------------------------------------------------------
//Callback Name: update_cb
//------------------------------------------------------------------------------
int SymBlock::update_cb(NXOpen::BlockStyler::UIBlock* block)
{
    try
    {
        if(block == blocktype)
        {
        //---------Enter your code here-----------
/*						createblock();*/
			
        }
        else if(block == selectcenterpoint)
        {
        //---------Enter your code here-----------
			Initializationpreview();
/*			createblock();*/

        }
        else if(block == dimxc)
        {
        //---------Enter your code here-----------
/*						createblock();*/
        }
        else if(block == dimyc)
        {
        //---------Enter your code here-----------
/*						createblock();*/
        }
        else if(block == dimzc)
        {
        //---------Enter your code here-----------
/*						createblock();*/
        }
        else if(block == booltype)
        {
        //---------Enter your code here-----------
			selectbooltype();
        }
        else if(block == separator0)
        {
        //---------Enter your code here-----------
        }
        else if(block == boolbodySelect)
        {
        //---------Enter your code here-----------
			selectbooltype();

			
        }
        else if(block == preview)
        {
        //---------Enter your code here-----------
			if (previewkey==1)
			{
				createblock();
				previestate(0);
				preview->SetBitmap("undo");
				preview->SetLabel("撤销 ");

			} 
			else
			{
				previestate(1);
				uf_list_t  *listtag=NULL;
				UF_MODL_create_list(&listtag);
				UF_MODL_put_list_item(listtag,theoverTAG);
				UF_MODL_delete_feature(listtag);
				UF_MODL_delete_list(&listtag);
				preview->SetBitmap("magnifying_glass");
				preview->SetLabel("预览 ");
				createblockTAG=NULL_TAG;
			}
			previewkey=!previewkey;





        }
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        SymBlock::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return 0;
}

//------------------------------------------------------------------------------
//Callback Name: ok_cb
//------------------------------------------------------------------------------
int SymBlock::ok_cb()
{
    int errorCode = 0;
    try
    {
        errorCode = apply_cb();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
/*		createblock();*/
        errorCode = 1;
        SymBlock::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return errorCode;
}

//------------------------------------------------------------------------------
//Function Name: GetBlockProperties
//Description: Returns the propertylist of the specified BlockID
//------------------------------------------------------------------------------
PropertyList* SymBlock::GetBlockProperties(const char *blockID)
{
    return theDialog->GetBlockProperties(blockID);
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void SymBlock::Initializationpreview()//初始化预览按钮
{
	std::vector<TaggedObject *>prevpoint=selectcenterpoint->GetSelectedObjects();

	if (int(prevpoint.size())==0)
	{
		preview->SetEnable(0);
	} 
	else if (int(prevpoint.size())>0)
	{
		preview->SetEnable(1);
	}
}
//------------------------------------------------------------------------------
void SymBlock:: previestate(bool previekey)//预览是灰显其他组
{

	UF_initialize();
	grouptype->SetEnable(previekey);
	groupselectpoint->SetEnable(previekey);
	groupdim->SetEnable(previekey);
	groupbool->SetEnable(previekey);
}


	void SymBlock:: createblock()
	{

		UF_initialize();
		Point3d tmp_point=selectcenterpoint->Point();
		double tmp_blockdimxc,tmp_blockdimyc,tmp_blockdimzc;
		tmp_blockdimxc=dimxc->Value();
		tmp_blockdimyc=dimyc->Value();
		tmp_blockdimzc=dimzc->Value();

		if (blocktype->GetProperties()->GetEnum("Value")==0)
		{

			mainpoint[1]= (tmp_point.X-(tmp_blockdimxc/2));
			mainpoint[2]= (tmp_point.Y-(tmp_blockdimyc/2));
			mainpoint[3]= tmp_point.Z;
		} 
		if (blocktype->GetProperties()->GetEnum("Value")==1)
		{

			mainpoint[1]= (tmp_point.X-(tmp_blockdimxc/2));
			mainpoint[2]= tmp_point.Y;
			mainpoint[3]= (tmp_point.Z-(tmp_blockdimzc/2));
		}
		if (blocktype->GetProperties()->GetEnum("Value")==2)
		{

			mainpoint[1]= tmp_point.X;
			mainpoint[2]= (tmp_point.Y-(tmp_blockdimyc/2));
			mainpoint[3]= (tmp_point.Z-(tmp_blockdimzc/2));
		}
		if (blocktype->GetProperties()->GetEnum("Value")==3)
		{

			mainpoint[1]= (tmp_point.X-(tmp_blockdimxc/2));
			mainpoint[2]= (tmp_point.Y-(tmp_blockdimyc/2));
			mainpoint[3]= (tmp_point.Z-(tmp_blockdimzc/2));
		}

			char blockdimxc[256];
			char blockdimyc[256];
			char blockdimzc[256];			

		sprintf(blockdimxc,"%f",tmp_blockdimxc);
		sprintf(blockdimyc,"%f",tmp_blockdimyc);
		sprintf(blockdimzc,"%f",tmp_blockdimzc);

			UF_FEATURE_SIGN sign=UF_NULLSIGN;
			double corner_pt [ 3 ] ={mainpoint[1],mainpoint[2],mainpoint[3]};
			char *edge_len [ 3 ]  ={blockdimxc,blockdimyc,blockdimzc};
			createblockTAG=NULL_TAG;
			UF_MODL_create_block1(sign, corner_pt, edge_len,&createblockTAG );


			UF_terminate();
			selectbooltype();
	}

	void SymBlock:: selectbooltype()//判断布尔运算选项是否启用
	{
		if (booltype->GetProperties()->GetEnum("Value")==0)
		{
			boolbodySelect->SetEnable(0);
			boolbodySelect->SetShow(0);
			 theoverTAG=createblockTAG;
		} 
		else
		{
			UF_initialize();
			boolbodySelect->SetEnable(1);
			boolbodySelect->SetShow(1);
			
			
			//获取选择的实体
			PropertyList*  boolbodySelectProps = boolbodySelect->GetProperties();
			boolbodys = boolbodySelectProps->GetTaggedObjectVector("SelectedObjects");
			delete boolbodySelectProps;
			boolbodySelectProps = NULL;
						
			booltargetTAG=NULL_TAG,booltoolTAG=NULL_TAG,booloverTAG=NULL_TAG;//初始化变量

			UF_MODL_ask_feat_body(createblockTAG, &booltargetTAG );//创建的方块块的特征TAG转到实体TAG

// 			if  (booltype->GetProperties()->GetEnum("Value")==1)
// 			{
					for ( int i = 0; i < boolbodys.size(); ++i) 
					{
						UF_MODL_ask_feat_body(boolbodys[i]->Tag(), &booltoolTAG );//选择体特征TAG到实体TAG
						UF_MODL_unite_bodies_with_retained_options(booltargetTAG,booltoolTAG,FALSE,FALSE,&booloverTAG);//求和
						UF_MODL_ask_feat_body(booloverTAG, &booltargetTAG );//将求和之后的特征设为目标体
  					}
// 			}				
// 				
// 				
// 				if  (booltype->GetProperties()->GetEnum("Value")==2)
// 				{
// 					for ( int i = 0; i < boolbodys.size(); ++i) 
// 					{
// 						UF_MODL_ask_feat_body(boolbodys[i]->Tag(), &booltargetTAG );
// 						UF_MODL_subtract_bodies_with_retained_options(booltoolTAG,booltargetTAG,FALSE,TRUE,&booloverTAG);//求差
// 					}
// 
// 				}
// 				theoverTAG=booloverTAG;
							UF_terminate();
	}
}
