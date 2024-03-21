/*******************************************************************
* getInfo *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/
# include <iostream>
using namespace std;
void getInfo(int & pickFrom, int & numPicks){
 cout << "How many balls (1-12) are in the pool to pick from? ";
 cin >> pickFrom;
 while (!(pickFrom <= 12 && pickFrom >= 1) || cin.fail()){
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        pickFrom = 13;
    }
    else{
        cout << "Input Error! There must be between 1 and 12 balls." << endl;
        cout << "How many balls (1-12) are in the pool to pick from? ";
        cin >> pickFrom;
    }
}
    cout << "How many balls (1-7) will be drawn? ";
    cin >> numPicks;
    while ((!(numPicks <= 7 && numPicks >= 1)) || cin.fail()){
        if (cin.fail()){
            cin.clear();
            cin.ignore(256,'\n');
            numPicks = 8;
        }
        else {
            cout << "Input Error!" << endl;
            cout << "How many balls (1-7) will be drawn? ";
            cin >> numPicks;
        }
    }
}

/******************************************************************
* computeWays                                                     *
* Computes and returns the number of different possible sets      *
* of k numbers that can be chosen from a set of n numbers.        *
* The formula for this is     k!(n- k)!                           *
*                             --------                            *
*                                 n!                              *
*******************************************************************/
// Note that the computation is done in a way that does not require
// multiplying two factorials together. This is done to prevent any
// intermediate result becoming so large that it causes overflow.


// This function computes factorials recursively. It is called by computeWays.
double factorial(int n){
    if(n>1){
        return n * factorial(n-1);
    }
    else{
        return 1;
    }
}
double computeWays(int n, int k){
    return ((factorial(k) * (factorial((n - k)))/factorial(n)));
}