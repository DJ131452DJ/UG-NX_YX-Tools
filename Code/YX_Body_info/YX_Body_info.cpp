﻿//==============================================================================
//  WARNING!!  This file is overwritten by the Block UI Styler while generating
//  the automation code. Any modifications to this file will be lost after
//  generating the code again.
//
//       Filename:  D:\YX_Tools\Code\YX_Body_info\YX_Body_info.cpp
//
//        This file was generated by the NX Block UI Styler
//        Created by: Yang
//              Version: NX 11
//              Date: 08-31-2016  (Format: mm-dd-yyyy)
//              Time: 10:53 (Format: hh-mm)
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
#include "YX_Body_info.hpp"
using namespace NXOpen;
using namespace NXOpen::BlockStyler;

//------------------------------------------------------------------------------
// Initialize static variables
//------------------------------------------------------------------------------
Session *(YX_Body_info::theSession) = NULL;
UI *(YX_Body_info::theUI) = NULL;
//------------------------------------------------------------------------------
// Constructor for NX Styler class
//------------------------------------------------------------------------------
YX_Body_info::YX_Body_info()
{
    try
    {
        // Initialize the NX Open C++ API environment
        YX_Body_info::theSession = NXOpen::Session::GetSession();
        YX_Body_info::theUI = UI::GetUI();
        theDlxFileName = "YX_Body_info.dlx";
        theDialog = YX_Body_info::theUI->CreateDialog(theDlxFileName);
        // Registration of callback functions
        theDialog->AddApplyHandler(make_callback(this, &YX_Body_info::apply_cb));
        theDialog->AddOkHandler(make_callback(this, &YX_Body_info::ok_cb));
        theDialog->AddUpdateHandler(make_callback(this, &YX_Body_info::update_cb));
        theDialog->AddInitializeHandler(make_callback(this, &YX_Body_info::initialize_cb));
        theDialog->AddDialogShownHandler(make_callback(this, &YX_Body_info::dialogShown_cb));
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
YX_Body_info::~YX_Body_info()
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
    YX_Body_info *theYX_Body_info = NULL;
    try
    {
        theYX_Body_info = new YX_Body_info();
        // The following method shows the dialog immediately
        theYX_Body_info->Show();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        YX_Body_info::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    if(theYX_Body_info != NULL)
    {
        delete theYX_Body_info;
        theYX_Body_info = NULL;
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
        YX_Body_info::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

int YX_Body_info::Show()
{
    try
    {
        theDialog->Show();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        YX_Body_info::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return 0;
}

//------------------------------------------------------------------------------
//---------------------Block UI Styler Callback Functions--------------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Callback Name: initialize_cb
//------------------------------------------------------------------------------
void YX_Body_info::initialize_cb()
{
    try
    {
        GroupSelect = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("GroupSelect"));
        BodySelect = dynamic_cast<NXOpen::BlockStyler::BodyCollector*>(theDialog->TopBlock()->FindBlock("BodySelect"));
        separator01 = dynamic_cast<NXOpen::BlockStyler::Separator*>(theDialog->TopBlock()->FindBlock("separator01"));
        ToggleHide = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("ToggleHide"));
        GroupSize = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("GroupSize"));
        StringSize = dynamic_cast<NXOpen::BlockStyler::StringBlock*>(theDialog->TopBlock()->FindBlock("StringSize"));
        ToggleUpround = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("ToggleUpround"));
        GroupVolume = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("GroupVolume"));
        StringVolume = dynamic_cast<NXOpen::BlockStyler::StringBlock*>(theDialog->TopBlock()->FindBlock("StringVolume"));
        GroupSet = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("GroupSet"));
        Togglewindows = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("Togglewindows"));
        separator0 = dynamic_cast<NXOpen::BlockStyler::Separator*>(theDialog->TopBlock()->FindBlock("separator0"));
        ColorSet = dynamic_cast<NXOpen::BlockStyler::ObjectColorPicker*>(theDialog->TopBlock()->FindBlock("ColorSet"));
        LayerSet = dynamic_cast<NXOpen::BlockStyler::LayerBlock*>(theDialog->TopBlock()->FindBlock("LayerSet"));
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        YX_Body_info::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

