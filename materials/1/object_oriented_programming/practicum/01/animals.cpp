// https://bit.ly/01MAR2022

#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <limits>

using namespace std;

enum AnimalCategory {
    OVERPOPULATED = 'o',
    NOT_ENDANGERED = 'n',
    ENDANGERED = 'e',
    CRITICALLY_ENDANGERED = 'c'
};

struct Animal {
    int id;
    double weight;
    double speed;
    bool eatsMeat;
    AnimalCategory category;

    // Animal(int id, double weight, double speed, bool eatsMeat, AnimalCategory category) :
    //     id(id), weight(weight), speed(speed), eatsMeat(eatsMeat), category(category) {}

    void print() const;
};

// initialize animal
Animal initAnimal(int id, double weight, double speed, bool eatsMeat, AnimalCategory category) {
    // return Animal(id, weight, speed, eatsMeat, category);

    Animal animal;
    animal.id = id;
    animal.weight = weight;
    animal.speed = speed;
    animal.eatsMeat = eatsMeat;
    animal.category = category;
    return animal;
}

// print animal information
void Animal::print() const {
    cout << "id: " << id << endl;
    cout << "weight: " << weight << endl;
    cout << "speed: " << speed << endl;
    cout << "eatsMeat: " << boolalpha << eatsMeat << endl;
    cout << "category: " << char(category) << endl;
}

void createZoo(Animal* animals, int numberOfAnimals) {
    int id = 0;

    for (int i = 0; i < numberOfAnimals; i++) {
        cout << "Animal " << i + 1 << ":" << endl;
        double weight; cin >> weight;
        double speed; cin >> speed;
        bool eatsMeat; cin >> eatsMeat;
        char category; cin >> category;
        while (category != 'o' && category != 'n' && category != 'e' && category != 'c') {
            cout << "Invalid category. Please enter again: "; cin >> category;
        }
        animals[i] = initAnimal(id++, weight, speed, eatsMeat, AnimalCategory(category));
    }
}

Animal heaviestAnimal(Animal* animals, int numberOfAnimals) {
    double maxWeight = animals[0].weight;
    int maxIndex = 0;

    for (int i = 1; i < numberOfAnimals; i++) {
        if (animals[i].weight > maxWeight) {
            maxWeight = animals[i].weight;
            maxIndex = i;
        }
    }

    return animals[maxIndex];
}

Animal fastestAnimal(Animal* animals, int numberOfAnimals) {
    double maxSpeed = animals[0].speed;
    int maxIndex = 0;

    for (int i = 1; i < numberOfAnimals; i++) {
        if (animals[i].speed > maxSpeed) {
            maxSpeed = animals[i].speed;
            maxIndex = i;
        }
    }

    return animals[maxIndex];
}

// print all animals from a given category
void printAnimalsByCategory(Animal* animals, int numberOfAnimals, AnimalCategory category) {
    for (int i = 0; i < numberOfAnimals; i++) {
        if (animals[i].category == category) {
            cout << animals[i].id << " ";
        }
    }
    cout << endl;
}

int main() {
    int numberOfAnimals; cin >> numberOfAnimals;
    Animal *animals = new Animal[numberOfAnimals];

    createZoo(animals, numberOfAnimals);

    delete[] animals;

    return 0;
}