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

  void addPart(Part *);
  void readFile(string);
  void printCatalogue();
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

class Character{
public:
  Catalogue partsOwned;
  vector <Mech> mechs;  
};


void buildMode(Character);

int main(){
  Catalogue mainCat;
  Character player;
  Mech m;
  
  buildMode(player);
  
  return 0;
}

//Core building function dictates mech creation
void buildMode(Character player){
  bool building = true;
  string input;
  Mech m;
  Catalogue c;
  int funds = 1000000;

  c.readFile("parts.partlist");


  while(building){
    cout << "Current Funds: $" << funds << endl;
    cin >> input;
    if(input == "exit")
      return;
    else if(input == "print"){
      m.printMech();
    }else if(input  == "list"){
      c.printCatalogue();
    }else if(input == "buy"){
      int i = 0;

      //TODO: Search for specific parts by name and type.

      cout << c.heads[i]->price << endl;
      if(funds > c.heads[i]->price){
        funds -= c.heads[i]->price;
        player.partsOwned.addPart(c.heads[i]);
      }      
    }else{
      cout << "Hi " << input << endl;
    }
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

void Catalogue::printCatalogue(){
  cout << "Heads" << endl;
  for(int i = 0; i<heads.size(); i++){
    cout << heads[i]->name << " " << heads[i]->price << endl;
  }
  cout << endl;
}

void Catalogue::addPart(Part *part){
    if(part->type == "Head")
      heads.push_back(part);
    else if(part->type == "Body")
      bodies.push_back(part);
    else if(part->type == "Arms")
      arms.push_back(part);
    else if(part->type == "Legs")
      legs.push_back(part);
    else
      cout << "Part " << part->name << " is invalid" << endl;
}