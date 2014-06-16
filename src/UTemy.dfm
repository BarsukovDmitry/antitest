object FTemy: TFTemy
  Left = 0
  Top = 0
  Caption = #1058#1077#1084#1099
  ClientHeight = 464
  ClientWidth = 629
  Color = clActiveBorder
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 19
  object StaticText1: TStaticText
    Left = 0
    Top = 0
    Width = 629
    Height = 42
    Align = alTop
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    Caption = #1058#1077#1084#1099' '#1076#1072#1085#1085#1086#1075#1086' '#1090#1077#1089#1090#1072':'
    Color = clMoneyGreen
    ParentColor = False
    TabOrder = 0
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 42
    Width = 629
    Height = 374
    Align = alClient
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -16
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDblClick = DBGrid1DblClick
  end
  object Panel1: TPanel
    Left = 0
    Top = 416
    Width = 629
    Height = 48
    Align = alBottom
    TabOrder = 2
    object Button1: TButton
      Left = 8
      Top = 6
      Width = 113
      Height = 25
      Caption = #1054#1090#1074#1077#1090#1099
      TabOrder = 0
      OnClick = DBGrid1DblClick
    end
  end
  object Database: TDatabase
    DatabaseName = 'antitest_vopros'
    DriverName = 'STANDARD'
    Params.Strings = (
      'PATH=H:\_'#1055#1054#1069#1048#1057'\'#1058#1077#1089#1090#1099'\'#1053#1072#1083#1086#1075'\test\Base'
      'DEFAULT DRIVER=PARADOX'
      'ENABLE BCD=FALSE')
    SessionName = 'Default'
    Left = 600
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = Tema
    Left = 600
    Top = 72
  end
  object Tema: TTable
    DatabaseName = 'antitest_vopros'
    FieldDefs = <
      item
        Name = 'NumTema'
        DataType = ftInteger
      end
      item
        Name = 'NameTema'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'LastVopros'
        DataType = ftInteger
      end
      item
        Name = 'TimeLimit'
        DataType = ftTime
      end
      item
        Name = 'WavePlay'
        DataType = ftBoolean
      end
      item
        Name = 'MyWave'
        DataType = ftBlob
      end
      item
        Name = 'MyPrint'
        DataType = ftBoolean
      end
      item
        Name = 'TempField'
        DataType = ftBoolean
      end
      item
        Name = 'MyBeep'
        DataType = ftInteger
      end
      item
        Name = 'RandomVopros'
        DataType = ftBoolean
      end
      item
        Name = 'CountVopros'
        DataType = ftInteger
      end
      item
        Name = 'TypeWave'
        DataType = ftInteger
      end
      item
        Name = 'NumCategory1'
        DataType = ftInteger
      end
      item
        Name = 'StrCategory1'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'NumCategory2'
        DataType = ftInteger
      end
      item
        Name = 'StrCategory2'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'NumCategory3'
        DataType = ftInteger
      end
      item
        Name = 'StrCategory3'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'NumCategory4'
        DataType = ftInteger
      end
      item
        Name = 'StrCategory4'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'Welcome'
        DataType = ftMemo
        Size = 1
      end
      item
        Name = 'HideIndicator'
        DataType = ftBoolean
      end
      item
        Name = 'TestNotBreak'
        DataType = ftBoolean
      end
      item
        Name = 'OcenkaPost'
        DataType = ftBoolean
      end
      item
        Name = 'MarkCount'
        DataType = ftInteger
      end
      item
        Name = 'MarkCopyCount'
        DataType = ftInteger
      end
      item
        Name = 'VoprosOgran'
        DataType = ftBoolean
      end
      item
        Name = 'VoprosOgranCount'
        DataType = ftInteger
      end
      item
        Name = 'TemaHide'
        DataType = ftBoolean
      end
      item
        Name = 'CountVoprosShow'
        DataType = ftInteger
      end
      item
        Name = 'TrueOtvetHide'
        DataType = ftBoolean
      end>
    IndexDefs = <
      item
        Name = 'TemaIndex1'
        Fields = 'NumTema'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'MarkCopyNT'
        Fields = 'MarkCopyCount;NumTema'
        Options = [ixCaseInsensitive]
      end
      item
        Name = 'Category4'
        Fields = 'StrCategory4;NumTema'
        Options = [ixCaseInsensitive]
      end
      item
        Name = 'Category3'
        Fields = 'StrCategory3;NumTema'
        Options = [ixCaseInsensitive]
      end
      item
        Name = 'Category2'
        Fields = 'StrCategory2;NumTema'
        Options = [ixCaseInsensitive]
      end
      item
        Name = 'Category1'
        Fields = 'StrCategory1;NumTema'
        Options = [ixCaseInsensitive]
      end
      item
        Name = 'MarkNT'
        Fields = 'MarkCount;NumTema'
        Options = [ixCaseInsensitive]
      end
      item
        Name = 'TimeLimitNT'
        Fields = 'TimeLimit;NumTema'
        Options = [ixCaseInsensitive]
      end
      item
        Name = 'CountVoprosNNT'
        Fields = 'CountVopros;NumTema;NameTema'
        Options = [ixCaseInsensitive]
      end
      item
        Name = 'NumTema'
        Fields = 'NumTema'
        Options = [ixCaseInsensitive]
      end
      item
        Name = 'NameTema'
        Fields = 'NameTema'
        Options = [ixCaseInsensitive]
      end
      item
        Name = 'NumNameTema'
        Fields = 'NumTema;NameTema'
        Options = [ixCaseInsensitive]
      end>
    IndexName = 'NumTema'
    ReadOnly = True
    StoreDefs = True
    TableName = 'Tema.DB'
    Left = 600
    Top = 40
    object TemaNumTema: TIntegerField
      DisplayLabel = #1053#1086#1084#1077#1088
      DisplayWidth = 5
      FieldName = 'NumTema'
    end
    object TemaNameTema: TStringField
      DisplayLabel = #1053#1072#1079#1074#1072#1085#1080#1077
      DisplayWidth = 50
      FieldName = 'NameTema'
      Size = 255
    end
    object TemaLastVopros: TIntegerField
      FieldName = 'LastVopros'
      Visible = False
    end
    object TemaTimeLimit: TTimeField
      FieldName = 'TimeLimit'
      Visible = False
    end
    object TemaWavePlay: TBooleanField
      FieldName = 'WavePlay'
      Visible = False
    end
    object TemaMyWave: TBlobField
      FieldName = 'MyWave'
      Visible = False
    end
    object TemaMyPrint: TBooleanField
      FieldName = 'MyPrint'
      Visible = False
    end
    object TemaTempField: TBooleanField
      FieldName = 'TempField'
      Visible = False
    end
    object TemaMyBeep: TIntegerField
      FieldName = 'MyBeep'
      Visible = False
    end
    object TemaRandomVopros: TBooleanField
      FieldName = 'RandomVopros'
      Visible = False
    end
    object TemaCountVopros: TIntegerField
      FieldName = 'CountVopros'
      Visible = False
    end
    object TemaTypeWave: TIntegerField
      FieldName = 'TypeWave'
      Visible = False
    end
    object TemaNumCategory1: TIntegerField
      FieldName = 'NumCategory1'
      Visible = False
    end
    object TemaStrCategory1: TStringField
      FieldName = 'StrCategory1'
      Visible = False
      Size = 255
    end
    object TemaNumCategory2: TIntegerField
      FieldName = 'NumCategory2'
      Visible = False
    end
    object TemaStrCategory2: TStringField
      FieldName = 'StrCategory2'
      Visible = False
      Size = 255
    end
    object TemaNumCategory3: TIntegerField
      FieldName = 'NumCategory3'
      Visible = False
    end
    object TemaStrCategory3: TStringField
      FieldName = 'StrCategory3'
      Visible = False
      Size = 255
    end
    object TemaNumCategory4: TIntegerField
      FieldName = 'NumCategory4'
      Visible = False
    end
    object TemaStrCategory4: TStringField
      FieldName = 'StrCategory4'
      Visible = False
      Size = 255
    end
    object TemaWelcome: TMemoField
      FieldName = 'Welcome'
      Visible = False
      BlobType = ftMemo
      Size = 1
    end
    object TemaHideIndicator: TBooleanField
      FieldName = 'HideIndicator'
      Visible = False
    end
    object TemaTestNotBreak: TBooleanField
      FieldName = 'TestNotBreak'
      Visible = False
    end
    object TemaOcenkaPost: TBooleanField
      FieldName = 'OcenkaPost'
      Visible = False
    end
    object TemaMarkCount: TIntegerField
      FieldName = 'MarkCount'
      Visible = False
    end
    object TemaMarkCopyCount: TIntegerField
      FieldName = 'MarkCopyCount'
      Visible = False
    end
    object TemaVoprosOgran: TBooleanField
      FieldName = 'VoprosOgran'
      Visible = False
    end
    object TemaVoprosOgranCount: TIntegerField
      FieldName = 'VoprosOgranCount'
      Visible = False
    end
    object TemaTemaHide: TBooleanField
      FieldName = 'TemaHide'
      Visible = False
    end
    object TemaCountVoprosShow: TIntegerField
      FieldName = 'CountVoprosShow'
      Visible = False
    end
    object TemaTrueOtvetHide: TBooleanField
      FieldName = 'TrueOtvetHide'
      Visible = False
    end
  end
end