//------------------------------------------------------------------------------
//Callback Name: dialogShown_cb
//This callback is executed just before the dialog launch. Thus any value set 
//here will take precedence and dialog will be launched showing that value. 
//------------------------------------------------------------------------------
void YX_Body_info::dialogShown_cb()
{
    try
    {
        //---- Enter your callback code here -----
		
		StringVolume->SetValue("0.00");
		StringSize->SetValue("0.0 x 0.0 x 0.0");
		ToggleHide->SetValue(0);

    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        YX_Body_info::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

//------------------------------------------------------------------------------
//Callback Name: apply_cb
//------------------------------------------------------------------------------
int YX_Body_info::apply_cb()
{
    int errorCode = 0;
    try
    {
		HideBody();
		//---- Enter your callback code here -----
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        errorCode = 1;
        YX_Body_info::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return errorCode;
}

//------------------------------------------------------------------------------
//Callback Name: update_cb
//------------------------------------------------------------------------------
int YX_Body_info::update_cb(NXOpen::BlockStyler::UIBlock* block)
{
    try
    {
        if(block == BodySelect)
        {
        //---------Enter your code here-----------

		//填写窗体
		GetVolume();
		PutSize();
        }
        else if(block == separator01)
        {
        //---------Enter your code here-----------
        }
        else if(block == ToggleHide)
        {
        //---------Enter your code here-----------


        }
        else if(block == StringSize)
        {
        //---------Enter your code here-----------
        }
        else if(block == ToggleUpround)
        {
        //---------Enter your code here-----------
		PutSize();
        }
        else if(block == StringVolume)
        {
        //---------Enter your code here-----------
        }
        else if(block == Togglewindows)
        {
        //---------Enter your code here-----------
        }
        else if(block == separator0)
        {
        //---------Enter your code here-----------
        }
        else if(block == ColorSet)
        {
        //---------Enter your code here-----------
        }
        else if(block == LayerSet)
        {
        //---------Enter your code here-----------
        }
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        YX_Body_info::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return 0;
}

//------------------------------------------------------------------------------
//Callback Name: ok_cb
//------------------------------------------------------------------------------
int YX_Body_info::ok_cb()
{
    int errorCode = 0;
    try
    {
        errorCode = apply_cb();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
	       errorCode = 1;
        YX_Body_info::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return errorCode;
}

//------------------------------------------------------------------------------
//Function Name: GetBlockProperties
//Description: Returns the propertylist of the specified BlockID
//------------------------------------------------------------------------------
PropertyList* YX_Body_info::GetBlockProperties(const char *blockID)
{
    return theDialog->GetBlockProperties(blockID);
}
//用户定义--获取体积
void YX_Body_info::GetVolume()
{
	PropertyList*  bodySelectProps = BodySelect->GetProperties();
	std::vector<NXOpen::TaggedObject *> bodys = bodySelectProps->GetTaggedObjectVector("SelectedObjects");
	delete bodySelectProps;
	bodySelectProps = NULL;
    UF_initialize();
	
	//计算体积总和
	char bodyTAGinfo[256];
	double  volum=0.0;

	int  response = 2;
/*	int type = 1;*/
/*	int  unit =3;*/
/*	int accuracy =  1;*/
/*	int  count = 1;*/
	double  acc_val[11] = {.01,0,0,0,0,0,0,0,0,0,0};
/*	double  density = 1.0;*/
	double  massprop[47];
	double  massprop_stat[13];
	for ( int i = 0; i < bodys.size(); ++i) 
	{
		tag_t bodyTAG=bodys[i]->Tag();
		sprintf(bodyTAGinfo,"%d",bodyTAG);

		UF_MODL_ask_mass_props_3d(&bodyTAG,1,1,3,1.0,1,acc_val,massprop,massprop_stat);
		volum=volum+massprop [1];
	}
	volum=volum/1000;//单位转换,立方毫米转换成立方厘米
	//输出所选体的体积总和
	sprintf(allvolume,"%.3f",volum*1000);
	StringVolume->SetValue(allvolume);//体积

	//以下为计算实体最大轮廓
	std::vector<double>x_point,y_point,z_point;
	tag_t csys_tag=null_tag;;
	double min_corner [ 3 ] ; 
	double directions [ 3 ] [ 3 ] ; 
	double distances [ 3 ] ;       
	for (int i = 0; i < bodys.size(); i++)
	{
		tag_t bodyTAG=bodys[i]->Tag();
		UF_MODL_ask_bounding_box_exact(bodyTAG,csys_tag,min_corner,directions,distances);
		double point_max[3]={min_corner [ 0 ]+distances [ 0], min_corner [ 1 ]+distances [ 1],min_corner [ 2]+distances [ 2],};
		x_point.push_back(min_corner[0]);
		x_point.push_back(point_max[0]);
		y_point.push_back(min_corner[1]);
		y_point.push_back(point_max[1]);
		z_point.push_back(min_corner[2]);
		z_point.push_back(point_max[2]);
		sort(x_point.begin(),x_point.end());
		sort(y_point.begin(),y_point.end());
		sort(z_point.begin(),z_point.end());
	}
		xvaule=(x_point.back()-x_point[0]);//计算X方向最大长度
		yvaule=(y_point.back()-y_point[0]);//计算Y方向最大长度
		zvaule=(z_point.back()-z_point[0]);//计算Z方向最大长度


UF_terminate();	
	}

//上取整单选框函数
void YX_Body_info::PutSize()
{

	char tmp_X[256],tmp_Y[256],tmp_Z[256];
	double intX,intY,intZ;
	//保留三位小数
	sprintf(tmp_X,"%.3f",xvaule);
	sprintf(tmp_Y,"%.3f",yvaule);
	sprintf(tmp_Z,"%.3f",zvaule);
	//char转double
	xvaule=atof(tmp_X);
	yvaule=atof(tmp_Y);	
	zvaule=atof(tmp_Z);	
	if (ToggleUpround->Value()==1)
	{
		//上取整
		intX=ceil(xvaule);
		intY=ceil(yvaule);
		intZ=ceil(zvaule);
		sprintf(msgsize,"%.0f x %.0f  x %.0f",intX,intY,intZ);
	} 
	else if(ToggleUpround->Value()==0)
	{
		sprintf(msgsize,"%.3f x %.3f  x %.3f",xvaule,yvaule,zvaule);
	}
		StringSize->SetValue(msgsize);//填写尺寸
}

//隐藏实体单选框
void YX_Body_info::HideBody()
{
	UF_initialize();
	PropertyList*  bodySelectProps = BodySelect->GetProperties();
	std::vector<NXOpen::TaggedObject *> bodys = bodySelectProps->GetTaggedObjectVector("SelectedObjects");
	delete bodySelectProps;
	bodySelectProps = NULL;
//获取切换开关的值
	PropertyList *ToggleHideProps = ToggleHide->GetProperties();
	int theToggleHide= ToggleHideProps->GetLogical("Value");
	delete ToggleHideProps;
	ToggleHideProps = NULL;
	for ( int i = 0; i < bodys.size(); ++i) 
	{
		tag_t bodyTAG=bodys[i]->Tag();
		if (theToggleHide==1)
		{		
			UF_OBJ_set_blank_status(bodyTAG,UF_OBJ_BLANKED);
		} 
		else if (theToggleHide==1)
		{
			UF_OBJ_set_blank_status(bodyTAG,UF_OBJ_NOT_BLANKED);
		}
	}
	UF_terminate();	
}