// bruteforce approach
//  #include <iostream>
//  #include <cstring>
//  using namespace std;
//  bool isPermutation(char a1[], char a2[])
//  {
//      int n1 = strlen(a1);
//      int n2 = strlen(a2);
//      if (n1 != n2)
//          return false;
//      int count = 0;
//      for (int i = 0; i < n1; i++)
//      {
//          for (int j = 0; j < n2; j++)
//          {
//              if (a1[i] == a2[j])
//              {
//                  count++;
//                  a2[j] = ' ';
//                  break;
//              }
//          }
//      }
//      if (count == n1)
//          return true;
//      else
//          return false;
//  }
//  int main()
//  {
//      char a1[50];
//      char a2[50];
//      cin >> a1 >> a2;
//      cout << (isPermutation(a1, a2) ? "true" : "false");
//  }

// optimal approach- Window Sliding Technique
#include <iostream>
#include <cstring>
using namespace std;
bool isPermutation(char a1[], char a2[])
{
    int frequency[256] = {0};
    for (int i = 0; a1[i] != '\0'; i++)
        frequency[a1[i]]++;
    for (int i = 0; a2[i] != '\0'; i++)
        frequency[a2[i]]--;
    for (int i = 0; i < 256; i++)
    {
        if (frequency[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    char a1[50];
    char a2[50];
    cin >> a1 >> a2;
    cout << (isPermutation(a1, a2) ? "true" : "false");
}