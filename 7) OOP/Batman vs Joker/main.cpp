#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool game_over = 0;

class Character {
    private:
            string name;
            int health = 100;
            int energy = 500;
            float shield = 1;
            int gadget = 0; // 1- weapons, 2- shields
            bool success = 0; // attack successed or failed
    public:
            Character(string name) : name(name) {
            cout<<"Character Created"<<endl;
        }
        
        // sets
        void setHealth(int health) {
            if(health <= 0) 
                game_over = 1;
            this->health = health;
        }
        void setEnergy(int energy) {
            if(energy <= 0)
            {
                printf("Unexpected Error");
                exit(1);
            }
            else 
                this->energy = energy;
        }
        void setShield(float shield) {
            this->shield = shield;
        }
        void setSuccess(bool success) {
            this->success = success;
        }

        // gets
        int getHealth() {
            return health;
        }
        int getEnergy() {
            return energy;
        }
        float getShield() {
            return shield;
        }
        string getName() {
            return name;
        }
        bool getSuccess() {
            return success;
        }

        // functions
        void display() {
            cout << "-->" << name << "'s Health: " << health << "%" << endl;
            cout << "-->" << name << "'s Energy: " << energy << endl;
        }
        int chooseGadget() {
            cout << "Choose Gadget: \n1- Weapons\n2- Shields\n3- skip turn\n---------------" << endl;
            do
            {
                cout << "Enter 1,2 or 3: "; 
                cin >> gadget;
            } while (gadget != 1 && gadget != 2 && gadget != 3);
            setSuccess(1);
            return gadget;
        }

        virtual void useWeapon(Character* defender) = 0;
        virtual void useShield() = 0;

        ~Character() {
            cout<<"Character Deleted"<<endl;
        }
};

class Batman : public Character {
    private:
        int choose_weapon = 0;
        int choose_shield = 0;
        const char* weapons[4] = {"Batarang", "Grapple Gun", "Explosive Gel", "Batclaw"};
        const char* shields[2] = {"Cape Glide", "Smoke Pellet"};
        // uses left
        int grapple_gun = 5;
        int explosive_gel = 3;
        int batclaw = 1;
        int smoke_pellet = 2;
        
