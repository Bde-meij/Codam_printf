Recreation of the printf function in c from scratch

to try the program, first run "make" (needs bash, use git bash if on windows)
if ready, run the program with "./testprint"

to try different arguments and combinations, edit the "main.c" file and 
afterwards run "make re" to recompile

arguments are:
%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.
