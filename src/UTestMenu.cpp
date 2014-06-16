//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UTestMenu.h"
#include "UTemy.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFTestMenu *FTestMenu;
extern bool TestMenuIsOpen, TemyIsOpen;
extern TFTemy *pTFTemy;
//---------------------------------------------------------------------------
__fastcall TFTestMenu::TFTestMenu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFTestMenu::FormClose(TObject *Sender, TCloseAction &Action)
{
	Free();	
}
//---------------------------------------------------------------------------
void __fastcall TFTestMenu::BitBtn1Click(TObject *Sender)
{
	if(!TemyIsOpen)
	{
		TFTemy *form = new TFTemy(Application);
		if(!form)
		{
			Application->MessageBoxA("Не удалось открыть ответы", "Ошибка", MB_ICONERROR);

		}
		else
		{
			form->Show();
			pTFTemy = form;

		}
	}
	else
	{
    	pTFTemy->Show();
    }
	
}
//---------------------------------------------------------------------------
void __fastcall TFTestMenu::FormCreate(TObject *Sender)
{
	TestMenuIsOpen = true;	
}
//---------------------------------------------------------------------------
void __fastcall TFTestMenu::FormDestroy(TObject *Sender)
{
	TestMenuIsOpen = false;	
}
//---------------------------------------------------------------------------
