# Portable Executable(PE) File Header Fields Printer
* Requires `MSVC C Compiler`   
* Usage : `test.exe example.exe`
* In 32 and 64 bit PE files only followings are different
  1. `BaseOfCode` there is no such a field in 64 bit PE file, instead it is in 32 bit PE file.
  2. `ImageBase` This field 8 bytes in 64 bit PE file, 4 byte in 32 bit PE file (right after `BaseOfCode`). 
  3. `SizeOfStack/Heap/Reserve/Commit` fields are 8 bytes in PE32+ , 4 bytes in PE32
  
# Rust Compiled(linked with MSVC) Example PE File :
<img width="484" height="376" alt="image" src="https://github.com/user-attachments/assets/2953b015-caad-4703-b4c8-7fa9d8b9b7f0" />
<img width="648" height="445" alt="image" src="https://github.com/user-attachments/assets/581f1bb2-0c86-4c3b-974e-aa4d8d4f8328" />
<img width="492" height="391" alt="image" src="https://github.com/user-attachments/assets/7657ce10-4dc0-47d4-b96c-1b4fdb378152" />

