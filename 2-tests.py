import random
import os

def generate_random_test_case():
    n = random.randint(1, 200000)  # Random n
    arr = [random.randint(1, min(1000000, n)) for _ in range(n)]   
    return n, arr

def save_test_cases_to_folder(num_files, folder_path):
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)
    
    
    for file_index in range(1, num_files + 1):
        file_name = f"test_file_{file_index}.txt"
        file_path = os.path.join(folder_path, file_name)
        
        test_cases = []
        total_n = 0
        
        while total_n < 200000:
            n, arr = generate_random_test_case()
            print('genrated')
            test_cases.append((n, arr))
            total_n += n
        
                
        with open(file_path, 'w') as f:
            f.write(f"{len(test_cases)}\n")  # Write the number of test cases in this file
            for _ in range( len(test_cases)):
                n, arr = test_cases[_]
                f.write(f"{n}\n")
                f.write(' '.join(map(str, arr)) + '\n')

            

# Configuration
num_files = 10  
folder_path = "./tests/test2" 

# Generate and save test cases
save_test_cases_to_folder(num_files, folder_path)

print(f"Test cases have been saved to the folder: {folder_path}")
