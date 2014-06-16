//---------------------------------------------------------------------------

#include <vcl.h>
#include <map.h>
#pragma hdrstop

#include "UTemy.h"
#include "UOtvety.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFTemy *FTemy;
extern AnsiString Dir;
extern bool TemyIsOpen;
extern map<int, TFOtvety *> pTFOtvety;
map<int, TFOtvety *>::iterator p;
//---------------------------------------------------------------------------
__fastcall TFTemy::TFTemy(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFTemy::FormClose(TObject *Sender, TCloseAction &Action)
{
	Free();	
}
//---------------------------------------------------------------------------

void __fastcall TFTemy::DBGrid1DblClick(TObject *Sender)
{
	/*ShowMessage("Ищем тему" + IntToStr(Tema->RecNo));
	for(p=pTFOtvety.begin(); p != pTFOtvety.end(); p++)
	{
        ShowMessage(p->first);
	}*/
	p = pTFOtvety.begin();
	p = pTFOtvety.find(Tema->RecNo);
	if(p == pTFOtvety.end())
	{
		TFOtvety *form = new TFOtvety(Application);
		if(!form)
		{
			Application->MessageBoxA("Не удалось открыть ответы", "Ошибка", MB_ICONERROR);

		}
		else
		{
			form->Show();
			form->SetNomerTemy(Tema->RecNo, Tema->FieldByName("NameTema")->AsString);
			//ShowMessage(Tema->RecNo);
		}
	}
	else
	{
    	p->second->Show();
    }
	
}
//---------------------------------------------------------------------------

void __fastcall TFTemy::FormCreate(TObject *Sender)
{
    Database->Connected = false;
	Database->Params->Strings[0]= "PATH=" + Dir + "\\base";
	Database->Connected = true;
	Database->Session->RemoveAllPasswords();
	Database->Session->AddPassword("jIGGAe");
	Tema->Active = true;
	TemyIsOpen = true;
}
//---------------------------------------------------------------------------

void __fastcall TFTemy::FormDestroy(TObject *Sender)
{
	Database->Connected = false;
	TemyIsOpen = false;	
}
//---------------------------------------------------------------------------

void __fastcall TFTemy::FormResize(TObject *Sender)
{
	if(DBGrid1->Columns->Items[1]->Width < Width - 100) DBGrid1->Columns->Items[1]->Width = Width - 100;	
}
//---------------------------------------------------------------------------

