## Functions:
- add_opiton
- box_menu
- option_input
- option_handler

## Mandetory:
```c
struct Menu menu;
menu.num_options = 0;
```
These two lines need to exist in the function before anything else. So best just copy paste it everytime.
### Details
`struct Menu <name>`
this creates the menu with the given name. (Leave the name be menu since its needed later)

`menu.num_options = 0;` this is just here because it messes up the option count otherwise. the `menu` needs to be the name of the menu (as i said leave it as `menu` for the greater good)

## Adding options:
```c
add_option(&menu, "Option text", optionFunction);
```
This is basically how u would add a option to the menu itself to be viewed. 

`&menu` is the name of the menu.

`"Option text"` is the labed that will be shown on the menu.

`optionFunction` this, oh boi, this, it needs to be an empty function put on the bottom of the file with proper naming so that i can go ahead and make the function and move it to a better place. But just for your menu to "work" make an empty function at the bottom of the file. And thn add the function on top of the file. If u open `ui-menu.c` u will see a few already existing. So make an empty function at the very bottom, call the function on top, and thats basically it. (Not making a example function for you to copy paste and just rename for learning purposes.)

## Box Menu:
```c
box_menu(&menu, "Menu Name");
```
this is after ur done adding all the options. This is basically the `printf` for the menu. Should be simple enough

## Option input:
```c
int option = option_input("Enter your option:", &menu);
```
You can name it whatever you want. Its just a input function that will take ur `menu` and handle the available option culling and things. So just treat it as a way to get the option the user selected. The name is needed on the handler, and thats all.

## Option handler:
```c
option_handler(&menu, option, user);
```
This is a bit more complicated to just write down, i will explain it when given the chance. This is as the name suggests the option handler. Basically takes the option and directs to the specific funtion its supposed to (the function in `add_option`). `option` must match the option name you set in option input. For testing purposes you can replace the `user` with `NULL` or just dont use the handler at all. It will still view ur options just wont do anything. Or u can look at the existing code and figure stuff out, learning it from the source itself!

If you choose to keep it to these default values its gonna be easier for you. But you can dabble and make ur own names and try to come up with appropriate names for those things, just make sure the useage of the names are set properly.  