// 12.1 Interface File for Digital Time
#include <iostream>
using namespace std;
class DigitalTime
{
  public:
    friend bool operator== (const DigitalTime &time1, const DigitalTime &time2);
    DigitalTime(int the_hour, int the_minute);
    DigitalTime();
    void advance(int minutes_added);
    void advance(int hours_added, int minutes_added);
    friend istream& operator>>(istream& ins, DigitalTime &the_object);
    // don't forget the const in the ()!!!
    // or you will have "hour is private" error
    friend ostream& operator<<(ostream& outs, const DigitalTime &the_object);
  private:
    int hour;
    int minute;
};

// 12.2 Implementation File for DigitalTime
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "dtime.h"
using namespace std;
// note that helper functions also in the implementation
// not accessible for users
void read_hour(istream& ins, int &the_hour);
void read_minute(istream& ins, int &the_hour);
int digit_to_int(char c);

bool operator==(const DigitalTime &time1, const DigitalTime &time2)
{
    return (time1.hour == time2.hour && time1.minute == time2.minute);
}

DigitalTime::DigitalTime(int the_hour, int the_minute)
{
    if (the_hour<0 || the_hour>23 || the_minute<0 || the_minute > 59)
    {
        cout << "Illegal argument to DigitalTime constructor.";
        exit(1);
    }
    else
    {
        hour = the_hour;
        minute = the_minute;
    }
}

DigitalTime::DigitalTime() : hour(0),minute(0)
{

}

void DigitalTime::advance(int minutes_added)
{
    int gross_minute = minute + minutes_added;
    minute = gross_minute%60;
    int hour_adjustment = gross_minute/60;
    hour = (hour+hour_adjustment)%24;
}

void DigitalTime::advance(int hours_added, int minutes_added)
{
    hour = (hour + hours_added)%24;
    // take advantages of built functions
    advance(minutes_added);
}

ostream& operator<<(ostream& outs, const DigitalTime &the_object)
{
    outs << the_object.hour << ":";
    if (the_object.minute<10)
        outs <<'0';
    outs << the_object.minute;
    return outs;
}

istream& operator>>(istream& ins, DigitalTime &the_object)
{
    read_hour(ins, the_object.hour);
    read_minute(ins, the_object.minute);
    return ins;
}

int digit_to_int(char c)
{
    return (static_cast <int>(c)-static_cast<int>('0'));
}

void read_minute(istream& ins, int &the_minute)
{
    char c1,c2;
    ins >> c1 >> c2;
    if (!(isdigit(c1)&&isdigit(c2)))
    {
        cout << "Error illegal input to read_minute\n";
        exit(1);
    }
    the_minute = (digit_to_int(c1)*10) + digit_to_int(c2);
    if (the_minute<0||the_minute>59)
    {
        cout << "Error illegal input to read_minute\n";
        exit(1);
    }
}

void read_hour(istream& ins, int &the_hour)
{
    char c1,c2;
    ins >> c1 >> c2;
    if (!(isdigit(c1)&&(isdigit(c2) || c2 == ':')))
    {
        cout << "Error illegal input to read_hour\n";
        exit(1);
    }
    if (isdigit(c1)&&c2==':')
    {
        the_hour = digit_to_int(c1);
    }
    // isdigit(c1) && isdigit(c2)
    else
    {
        the_hour = (digit_to_int(c1)*10)+digit_to_int(c2);
        ins >> c2;
        if (c2!= ':')
        {
            cout << "Error illegal input to read_hour\n";
            exit(1);
        }
    }
    if (the_hour<0||the_hour>23)
    {
        cout << "Error illegal input to read_hour\n";
        exit(1);
    }

}


// 12.3 Application File Using DigitalTime
#include <iostream>
#include "dtime.h"
using namespace std;
int main()
{
    DigitalTime clock, old_clock;
    cout << "Enter the time in 24-hour notation: ";
    cin >> clock;
    old_clock = clock;
    clock.advance(15);
    if(clock==old_clock)
        cout << "Something is wrong.";
    cout << "You entered " << old_clock << endl;
    cout << "15 minutes later the time will be " << clock << endl;
    clock.advance(2,15);
    cout << "2 hours and 15 minutes after that\n"
         << "the time will be " << clock << endl;
    return 0;
}

