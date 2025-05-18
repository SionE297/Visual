import py7zr
import io

def modify_text_in_7zip(archive_path, password, file_to_modify, new_content):
    try:
        # Extract the specific file to memory
        with py7zr.SevenZipFile(archive_path, mode='r', password=password) as archive:
            file_content = archive.read([file_to_modify])
            if file_to_modify in file_content:
                original_content = file_content[file_to_modify].read().decode('utf-8')
                print(f"Original content of {file_to_modify}:\n{original_content}")

                # Modify the content
                modified_content = new_content.encode('utf-8')

                # Create a new in-memory archive with the modified content
                in_memory_archive = io.BytesIO()
                with py7zr.SevenZipFile(in_memory_archive, mode='w', password=password) as new_archive:
                    # Add all files except the one to be modified
                    for file in archive.getnames():
                        if file != file_to_modify:
                            file_data = archive.read([file])
                            new_archive.writestr(file, file_data[file].read())
                    # Add the modified file
                    new_archive.writestr(file_to_modify, modified_content)

                # Save the in-memory archive back to disk
                in_memory_archive.seek(0)  # Move to the start of the BytesIO buffer
                with open(archive_path, 'wb') as f:
                    f.write(in_memory_archive.getbuffer())

                print(f"Modified content of {file_to_modify} saved in the archive.")
            else:
                print(f"File {file_to_modify} not found in the archive.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    encrypted_7zip_file = "C:/Users/minyg/OneDrive/Documents/Visual/note.7z"
    file_password = "q3e7q3e7"
    text_file_to_modify = "note.txt"  # Ensure this path is correct
    new_text_content = str(input('New Text Here:'))

    modify_text_in_7zip(encrypted_7zip_file, file_password, text_file_to_modify, new_text_content)
