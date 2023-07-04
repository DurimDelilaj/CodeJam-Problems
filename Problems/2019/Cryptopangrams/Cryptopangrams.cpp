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


void PrimeList (int Max , vector<int> &Values)
{
  int Prime {0};

  for(int i {Max} ; Prime != 26 ; i--)
  {
    if(PrimeCheck(i) == true)
    {
      Values.push_back(i);
      Prime++;
    }
  }
}

void CryptedVal (vector<int> &CryptedValues , int ListValues)
{
  int Values {0} , Input {};

  while(Values != ListValues)
  {
    cin>> Input;
    CryptedValues.push_back(Input);
    Values++;
  }
}

void CharacterVerifier (vector<int> PrimeValues , vector<int> &DecryptedValues , int CryptedValue)
{
  for(int i : PrimeValues)
  {
    if(CryptedValue % i == 0 )
    {
      DecryptedValues.push_back(CryptedValue / i);
    }
  }
}

void DecryptMessage(vector<int> PrimeValues , vector<int> CryptedValues , vector<int> &DecryptedValues)
{
  for(int i : CryptedValues)
  {
    CharacterVerifier(PrimeValues , DecryptedValues , i);
  }
}
  


int main()
{
  vector<int> CryptedValues {};
  vector<int> PrimeValues {};
  vector<int> DecryptedValues {};
  vector<int> ValCharacters {};
  

  int Max {} , InputValues {} , Index {} , Double {1};

  cin>> Max;
  cin>> InputValues;

  PrimeList( Max , PrimeValues );

  CryptedVal(CryptedValues , InputValues);

  //DecryptMessage(PrimeValues , CryptedValues , DecryptedValues);

  /*for(int i : DecryptedValues)
  {
    if(i == DecryptedValues[0])
    {
      cout<< i <<endl;
      ValCharacters.push_back(i);
    }

    if(i == DecryptedValues[Index + 1] && i != DecryptedValues[0] && i != DecryptedValues[( DecryptedValues.size() - 1)])
    {
      cout<< i <<endl;
      ValCharacters.push_back(i);
    }

    if(i == DecryptedValues[(DecryptedValues.size() - 1)])
    {
      cout<< i <<endl;
      ValCharacters.push_back(i);
    }
    
    Index++;
  } */ 
  for(int i : PrimeValues)
  {
    cout<< i <<endl;
  }

  
}
