//complusroy one 
//code

#include<iostream>
#include<queue>
#include<string>
using namespace std;

class combatant {
public:
    string name;
    int health;
    int attackpower;
    
    combatant(string n, int h, int ap) : name(n), health(h), attackpower(ap) {}
    
    bool operator<(const combatant& other) const {
        return name < other.name;
    }
    
    bool operator>(const combatant& other) const {
        return name > other.name;
    }
    
    bool operator==(const combatant& other) const {
        return name == other.name;
    }
};

class node {
public:
    combatant data;
    node* right;
    node* left;

    node(combatant value) : data(value), left(nullptr), right(nullptr) {}
};

node* insertbst(node* root, combatant key) {
    if(root == nullptr) return new node(key);

    if(key > root->data)
        root->right = insertbst(root->right, key);
    else if(key < root->data)
        root->left = insertbst(root->left, key);

    return root;
}

void inorder(node* root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data.name << " (hp: " << root->data.health << ") ";
    inorder(root->right);
}

node* minbst(node* root) {
    while(root != nullptr && root->left != nullptr)
        root = root->left;
    return root;
}

node* deletecombatant(node* root, combatant key) {
    if(root == nullptr) return root;

    if(key < root->data) {
        root->left = deletecombatant(root->left, key);
    }
    else if(key > root->data) {
        root->right = deletecombatant(root->right, key);
    }
    else {
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if(root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        node* temp = minbst(root->right);
        root->data = temp->data;
        root->right = deletecombatant(root->right, temp->data);
    }
    return root;
}

bool isempty(node* root) {
    return root == nullptr;
}

int totalnodes(node* root) {
    if(root == nullptr) return 0;
    return 1 + totalnodes(root->left) + totalnodes(root->right);}

class battlequestgame {
private:
    node* playerteam;
    node* enemyteam;
    int round;
    
public:
    battlequestgame() : playerteam(nullptr), enemyteam(nullptr), round(1) {
        initializeteams();
    }
    
    void initializeteams() {
        combatant heroes[] = {
            combatant("arthur", 100, 15),
            combatant("lancelot", 90, 18),
            combatant("galahad", 110, 12),
            combatant("percival", 95, 16),
            combatant("gawain", 105, 14)
        };
        
        combatant enemies[] = {
            combatant("goblin", 60, 10),
            combatant("orc", 120, 8),
            combatant("skeleton", 50, 12),
            combatant("troll", 150, 6),
            combatant("dragon", 200, 20)
        };
        
        for(int i = 0; i < 5; i++) {
            playerteam = insertbst(playerteam, heroes[i]);
            enemyteam = insertbst(enemyteam, enemies[i]);
        }
    }
    
    void displaycombatants() {
        cout << "player team: ";
        inorder(playerteam);
        cout << endl;
        
        cout << "enemy team: ";
        inorder(enemyteam);
        cout << endl;
    }
    
    void playgame() {
        cout << "=== battlequest: bst arena ===" << endl;
        cout << "the battle begins!" << endl << endl;
        
        while(!isempty(playerteam) && !isempty(enemyteam)) {
            playround();
            round++;
        }
        
        declarewinner();
    }
    
    void playround() {
        cout << "=== round " << round << " ===" << endl;
        
        displaycombatants();
        
        node* playerfrontline = minbst(playerteam);
        node* enemyfrontline = minbst(enemyteam);
        
        cout << "\nfrontline combatants:" << endl;
        cout << "player: " << playerfrontline->data.name << " (hp: " << playerfrontline->data.health << ")" << endl;
        cout << "enemy: " << enemyfrontline->data.name << " (hp: " << enemyfrontline->data.health << ")" << endl;
        
        cout << "\n--- player attack ---" << endl;
        performattack(playerfrontline, enemyfrontline, true);
        
        if(enemyfrontline->data.health <= 0) {
            cout << ">>> " << enemyfrontline->data.name << " has been defeated! <<<" << endl;
            enemyteam = deletecombatant(enemyteam, enemyfrontline->data);
        }
        
        if(isempty(enemyteam)) return;
        
        enemyfrontline = minbst(enemyteam);
        cout << "\n--- enemy counterattack ---" << endl;
        performattack(enemyfrontline, playerfrontline, false);
        
        if(playerfrontline->data.health <= 0) {
            cout << ">>> " << playerfrontline->data.name << " has been defeated! <<<" << endl;
            playerteam = deletecombatant(playerteam, playerfrontline->data);
        }
        
        cout << "\n" << string(50, '-') << endl;
    }
    
    void performattack(node* attacker, node* defender, bool isplayerattack) {
        int randombonus = rand() % 5;
        int damage = attacker->data.attackpower + randombonus;
        
        string attackertype = isplayerattack ? "player" : "enemy";
        string defendertype = isplayerattack ? "enemy" : "player";
        
        cout << attackertype << " " << attacker->data.name << " attacks " 
             << defendertype << " " << defender->data.name << "!" << endl;
        cout << "damage dealt: " << damage << " (base: " << attacker->data.attackpower 
             << " + random: " << randombonus << ")" << endl;
        
        defender->data.health -= damage;
        cout << defender->data.name << "'s hp reduced from " 
             << (defender->data.health + damage) << " to " << defender->data.health << endl;
    }
    
    void declarewinner() {
        cout << "\n=== battle results ===" << endl;
        
        if(isempty(playerteam) && isempty(enemyteam)) {
            cout << "it's a draw! both teams have been eliminated!" << endl;
        }
        else if(isempty(enemyteam)) {
            cout << "victory! the player's team has triumphed!" << endl;
            cout << "remaining heroes: ";
            inorder(playerteam);
            cout << endl;
        }
        else {
            cout << "defeat! the enemy team has prevailed!" << endl;
            cout << "remaining enemies: ";
            inorder(enemyteam);
            cout << endl;
        }
        
        cout << "total rounds fought: " << (round - 1) << endl;
    }
};

int main() {
    battlequestgame game;
    game.playgame();
    return 0;
}
