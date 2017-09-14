#include <stdio.h>
#include <stdlib.h>

/* ************************************
Main Package :
1. Starter pack     $150       1 user
2. pro              $200       2
3 enterprise        $250       5


Add :
1. Add 1 user       $10
2. 100 api call     $5
************************************** */

 struct target { ///Structuring variable
     int angka, checker;
 };

 typedef struct target myStruct; ///Connect structured variable our data type

myStruct input_validator () ///Create a function with our data type to connect with our structure variable
{
    myStruct con;
  char buf[BUFSIZ];
  char *p;
  long int i;
  int v = 0;

  if (fgets(buf, sizeof(buf), stdin) != NULL)
  {
    i = strtol(buf, &p, 10);

    /*
     *  If the first character of the buffer is \n, the user
     *  pressed [Enter] with entering any text at all, which
     *  is therefore invalid.
     *
     *  The pointer p has been updated by strtol() to point to
     *  the first invalid character after the number.
     *  If this character is \0 it means we reached the end of
     *    the array successfully, so we received a good number.
     *  If this character is \n it also means we reached the
     *    end of the input successfully.
     *  If this character is anything else, it means there was
     *    some additional characters entered after the number,
     *    will consider to be invalid.
     */

    if (buf[0] != '\n' && (*p == '\n' || *p == '\0')) {
        v = 1;
    } else {
        v = 2;
    }
  }
  con.angka = i; ///Number that user has been input.
  con.checker = v;///Result after user input has been check by system.
  return(con); ///Returning a structure variable from a function. So, we can get 2 returned value from input_validator
}

void main(void)
{
    int counter = 0, innerCounter = 0, mainPack = 0, additional1 = 0, additional2 = 0, total = 0;
    myStruct result; ///Creating a object of

    ///Main package
    printf("Package                Price        Description\n1.Starter Package      $150         1 User");
    printf("\n2.Pro Package          $200         2 User\n3.Enterprise Package   $250         5 User");

    while (counter < 1){ ///Using While..Do in order to get an appropriate input and right available option. Loop will end when user enter an appropriate input and choose the right available option
        printf("\n\nWhich package number do you want to? : ");
        result = input_validator (); ///Call input_validator function to check user input

        if (result.checker == 1){
            if (result.angka == 1) {
                printf("\nYou Choose: Starter Package");
                mainPack = 150;
                counter = 1; ///key to stop the loop
            } else if (result.angka == 2){
                printf("\nYou Choose: Pro Package");
                mainPack = 200;
                counter = 1; ///key to stop the loop
            } else if (result.angka == 3){
                printf("\nYou Choose: Enterprise Package");
                mainPack = 250;
                counter = 1; ///key to stop the loop
            } else {
                printf ("\nPlease choose package 1, 2, or 3");
            }
        } else {
            printf ("\nInvalid input entered");
        }
    } ///counter = 1

    ///Additional User Selection
    while (counter < 2){ ///Using While..Do in order to get an appropriate input and right available option. Loop will end when user enter an appropriate input and choose the right available option
        printf("\n\nDo you want to add additional user? (Enter '1' if you want, otherwise '0'): ");
        result = input_validator (); ///Call input_validator function to check user input

        if (result.checker == 1) { ///if user enter an appropriate input, then :
            if (result.angka == 1){ ///if user wants to add additional user, then :
                while (innerCounter < 1) { ///Using While..Do in order to get an appropriate input and right available option. Loop will end when user enter an appropriate input and choose the right available option
                    printf("\nAdditional Package 1 -- Add 1 user = $10\nHow many user do you want to add? : ");
                    result = input_validator (); ///Call input_validator function to check user input

                    if (result.checker == 1) { ///if user enter an appropriate input, then :
                        additional1 = result.angka;
                        innerCounter = 1; ///key to stop the loop
                        counter = 2; ///key to stop the loop
                    } else { ///if user enter an INappropriate input, then :
                        printf ("\nInvalid input entered");
                    }
                }
            } else if (result.angka == 0) { ///if user dont want to add additional user
                innerCounter = 1; ///key to stop the loop
                counter = 2; ///key to stop the loop
            }
        } else { ///if user enter an INappropriate input, then :
            printf ("\nInvalid input entered");
        }
    } ///innerCounter = 1, counter = 2


    ///Additional API Call
    while (counter < 3){ ///Using While..Do in order to get an appropriate input and right available option. Loop will end when user enter an appropriate input and choose the right available option
        printf("\n\nDo you want to add additional API Call? (Enter '1' if you want, otherwise '0'): ");
        result = input_validator (); ///Call input_validator function to check user input

        if (result.checker == 1) { ///if user enter an appropriate input, then :
            if (result.angka == 1){ ///if user wants to add additional api call, then :
                while (innerCounter < 2) {///Using While..Do in order to get an appropriate input and right available option. Loop will end when user enter an appropriate input and choose the right available option
                    printf("\nAdditional Package 2 -- 100 API call = $5\nHow many API Call do you want to add? : ");
                    result = input_validator (); ///Call input_validator function to check user input

                    if (result.checker == 1) { ///if user enter an appropriate input, then :
                        if (result.angka >= 100 && result.angka%100 == 0) { ///if user demand api call that greater or equal to 100 AND is a multiple of 100, then :
                            additional2 = result.angka;
                            innerCounter = 2; ///key to stop the loop
                            counter = 3; ///key to stop the loop
                        } else { ///if user demand api call that LESSER than 100 OR is NOT a multiple of 100, then :
                            printf("\n\nMinimum order is 100 API Call and multiple of it.");
                        }
                    } else { ///if user enter an INappropriate input, then :
                        printf ("\nInvalid input entered");
                    }
                }
            } else if (result.angka == 0) { ///if user dont want to add additional API Call
                innerCounter = 2; ///key to stop the loop
                counter = 3; ///key to stop the loop
            }
        } else { ///if user enter an INappropriate input, then :
            printf ("\nInvalid input entered");
        }
    } ///innerCounter = 2, counter = 3

    additional1 *= 10; ///How many additional user is multiply by $10
    additional2 *= 5; ///How many additional API Call is multiply by $5
    total = mainPack + additional1 + additional2; ///Sum all the variable (Main Package + Additional 1 + Additional 2)
    printf("\n\nMain Package: $%d\nAdditional User(s) : $%d\nAdditional API Call : $%d", mainPack, additional1, additional2);
    printf("\nTotal cost: $%d\n\n", total);


    system ("PAUSE");
}
