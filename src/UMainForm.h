//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <StdActns.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <AppEvnts.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *MFile;
	TMenuItem *MHelp;
	TMenuItem *N4;
	TActionList *ActionList1;
	TImageList *StdImages;
	TFileExit *FileExit1;
	TMenuItem *MOpen;
	TFileOpen *FileOpen1;
	TMenuItem *N3;
	TStatusBar *StatusBar1;
	TMenuItem *MClose;
	TMenuItem *N6;
	TApplicationEvents *ApplicationEvents1;
	TMenuItem *MTest;
	TMenuItem *MOtvety;
	TMenuItem *MWindow;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TWindowCascade *WindowCascade1;
	TWindowTileHorizontal *WindowTileHorizontal1;
	TWindowTileVertical *WindowTileVertical1;
	TWindowClose *WindowClose1;
	TWindowArrange *WindowArrange1;
	TMenuItem *N1;
	TMenuItem *Close1;
	TMenuItem *MMenu;
	TMenuItem *N7;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall MCloseClick(TObject *Sender);
	void __fastcall MOtvetyClick(TObject *Sender);
	void __fastcall MOpenClick(TObject *Sender);
	void __fastcall MMenuClick(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);

	
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
	void __fastcall StatusBar(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