// 12.4 Avoiding Multiple Definitions of a Class
// all in uppercase letters
#ifndef DTIME_H
#define DTIME_H
#include <iostream>
using namespace std;
class DigitalTime
{
    
} ;
#endif


// 12.5 Namespace Demonstration
#include <iostream>
// place a using directive at the start of a file, it applies to the entire file
using namespace std;

namespace savitch1
{
    void greeting();
}

namespace savitch2
{
    void greeting();
}

void big_greeting();

int main()
{
    {
        using namespace savitch2;
        greeting();
    }
    {
        using namespace savitch1;
        greeting();
    }
    big_greeting();
    return 0;
}
// every name defined in a namespace is available inside the namespace grouping
namespace savitch1
{
    void greeting()
    {
        cout << "Hello from namespace savitch1.\n";
    }
}


namespace savitch2
{
    void greeting()
    {
        cout << "Hello from namespace savitch2.\n";
    }
}

void big_greeting()
{
    cout << "A Big Global Hello!\n";
}

/* difference between using std::cout and using namespace std;
 * former makes only one name in the namespace available 
 * latter makes all the names in a namespace available
 * using namespace ns1; 
 * using namespace ns2;
 * is OKAY
 * but using ns1::my_function; using ns2::my_function;
 * will generate problems 
 */
 
 // 12.6 Placing a Class in a Namespace - Header File
 #ifndef DTIME_H
 #define DTIME_H
 #include <iostream>
 using namespace std;
 namespace dtimesavitch
 {
     class DigitalTime
     {
           public:
            friend bool operator== (const DigitalTime &time1, const DigitalTime &time2);
            DigitalTime(int the_hour, int the_minute);
            DigitalTime();
            void advance(int minutes_added);
            void advance(int hours_added, int minutes_added);
            friend istream& operator>>(istream& ins, DigitalTime &the_object);
            // don't forget the const in the ()!!!
            // or you will have "hour is private" error
            friend ostream& operator<<(ostream& outs, const DigitalTime &the_object);
          private:
            int hour;
            int minute;
     };
 }
 #endif
 
// 12.7 Placing a Class in a Namespace - Implementation File
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "dtime.h"
using namespace std;
/* one grouping for the unnamed namespace
 * functions defined in the unnamed namespace are local to this compilation unit(this file and included files(such as interface header file for the class))
 * they can be used anywhere in this file, but have no meaning outside this unit
 * global namespace vs unnamed namespace
 * global scope(all the program files) vs local to compilation unit 
 * put it in a namespace without name => unnamed namespace
 * bother can be accessed without a qualifier
 */

namespace 
{
    void read_hour(istream& ins, int &the_hour);
    void read_minute(istream& ins, int &the_hour);
    int digit_to_int(char c);
}
namespace dtimesavitch
{
    bool operator==(const DigitalTime &time1, const DigitalTime &time2)
    {
        return (time1.hour == time2.hour && time1.minute == time2.minute);
    }

    DigitalTime::DigitalTime(int the_hour, int the_minute)
    {
        if (the_hour<0 || the_hour>23 || the_minute<0 || the_minute > 59)
        {
            cout << "Illegal argument to DigitalTime constructor.";
            exit(1);
        }
        else
        {
            hour = the_hour;
            minute = the_minute;
        }
    }

    DigitalTime::DigitalTime() : hour(0),minute(0)
    {

    }

    void DigitalTime::advance(int minutes_added)
    {
        int gross_minute = minute + minutes_added;
        minute = gross_minute%60;
        int hour_adjustment = gross_minute/60;
        hour = (hour+hour_adjustment)%24;
    }

