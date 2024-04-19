class Great_grand_father():
    def __init__(self):
        self.y:int=1
    def get_my_name(self)->str:
        return "Father-1"

class Grand_father(Great_grand_father):
    def __init__(self):
        self.x:int=1
    def sub(self, a:int, b:int)->int:
        return a-b


class Father(Grand_father):
    def __init__(self,x:int,y:int):
        self.z:int = 1

    def mul(self, a:int,b:int) -> int:
        x :int = a * b
        return x

class Son(Father):
    def __init__(self,x:int):
        self.a: int = x

    def level(self) -> int:
        return 3


class temp():
    def __init__(self,x:int):
        self.z:int = x
        
    def increment(self) -> int:
        return self.z+1



def main():
    
    k:Son= Son(12)
    p:int = k.level()
    q:int = k.mul(4,3)
    r:int=k.sub(112,12)
    s:str=k.get_my_name()
    print(p)
    print(q)
    print(r)
    print(s)
    
    a:temp=temp(123)
    z:int = a.increment()
    print(z)
  
