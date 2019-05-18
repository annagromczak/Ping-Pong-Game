//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *Timer_ball;
        TImage *paddle_left;
        TImage *paddle_right;
        TTimer *paddle_left_up;
        TTimer *paddle_left_down;
        TTimer *paddle_right_up;
        TTimer *paddle_right_down;
        TLabel *Label1;
        TButton *StartGame;
        TMainMenu *MainMenu1;
        TMenuItem *eHelp1;
        TMenuItem *Informacje1;
        TMenuItem *aboutthegame1;
        TMenuItem *Website1;
        TLabel *whoScored;
        TLabel *score;
        TLabel *numberOfBounces;
        TButton *NextRound;
        TButton *NewGame;
        void __fastcall Timer_ballTimer(TObject *Sender);
        void __fastcall paddle_left_upTimer(TObject *Sender);
        void __fastcall paddle_left_downTimer(TObject *Sender);
        void __fastcall paddle_right_downTimer(TObject *Sender);
        void __fastcall paddle_right_upTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall aboutthegame1Click(TObject *Sender);
        void __fastcall Website1Click(TObject *Sender);
        void __fastcall StartGameClick(TObject *Sender);
        void __fastcall NewGameClick(TObject *Sender);
        void __fastcall NextRoundClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
