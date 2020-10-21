#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int length;
    cin >> length;
    vector<int> array(length);
    int zeroes = 0;
    for (int i = 0; i < length; i++)
    {
      cin >> array[i];
      if (!array[i])
        zeroes++;
    }
    int ones = length - zeroes;

    if (zeroes >= length / 2)
    {
      cout << zeroes << endl;
      for (int i = 0; i < zeroes; i++)
        cout << "0" << " ";
    }else{
      cout<<ones - ones%2<<endl;
      for (int i = 0; i < ones - ones%2; i++)
        cout<<"1"<<" ";
    }
    cout<<endl;
  }
  return 0;
}