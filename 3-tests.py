import random
import os

def generate_test_case():
    n = random.randint(1, 1000)  # n can be up to 1000
    m = random.randint(1, 1000)  # m can be up to 1000
    k = random.randint(1, 100)  
    grid = [[random.choice([0, 1]) for _ in range(m)] for _ in range(n)]
    return n, m, k, grid

def save_test_cases_to_folder(num_files, max_cells, folder_path):
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)
    
    for file_index in range(1, num_files + 1):
        test_cases = []
        total_cells = 0
        
        while total_cells < max_cells:
            n, m, k, grid = generate_test_case()
            test_cases.append((n, m, k, grid))
            total_cells += n * m
        
        # Save the test cases to a file
        file_name = f"test_file_{file_index}.txt"
        file_path = os.path.join(folder_path, file_name)
        
        print('writing to file')
        with open(file_path, 'w') as f:
            f.write(f"{len(test_cases)}\n")  # Number of test cases in this file
            for _ in range(len(test_cases)):
                n, m, k, grid = test_cases[_]
                f.write(f"{n} {m} {k}\n")
                for row in grid:
                    f.write(' '.join(map(str, row)) + '\n')

# Configuration
num_files = 10  # Number of files to generate
max_cells_per_file = 200_000  # Maximum total cells in any single file
folder_path = "./tests/test3"  # Folder to store the test cases

# Generate and save test cases
save_test_cases_to_folder(num_files, max_cells_per_file, folder_path)

print(f"Test cases have been saved to the folder: {folder_path}")
