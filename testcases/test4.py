

def factorial(n:int)->int:
    if n <= 1:
        return 1
    else:
        return n*factorial(n-1)


def fibonacci(n:int)->int:
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

def power_mod(n:int,p:int,m:int)->int:
    if p == 0:
        return 1
    h:int = power_mod(n,p//2,m)
    
    if p%2 == 0:
        h = (h*h)%m
    else:
        h = ((h*h)%m * n)%m
    
    return h


def main():
    # Fibonacci code
    fib_number1:int = fibonacci(9)
    fib_number2:int = fibonacci(10)
    fib_number3:int = fibonacci(11)
    print(fib_number1)    
    print(fib_number2)
    print(fib_number3)
    # Correct answer: 34, 55, 89
    if(fib_number1 == 34 and fib_number2 == 55 and fib_number3 == 89):
        print("Fibonacci test passed")
    else:
        print("Fibonacci test failed")
    
    if(fib_number3 == fib_number2 + fib_number1):
        print("Fibonacci test passed")
    else:
        print("Fibonacci test failed")
    
    # factorial tests
    factorial_number1: int = factorial(3)
    factorial_number2: int = factorial(4)
    factorial_number3: int = factorial(5)
    print(factorial_number1)
    print(factorial_number2)
    print(factorial_number3)

    if (factorial_number1 == 6 and factorial_number2 == 24 and factorial_number3 == 120):
        print("Factorial test passed")
    else:
        print("Factorial test failed")

    # power_mod tests
    power_number1: int = power_mod(2, 10, 1000)
    power_number2: int = power_mod(2, 20, 1000)
    print(power_number1)
    print(power_number2)

if __name__ == "__main__":
    main()
