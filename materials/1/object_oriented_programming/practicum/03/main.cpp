#include <cmath>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <limits>

using namespace std;

class Card {
private:
  char suit;
  char rank;

public:
  Card() {}

  Card(char s, char r) {
    suit = s;
    rank = r;
  }

  void print() { cout << rank << " of " << suit << endl; }
};

class Deck {
private:
  const char suits[4] = {'C', 'D', 'H', 'S'};
  const char ranks[13] = {'2', '3', '4', '5', '6', '7', '8',
                          '9', 'T', 'J', 'Q', 'K', 'A'};

  Card *cards;
  int size;

public:
  Deck() {
    srand(time(NULL));
    this->size = 52;
    this->cards = new Card[size];
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        this->cards[i * 13 + j] = Card(suits[i], ranks[j]);
      }
    }
    this->shuffle();
  }

  ~Deck() { delete[] cards; }

  void print() {
    cout << "Deck contains:" << endl;
    for (int i = 0; i < 52; i++) {
      cards[i].print();
    }
  }

  void shuffle() {
    for (int i = 0; i < 52; i++) {
      int j = rand() % 52;
      Card temp = cards[i];
      cards[i] = cards[j];
      cards[j] = temp;
    }
  }

  Card deal() {
    Card temp = cards[0];
    for (int i = 0; i < size--; i++) {
      cards[i] = cards[i + 1];
    }
    return temp;
  }
};

class Person {
private:
  char *name;
  int age;
  Card *hand;
  int handSize;

public:
  Person() {}

  Person(char *name, int age) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->age = age;
    this->hand = new Card[8];
    this->handSize = 0;
  }

  ~Person() {
    delete[] this->name;
    delete[] this->hand;
  }

  void print() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    this->printHand();
  }

  void addCard(Card card) {
    this->hand[this->handSize] = card;
    this->handSize++;
  }

  void printHand() {
    cout << "Hand: " << endl;
    for (int i = 0; i < 8; i++) {
      hand[i].print();
    }
  }
};

class GameOfWar {
private:
  Deck deck;
  Person *players;
  int numPlayers;
  int currentPlayer;
  int currentRound;

public:
  GameOfWar(int numPlayers) {
    this->numPlayers = numPlayers;
    this->players = new Person[numPlayers];
    this->currentPlayer = 0;
    this->currentRound = 0;

    this->deal();
  }

  ~GameOfWar() { delete[] players; }

  void deal() {
    for (int i = 0; i < numPlayers; i++) {
      for (int j = 0; j < 8; j++) {
        players[i].addCard(deck.deal());
      }
    }
  }

  void printPlayers() {
    for (int i = 0; i < numPlayers; i++) {
      players[i].print();
    }
  }

  void printDeck() { deck.print(); }

};

int main() {
  // Person p = Person("John", 21);
  // p.print();

  // Deck d;
  // d.print();

  GameOfWar g = GameOfWar(2);
  g.printPlayers();

  return 0;
}