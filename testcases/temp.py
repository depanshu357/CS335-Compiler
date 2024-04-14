class foo():
    def __init__(self):
        self.x:int=1
        self.y:int=1

    def prit(self)->None:
        print("Hello")
    
    def temp(self,a:int)->int:
        data : list[int] = [10,9,8,7,6,5,4,3,2,1]
        i:int = data[a] * data[a]
        print(i)
        return i

def main():
    f:foo=foo()
    f.prit()
    i:int=f.temp(5)
    print(i)


