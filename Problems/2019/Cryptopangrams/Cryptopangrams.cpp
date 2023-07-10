//Google Code Jam '19 Qualification Round Problem C - Cryptopangrams
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>



using namespace std;

int Test(int CryptedValue , vector<int> &PrimeValues)
{
  for(int i {2} ; i != CryptedValue ; i++)
  {
    if(CryptedValue % i == 0 )
    {
      PrimeValues.push_back(i);
    }
  }

  return 0;
}

void PrimeList (int Max , vector<int> &PrimeValues , vector<int> CryptedValues)
{
  for(int i : CryptedValues)
  {
    Test(i , PrimeValues);
  }
}

void CryptedInput (vector<int> &CryptedValues , int Length)
{
  int Cont {0} , Input {};

  while(Cont != Length)
  {
    cin>> Input;
    CryptedValues.push_back(Input);
    Cont++;
  }
}

bool PrimeCheck(int Num )
{
  if(Num < 2)
  {
    return false;
  }
  
  for(int i {2} ; i <= sqrt(Num) ; i++)
  {
    if( Num % i == 0)
    {
      return false;
    }
  }

  return true;
}


void DivisorList (int Max , vector<int> &DivisorValues)
{
  int Prime {0};

  for(int i {Max} ; Prime != 26 ; i--)
  {
    if(PrimeCheck(i) == true)
    {
      DivisorValues.push_back(i);
      Prime++;
    }
  }
}

int Bigger(vector<int>DecryptedValues)
{
  int BiggerPrime {0};

  for(int i : DecryptedValues)
  {
    if(i > BiggerPrime)
    {
      BiggerPrime = i;
    }
  }

  return BiggerPrime;
}

void DecryptValues( vector<int> &DivisorValues , vector<int> &DecryptedValues , vector<int> &CryptedValues )
{

  int Index {0};

  for(int i : DivisorValues)
  {
    if(Index == ((CryptedValues.size() * 2) - 2))
    {
      DecryptedValues.push_back(DivisorValues.at(DivisorValues.size() - 1));
      break;
    }

    if(i == DivisorValues[0])
    {
      DecryptedValues.push_back(i);
    }

    if(i == DivisorValues[Index + 1] || (i == DivisorValues[Index + 2] && i != DivisorValues[DivisorValues.size() - 1]))
    {
      DecryptedValues.push_back(i);
    }
    
    Index++;
  }  
}

int DecryptMessage (vector<int> PrimeValues, vector<int> Lol ,int Value)
{
  int Index {0};

  for(int i : Lol)
  {
    if(Value == i)
    {
      break;
    }

    Index++;
  }

  return Index;
}

void Message (vector<int> DecryptedValues , vector<int> PrimeValues , vector<int> Lol , int Cont)
{
  vector<char> Character {'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N', 'O', 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z'};

  cout<< "Case #" << Cont << ":";

  for(int i : DecryptedValues)
  {
    cout<< Character[DecryptMessage(PrimeValues , Lol , i)];
  }

  cout<< "\n";
}

int main()
{
  vector<int> CryptedValues {};
  vector<int> PrimeValues {};
  vector<int> DivisorValues {};
  vector<int> DecryptedValues {};

  int Max {} , Length {} , TestCases {} , Cont {1};

  cin >> TestCases;

  while(TestCases != 0)
  {
    cin >> Max >> Length;

    CryptedInput( CryptedValues , Length );

    PrimeList(Max , PrimeValues , CryptedValues);

    DecryptValues( PrimeValues , DecryptedValues , CryptedValues);

    DivisorList( Bigger(DecryptedValues) , DivisorValues);

    sort(DivisorValues.begin() , DivisorValues.end());

    Message(DecryptedValues , PrimeValues , DivisorValues , Cont);
    
    Cont++;
    TestCases--;
  }


  return 0;

}
