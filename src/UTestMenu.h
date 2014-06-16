//---------------------------------------------------------------------------

#ifndef UTestMenuH
#define UTestMenuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFTestMenu : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *BitBtn1;
	TStaticText *StaticText1;
	TBitBtn *BitBtn2;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFTestMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFTestMenu *FTestMenu;
//---------------------------------------------------------------------------
#endif
