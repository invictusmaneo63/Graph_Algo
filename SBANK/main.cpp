#include <iostream>
#include<set>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
using namespace std;

#define REMOVE_SPACE(x) x.erase(remove_if(x.begin(), x.end(), ::isspace), x.end())
int main() {
//
string temp;
int cases, n;
cin >> cases;
while(cases--)
{
    set<string> s1;
    cin >> n;
    cout << n;
    while(n--)
    {
       cin >> temp;
//       cout << temp << endl;
//        cout << temp << endl;

//       cout<< " hello"<< endl;
//        scanf("\n%[^\n]s", temp);
        cout<< temp << endl;
       REMOVE_SPACE(temp);
       cout << temp;
       s1.insert(temp);
    }

}

//temp = " 03 10103538 2222 1233 6160 0142";
//REMOVE_SPACE(temp);
//cout << temp << endl;




//ifstream inFile ("C:\\Users\\Prem Kumar Tiwari\\Documents\\cplus\\SBANK\\in.txt");
//char arr[100];
//string line;
//while(getline(inFile,line))
//{
//    cout <<line.c_str()<< endl;
//}


    return 0;
}