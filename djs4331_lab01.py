# Name- Darshil Jigneshkumar Shah
# ID-1002084331
# Language Used: Python 3.11.4
# Os used:Windows


import os

def djs4331_total_size(location):
    djs4331_totalSize = 0
    doc = os.listdir(location)  # List all files in the specified location
    for item in doc:
        path = os.path.join(location, item)  # Get the full path of the files
        if os.path.isfile(path): 
            djs4331_totalSize += os.path.getsize(path)  # Add the file size to the total size
        elif os.path.isdir(path):  # Check if the files is a folder
            djs4331_totalSize += djs4331_total_size(path)  # Recursively calculate the total size of the subfolder
        else:
            print('The folder is empty')  # error message files is neither a folder 
    return djs4331_totalSize


current_location = os.getcwd()

# Calculate the total size of all files in the current folder and its subfolder
djs4331_totalSize = djs4331_total_size(current_location)

# Print the total size
print('Total size of all files in {} and its sub-folders: {} bytes'.format(current_location, djs4331_totalSize))
