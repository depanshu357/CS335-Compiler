# Test Case: Explicit Type Casting

# Function to calculate the area of a rectangle
def calculate_rectangle_area(length: float, width: float) -> float:
    # Explicitly casting length and width to float
    area: float = length * width
    return area

# Test the function with sample inputs
if __name__ == "__main__":
    # Test 1: Positive integer values
    length1: float = 5
    width1: float = 4.5
    area1: float = calculate_rectangle_area(length1, width1)
    print(f"Test 1: The area of rectangle with length {length1} and width {width1} is {area1}")

    # Test 2: Float values
    length2: float = 10.5
    width2: float = 3.2
    area2: float = calculate_rectangle_area(length2, width2)
    print(f"Test 2: The area of rectangle with length {length2} and width {width2} is {area2}")

    # Test 3: Negative integer values
    length3: float = -8
    width3: float = 6.3
    area3: float = calculate_rectangle_area(length3, width3)
    print(f"Test 3: The area of rectangle with length {length3} and width {width3} is {area3}")

    # Test 4: Zero values
    length4: float = 0
    width4: float = 0
    area4: float = calculate_rectangle_area(length4, width4)
    print(f"Test 4: The area of rectangle with length {length4} and width {width4} is {area4}")

    # Test 5: Large integer values
    length5: float = 1000000
    width5: float = 0.0001
    area5: float = calculate_rectangle_area(length5, width5)
    print(f"Test 5: The area of rectangle with length {length5} and width {width5} is {area5}")

    # Test 6: Large float values
    length6: float = 999999.999
    width6: float = 0.000000001
    area6: float = calculate_rectangle_area(length6, width6)
    print(f"Test 6: The area of rectangle with length {length6} and width {width6} is {area6}")
