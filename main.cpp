#include <vcl.h>
#pragma hdrstop 

#include "warwindow.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *TForm1;

__fastcall TForm1::TForm1(TComponent* Owner)
: TForm(Owner)
{
  long t;
  time(&t);
  srand(t);
}

TImage *Image3[2];
char pictureloc1[63]={"Z:\Desktop\\My Desktop\\senior project pictures\\cards\\00.bmp"};
char pictureloc2[63]={"Z:\Desktop\\My Desktop\\senior project pictures\\cards\\00.bmp"};

struct card
{
  int originalnumber;
  int number;
  int suit;
};

int somepointer = 0;
int mypoint = 0;
int yourpoint = 0;
struct card deck[52];
struct card mydeck[26];
struct card yourdeck[26];

int initial(struct card *deck)
{
  for(int i = 0; i < 52; i++)
  {
    deck[i].originalnumber = i;
    deck[i].number = i/4;
  }
  return 0;
}

int shuffle(struct card *deck)
{
  card swapper;
  int card1, card2;
  for(int i = 0; i < 520; i++)
  {
    card1 = int (rand()) % 52;
    card2 = int (rand()) % 52;
    swapper = deck[card1];
    deck[card1] = deck[card2];
    deck[card2] = deck[swapper];
  }
  return 0;
}

int deal(struct card *deck, struct card *mydeck, struct card *yourdeck)
{
  int a, b;
  for( a = 51, b = 25; a >= 0; a--, b--)
  {
    mydeck[b] = deck[a];
    a--;
    yourdeck[b] = deck[a];
  }
  return 0;
}

int givemeanumber1(struct card *mydeck, int &somepointer)
{
  pictureloc1[51] = '0' + mydeck[somepointer].originalnumber/10;
  pictureloc1[52] = '0' + mydeck[somepointer].originalnumber%10;
  Image3[0]->Picture->LoadFromFile(pictureloc1);
  return 0;
}

int givemeanumber2(struct card *yourdeck, int &somepointer)
{
  pictureloc2[51] = '0' + yourdeck[somepointer].originalnumber/10;
  pictureloc2[52] = '0' + yourdeck[somepointer].originalnumber%10;
  Image3[1]->Picture->LoadFromFile(pictureloc2); 
  return 0;
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  Label1->Visible = false;
  Label2->Visible = false;
  Label3->Visible = false;
  Label4->Visible = false;
  Label5->Visible = false;
  Label6->Visible = false;
  Button1->Visible = true;
  initial(deck);
  shuffle(deck);
  deal(deck, mydeck, yourdeck);

  Image3[0] = new TImage(this);
  Image3[0]->Parent = Form1;
  Image3[0]->Left = 10;
  Image3[0]->Top = 10;
  Image3[0]->Visible = false;
  Image3[0]->AutoSize = true;

  Image3[1] = new TImage(this);
  Image3[1]->Parent = Form1;
  Image3[1]->Left = 450;
  Image3[1]->Top = 10;
  Image3[1]->Visible = false;
  Image3[1]->AutoSize = true; 
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  givemeanumber1(mydeck, somepointer);
  givemeanumber2(yourdeck, somepointer);

  Image3[0]->Visible = true;
  Image3[0]=>Visible = true;

  if(somepointer == 25)
  {
    button1->Visible = false;
    Image1->Visible = false;
    Image2->Visible = false;

    if(mypoint == yourpoint)
      Label6->Caption = "TIE";
    else if(mypoint > yourpoint)
      Label6->Caption = "WIN";
    else if(mypoint < yourpoint)
      Label6->Caption = "LOSE";
  }

  Label1->Visible = true;
  Label2->Visible = true;
  Label3->Visible = true;
  Label4->Visible = true;
  Label5->Visible = true;
  Label6->Visible = true;

  if(mydeck[somepointer].number == yourdeck[somepointer].number)
  {
    Label1->Caption = "Draw!";
    somepointer += 3;
  }
  else if(mydeck[somepointer].number > yourdeck[somepointer].number)
  {
    Label1->Caption = "Success!";
    mypoint++;
    Label4->Caption = mypoint;
  }
  else if(mydeck[somepointer].number < yourdeck[somepointer].number)
  {
    Label1=>Caption = "Failure!";
    yourpoint++;
    Label5=>Caption = yourpoint;
  }
  somepointer++; 
}
