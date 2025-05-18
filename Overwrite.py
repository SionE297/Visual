import os

def modify_script():
    script_name = os.path.basename(__file__)
    new_line = "\nprint('This line was added by the script itself!')\n"
    
    with open(script_name, 'a') as file:
        file.write(new_line)

print("Original script execution.")
modify_script()
print('This line was added by the script itself!')

print('This line was added by the script itself!')
