//---------------------------------------------------------------------------

#ifndef UTemyH
#define UTemyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFTemy : public TForm
{
__published:	// IDE-managed Components
	TStaticText *StaticText1;
	TDatabase *Database;
	TDataSource *DataSource1;
	TTable *Tema;
	TIntegerField *TemaNumTema;
	TStringField *TemaNameTema;
	TIntegerField *TemaLastVopros;
	TTimeField *TemaTimeLimit;
	TBooleanField *TemaWavePlay;
	TBlobField *TemaMyWave;
	TBooleanField *TemaMyPrint;
	TBooleanField *TemaTempField;
	TIntegerField *TemaMyBeep;
	TBooleanField *TemaRandomVopros;
	TIntegerField *TemaCountVopros;
	TIntegerField *TemaTypeWave;
	TIntegerField *TemaNumCategory1;
	TStringField *TemaStrCategory1;
	TIntegerField *TemaNumCategory2;
	TStringField *TemaStrCategory2;
	TIntegerField *TemaNumCategory3;
	TStringField *TemaStrCategory3;
	TIntegerField *TemaNumCategory4;
	TStringField *TemaStrCategory4;
	TMemoField *TemaWelcome;
	TBooleanField *TemaHideIndicator;
	TBooleanField *TemaTestNotBreak;
	TBooleanField *TemaOcenkaPost;
	TIntegerField *TemaMarkCount;
	TIntegerField *TemaMarkCopyCount;
	TBooleanField *TemaVoprosOgran;
	TIntegerField *TemaVoprosOgranCount;
	TBooleanField *TemaTemaHide;
	TIntegerField *TemaCountVoprosShow;
	TBooleanField *TemaTrueOtvetHide;
	TDBGrid *DBGrid1;
	TPanel *Panel1;
	TButton *Button1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFTemy(TComponent* Owner);
	
};
//---------------------------------------------------------------------------
extern PACKAGE TFTemy *FTemy;
//---------------------------------------------------------------------------
#endif
