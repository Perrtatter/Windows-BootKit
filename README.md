# Windows-BootKit

## Description 
A bootkit program that you can put on a wndows setup bootable usb key and run it from your key for change password , list user , dump sam base and more :)



## Installation
1) Make a Windows Bootable USB key ( setup ) with tools like Rufus , Balena Etcher or Ventoy

2) Git clone this repository to your usb drive directory



### Usage 
1) Boot on your USB 
2) Press SHIFT+F10 for open command prompt
3) Run "wmic logicaldisk get name" to list disk
3) Run "[DRIVE_LETTER]:" to go in your disk
5) Go to your git clone directory
6) Run executable
7) Enjoy ;)