        // weapons
        void Batarang(Character* defender) {
            int newEnergy = (getEnergy() - 50);
            if( newEnergy <= 0)
            {
                printf("Not enough energy available to use this gadget, choose another gadget.\n");
                setSuccess(0);
            }
            else
            {   
                setEnergy(newEnergy);
                defender->setHealth(defender->getHealth() - (11 * defender->getShield()));
                defender->setShield(1); // remove oponent's shield after being used to defend attack
                setSuccess(1);
            }
        }
        void grappleGun(Character* defender) {
            
            if(grapple_gun > 0)
            { 
                int newEnergy = (getEnergy() - 88);
                if( newEnergy <= 0)
                {
                    printf("Not enough energy available to use this gadget, choose another gadget.\n");
                    setSuccess(0);
                }
                else
                {
                    setEnergy(newEnergy);
                    defender->setHealth(defender->getHealth() - (18 * defender->getShield()));
                    defender->setShield(1); // remove oponent's shield after being used to defend attack
                    grapple_gun--;
                    setSuccess(1);
                }
            }
            else
            {
                printf("Cannot use this gadget anymore, try another gadget.\n");
                setSuccess(0);
            }
        }
        void explosiveGel(Character* defender) {
            
            if(explosive_gel > 0)
            { 
                int newEnergy = (getEnergy() - 92);
                if( newEnergy <= 0)
                {
                    printf("Not enough energy available to use this gadget, choose another gadget.\n");
                    setSuccess(0);
                }
                else
                {
                    setEnergy(newEnergy);
                    defender->setHealth(defender->getHealth() - (10 * defender->getShield()));
                    defender->setShield(1); // remove oponent's shield after being used to defend attack
                    setShield(0.8);
                    explosive_gel--;
                    setSuccess(1);
                }
            }
            else
            {
                printf("Cannot use this gadget anymore, try another gadget.\n");
                setSuccess(0);
            }
        }
        void Batclaw(Character* defender) {
            
            if(batclaw > 0)
            { 
                int newEnergy = (getEnergy() - 120);
                if( newEnergy <= 0)
                {
                    printf("Not enough energy available to use this gadget, choose another gadget.\n");
                    setSuccess(0);
                }
                else
                {
                    setEnergy(newEnergy);
                    defender->setHealth(defender->getHealth() - 20);
                    batclaw--;
                    setSuccess(1);
                }
            }
            else
            {
                printf("Cannot use this gadget anymore, try another gadget.\n");
                setSuccess(0);
            }
        }
        // shields
        void capeGlide() {
            int newEnergy = (getEnergy() - 20);
            if( newEnergy <= 0)
            {
                printf("Not enough energy available to use this gadget, choose another gadget.\n");
                setSuccess(0);
            }
            else
            {
                setEnergy(newEnergy);
                setShield(0.6);
                setSuccess(1);
            }
        }
        void smokePellet() {
            if(smoke_pellet > 0)
            { 
                int newEnergy = (getEnergy() - 50);
                if( newEnergy <= 0)
                {
                    printf("Not enough energy available to use this gadget, choose another gadget.\n");
                    setSuccess(0);
                }
                else
                {
                    setEnergy(newEnergy);
                    setShield(0.1);
                    smoke_pellet--;
                    setSuccess(1);
                }
            }
            else
            {
                printf("Cannot use this gadget anymore, try another gadget.\n");
                setSuccess(0);
            }
        }
    public:
        Batman() : Character("Batman") {
            cout<<"Batman Created"<<endl;
        }
        void useWeapon(Character* defender) override {
            cout << "\nChoose Weapon: " << endl;
            printf("1- Batarang (uses left: infinity)\n");
            printf("2- Grapple Gun (uses left: %d)\n", grapple_gun);
            printf("3- Explosive Gel (uses left: %d)\n", explosive_gel);
            printf("4- Batclaw (uses left: %d)\n---------------\n", batclaw);
            do 
            {
                cout << "Enter 1, 2, 3 or 4: "; 
                cin >> choose_weapon;
            } while (choose_weapon != 1 && choose_weapon != 2 && choose_weapon != 3 && choose_weapon != 4);

            switch (choose_weapon)
            {
            case 1:
                Batarang(defender);
                break;
            case 2:
                grappleGun(defender);
                break;
            case 3:
                explosiveGel(defender);
                break;
            case 4:
                Batclaw(defender);
                break;
            default:
                cout << "unexpected error" << endl; // should never happen
                break;
            }
            if(getSuccess())
            {
                printf("\n---------------\nBatman is attacking Joker with the <%s> Weapon!\n", weapons[choose_weapon-1]);
                printf("Joker's remaining Health: %d%\n---------------\n\n", defender->getHealth());
            }
        }
        void useShield() override {
            cout << "\nChoose Shield: " << endl;
            printf("1- Cape Glide (uses left: infinity)\n");
            printf("2- Smoke Pellet (uses left: %d)\n", smoke_pellet);
            do 
            {
                cout << "Enter 1 or 2: "; 
                cin >> choose_shield;
            } while (choose_shield != 1 && choose_shield != 2);

            if(getShield() != 1) // check if already exists shield
            {
                printf("You already have a shield of %g%% protection, try attacking or skip.\n", (100-getShield()*100));
                setSuccess(0);
            }
            else
            {
                switch (choose_shield)
                {
                case 1:
                    capeGlide();
                    break;
                case 2:
                    smokePellet();
                    break;
                default:
                    cout << "unexpected error" << endl; // should never happen
                    break;
                }
                if(getSuccess())
                {
                    printf("\n---------------\nBatman is defending himself with the <%s> Shield!\n", shields[choose_shield-1]);
                    printf("Shield applied: %g%% protection\n---------------\n\n", (100 - getShield()*100));
                }
            }
        }
};




class Joker : public Character {
    private:
        int choose_weapon = 0;
        int choose_shield = 0;
        const char* weapons[3] = {"Joy Buzzer", "Laughing Gas", "Acid Flower"};
        const char* shields[2] = {"Trick Shield", "Rubber Chicken"};
        // uses left
        int laughing_gas = 8;
        int acid_flower = 3;
        int rubber_chicken = 3;
        
