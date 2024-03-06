////////////////////////  VIM
/*
User-Specific Configuration (Recommended):

1) create VIM settings file using: "nano ~/.vimrc". 
    Include in it the desired settings:
        -set number
        -set syntax=on
        -set mouse=a

2) Go to:   "~/.vimrc" for Unix/Linux

3) Access without permissions, you can use SUDO: 
    "sudo nano ~/.vimrc"
    
4) Change permissions:
    "chmod u+w ~/.vimrc"

5) Check ownership:
    "sudo chown your_username:your_username ~/.vimrc"

*/


/*-----------------------   VIM SETTING FILE commands

-->  setup CLIPBOARD:
:set clipboard=unnamedplus

Syntax Highlighting:
:set syntax=on or set syntax=off: Enable or disable syntax highlighting.

Line Numbers:
:set number or set nonumber: Show or hide line numbers in the left margin.
:set relativenumber

Auto Indentation:
:set autoindent or set noautoindent: Enable or disable auto-indentation.

Tabstop and Indentation:
:set tabstop=n: Set the number of spaces for a tab character (replace 'n' with the desired number).
:set expandtab or set noexpandtab: Use spaces instead of tabs for indentation.
:set shiftwidth=n: Set the number of spaces to use for each level of shift (replace 'n' with the desired number).

Search Options:
set ignorecase or set noignorecase: Perform case-insensitive search.
set smartcase or set nosmartcase: Use case-insensitive search unless an uppercase letter is used in the search pattern.

Highlight Search Results:
:set hlsearch or set nohlsearch: Highlight or remove search results highlighting.

Mouse Support:
:set mouse=a or set mouse=: Enable or disable mouse support.

Backup Files:
:set backup or set nobackup: Create backup files when saving.

Autocommands:
:set autocommand or set noautocommand: Enable or disable autocommands, which are scripts that run automatically in response to specific events.

Text Wrapping:
:set wrap or set nowrap: Enable or disable text wrapping.

Line Wrapping:
:set linebreak or set nolinebreak: Enable or disable line wrapping (soft wrapping).

Clipboard Integration:
:set clipboard=unnamedplus: Integrate Vim with the system clipboard for copy and paste operations.

*/




/////////////////////// VIM shortcuts
/*
v - enters visual mode, then select the desired text and proceed with the following options:
y - yanks (copies) the selected text.
d - deletes (cuts) the selected text.
P - pastes before the cursor.
p - pastes after the cursor.
u - undo
crtl + r  - redo 

*/
