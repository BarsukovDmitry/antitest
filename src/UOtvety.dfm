object FOtvety: TFOtvety
  Left = 0
  Top = 0
  Caption = #1054#1090#1074#1077#1090#1099
  ClientHeight = 458
  ClientWidth = 639
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDefaultSizeOnly
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 19
  object DBGrid1: TDBGrid
    Left = 0
    Top = 42
    Width = 639
    Height = 260
    Align = alClient
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -16
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'NumVopros'
        Title.Caption = #1053#1086#1084#1077#1088
        Width = 55
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NameVopros'
        Title.Caption = #1042#1086#1087#1088#1086#1089
        Width = 541
        Visible = True
      end>
  end
  object StaticText1: TStaticText
    Left = 0
    Top = 0
    Width = 639
    Height = 42
    Align = alTop
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    Caption = #1042#1086#1087#1088#1086#1089#1099':'
    Color = clMoneyGreen
    ParentColor = False
    TabOrder = 1
  end
  object StaticText2: TStaticText
    Left = 0
    Top = 302
    Width = 639
    Height = 42
    Align = alBottom
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    Caption = #1054#1090#1074#1077#1090#1099':'
    Color = clMoneyGreen
    ParentColor = False
    TabOrder = 2
  end
  object Memo1: TMemo
    Left = 0
    Top = 344
    Width = 639
    Height = 114
    Align = alBottom
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 3
  end
  object DataSource1: TDataSource
    DataSet = Vopros
    Left = 600
    Top = 104
  end
  object Vopros: TTable
    AfterScroll = VoprosAfterScroll
    DatabaseName = 'antitest_vopros'
    Filter = 'NumTema=1'
    Filtered = True
    ReadOnly = True
    TableName = 'Vopros.db'
    Left = 600
    Top = 8
    object VoprosNumTema: TIntegerField
      FieldName = 'NumTema'
    end
    object VoprosNumVopros: TIntegerField
      FieldName = 'NumVopros'
    end
    object VoprosNameVopros: TStringField
      FieldName = 'NameVopros'
      Size = 255
    end
    object VoprosTrueOtvet: TStringField
      FieldName = 'TrueOtvet'
      Size = 255
    end
    object VoprosVsegoOtvet: TStringField
      FieldName = 'VsegoOtvet'
      Size = 5
    end
    object VoprosMyImage: TBlobField
      FieldName = 'MyImage'
    end
    object VoprosMyWave: TBlobField
      FieldName = 'MyWave'
    end
    object VoprosTypeVopros: TIntegerField
      FieldName = 'TypeVopros'
    end
    object VoprosBal: TIntegerField
      FieldName = 'Bal'
    end
    object VoprosNumVoprosShow: TIntegerField
      FieldName = 'NumVoprosShow'
    end
    object VoprosRandomOtvet: TBooleanField
      FieldName = 'RandomOtvet'
    end
    object VoprosOtvetEst: TBooleanField
      FieldName = 'OtvetEst'
    end
    object VoprosTypeWave: TIntegerField
      FieldName = 'TypeWave'
    end
    object VoprosTypeImage: TIntegerField
      FieldName = 'TypeImage'
    end
    object VoprosTempBool: TBooleanField
      FieldName = 'TempBool'
    end
    object VoprosNote: TMemoField
      FieldName = 'Note'
      BlobType = ftMemo
      Size = 1
    end
    object VoprosVoprosHide: TBooleanField
      FieldName = 'VoprosHide'
    end
  end
  object OtvetSootv: TTable
    DatabaseName = 'antitest_vopros'
    ReadOnly = True
    TableName = 'OtvetSootv.DB'
    Left = 600
    Top = 72
  end
  object Otvet: TTable
    DatabaseName = 'antitest_vopros'
    ReadOnly = True
    TableName = 'Otvet.DB'
    Left = 600
    Top = 40
  end
  object MainMenu1: TMainMenu
    Left = 600
    Top = 136
    object N1: TMenuItem
      Caption = #1054#1090#1074#1077#1090#1099
      GroupIndex = 3
      object N2: TMenuItem
        Caption = '&'#1069#1082#1089#1087#1086#1088#1090'...'
        Hint = #1069#1082#1089#1087#1086#1088#1090' '#1086#1090#1074#1077#1090#1086#1074' '#1074' HTML'
        OnClick = N2Click
      end
    end
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.htm'
    Filter = 'HTML|*.htm'
    Left = 600
    Top = 168
  end
end
