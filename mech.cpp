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
  vector <Part *> parts;

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

  player.mechs.push_back(m);
  c.readFile("parts.partlist");


  while(building){
    cout << "Current Funds: $" << funds << endl;
    cin >> input;
    if(input == "exit")
      return;
    else if(input == "print"){
      player.mechs[0].printMech();
    }else if(input  == "list"){
      c.printCatalogue();
    }else if(input == "buy"){
      int i;

      cin >> input;
      for(i = 0; i<c.parts.size(); i++){
        if(input == c.parts[i]->name)
          break;
      }

      if(input == c.parts[i]->name){
        if(funds > c.parts[i]->price){
          funds -= c.parts[i]->price;
          player.partsOwned.addPart(c.parts[i]);
        }
      }else{
        cout << input << " not found." << endl;
      }      
    }else if(input == "inventory"){
      player.partsOwned.printCatalogue();
    }else if(input == "equip"){
      int i;
      int mechNumber;

      cin >> mechNumber;
      if(mechNumber < player.mechs.size()){
        cin >> input;
        for(i=0; i<c.parts.size(); i++){
          if(input == player.partsOwned.parts[i]->name)
            break;        
        }

        if(input == player.partsOwned.parts[i]->name){
          if(player.partsOwned.parts[i]->type == "Head"){
            player.mechs[mechNumber].head = *player.partsOwned.parts[i];
          }else if(player.partsOwned.parts[i]->type == "Body"){
            player.mechs[mechNumber].body = *player.partsOwned.parts[i];
          }else if(player.partsOwned.parts[i]->type == "Arms"){
            player.mechs[mechNumber].arms = *player.partsOwned.parts[i];
          }else if(player.partsOwned.parts[i]->type == "Legs"){
            player.mechs[mechNumber].legs = *player.partsOwned.parts[i];
          }
        }else{
          cout << "Part not owned." << endl;
        }
      }else{
        cout << "You don't have that many mechs." << endl;
      }
    }else{
      cout << "Invalid command: \"" << input << "\" maybe you've capitalized something?" << endl;
    }

    cout << endl;
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
    //Read in a part and place it in the list
    p = new Part;
    partsFile >> p->type >> p->name >> p->durability >> p->price;
    parts.push_back(p);
  }
}

void Catalogue::printCatalogue(){
  cout << "Listing Current Catalogue" << endl;
  for(int i = 0; i<parts.size(); i++){
    cout << parts[i]->name << " " << parts[i]->price << endl;
  }
  cout << endl;
}

void Catalogue::addPart(Part *part){
  parts.push_back(part);
}