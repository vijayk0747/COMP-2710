#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

//Declare Prototypes
bool at_least_two_alive(bool,bool,bool);
void Aaron_shoots1(bool&,bool&);
void Bob_shoots(bool&,bool&);
void Charlie_shoots(bool&,bool&);
void Aaron_shoots2(bool&,bool&);

//Declare Prototype Tests
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

//Implement Pause
void Press_any_key(void);

//Declaring Variables (3 Constants)
const float aaronHitRate = 1.0/3.0;
const float bobHitRate = 1.0/2.0;
const float charlieHitRate = 1.0;

int main()
{
    //Opening Message
    cout<<"*** Welcome to Vijay's Duel Simulator ***\n";

    //Initialize random number generator
    srand(time(0));

    //Call Prototype Testers
    test_at_least_two_alive();
    Press_any_key();
    test_Aaron_shoots1();
    Press_any_key();
    test_Bob_shoots();
    Press_any_key();
    test_Charlie_shoots();
    Press_any_key();
    test_Aaron_shoots2();
    Press_any_key();

    //Another constant
    const int TOTAL_RUNS = 10000;

    //Strategy 1
    cout << "Ready to test Strategy 1 (run "<<TOTAL_RUNS<<" times):\n";

    Press_any_key();

    bool aaronAlive, bobAlive, charlieAlive;

    int aWins1=0, bWins1=0, cWins1=0;

    for(int i=0;i<TOTAL_RUNS;i++)
    {

        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;

        //Battle
        while(at_least_two_alive(aaronAlive,bobAlive,charlieAlive))
        {
            if(aaronAlive)
            {
                Aaron_shoots1(bobAlive,charlieAlive);
            }
            if(bobAlive)
            {
                Bob_shoots(aaronAlive,charlieAlive);
            }
            if(charlieAlive)
            {
                Charlie_shoots(aaronAlive,bobAlive);
            }
        }

        //Count Wins
        if(aaronAlive)
        {
            aWins1++;
        }
        if(bobAlive)
        {
            bWins1++;
        }
        if(charlieAlive)
        {
            cWins1++;
        }
   }

    //Display strategy 1 results
    cout<<"Aaron won "<<aWins1<<"/"<<TOTAL_RUNS<<" duels or "<<static_cast<double>(aWins1)/TOTAL_RUNS*100<<"%\n";
    cout<<"Bob won "<<bWins1<<"/"<<TOTAL_RUNS<<" duels or "<<static_cast<double>(bWins1)/TOTAL_RUNS*100<<"%\n";
    cout<<"Charlie won "<<cWins1<<"/"<<TOTAL_RUNS<<" duels or "<<static_cast<double>(cWins1)/TOTAL_RUNS*100<<"%\n\n";

    //Strategy 2
    cout << "Ready to test Strategy 2 (run "<<TOTAL_RUNS<<" times):\n";

    Press_any_key();

    int aWins2 = 0, bWins2 = 0, cWins2 = 0;

    for(int i=0;i<TOTAL_RUNS;i++)
    {

        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;

        //Battle
        while(at_least_two_alive(aaronAlive,bobAlive,charlieAlive))
        {
            if(aaronAlive)
            {
                Aaron_shoots2(bobAlive,charlieAlive);
            }
            if(bobAlive)
            {
                Bob_shoots(aaronAlive,charlieAlive);
            }
            if(charlieAlive)
            {
                Charlie_shoots(aaronAlive,bobAlive);
            }
        }

        //Count wins
        if(aaronAlive)
        {
            aWins2++;
        }
        if(bobAlive)
        {
            bWins2++;
        }
        if(charlieAlive)
        {
            cWins2++;
        }
    }

    //Display strategy 2 results

    cout<<"Aaron won "<<aWins2<<"/10000 duels or "<<static_cast<double>(aWins2)/TOTAL_RUNS*100<<"%\n";
    cout<<"Bob won "<<bWins2<<"/10000 duels or "<<static_cast<double>(bWins2)/TOTAL_RUNS*100<<"%\n";
    cout<<"Charlie won "<<cWins2<<"/10000 duels or "<<static_cast<double>(cWins2)/TOTAL_RUNS*100<<"%\n\n";

    //Determine which strategy is better
    if(aWins2<aWins1)
    {
        cout<<"Strategy 1 is better than Strategy 2.\n";
    }
    else
    {
        cout<<"Strategy 2 is better than Strategy 1.\n";
    }

    return 0;
}

//At least two alive function
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive)
{
    if((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Tester for at least two alive
void test_at_least_two_alive(void)
{
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true,true,false));
   cout << "\tCase passed ...\n";

   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false,false,true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false,true,false));
   cout << "\tCase passed ...\n";

   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true,false,false));
   cout << "\tCase passed ...\n";

   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false,false,false));
   cout << "\tCase passed ...\n";
}

