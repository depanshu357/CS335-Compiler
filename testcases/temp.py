class ompho():
    def __init__(self):
        self.y:int=1
    def say_my_name(self)->str:
        return "omphoo"

class foo(ompho):
    def __init__(self):
        self.x:int=1
    def sub(self, a:int, b:int)->int:
        return a-b


class klass(foo):
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
    m:int=k.sub(102,33)
    l:str=k.say_my_name()
    print(m)
    a:str="b"
    b:str="a"
    print(a==b)
    print(a>b)
    print(a<b)
    print(l)
