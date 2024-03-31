number_of_students: int = 30
average_score: float = 85.5
top_student_name: str = "John Doe"
student_ids: list[int] = [1001, 1002, 1003, 1004, 1005]


def sum_of_squares(n: int) -> int:
    total: int = 0
    i:int = 0
    for i in range(1, n + 1):
        total += i ** 2
    return total

def is_prime(num: int) -> bool:
    if num <= 1:
        return False
    i:int = 0
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

def count_primes_up_to_n(n: int) -> int:
    count: int = 0
    i:int = 0
    for i in range(2, n + 1):
        if is_prime(i):
            count += 1
    return count
def main():
    sum_of_squares_result: int = sum_of_squares(5)
    count_primes_result: int = count_primes_up_to_n(10)

    if sum_of_squares_result == 55:
        print("Sum of squares test passed!")
    else:
        print("Sum of squares test failed!")

    if count_primes_result == 4:
        print("Count primes test passed!")
    else:
        print("Count primes test failed!")

if __name__=="__main__":
    a:int=0
    b:int=0
    z:int=a*b
    main()
