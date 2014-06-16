//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma resource "res.res"
TFAbout *FAbout;
bool move=false;
int x0, y0;
//---------------------------------------------------------------------------
__fastcall TFAbout::TFAbout(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFAbout::FormCreate(TObject *Sender)
{
	HRGN MyRegion, MyRegion2;
	MyRegion = 0;
	TColor ColorTrans;
	// ������� ������� ������ ����������� �����
	int j0; // ������ ���� �������� ������������� �����
	Image1->Picture->Bitmap->LoadFromResourceName((unsigned int) HInstance, "MYPIKCHA");
	//Image1->Canvas->Brush->Color = clGreen;
	ColorTrans = Image1->Canvas->Pixels[Image1->Width-1][Image1->Height-1];
	for(int i = 0; i < Image1->Height; i++)
	// ���� �� �������
	{
		j0 = -1;
		for(int j = 0; j < Image1->Width; j++)
		// ���� �� �������� ������
		{
			if(Image1->Canvas->Pixels[j][i] != ColorTrans)
			// ������������ ����
			{
				// ���� ��� ������������ �������� �� �����, �� ����������
				if(j0 < 0) j0 = j;
			}
			else  // ���������� ����
				if(j0 >= 0)
				// ���� ���� ��� ������������ ��������,
				// �� �� ������������ ������
				{
					if(! MyRegion)
					{
						MyRegion = CreateRectRgn(j0, i, j, i + 1);
						Image1->Canvas->FillRect(Rect(j0, i, j, i + 1));
					}
					else
					{
						MyRegion2 = CreateRectRgn(j0, i, j, i + 1);
						Image1->Canvas->FillRect(Rect(j0, i, j, i + 1));
						CombineRgn(MyRegion, MyRegion2, MyRegion, RGN_OR);
					}
					j0 = -1;
				}
		} // ����� ����� �� j - �� �������� ������
		if(j0 >= 0)
		{
			// ��� ������������ �������� ���������� �� ������� �������
			if(! MyRegion)
			{
				MyRegion = CreateRectRgn(j0, i, Image1->Width - 1, i + 1);
				Image1->Canvas->FillRect(Rect(j0, i, Image1->Width - 1, i + 1));
			}
			else
			{
				MyRegion2 = CreateRectRgn(j0, i, Image1->Width - 1, i + 1);
				Image1->Canvas->FillRect(Rect(j0, i, Image1->Width - 1, i + 1));
				CombineRgn(MyRegion, MyRegion2, MyRegion, RGN_OR);
			}
		}
		//Sleep(30);
		//Image1->Repaint();
	} // ����� ����� �� i - �� �������
	MyRegion2 = CreateRectRgn(0, 0, Width, Height);
	CombineRgn(MyRegion, MyRegion2, MyRegion, RGN_AND); 
	SetWindowRgn(Handle, MyRegion, true);	
}
//---------------------------------------------------------------------------



void __fastcall TFAbout::Timer1Timer(TObject *Sender)
{
	if(AlphaBlendValue < 255) AlphaBlendValue += 5;
	else Timer1->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TFAbout::Image2MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
	move = true;
	x0 = X;
	y0 = Y;

}
//---------------------------------------------------------------------------

void __fastcall TFAbout::Image2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
	move = false;	
}
//---------------------------------------------------------------------------

void __fastcall TFAbout::Image2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
	if(move)
	{
		Left += X-x0;
		Top += Y-y0;
    }

}
//---------------------------------------------------------------------------

void __fastcall TFAbout::FormShow(TObject *Sender)
{
	Timer1->Enabled = true;	
}
//---------------------------------------------------------------------------



void __fastcall TFAbout::Image2Click(TObject *Sender)
{
	Close();
	AlphaBlendValue = 0;
}
//---------------------------------------------------------------------------