    void DigitalTime::advance(int hours_added, int minutes_added)
    {
        hour = (hour + hours_added)%24;
        // take advantages of built functions
        advance(minutes_added);
    }

    ostream& operator<<(ostream& outs, const DigitalTime &the_object)
    {
        outs << the_object.hour << ":";
        if (the_object.minute<10)
            outs <<'0';
        outs << the_object.minute;
        return outs;
    }

    istream& operator>>(istream& ins, DigitalTime &the_object)
    {
        read_hour(ins, the_object.hour);
        read_minute(ins, the_object.minute);
        return ins;
    }
}
namespace
{

    int digit_to_int(char c)
    {
        return (static_cast <int>(c)-static_cast<int>('0'));
    }

    void read_minute(istream& ins, int &the_minute)
    {
        char c1,c2;
        ins >> c1 >> c2;
        if (!(isdigit(c1)&&isdigit(c2)))
        {
            cout << "Error illegal input to read_minute\n";
            exit(1);
        }
        the_minute = (digit_to_int(c1)*10) + digit_to_int(c2);
        if (the_minute<0||the_minute>59)
        {
            cout << "Error illegal input to read_minute\n";
            exit(1);
        }
    }

    void read_hour(istream& ins, int &the_hour)
    {
        char c1,c2;
        ins >> c1 >> c2;
        if (!(isdigit(c1)&&(isdigit(c2) || c2 == ':')))
        {
            cout << "Error illegal input to read_hour\n";
            exit(1);
        }
        if (isdigit(c1)&&c2==':')
        {
            the_hour = digit_to_int(c1);
        }
        // isdigit(c1) && isdigit(c2)
        else
        {
            the_hour = (digit_to_int(c1)*10)+digit_to_int(c2);
            ins >> c2;
            if (c2!= ':')
            {
                cout << "Error illegal input to read_hour\n";
                exit(1);
            }
        }
        if (the_hour<0||the_hour>23)
        {
            cout << "Error illegal input to read_hour\n";
            exit(1);
        }

    }
}

// 12.8 Placing a Class in a Namespace - Application Program
#include <iostream>
#include "dtime.h"
using namespace std;

// this is different than the one in the dtime.cpp
void read_hour(int &the_hour);

int main()
{
    using namespace std;
    using namespace dtimesavitch;
    int the_hour;
    read_hour(the_hour);
    
    DigitalTime clock(the_hour,0), old_clock;
    old_clock = clock;
    clock.advance(15);
    if(clock==old_clock)
        cout << "Something is wrong.";
    cout << "You entered " << old_clock << endl;
    cout << "15 minutes later the time will be " << clock << endl;
    clock.advance(2,15);
    cout << "2 hours and 15 minutes after that\n"
         << "the time will be " << clock << endl;
    return 0;
}

 void read_hour(int &the_hour)
 {
     using namespace std;
     cout << "Let's play a time game.\n"
          << "Let's pretend the hour has just changed.\n"
          << "You may write midnight as either 0 or 24,\n"
          << "but I will always write it as 0.\n"
          << "Enter the hour as a number (0-24)";
      cin >> the_hour;
      if (the_hour==24)
      {
          the_hour=0;
      }
 }
 
 // the whole file together should be 
 #include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;
 namespace dtimesavitch
 {
     class DigitalTime
     {
           public:
            friend bool operator== (const DigitalTime &time1, const DigitalTime &time2);
            DigitalTime(int the_hour, int the_minute);
            DigitalTime();
            void advance(int minutes_added);
            void advance(int hours_added, int minutes_added);
            friend istream& operator>>(istream& ins, DigitalTime &the_object);
            // don't forget the const in the ()!!!
            // or you will have "hour is private" error
            friend ostream& operator<<(ostream& outs, const DigitalTime &the_object);
          private:
            int hour;
            int minute;
     };
 }

 namespace
{
    void read_hour(istream& ins, int &the_hour);
    void read_minute(istream& ins, int &the_hour);
    int digit_to_int(char c);
}

using namespace std;

