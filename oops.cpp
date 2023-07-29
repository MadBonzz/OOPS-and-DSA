#include<iostream>
using namespace std;

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
}