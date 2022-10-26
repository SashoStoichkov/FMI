from playsound import playsound
from abc import ABC, abstractmethod


class Animal(ABC):
    def __init__(self, name):
        self._name = name

    @abstractmethod
    def make_sound(self):
        pass

    def pet(self):
        print(f"Petting {self._name}...")
        self.make_sound()


class Fox(Animal):
    def make_sound(self):
        playsound("fox.mp3")


Fox("Fox").pet()
