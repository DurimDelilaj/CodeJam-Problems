//Google Code Jam '19 Qualification Round Problem C - Cryptopangrams
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

  

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


void PrimeList (int Max , vector<int> &PrimeValues)
{
  int Prime {0};

  for(int i {Max} ; Prime != 26 ; i--)
  {
    if(PrimeCheck(i) == true)
    {
      PrimeValues.push_back(i);
      Prime++;
    }
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

void DivisorCheck (vector<int> PrimeValues , vector<int> &DivisorValues , int CryptedValue)
{
  for(int i : PrimeValues)
  {
    if(CryptedValue % i == 0 )
    {
      DivisorValues.push_back(CryptedValue / i);
    }
  }

}

void DivisorList (vector<int> PrimeValues , vector<int> CryptedValues , vector<int> &DivisorValues )
{
  for(int i : CryptedValues)
  {
    DivisorCheck(PrimeValues , DivisorValues , i);
  }
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

    if(i == DivisorValues[Index + 1] || i == DivisorValues[Index + 2] && i != DivisorValues[DivisorValues.size() - 1])
    {
      DecryptedValues.push_back(i);
    }
    
    Index++;
  }  
}

int main()
{
  vector<int> CryptedValues {};
  vector<int> PrimeValues {};
  vector<int> DivisorValues {};
  vector<int> DecryptedValues {};
  
  int Max {} , Length {};

  cin >> Max >> Length;

  PrimeList( Max , PrimeValues );

  CryptedInput( CryptedValues , Length );

  DivisorList( PrimeValues , CryptedValues , DivisorValues );

  DecryptValues( DivisorValues , DecryptedValues , CryptedValues );

  return 0;

}
