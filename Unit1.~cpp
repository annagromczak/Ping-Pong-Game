//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8, y = -8;
int sumOfBounces = 0;
int leftPlayerScores = 0;
int rightPlayerScores = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
        ball -> Left += x;
        ball -> Top += y;

        //bounce off the top wall
        if(ball -> Top - 5 <= background -> Top) y = -y;
        //bounce off the bottom wall
        if(ball -> Top + ball -> Height + 5 > background -> Height) y = -y;

        //loss
        if(ball -> Left + ball -> Width <= paddle_left -> Left - 5)
        {
                rightPlayerScores++;
                Timer_ball -> Enabled = false;
                ball -> Visible = false;
                whoScored -> Caption = "Point for the right player >";
                whoScored -> Visible = true;
                score -> Caption = IntToStr(leftPlayerScores) + ":" + IntToStr(rightPlayerScores);
                score -> Visible = true;
                numberOfBounces -> Caption = "Count of bounces: " + IntToStr(sumOfBounces);
                numberOfBounces -> Visible = true;
                NextRound ->  Visible = true;
                NewGame ->  Visible = true;
                sndPlaySound("snd/applause.wav", SND_ASYNC);
        }
        else if(ball -> Left >= paddle_right -> Left + paddle_right -> Width - 5)
        {
                leftPlayerScores++;
                Timer_ball -> Enabled = false;
                ball -> Visible = false;
                whoScored -> Caption = "< Point for the left player";
                whoScored -> Visible = true;
                score -> Caption = IntToStr(leftPlayerScores) + ":" + IntToStr(rightPlayerScores);
                score -> Visible = true;
                numberOfBounces -> Caption = "Count of bounces: " + IntToStr(sumOfBounces);
                numberOfBounces -> Visible = true;
                NextRound ->  Visible = true;
                NewGame ->  Visible = true;
                sndPlaySound("snd/applause.wav", SND_ASYNC);
        }
        //bounce
        else if (ball -> Top + ball -> Height/2 >= paddle_left -> Top &&
                ball -> Top + ball -> Height/2 <= paddle_left -> Top + paddle_left -> Height &&
                ball -> Left <= paddle_left -> Left + paddle_left -> Width)
                {
                        //acceleration
                        if (ball -> Top + ball -> Height/2 < paddle_left -> Top + paddle_left -> Height/2 - 15
                        && ball -> Top + ball -> Height/2 > paddle_left -> Top + paddle_left -> Height/2 + 15)
                        {
                                x = x * 1.5;
                                y = y * 1.5;
                        }
                        else
                        {
                                x = x * 1.2;
                                y = y * 1.2;
                        }

                        if (x < 0)
                        x = -x;
                        sumOfBounces++;
                }
        else if(ball -> Top + ball -> Height/2 >= paddle_right -> Top &&
                ball -> Top + ball -> Height/2 <= paddle_right -> Top + paddle_right -> Height &&
                ball -> Left + ball -> Width >= paddle_right -> Left)
                {
                        //acceleration
                        if (ball -> Top + ball -> Height/2 < paddle_right -> Top + paddle_right -> Height/2 - 15
                        && ball -> Top + ball -> Height/2 > paddle_right -> Top + paddle_right -> Height/2 + 15)
                        {
                                x = x * 1.5;
                                y = y * 1.5;
                        }
                        else
                        {
                                x = x * 1.2;
                                y = y * 1.2;
                        }

                        if (x > 0)
                        x = -x;
                        sumOfBounces++;
                }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle_left_upTimer(TObject *Sender)
{
        if(paddle_left -> Top > 10) paddle_left -> Top -= 15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle_left_downTimer(TObject *Sender)
{
        if(paddle_left -> Top + paddle_left -> Height < background -> Height - 10) paddle_left -> Top += 15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle_right_downTimer(TObject *Sender)
{
        if(paddle_right -> Top + paddle_right -> Height < background -> Height - 10) paddle_right -> Top += 15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle_right_upTimer(TObject *Sender)
{
        if(paddle_right -> Top > 10) paddle_right -> Top -= 15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 'A') paddle_left_up -> Enabled = true;
        if(Key == 'Z') paddle_left_down -> Enabled = true;
        if(Key == VK_UP) paddle_right_up -> Enabled = true;
        if(Key == VK_DOWN) paddle_right_down -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 'A') paddle_left_up -> Enabled = false;
        if(Key == 'Z') paddle_left_down -> Enabled = false;
        if(Key == VK_UP) paddle_right_up -> Enabled = false;
        if(Key == VK_DOWN) paddle_right_down -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        ShowMessage("Welcome in the PingPong game.\n\n"
        "The left player moves the paddle using A and Z.\n"
        "The right player moves the paddle using UP and DOWN.\n\n"
        "To spice up the fun:\n"
        "When you pick up the ball in the center of the paddle, you will change the angle of the ball and the ball will accelerate.\n"
        "The longer you bounce, the faster the ball moves.\n"
        "You can change the playing field as you like.\n\n"
        "Enjoy!");

        Form1 -> StartGameClick(Form1);

        sumOfBounces = 0;
        leftPlayerScores = 0;
        rightPlayerScores = 0;

        ball -> Visible = true;
        Timer_ball -> Enabled = false;

        Label1 -> Visible = true;
        StartGame -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::aboutthegame1Click(TObject *Sender)
{
        Form2 -> ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Website1Click(TObject *Sender)
{
        ShellExecute(NULL, "open", "https://github.com/annagromczak", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StartGameClick(TObject *Sender)
{
        Form1 -> FormResize(Form1);

        Label1 -> Visible = false;
        StartGame -> Visible = false;
        NewGame -> Visible = false;
        NextRound -> Visible = false;
        numberOfBounces -> Visible = false;
        score -> Visible = false;
        whoScored -> Visible = false;

        ball -> Visible = true;
        Timer_ball -> Enabled = true;


}
//---------------------------------------------------------------------------


void __fastcall TForm1::NewGameClick(TObject *Sender)
{
        if(Application -> MessageBox("Are you sure to start from the beginning?", "Confirm", MB_YESNO) == IDYES);
         {
                x = 8;
                y = 8;
                sumOfBounces = 0;
                leftPlayerScores = 0;
                rightPlayerScores = 0;

                Form1 -> StartGameClick(Form1);
         }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NextRoundClick(TObject *Sender)
{
                x = 8;
                y = 8;
                sumOfBounces = 0;

                Form1 -> StartGameClick(Form1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
        ball -> Left = background -> Width/2;
        ball -> Top = background -> Height/2;
        paddle_left -> Left = background -> Left + 20;
        paddle_left -> Top = background -> Height/2 - paddle_left -> Height/2;
        paddle_right -> Left = background -> Width - 20 - paddle_right -> Width;
        paddle_right -> Top = background -> Height/2 - paddle_left -> Height/2;

        Label1 -> Left = background -> Width/2 - Label1 -> Width/2;
        Label1 -> Top = background -> Height * 0.2;
        StartGame -> Left = background -> Width/2 - StartGame -> Width/2;
        StartGame -> Top = background -> Height * 0.8;
        NewGame -> Left = background -> Width/2 - NewGame -> Width/2;
        NewGame -> Top = background -> Height * 0.7;
        NextRound -> Left = background -> Width/2 - NextRound -> Width/2;
        NextRound -> Top = background -> Height * 0.8;
        numberOfBounces -> Left = background -> Width/2 - numberOfBounces -> Width/2;
        numberOfBounces -> Top =background -> Height * 0.2;
        score -> Left = background -> Width/2 - score -> Width/2;
        score -> Top = background -> Height * 0.3;
        whoScored -> Left = background -> Width/2 - whoScored -> Width/2;
        whoScored -> Top = background -> Height * 0.4;
}
//---------------------------------------------------------------------------

