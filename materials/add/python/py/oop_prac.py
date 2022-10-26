from math import pi


class Rectangle:
    def __init__(self, length, width, color):
        self._length = length
        self._width = width
        self._color = color

    def __str__(self):
        return "This is a {} rectangle with a length of {} and a width of {}.".format(
            self._color, self._length, self._width
        )

    @property
    def length(self):
        return self._length

    @length.setter
    def length(self, new_length):
        self._length = new_length

    @property
    def width(self):
        return self._width

    @width.setter
    def width(self, new_width):
        self._width = new_width

    @property
    def color(self):
        return self._color

    @color.setter
    def color(self, new_color):
        self._color = new_color

    def area(self):
        return self._length * self._width

    def perimeter(self):
        return 2 * (self._length + self._width)


class Circle:
    def __init__(self, radius, color):
        self._radius = radius
        self._color = color

    def __str__(self):
        return "This is a {} circle with a radius of {}.".format(
            self._color, self._radius
        )

    @property
    def radius(self):
        return self._radius

    @radius.setter
    def radius(self, new_radius):
        self._radius = new_radius

    @property
    def color(self):
        return self._color

    @color.setter
    def color(self, new_color):
        self._color = new_color

    def area(self):
        return pi * self._radius**2

    def perimeter(self):
        return 2 * pi * self._radius


class Shapes:
    def __init__(self):
        self._shapes = []

    def __str__(self):
        return "This is a collection of shapes."

    def add_shape(self, shape):
        self._shapes.append(shape)

    def total_area(self, shape_type=None):
        total_area = 0
        for shape in self._shapes:
            if type(shape) == shape_type or shape_type == None:
                total_area += shape.area()
        return total_area

    def total_perimeter(self, shape_type=None):
        total_perimeter = 0
        for shape in self._shapes:
            if type(shape) == shape_type or shape_type == None:
                total_perimeter += shape.perimeter()
        return total_perimeter


# if __name__ == "__main__":
#     shapes = Shapes()
#     shapes.add_shape(Rectangle(5, 10, "blue"))
#     shapes.add_shape(Circle(5, "red"))
#     shapes.add_shape(Rectangle(2, 3, "green"))
#     shapes.add_shape(Circle(3, "purple"))

#     print(shapes.total_area())
#     print(shapes.total_area(Rectangle))
#     print(shapes.total_area(Circle))
#     print(shapes.total_perimeter())

#     print(shapes)

# =============================================================================

from abc import ABC, abstractmethod


class ACounter(ABC):
    def __init__(self, initial, step):
        self._total = initial
        self.__step = step

    def __str__(self):
        return "This is a counter with a count of {}.".format(self._total)

    @abstractmethod
    def increment(self):
        pass

    @abstractmethod
    def decrement(self):
        pass

    @property
    def total(self):
        return self._total

    @property
    def step(self):
        return self.__step


class Counter(ACounter):
    def __init__(self, initial, step):
        super().__init__(initial, step)

    def increment(self):
        self._total += self.step

    def decrement(self):
        pass


class TwoWayCounter(Counter):
    def __init__(self, initial, step):
        super().__init__(initial, step)

    def decrement(self):
        self._total -= self.step


class LimitedCounter(Counter):
    def __init__(self, initial, step, max):
        super().__init__(initial, step)
        self._max = max

    def increment(self):
        if self._total + self.step <= self._max:
            super().increment()

    @property
    def max(self):
        return self._max


class LimitedTwoWayCounter(LimitedCounter, TwoWayCounter):
    def __init__(self, initial, step, max, min):
        super().__init__(initial, step, max)
        self._min = min

    def decrement(self):
        if self._total - self.step >= self._min:
            super().decrement()

    @property
    def min(self):
        return self._min


if __name__ == "__main__":
    # counter = Counter(0, 1)
    # counter.increment()
    # print(counter.total)
    # counter.increment()
    # print(counter.total)

    # twowaycounter = TwoWayCounter(0, 1)
    # twowaycounter.increment()
    # print(twowaycounter.total)
    # twowaycounter.decrement()
    # print(twowaycounter.total)

    # limitedcounter = LimitedCounter(0, 1, 5)
    # for i in range(6):
    #     limitedcounter.increment()
    #     print(limitedcounter.total)

    limitedtwowaycounter = LimitedTwoWayCounter(0, 1, 5, -5)

    for i in range(6):
        limitedtwowaycounter.increment()
        print(limitedtwowaycounter.total)

    for i in range(12):
        limitedtwowaycounter.decrement()
        print(limitedtwowaycounter.total)

    print(limitedtwowaycounter.max)
