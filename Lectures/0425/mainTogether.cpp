#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

class Character
{
	public:
		Character(string csvString);
		void print();
		int getSpeed() const {return _speed;}
    private:
		string chopFirst(string&);
		int toInt(string s);
		string _name;
		int _health;
		int _speed;
		int _b_damage;
		int _s_damage;
		int _s_damage2;
		int _a_damage;
		int _phy_crit;
		int _spec_crit;
		int _armor;
		int _armor_pen;
		int _resist;
		int _resist_pen;
		int _potency;
		int _tenacity;
		int _hp_steal;
};

class SpeedComparison
{
 private:
  bool reverse;
 public:
  SpeedComparison(const bool& revparam=false)
    {
      reverse=revparam;
    }
  bool operator() (const Character* lhs, const Character* rhs) const
  {
    if (reverse)
      return (lhs->getSpeed() > rhs->getSpeed());
    else
      return (lhs->getSpeed() < rhs->getSpeed());
  }
};


int main()
{
  priority_queue<Character*, vector<Character*>, SpeedComparison> battleQueue;
  Character *test;
  ifstream dataFile("statsL90.csv");
  string inputBuffer;
  getline(dataFile, inputBuffer); /// skip titles

  do {
    getline(dataFile, inputBuffer);
    if (!dataFile.eof())
      {
	battleQueue.push( new Character(inputBuffer) );
      }
  } while ( !dataFile.eof() );

  for (int i=0;i<5;i++)
    {
      battleQueue.top()->print();
      battleQueue.pop();
    }

};

Character::Character(string csvString)
{
	_name = chopFirst(csvString);
  _health=toInt(chopFirst(csvString)) ;
  _speed=toInt(chopFirst(csvString)) ;
  _b_damage=toInt(chopFirst(csvString)) ;
  _s_damage=toInt(chopFirst(csvString)) ;
}

int Character::toInt(string s)
{
  return atoi(s.c_str());
}

string Character::chopFirst(string &csvString)
{

  string retVal;
  //  cout << "Given: " << csvString << endl;
  int pos = csvString.find(',');

  if (pos == string::npos) /// not found
    {
      retVal = csvString;
      csvString.clear();
    }
  else
    {
      //  cout << "Found a comma at " << pos << endl;
      retVal = csvString.substr(0, pos);
      csvString = csvString.substr(pos+1);
    }

  /// clean up the string of double quotes

  for (int i=0;i<retVal.size();i++)
    {
      if (retVal[i] == '\"')
	{
	  retVal.erase(i, 1);
	  i--; /// don't increement this iteration
	}
    }

  // cout << "returning: " << retVal << endl;
  return retVal;
}

void Character::print()
{
  cout << "Name: " << _name << " Speed " << _speed << endl;
}
