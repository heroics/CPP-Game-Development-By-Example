#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
class Hero
{
public:
    void setGold(int gold)
    {

        this->gold = gold;
    }
    int level;
    string role;
    int getGold()
    {
        return this->gold;
    }

protected:
    int gold;
};
class PrestigeClass : public Hero
{
public:
    string advanceClass = "Rank 1";
};
int main()
{
    PrestigeClass myHero;
    myHero.setGold(420);
    cout << myHero.getGold()
         << endl;
    cout << myHero.advanceClass;
}
