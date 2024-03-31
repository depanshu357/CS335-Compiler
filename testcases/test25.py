# Abstract class representing the Polygon interface
class Polygon():
    def __init__(self):
        self.dim:int = 0  # Class variable for dimension

    def getPolygonArea(self, length:int, breadth:int) -> int:
        return length * breadth

# Class implementing the Polygon interface
class Rectangle(Polygon):
    def __init__(self):  # Constructor to initialize attributes
        self.dim:int = 3

    def getRectangleArea(self, length:int, breadth:int) -> int:
        print("The area of the rectangle is ")
        print(length * breadth)


class Circle(Polygon):
    def __init__(self):  # Constructor to initialize attributes
        self.radius:int = 2

    def getCircleArea(self, radius:int) -> float:
        area:float=3.14*radius*radius
        print("The area of the circle is ")
        print(3.14 * radius * radius)
        return area

    
    def getCircumference(self, radius:int) -> float:
        circ:float=3.14*radius*2
        print("The circumference of the circle is ")
        print(2 * 3.14 * radius)
        return circ

def test():
    r1:Rectangle = Rectangle()  # Call the constructor with a dummy argument
    r1.getRectangleArea(5, 6)
    c1:Circle = Circle()  # Call the constructor with a dummy argument
    c1.getCircleArea(7)
    c1.getCircumference(7)
    print("Done")  # Accessing the class variable

# Main execution
    
def main():
    r1:Rectangle = Rectangle()  # Call the constructor with a dummy argument
    r1.getRectangleArea(5, 6)
    print("Done")  # Accessing the class variable

    c1:Circle = Circle()  # Call the constructor with a dummy argument
    c1.getCircleArea(7)
    c1.getCircumference(7)
    test()
    print("Done")  # Accessing the class variable

if __name__ == "__main__":
    main()
