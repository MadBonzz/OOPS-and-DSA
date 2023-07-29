/*#include<iostream>
using namespace std;

// Creating and accessing class

class footballer{
public:
    string name;
    string position;
    int age;
};

int main(){
    footballer player1;
    player1.name = "Messi";
    player1.position = "CAM";
    player1.age = 36;

    cout<<player1.name<<" "<<player1.position<<" "<<player1.age<<endl;

    footballer *player2 = new footballer();
    player2->name = "Pedri";
    player2->position = "CM";
    player2->age = 20;

    cout<<player2->name<<" "<<player2->position<<" "<<player2->age<<endl;
}*/

#include<iostream>
using namespace std;

// Constructor and Destructor

class player{
public:
    int goals;
    int assist;

    player(){ // Default constructor
        goals = 0;
        assist = 0;
    }

    player(int a, int b){ // Parameterised constructor
        goals = a;
        assist = b;
    }

    player(player &p){ // Copy constructor
        goals = p.goals;
        assist = p.assist;
    }

    ~player(){// Destructor 
        cout<<"Object Deleted"<<endl;
    }
};

int main(){
    player *ronaldo = new player();
    cout<<ronaldo->goals<<" "<<ronaldo->assist<<endl;
    delete ronaldo;

    player messi(808, 234);
    cout<<messi.goals<<" "<<messi.assist<<endl;

    player neymar = messi;
    cout<<neymar.goals<<" "<<neymar.assist<<endl;

}