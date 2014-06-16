//---------------------------------------------------------------------------

#ifndef UAboutH
#define UAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFAbout : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TTimer *Timer1;
	TImage *Image2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Image2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Image2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Image2MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAbout *FAbout;
//---------------------------------------------------------------------------
#endif
