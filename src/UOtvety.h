//---------------------------------------------------------------------------

#ifndef UOtvetyH
#define UOtvetyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFOtvety : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TDataSource *DataSource1;
	TTable *Vopros;
	TTable *OtvetSootv;
	TTable *Otvet;
	TIntegerField *VoprosNumTema;
	TIntegerField *VoprosNumVopros;
	TStringField *VoprosNameVopros;
	TStringField *VoprosTrueOtvet;
	TStringField *VoprosVsegoOtvet;
	TBlobField *VoprosMyImage;
	TBlobField *VoprosMyWave;
	TIntegerField *VoprosTypeVopros;
	TIntegerField *VoprosBal;
	TIntegerField *VoprosNumVoprosShow;
	TBooleanField *VoprosRandomOtvet;
	TBooleanField *VoprosOtvetEst;
	TIntegerField *VoprosTypeWave;
	TIntegerField *VoprosTypeImage;
	TBooleanField *VoprosTempBool;
	TMemoField *VoprosNote;
	TBooleanField *VoprosVoprosHide;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TMemo *Memo1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TSaveDialog *SaveDialog1;
	void __fastcall N2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall VoprosAfterScroll(TDataSet *DataSet);
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFOtvety(TComponent* Owner);
	void SetNomerTemy(int Param, AnsiString Tema);
};
//---------------------------------------------------------------------------
extern PACKAGE TFOtvety *FOtvety;
//---------------------------------------------------------------------------
#endif
