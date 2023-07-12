//Google Code Jam '19 Qualification Round Problem C - Cryptopangrams
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>



using namespace std;

int PrimeCheck(int CryptedValue, vector<int>& PrimeValues)
{
    for (int i{ 2 }; i != CryptedValue; i++)
    {
        if (CryptedValue % i == 0)
        {
            PrimeValues.push_back(i);
        }
    }

    return 0;
}

void PrimeList(int Max, vector<int>& PrimeValues, vector<int> CryptedValues)
{
    for (int i : CryptedValues)
    {
        PrimeCheck(i, PrimeValues);
    }
}

void CryptedInput(vector<int>& CryptedValues, int Length)
{
    int Cont{ 0 }, Input{};

    while (Cont != Length)
    {
        cin >> Input;
        CryptedValues.push_back(Input);
        Cont++;
    }
}



void DecryptValues(vector<int>& DivisorValues, vector<int>& DecryptedValues, vector<int>& CryptedValues)
{

    int Index{ 0 };

    for (int i : DivisorValues)
    {
        if (Index == ((CryptedValues.size() * 2) - 2))
        {
            DecryptedValues.push_back(DivisorValues.at(DivisorValues.size() - 1));
            break;
        }

        if (i == DivisorValues[0])
        {
            DecryptedValues.push_back(i);
        }

        if ((i == DivisorValues[Index + 1] || i == DivisorValues[Index + 2] || i == DivisorValues[Index + 3]) && i != DivisorValues[DivisorValues.size() - 1])
        {
            DecryptedValues.push_back(i);
        }

        Index++;
    }
}

int DecryptMessage(vector<int> PrimeValues, vector<int> DivisorValues, int Value)
{
    int Index{ 0 };

    for (int i : DivisorValues)
    {
        if (Value == i)
        {
            break;
        }

        Index++;
    }

    return Index;
}

void Message(vector<int> DecryptedValues, vector<int> PrimeValues, vector<int> DivisorValues, int Cont)
{
    vector<char> Character {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    if(Cont == 1)
    {
      cout<< "\n";
    }
    cout << "Case # " << Cont << ":";

    for (int i : DecryptedValues)
    {
        cout << Character[DecryptMessage(PrimeValues, DivisorValues, i)];
    }

    cout << "\n";
}

int main()
{
  int TestCases{}, Cont{ 1 } ;

  cin >> TestCases;


  while (TestCases != 0)
  {
    vector<int> CryptedValues {};
    vector<int> PrimeValues {};
    vector<int> DivisorValues {};
    vector<int> DecryptedValues {};

    int Max {} , Length {};
    
    cin>> Max >> Length;

    CryptedInput(CryptedValues, Length);

    PrimeList(Max, PrimeValues, CryptedValues);

    DecryptValues(PrimeValues, DecryptedValues, CryptedValues);

    DivisorValues = DecryptedValues;

    sort(DivisorValues.begin(), DivisorValues.end());
    DivisorValues.erase(unique(DivisorValues.begin(), DivisorValues.end()), DivisorValues.end());

    Message(DecryptedValues, PrimeValues, DivisorValues, Cont);

    Cont++;
    TestCases--;
  }

  return 0;
}
