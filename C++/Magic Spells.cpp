#problem: https://www.hackerrank.com/challenges/magic-spells/problem


#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */
  if (Fireball* fb = dynamic_cast<Fireball*>(spell)) {
      fb->revealFirepower();
  } else if (Frostbite* frb = dynamic_cast<Frostbite*>(spell)) {
      frb->revealFrostpower();
  } else if (Thunderstorm* ts = dynamic_cast<Thunderstorm*>(spell)) {
      ts->revealThunderpower();
  } else if (Waterbolt* wb = dynamic_cast<Waterbolt*>(spell)) {
      wb->revealWaterpower();
  } else {
      string spellName = spell->revealScrollName();
      string spellJournal = SpellJournal::read();
      int sNameLength = spellName.length();
      int sJournalLength = spellJournal.length();
      int array[sNameLength+1][sJournalLength+1];
      
      for(int row = 0; row <= sNameLength; row++) {
          array[row][0] = 0;
      }
      for (int col = 0; col <= sJournalLength; col++) {
          array[0][col] = 0;
      }
      for (int row = 1; row <= sNameLength; row++) {
          for(int col = 1; col <= sJournalLength; col++) {
              if (spellName[row-1] == spellJournal[col-1]) {
                  array[row][col] = array[row-1][col-1] + 1;
              } else {
                  array[row][col] = max(array[row][col-1], array[row-1][col]);
              }
          }
      }
      cout << array[sNameLength][sJournalLength] << '\n'; 
  }
  

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
