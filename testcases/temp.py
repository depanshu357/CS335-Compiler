class klass():
    def __init__(self,x:int):
        self.a: int = 1
        self.b: int = 2

    def add(self) -> None:
        x :int = self.a + self.b
        print(x)
        return 

class temp():
    def __init__(self,x:int):
        self.z:int = x
        

    def sub(self) -> int:
        print(self.z)
        return 3



def main():
    z:temp=temp(123)
    k:klass = klass(2)
    # print(z)
    w:int = z.sub()
    k.add()
