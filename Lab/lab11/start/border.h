#ifndef _BORDER_H_
#define _BORDER_H_

class Border :public Organism
{
 public:
  string toString() {return "Border";}
  string getImageName() {return "border.jpg"; }
  bool isEmpty() {return false;} /// not empty!
  void move() {}; //do nothing

 private:
};


#endif
