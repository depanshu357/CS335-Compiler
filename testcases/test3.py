class Klass():
    def __init__(self, value:int):
        self.value:int = value
    def get_value(self)->int:
        return self.value
    def add_value(self, value:int)->int:
        return self.value + value
    def sub_value(self, value:int)->int:
        return self.value - value

def main()->None:
    obj1:Klass = Klass(10)
    obj2:Klass = Klass(20)
    
    print("obj1 value:")
    val:int = obj1.get_value()
    print(val)

    sum:int = obj1.add_value(5)
    print("obj1 value after adding 5:")
    print(sum)

    diff:int = obj1.sub_value(5)
    print("obj1 value after subtracting 5:")
    print(diff)

    total:int = obj1.add_value(15) + obj2.add_value(25)
    print("Total sum of obj1 and obj2:")
    print(total)


if __name__ == "__main__":
    main()
