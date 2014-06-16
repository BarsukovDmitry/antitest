//---------------------------------------------------------------------------

#include <vcl.h>
#include <FileCtrl.hpp>
#include <map.h>
#pragma hdrstop

#include "UMainForm.h"
#include "UOtvety.h"
#include "UTestMenu.h"
#include "UTemy.h"
#include "UAbout.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
AnsiString Dir;
AnsiString ApplTitle = "Keepsoft ������� �� 100%";
TFTestMenu *pTFTestMenu;
TFTemy *pTFTemy;
map<int, TFOtvety *> pTFOtvety;
map<int, TFOtvety *>::iterator p;
bool TestIsOpen=false, TestMenuIsOpen=false, TemyIsOpen=false;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{

	Application->OnHint = (TNotifyEvent) &StatusBar;
	Dir = ExtractFilePath(Application->ExeName);
	Caption = ApplTitle;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MCloseClick(TObject *Sender)
{
	MMenu->Enabled = false;
	MOtvety->Enabled = false;
	MClose->Enabled = false;
	pTFTestMenu->Free();
	if(TestMenuIsOpen) pTFTestMenu->Free();
	if(TemyIsOpen) pTFTemy->Free();
	p = pTFOtvety.begin();
	while(p != pTFOtvety.end())
    {
		p->second->Free();
		p = pTFOtvety.begin();
	}
	TestIsOpen = false;
	StatusBar1->Panels->Items[1]->Text = "";
	Caption = ApplTitle;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StatusBar(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = Application->Hint;
	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MOtvetyClick(TObject *Sender)
{
	if(!TemyIsOpen)
	{
		TFTemy *form = new TFTemy(Application);
		if(!form)
		{
			Application->MessageBoxA("�� ������� ������� ������", "������", MB_ICONERROR);

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

void __fastcall TMainForm::MOpenClick(TObject *Sender)
{
	if(!TestIsOpen)
	{
		if(SelectDirectory("������� ����������, ��� ��������� ����", "", Dir))
		{
			if(FileExists(Dir + "\\base\\Vopros.db"))
			{
				Caption = Dir.SubString(Dir.LastDelimiter("\\")+1, Dir.Length()- Dir.LastDelimiter("\\")) + " - " + ApplTitle;
				MMenu->Enabled = true;
				MOtvety->Enabled = true;
				MClose->Enabled = true;
				TestIsOpen = true;
				MOtvetyClick(Sender);
				StatusBar1->Panels->Items[1]->Text = Dir;
			}
			else
			{
				Application->MessageBoxA("�� ������ ������� ���� � ������ ����������", "������", MB_ICONERROR);
			}

		}
	}
	else
	{
		if(Application->MessageBoxA("������� ����?", "�������������", MB_ICONQUESTION + MB_YESNO) == ID_YES)
		{
			MCloseClick(Sender);
			MOpenClick(Sender);
        }
    }
	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MMenuClick(TObject *Sender)
{
	if(!TestMenuIsOpen)
	{
		TFTestMenu *form = new TFTestMenu(Application);
		form->StaticText1->Caption = "����: " + Dir;
		form->Show();
		pTFTestMenu = form;
	}
	else
	{
        pTFTestMenu->Show();
    }
	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N4Click(TObject *Sender)
{
	Application->Terminate();	
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N3Click(TObject *Sender)
{
	FAbout->Show();	
}
//---------------------------------------------------------------------------

