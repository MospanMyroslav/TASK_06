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
      cout << "� ��� � $" << bankBalance 
         << " � �����.\n������ ������: ";
      cin >> wager;

      while ( wager <= 0 || wager > bankBalance ) 
      {
         cout << "���� ����� ������ ��������� ������.\n";
         cin >> wager;
      } 

      result = craps(); 

      if ( result == LOST )
      {
         bankBalance -= wager; 

         
         cout << "��� ���������  ������ � ����� $" << bankBalance << "\n";

         if ( bankBalance == 0 ) 
         {
          
            cout << "�������. �� �������! ������ �� ���.\n";
            break; 
         }
      }
      else 
      {
         bankBalance += wager;

         cout << "��� ���������  ������ � ����� $" << bankBalance << "\n";
      } 

      cout << "������ ����������� ����� ����� (y/n)? ";
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

   cout << "����� ����� " << die1 << " + " << die2
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
         cout << "������� � " << myPoint << '\n';
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
      cout << "����� ������" << endl;
      return WON;
   } // end if
   else 
   {
      cout << "����� ���))))) ������������" << endl;
      return LOST;
   } 
} 


void chatter()
{
   
   switch ( rand() % 9 ) 
   {
      case 0:
         cout << "�, �� ����������� ��-����, �?";
         break;
      case 1:
         cout << "�� �� �����, ��������!";
         break;
      case 2:
         cout << "��, � �����, ��� ���� ������ ���������� ������� ����!";
         break;
      case 3:
         cout << "�� �� ������. ����� ���� ���, ��� ������� ��� �����!";
         break;
      case 4:
         cout << "������� ���������! ֳ ����� ������ ���� ����������!";
         break;
      case 5:
         cout << "������ ��� ��! ������ ��� ��!";
         break;
      case 6:
         cout << "���� � ����� ���?";
         break;
      case 7:
         cout << "������� �������� ������ ����� � ����� �������.";
         break;
      case 8:
         cout << "�� ��������! �� ������ ���� ������� ����"
            << "\n���� �� � ������ ����!!!!";
         break;
   } 

   cout << endl;
}