// this is different than the one in the dtime.cpp
void read_hour(int &the_hour);

int main()
{
    using namespace std;
    using namespace dtimesavitch;
    int the_hour;
    // this is the read_hour() in the namespace std
    // the number of parameters are different
    read_hour(the_hour);

    DigitalTime clock(the_hour,0), old_clock;
    old_clock = clock;
    clock.advance(15);
    if(clock==old_clock)
        cout << "Something is wrong.";
    cout << "You entered " << old_clock << endl;
    cout << "15 minutes later the time will be " << clock << endl;
    clock.advance(2,15);
    cout << "2 hours and 15 minutes after that\n"
         << "the time will be " << clock << endl;
    return 0;
}

 void read_hour(int &the_hour)
 {
     using namespace std;
     cout << "Let's play a time game.\n"
          << "Let's pretend the hour has just changed.\n"
          << "You may write midnight as either 0 or 24,\n"
          << "but I will always write it as 0.\n"
          << "Enter the hour as a number (0-24)";
      cin >> the_hour;
      if (the_hour==24)
      {
          the_hour=0;
      }
 }

 namespace dtimesavitch
{
    bool operator==(const DigitalTime &time1, const DigitalTime &time2)
    {
        return (time1.hour == time2.hour && time1.minute == time2.minute);
    }

    DigitalTime::DigitalTime(int the_hour, int the_minute)
    {
        if (the_hour<0 || the_hour>23 || the_minute<0 || the_minute > 59)
        {
            cout << "Illegal argument to DigitalTime constructor.";
            exit(1);
        }
        else
        {
            hour = the_hour;
            minute = the_minute;
        }
    }

    DigitalTime::DigitalTime() : hour(0),minute(0)
    {

    }

    void DigitalTime::advance(int minutes_added)
    {
        int gross_minute = minute + minutes_added;
        minute = gross_minute%60;
        int hour_adjustment = gross_minute/60;
        hour = (hour+hour_adjustment)%24;
    }

    void DigitalTime::advance(int hours_added, int minutes_added)
    {
        hour = (hour + hours_added)%24;
        // take advantages of built functions
        advance(minutes_added);
    }

    ostream& operator<<(ostream& outs, const DigitalTime &the_object)
    {
        outs << the_object.hour << ":";
        if (the_object.minute<10)
            outs <<'0';
        outs << the_object.minute;
        return outs;
    }

    istream& operator>>(istream& ins, DigitalTime &the_object)
    {
        read_hour(ins, the_object.hour);
        read_minute(ins, the_object.minute);
        return ins;
    }
}
namespace
{

    int digit_to_int(char c)
    {
        return (static_cast <int>(c)-static_cast<int>('0'));
    }

    void read_minute(istream& ins, int &the_minute)
    {
        char c1,c2;
        ins >> c1 >> c2;
        if (!(isdigit(c1)&&isdigit(c2)))
        {
            cout << "Error illegal input to read_minute\n";
            exit(1);
        }
        the_minute = (digit_to_int(c1)*10) + digit_to_int(c2);
        if (the_minute<0||the_minute>59)
        {
            cout << "Error illegal input to read_minute\n";
            exit(1);
        }
    }

    void read_hour(istream& ins, int &the_hour)
    {
        char c1,c2;
        ins >> c1 >> c2;
        if (!(isdigit(c1)&&(isdigit(c2) || c2 == ':')))
        {
            cout << "Error illegal input to read_hour\n";
            exit(1);
        }
        if (isdigit(c1)&&c2==':')
        {
            the_hour = digit_to_int(c1);
        }
        // isdigit(c1) && isdigit(c2)
        else
        {
            the_hour = (digit_to_int(c1)*10)+digit_to_int(c2);
            ins >> c2;
            if (c2!= ':')
            {
                cout << "Error illegal input to read_hour\n";
                exit(1);
            }
        }
        if (the_hour<0||the_hour>23)
        {
            cout << "Error illegal input to read_hour\n";
            exit(1);
        }

    }
}
