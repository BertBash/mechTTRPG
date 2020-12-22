#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Part{
public:
  string name;
  string type;
  int price;
  int durability;
};

class Catalogue{
public:
  vector <Part *> heads;
  vector <Part *> bodies;
  vector <Part *> arms;
  vector <Part *> legs;

  void readFile(string);
};

class Mech{
public:
  string name;
  Part head;
  Part body;
  Part arms;
  Part legs;

  void printMech();
};

void buildMode(Mech, Catalogue);

int main(){
  Catalogue mainCat;
  Mech m;
  
  mainCat.readFile("parts.partlist");

  buildMode(m, mainCat);
  
  return 0;
}


//TODO: Add the ability to change parts
void buildMode(Mech m, Catalogue c){
  bool building = true;
  string input;
  int funds = 1000000;
  
  while(building){
    cout << "Current Funds: $" << funds << endl;
    cin >> input;
    if(input == "exit")
      return;
    else if(input == "print"){
      m.printMech();
    }else if
      cout << "Hi " << input << endl;
  }  
}

void Mech::printMech(){
  cout << "#######################" << endl;
  cout << "Name: " << name << endl;
  cout << "Head: " << head.name << endl;
  cout << "Body: " << body.name << endl;
  cout << "Arms: " << arms.name << endl;
  cout << "Legs: " << legs.name << endl;
  cout << "#######################" << endl;
}

//Reads part entries from a .partList file and enters them into the catalogue.
void Catalogue::readFile(string fileName){
  ifstream partsFile;
  Part *p;

  partsFile.open(fileName);
  
  while(!partsFile.eof()){

    //Read in a part
    p = new Part;
    partsFile >> p->type >> p->name >> p->durability >> p->price;

    //Place it in the correct section
    if(p->type == "Head")
      heads.push_back(p);
    else if(p->type == "Body")
      bodies.push_back(p);
    else if(p->type == "Legs")
      legs.push_back(p);
    else if(p->type == "Arms")
      arms.push_back(p);
  }
}
