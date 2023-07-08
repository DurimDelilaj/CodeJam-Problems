//Google Code Jam '19 Qualification Round Problem C - Cryptopangrams
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

  

bool PrimeCheck(long int Num )
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


void PrimeList (long int Max , vector<long long int> &PrimeValues)
{
  long int Prime {0};

  for(long int i {Max} ; Prime != 26 ; i--)
  {
    if(PrimeCheck(i) == true)
    {
      PrimeValues.push_back(i);
      Prime++;
    }
  }
}

void CryptedInput (vector<long long int> &CryptedValues , long int Length)
{
  long long int Cont {0} , Input {};

  while(Cont != Length)
  {
    cin>> Input;
    CryptedValues.push_back(Input);
    Cont++;
  }
}

void DivisorCheck (vector<long long int> PrimeValues , vector<long long int> &DivisorValues , long long int CryptedValue)
{
  for(long long int i : PrimeValues)
  {
    if(CryptedValue % i == 0 )
    {
      DivisorValues.push_back(CryptedValue / i);
    }
  }

}

void DivisorList (vector<long long int> PrimeValues , vector<long long int> CryptedValues , vector<long long int> &DivisorValues )
{
  for(long int i : CryptedValues)
  {
    DivisorCheck(PrimeValues , DivisorValues , i);
  }
}
  


void DecryptValues( vector<long long int> &DivisorValues , vector<long long int> &DecryptedValues , vector<long long int> &CryptedValues )
{

  long int Index {0};

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

int DecryptMessage (vector<long long int> PrimeValues, long int Value)
{
  long int Index {25};

  for(long long int i : PrimeValues)
  {
    if(Value == i)
    {
      break;
    }

    Index--;
  }

  return Index;
}

void Message (vector<long long int> DecryptedValues , vector<long long int> PrimeValues ,long int Cont)
{
  vector<char> Character {'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N', 'O', 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z'};

  cout<< "Case #" << Cont << ":";

  for(int i : DecryptedValues)
  {
    cout<< Character[DecryptMessage(PrimeValues , i)];
  }

  cout<< "\n";
}

int main()
{
  vector<long long int> CryptedValues {};
  vector<long long int> PrimeValues {};
  vector<long long int> DivisorValues {};
  vector<long long int> DecryptedValues {};
  
  long int Max {} , Length {} , TestCases {} , Cont {1};

  cin >> TestCases;

  while(TestCases != 0)
  {
    cin >> Max >> Length;

    PrimeList( Max , PrimeValues );

    CryptedInput( CryptedValues , Length );

    DivisorList( PrimeValues , CryptedValues , DivisorValues );

    DecryptValues( DivisorValues , DecryptedValues , CryptedValues );

    Message(DecryptedValues , PrimeValues , Cont);
    
    Cont++;
    TestCases--;
  }
  
  return 0;

}
