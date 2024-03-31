def is_code_line(line):
  """Checks if a line is code (not a comment or empty line)."""
  line = line.strip()  # Remove leading/trailing whitespace
  if not line:  # Empty line
    return False
  # Check for single-line comments (language-specific adjustments needed)
  if line.startswith("//") or line.startswith("#"):  # Example comment styles
    return False
  return True

def count_code_lines(filename):
  """Counts lines of code in a file."""
  code_count = 0
  with open(filename, 'r') as file:
    for line in file:
      if is_code_line(line):
        code_count += 1
  return code_count

# Example usage
filename = "my_code.py"
code_lines = count_code_lines(filename)
print(f"Number of code lines in {filename}: {code_lines}")
