"""
Author: Adamu Muhammad Muhammad
Date: 2024-05-25
Description: input output in C++
"""

import subprocess
import os
import time

# Define color codes
RED = '\033[0;31m'
GREEN = '\033[0;32m'
YELLOW = '\033[1;33m'
BLUE = '\033[0;34m'
NC = '\033[0m' # No Color

def test_main():
    print(f"{BLUE}Starting the build and test process...{NC}")
    
    # Compile the C++ code
    build_dir = os.path.join(os.path.dirname(__file__), '../build')
    src_dir = os.path.join(os.path.dirname(__file__), '../src')
    main_cpp = os.path.join(src_dir, 'main.cpp')
    executable = os.path.join(build_dir, 'main')

    if not os.path.exists(build_dir):
        os.makedirs(build_dir)

    print(f"{YELLOW}Compiling the C++ code ...{NC}")
    compile_command = f"g++ -o {executable} {main_cpp}"
    compile_process = subprocess.run(compile_command, shell=True, capture_output=True, text=True)
    time.sleep(2)  # Simulate waiting time
    
    if compile_process.returncode != 0:
        print(f"{RED}Compilation failed: {compile_process.stderr}{NC}")
        return
    
    print(f"{GREEN}Compilation successful.{NC}")
    
    # Run the compiled executable
    print(f"{YELLOW}Running the program...{NC}")
    run_command = executable
    run_process = subprocess.run(run_command, shell=True, capture_output=True, text=True)
    time.sleep(2)  # Simulate waiting time
    
    if run_process.returncode != 0:
        print(f"{RED}Execution failed: {run_process.stderr}{NC}")
        return
    
    print(f"{GREEN}Execution successful. Program output: {NC}{run_process.stdout.strip()} {GREEN} As Expected{NC}")
    assert run_process.stdout.strip() == "Hello, World!", f"{RED}Unexpected output: {run_process.stdout}{NC}"

if __name__ == "__main__":
    test_main()