        // weapons
        void joyBuzzer(Character* defender) {
            int newEnergy = (getEnergy() - 40);
            if( newEnergy <= 0)
            {
                printf("Not enough energy available to use this gadget, choose another gadget.\n");
                setSuccess(0);
            }
            else
            {   
                setEnergy(newEnergy);
                defender->setHealth(defender->getHealth() - (8 * defender->getShield()));
                defender->setShield(1); // remove oponent's shield after being used to defend attack
                setSuccess(1);
            }
        }
        void laughingGas(Character* defender) {
            
            if(laughing_gas > 0)
            { 
                int newEnergy = (getEnergy() - 56);
                if( newEnergy <= 0)
                {
                    printf("Not enough energy available to use this gadget, choose another gadget.\n");
                    setSuccess(0);
                }
                else
                {
                    setEnergy(newEnergy);
                    defender->setHealth(defender->getHealth() - (13 * defender->getShield()));
                    defender->setShield(1); // remove oponent's shield after being used to defend attack
                    laughing_gas--;
                    setSuccess(1);
                }
            }
            else
            {
                printf("Cannot use this gadget anymore, try another gadget.\n");
                setSuccess(0);
            }
        }
        void acidFlower(Character* defender) {
            
            if(acid_flower > 0)
            { 
                int newEnergy = (getEnergy() - 100);
                if( newEnergy <= 0)
                {
                    printf("Not enough energy available to use this gadget, choose another gadget.\n");
                    setSuccess(0);
                }
                else
                {
                    setEnergy(newEnergy);
                    defender->setHealth(defender->getHealth() - (22 * defender->getShield()));
                    defender->setShield(1); // remove oponent's shield after being used to defend attack
                    acid_flower--;
                    setSuccess(1);
                }
            }
            else
            {
                printf("Cannot use this gadget anymore, try another gadget.\n");
                setSuccess(0);
            }
        }
        // shields
        void trickShield() {
            int newEnergy = (getEnergy() - 15);
            if( newEnergy <= 0)
            {
                printf("Not enough energy available to use this gadget, choose another gadget.\n");
                setSuccess(0);
            }
            else
            {
                setEnergy(newEnergy);
                setShield(0.68);
                setSuccess(1);
            }
        }
        void rubberChicken() {
            if(rubber_chicken > 0)
            { 
                int newEnergy = (getEnergy() - 40);
                if( newEnergy <= 0)
                {
                    printf("Not enough energy available to use this gadget, choose another gadget.\n");
                    setSuccess(0);
                }
                else
                {
                    setEnergy(newEnergy);
                    setShield(0.2);
                    rubber_chicken--;
                    setSuccess(1);
                }
            }
            else
            {
                printf("Cannot use this gadget anymore, try another gadget.\n");
                setSuccess(0);
            }
        }
    public:
        Joker() : Character("Joker") {
            cout<<"Joker Created"<<endl;
        }
        void useWeapon(Character* defender) override {
            cout << "\nChoose Weapon: " << endl;
            printf("1- Joy Buzzer (uses left: infinity)\n");
            printf("2- Laughing Gas (uses left: %d)\n", laughing_gas);
            printf("3- Acid Flower (uses left: %d)\n", acid_flower);
            do 
            {
                cout << "Enter 1, 2 or 3: "; 
                cin >> choose_weapon;
            } while (choose_weapon != 1 && choose_weapon != 2 && choose_weapon != 3);

            switch (choose_weapon)
            {
            case 1:
                joyBuzzer(defender);
                break;
            case 2:
                laughingGas(defender);
                break;
            case 3:
                acidFlower(defender);
                break;
            default:
                cout << "unexpected error" << endl; // should never happen
                break;
            }
            if(getSuccess())
            {
                printf("\n---------------\nJoker is attacking Batman with the <%s> Weapon!\n", weapons[choose_weapon-1]);
                printf("Batman's remaining Health: %d%\n---------------\n\n", defender->getHealth());
            }
        }
        void useShield() override {
            cout << "\nChoose Shield: " << endl;
            printf("1- Trick Shield (uses left: infinity)\n");
            printf("2- Rubber Chicken (uses left: %d)\n", rubber_chicken);
            do 
            {
                cout << "Enter 1 or 2: "; 
                cin >> choose_shield;
            } while (choose_shield != 1 && choose_shield != 2);

            if(getShield() != 1) // check if already exists shield
            {
                printf("You already have a shield of %g%% protection, try attacking or skip.\n", (100-getShield()*100));
                setSuccess(0);
            }
            else
            {
                switch (choose_shield)
                {
                case 1:
                    trickShield();
                    break;
                case 2:
                    rubberChicken();
                    break;
                default:
                    cout << "unexpected error" << endl; // should never happen
                    break;
                }
                if(getSuccess())
                {
                    printf("\n---------------\nJoker is defending himself with the <%s> Shield!\n", shields[choose_shield-1]);
                    printf("Shield applied: %g%% protection\n---------------\n\n", (100 - getShield()*100));
                }
            }
        }
};



void Attack(Character* attacker, Character* defender) {
    int gadget = attacker->chooseGadget();
    if(gadget == 1) // Weapons
    {
        attacker->useWeapon(defender);
    }
    else if(gadget == 2)// Shields
    {
        attacker->useShield();
    }
    else
        cout << attacker->getName() << "'s turn has been skipped.\n" << endl;
}

void displayStats(Character* player1, Character* player2) {
    player1->display();
    cout << endl;
    player2->display();
}


int main() {

    Batman batman;
    Joker joker;

    cout << endl;
    displayStats(&batman, &joker);
    int round_no = 1;
    bool turn = 1;
    while(!game_over) {
        if(turn) 
        {
            printf("\n<---||ROUND %d||--->\n\n", round_no);

            cout << "|Batman's Turn to Attack|" << endl;
            do
                Attack(&batman, &joker);
            while (!batman.getSuccess());
        }
        else
        {   
            cout << "|Joker's Turn to Attack|" << endl;
            do
                Attack(&joker, &batman);
            while (!joker.getSuccess());

            round_no++;
            printf("\n---------------End of Round Status---------------\n");
            displayStats(&batman, &joker);
        }
        turn = !turn;
        if(batman.getEnergy() < 50 && joker.getEnergy() < 40) // check if there is not enough energy for both players to perform an attack
            game_over = 1;
    }

    cout << "<----------GAME OVER!!---------->" << endl << "The Winner is....\n" << endl;
    if(batman.getEnergy() < 50 && joker.getEnergy() < 40)
        cout << "It's a Draw! Both players do not have enough energy to perform an attack." << endl;
    else
        cout <<"-->!!" << (batman.getHealth()<=0 ? "Batman":"Joker") << "!!<--" << endl;
    return 0;
}