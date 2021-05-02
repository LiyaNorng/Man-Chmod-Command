/*
 PC0301
 Use the chmod system call to write your own version of the chmod command.  The program should accept two command-line arguments, the name of a file, and the octal value for setting the permissions for the file.
 
 The program should display an appropriate message if the file does not exist, or the command is invoked with the wrong number of arguments.
 
 
 Hw Assignment #3
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>


void show_stat_info(char * fileName, int);

int main( int ac, char* av[] )
{
    struct stat info;
    int mode = -1;
    mode = atoi (av[1]);    
    if (ac > 2)
    {
        if( chmod (av[2], mode) != -1 )
        {
            if (mode > -1)
            {
                show_stat_info(av[2] , mode);
            }
            else
            {
                printf("%s is a bad value. Try some other value higher or equal to 0.\n", av[1] );
            }
        }
        else
        {
            printf("%s: cannot access '", av[0] );
            printf("%s'", av[2]);
            printf("\n");
            perror(av[2]);
        }
    }
    else
    {
        printf("%s: missing operand\n", av[0]);
        printf ("Try '");
        printf( "%s --help' for more information.\n", av[0]);
    }
    return (0);
}

void show_stat_info( char * fileName, int modeSwitch)
{
    if (modeSwitch > -1)
    {
        int result = chmod (fileName, modeSwitch);
    }
}



