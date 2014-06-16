//---------------------------------------------------------------------------

#include <vcl.h>
#include <map.h>
#include <fstream.h>
#pragma hdrstop

#include "UOtvety.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFOtvety *FOtvety;
int NomerTemy;
AnsiString Tema;
extern Set<int, 1, 100> Otvety;
extern map<int, TFOtvety *> pTFOtvety;

//---------------------------------------------------------------------------
__fastcall TFOtvety::TFOtvety(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFOtvety::N2Click(TObject *Sender)
{
	while(Tema.Pos("\""))
	{
		Tema.Delete(Tema.Pos("\""), 1);
    }

	SaveDialog1->FileName = Tema;
	if(SaveDialog1->Execute())
	{
		int prevnum;
		AnsiString Otvet;
		ofstream out(SaveDialog1->FileName.c_str());
		out << "<html>" << endl;
		out << "<head>" << endl;
		out << "<title>" << endl;
		out << Tema.c_str() << endl;
		out << "</title>" << endl;
		out << "</head>" << endl;
		out << "<body>" << endl;
        prevnum = Vopros->RecNo;
		for(int i=1; i<=Vopros->RecordCount; i++)
    	{
			Vopros->RecNo = i;
			out << "<p><b>" << (IntToStr(i) + ". ").c_str() << Vopros->FieldByName("NameVopros")->AsString.c_str() << "</b><br>" << endl;
			Otvet = Memo1->Text;
			while(Otvet.Pos("\r"))
			{
				Otvet.Insert("<br>", Otvet.Pos("\r"));
				Otvet.Delete(Otvet.Pos("\r"), 2);
            }
			out << Otvet.c_str() << "</p>";
		}
		Vopros->RecNo = prevnum;
        out << "\n</body>" << endl;
		out << "</html>";
		out.close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFOtvety::FormClose(TObject *Sender, TCloseAction &Action)
{
	Free();	
}
//---------------------------------------------------------------------------

void TFOtvety::SetNomerTemy(int Param, AnsiString Tema)
{
	NomerTemy = Param;
	Vopros->Filter = "NumTema=" + IntToStr(NomerTemy);
	Vopros->Filtered = true;
	Vopros->Active = true;
	Otvet->Active = true;
	Caption = Tema + " - Ответы";
	::Tema = Tema;
	pTFOtvety.insert(pair<int, TFOtvety *>(NomerTemy, this));
}
//---------------------------------------------------------------------------

void __fastcall TFOtvety::FormDestroy(TObject *Sender)
{
	pTFOtvety.erase(NomerTemy);
	Vopros->Active = false;
	Otvet->Active = false;
	OtvetSootv->Active = false;
	
}
//---------------------------------------------------------------------------

void __fastcall TFOtvety::FormCreate(TObject *Sender)
{
	Vopros->Active = false;
	Otvet->Active = false;
	OtvetSootv->Active = false;
	
}
//---------------------------------------------------------------------------


void __fastcall TFOtvety::VoprosAfterScroll(TDataSet *DataSet)
{
	//Memo1->Text = Vopros->RecNo;
	//ShowMessage(Vopros->FieldByName("TypeVopros")->AsString.Length());
	Otvet->Active = true;
	Otvet->Filter = "NumTema=" + IntToStr(NomerTemy) + " and NumVopros=" + IntToStr(Vopros->RecNo);
	Otvet->Filtered = true;
	//ShowMessage(Otvet->RecordCount);
	Memo1->Text = "";
	Otvet->First();
	for(int i=0; i<Otvet->RecordCount; i++)
	{
		if(Vopros->FieldByName("TypeVopros")->AsString == "1" ||
			Vopros->FieldByName("TypeVopros")->AsString == "2" ||
			Vopros->FieldByName("TypeVopros")->AsString == "5")
		{
			if(Otvet->FieldByName("TrueOtvet")->AsBoolean)
			{
				Memo1->Text = Memo1->Text + Otvet->FieldByName("NameOtvet")->AsString + "\r\n";
			}
        }
		else if(Vopros->FieldByName("TypeVopros")->AsString == "3" ||
			Vopros->FieldByName("TypeVopros")->AsString == "4")
		{
			Memo1->Text = Memo1->Text + "[" + Otvet->FieldByName("NameOtvet")->AsString + "]" + "\r\n"; 
			OtvetSootv->Active = true;
			OtvetSootv->Filter = "NumVopros=" + IntToStr(Vopros->RecNo) + " and " + "NumOtvet=" + IntToStr(Otvet->FieldByName("NumOtvet")->AsInteger);
			OtvetSootv->Filtered = true;
			OtvetSootv->First();
			//ShowMessage(OtvetSootv->RecordCount);
			for(int j=0; j<OtvetSootv->RecordCount; j++)
			{
				if(OtvetSootv->FieldByName("TrueOtvet")->AsBoolean)
					Memo1->Text = Memo1->Text + OtvetSootv->FieldByName("NameOtvetSootv")->AsString + "\r\n";
				OtvetSootv->Next();	
            }


        }
		Otvet->Next();
	}
		

}
//---------------------------------------------------------------------------

void __fastcall TFOtvety::FormResize(TObject *Sender)
{
	if(DBGrid1->Columns->Items[1]->Width < Width - 100) DBGrid1->Columns->Items[1]->Width = Width - 100;
}
//---------------------------------------------------------------------------

