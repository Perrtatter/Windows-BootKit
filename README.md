# Windows-RootKit v1.4

## Description 


/!\ THE ONLY THING YOU CAN TO IN SETUP MODE IS "Replace sethc.exe to cmd.exe" ( but you can reboot , presse muli time SHIFT and reload script for use full features ) /!\



## Installation
1) Make a Windows Bootable USB key ( setup ) with tools like Rufus , Balena Etcher or Ventoy

2) Git clone this repository to your usb drive directory



### Usage 
1) Boot on your USB 
2) Press SHIFT+F10 for open command prompt
3) Run "wmic logicaldisk get name" to list disk
3) Run "[DRIVE_LETTER]:" to go in your disk
5) Go to your git clone directory
6) Run "start bootkit-v1.4.exe"
7) Enjoy ;)

### Exemple of usage 
1) Boot on disk 
2) Choose option "1"
3) Reboot 
4) Presse many time SHIFT of login screen 
5) Run "wmic logicaldisk get name" to list disk
6) Run "[DRIVE_LETTER]:" to go in your disk
7) Go to your git clone directory
8) Run "start bootkit-v1.4.exe"
9) List users , change password and dump sam base 


