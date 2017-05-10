#ifndef _EMPTY_H_
#define _EMPTY_H_

class Empty :public Organism
{
 public:
  string toString() {return "Empty";}
  string getImageName() {return "empty.jpg"; }
  bool isEmpty() {return true;} /// empty is empty!
  void move(){} // do nothing;

 private:
};


#endif
