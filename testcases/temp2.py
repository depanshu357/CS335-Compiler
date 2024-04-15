class Test:
    def __init__(self):
        self.a:int = 1

    def add(self,  b:int)->int:
        x:int = self.a +b
        return x


                

def main():
    
     # Expression 1
    print("Result of expression 1:")
    x:int=4+3-2
    print(x)  # Correct answer: 5

    # Expression 2
    print("\nResult of expression 2:")
    x=3*4-2
    print(x)  # Correct answer: 10

    # Expression 3
    print("\nResult of expression 3:")
    x=10/2/5
    print(x)  # Correct answer: 1.0

    # Expression 4
    print("\nResult of expression 4:")
    x=2**3**2
    print(x)  # Correct answer: 512

    # Expression 5
    print("\nResult of expression 5:")
    x=2+3*4
    print(x)  # Correct answer: 14

    # Expression 6
    print("\nResult of expression 6:")
    x=(2+3)*4
    print(x)  # Correct answer: 20

    # Expression 7
    print("\nResult of expression 7:")
    x=10-5+3
    print(x)  # Correct answer: 8

    # Expression 8
    print("\nResult of expression 8:")
    x=8%5%2
    print(x)  # Correct answer: 8

    # arr:list[int] = [64, 34, 25, 12, 22, 11, 90]
    # t1:Test = Test()
    # t2:Test = Test()
    # arr:list[Test]=[t1,t2]
    # i:Test = Test()
    # j:int = 0
    # # for i in arr:
    # j = i.add(1)
    # print(j)