//Aaron's first strategy
void Aaron_shoots1(bool& B_alive, bool& C_alive)
{
    bool hit = false;
    int shotResult = rand()%100;

    if (shotResult <= (aaronHitRate*100))
    {
        hit = true;
    }

    if (C_alive == true && hit == true)
    {
        C_alive = false;
    }
    else if (B_alive == true && hit == true)
    {
        B_alive = false;
    }
}

//Tester for Aaron shoots 1
void test_Aaron_shoots1(void)
{
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   bool bob_a = true;
   bool charlie_a = true;
   cout << "\tCase1: Bob alive, Charlie alive \n"
        << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(bob_a,charlie_a);

   bob_a = false;
   charlie_a = true;
   cout << "\tCase2: Bob dead, Charlie alive \n"
        << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(bob_a,charlie_a);

   bob_a = true;
   charlie_a = false;
   cout << "\tCase3: Bob alive, Charlie dead \n"
        << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots1(bob_a,charlie_a);
}

//Bob shoots function
void Bob_shoots(bool& A_alive, bool& C_alive)
{
    bool hit = false;
    int shotResult = rand()%100;

    if (shotResult <= (bobHitRate*100))
    {
        hit = true;
    }

    if (C_alive == true && hit == true)
    {
        C_alive = false;
    }
    else if (A_alive == true && hit == true)
    {
        A_alive = false;
    }
}

//Tester for boob shoots
void test_Bob_shoots(void)
{
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   bool aaron_a = true;
   bool charlie_a = true;
   cout << "\tCase1: Aaron alive, Charlie alive \n"
        << "\t\tBob is shooting at Charlie\n";
   Bob_shoots(aaron_a,charlie_a);

   aaron_a = false;
   charlie_a = true;
   cout << "\tCase2: Aaron dead, Charlie alive \n"
        << "\t\tBob is shooting at Charlie\n";
   Bob_shoots(aaron_a,charlie_a);

   aaron_a = true;
   charlie_a = false;
   cout << "\tCase3: Aaron alive, Charlie dead \n"
        << "\t\tBob is shooting at Aaron\n";
   Bob_shoots(aaron_a,charlie_a);
}

//Charlie shoots function
void Charlie_shoots(bool& A_alive, bool& B_alive)
{
    bool hit = false;
    int shotResult = rand()%100;

    if (shotResult <= (charlieHitRate*100))
    {
        hit = true;
    }

    if (B_alive == true && hit == true)
    {
        B_alive = false;
    }
    else if (A_alive == true && hit == true)
    {
        A_alive = false;
    }
}

//Tester for charlie shoots
void test_Charlie_shoots(void)
{
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   bool aaron_a = true;
   bool bob_a = true;
   cout << "\tCase1: Aaron alive, Bob alive \n"
        << "\t\tCharlie is shooting at Bob\n";
   Charlie_shoots(aaron_a,bob_a);

   aaron_a = false;
   bob_a = true;
   cout << "\tCase2: Aaron dead, Bob alive \n"
        << "\t\tCharlie is shooting at Bob\n";
   Charlie_shoots(aaron_a,bob_a);

   aaron_a = true;
   bob_a = false;
   cout << "\tCase3: Aaron alive, Bob dead \n"
        << "\t\tCharlie is shooting at Aaron\n";
   Charlie_shoots(aaron_a,bob_a);
}

//Aaron's second strategy
void Aaron_shoots2(bool& B_alive, bool& C_alive)
{
    bool hit = false;
    int shotResult = rand()%100;

    if (shotResult <= (aaronHitRate*100))
    {
        hit = true;
    }

    if (B_alive == true && C_alive == true)
    {
        return;
    }
    else
    {
        if (C_alive == true && hit == true)
        {
            C_alive = false;
        }
        else if (B_alive == true && hit == true)
        {
            B_alive = false;
        }
    }
}

//Tester for Aaron shoots 2
void test_Aaron_shoots2(void)
{
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   bool bob_a = true;
   bool charlie_a = true;
   cout << "\tCase1: Bob alive, Charlie alive \n"
        << "\t\tAaron intentionally misses his first shot\n"
        << "\t\tBoth Bob and Charlie are alive.\n";
   Aaron_shoots2(bob_a,charlie_a);

   bob_a = false;
   charlie_a = true;
   cout << "\tCase2: Bob dead, Charlie alive \n"
        << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots2(bob_a,charlie_a);

   bob_a = true;
   charlie_a = false;
   cout << "\tCase3: Bob alive, Charlie dead \n"
        << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots2(bob_a,charlie_a);
}

//Implementing Pause
void Press_any_key(void)
{
   cout << "Press enter key to continue...\n";
   cin.get();
}



