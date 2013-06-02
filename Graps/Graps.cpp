#include <iostream> 
#include <cstdlib>
#include <ctime> 
using namespace std;

enum Status { WON, LOST, CONTINUE };

int rollDice( void );
Status craps( void ); 
void chatter( void ); 

int main()
{
	setlocale(LC_ALL,"Russian");
   Status result; 
   int wager = 0; 
   int bankBalance = 1000; 
   char playAgain; 
   srand( time( 0 ) );
   do 
   {
      cout << "У вас е $" << bankBalance 
         << " У банку.\nЗробіть ставку: ";
      cin >> wager;

      while ( wager <= 0 || wager > bankBalance ) 
      {
         cout << "Будь ласка зробіть правельну ставку.\n";
         cin >> wager;
      } 

      result = craps(); 

      if ( result == LOST )
      {
         bankBalance -= wager; 

         
         cout << "Ваш оновлений  баланс в банку $" << bankBalance << "\n";

         if ( bankBalance == 0 ) 
         {
          
            cout << "Вибачте. Ви банкрот! Дякуємо за гру.\n";
            break; 
         }
      }
      else 
      {
         bankBalance += wager;

         cout << "Ваш оновлений  баланс в банку $" << bankBalance << "\n";
      } 

      cout << "Хочете випробувати удачу знову (y/n)? ";
      cin >> playAgain;

   } while ( playAgain == 'y' || playAgain == 'Y' );

   cout << endl;
}

int rollDice( void )
{
   int die1; 
   int die2; 
   int workSum; 
   
   die1 = 1 + rand() % 6; 
   die2 = 1 + rand() % 6;
   workSum = die1 + die2; 

   cout << "Игрок ролит " << die1 << " + " << die2
      << " = " << workSum << endl;
   return workSum; 
} 

Status craps( void )
{
   int sum;
   int myPoint;
   Status gameStatus; 

   sum = rollDice(); 

   switch ( sum ) 
   {
      case 7: 
      case 11:
         gameStatus = WON;
         break;
      case 2: 
      case 3: 
      case 12:
         gameStatus = LOST;
         break;
      default: 
         gameStatus = CONTINUE;
         myPoint = sum;
         cout << "Поинтов е " << myPoint << '\n';
         break;
   } 

   while ( gameStatus == CONTINUE ) 
   {
      chatter(); 
      sum = rollDice(); 
   
      
      if ( sum == myPoint )
         gameStatus = WON; 
      else 
      {
         if ( sum == 7 ) 
            gameStatus = LOST;
      } 
   } 

  
   if ( gameStatus == WON ) 
   {
      cout << "Игрок виграв" << endl;
      return WON;
   } // end if
   else 
   {
      cout << "Игрок нуб))))) ахахахахахах" << endl;
      return LOST;
   } 
} 


void chatter()
{
   
   switch ( rand() % 9 ) 
   {
      case 0:
         cout << "О, вы собираетесь ва-банк, а?";
         break;
      case 1:
         cout << "Ой да ладно, рискнуть!";
         break;
      case 2:
         cout << "Эй, я думаю, что этот парень собирается сорвать банк!";
         break;
      case 3:
         cout << "Ти до великої. Зараз саме час, щоб забрати свої фішки!";
         break;
      case 4:
         cout << "Занадто пощастило! Ці кістки повинні бути завантажені!";
         break;
      case 5:
         cout << "Ставка все це! Ставка все це!";
         break;
      case 6:
         cout << "Можу я взяти чіп?";
         break;
      case 7:
         cout << "Давайте спробуємо нашого щастя в іншій таблиці.";
         break;
      case 8:
         cout << "Ти обманщик! Це всього лише питання часу"
            << "\nперш ніж я зловлю тебе!!!!";
         break;
   } 

   cout << endl;
}