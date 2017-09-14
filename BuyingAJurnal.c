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

int main (void)
{

//initializer_list *******************
char buf[BUFSIZ];
char *p;
long int mainPack = 0, addPack1 = 0, addPack1a = 0, addPack2 = 0, addPack2a = 0;
int counter = 0, counter2 = 0, orderMainPack, orderAddPack1, orderAddPack2, k1 = 10, k2 = 5;
//************************************

//algo

    printf("Package                Price        Description\n1.Starter Package      $150         1 User");
    printf("\n2.Pro Package          $200         2 User\n3.Enterprise Package   $250         5 User");

    ///Main package section
    while (counter < 1)
    {
        printf("\nWhich package number do you want to? : ");
        if (fgets(buf, sizeof(buf), stdin) != NULL) {
            mainPack = strtol(buf, &p, 10);

            if (buf[0] != '\n' && (*p == '\n' || *p == '\0')) {
                if (mainPack == 1){
                    printf("\nYou Choose: Starter Package");
                    mainPack = 150;
                    counter = 1;
                }
                else if (mainPack == 2) {
                    printf("\nYou Choose: Pro Package");
                    mainPack = 200;
                    counter = 1;
                }
                else if (mainPack == 3 ){
                    printf("\nYou Choose: Enterprise Package");
                    mainPack = 250;
                    counter = 1;
                }
                else {
                    printf ("\nPlease choose package 1, 2, or 3");
                }
            }
            else {
                printf ("\nInvalid input entered");
            }
        }
    }

    ///Additional User section
    while (counter < 2)
    {
        printf("\n\nDo you want to add additional user? (Enter '1' if you want, otherwise '0'): ");
        if (fgets(buf, sizeof(buf), stdin) != NULL) {
            addPack1 = strtol(buf, &p, 10);

            if (buf[0] != '\n' && (*p == '\n' || *p == '\0')) {
                if (addPack1 == 1){
                    while (counter2 < 1) {
                        printf("\nAdditional Package 1 -- Add 1 user = $10\nHow many user do you want to add? : ");
                        if (fgets(buf, sizeof(buf), stdin) != NULL) {
                                addPack1a = strtol(buf, &p, 10);

                                if (buf[0] != '\n' && (*p == '\n' || *p == '\0')) {
                                    counter2 = 1;
                                    counter = 2;
                                } else {
                                    printf ("\nInvalid input entered");
                                }
                        } else {
                                printf ("\nInvalid input entered");
                        }
                    }
                } else if (addPack1 == 0) {
                    counter2 = 1;
                    counter = 2;
                } else {
                    printf ("Invalid input entered");
                }
            } else {
                printf ("Invalid input entered");
            }
        } else {
            printf ("Invalid input entered");
        }
    }

    ///Additional API section
    while (counter < 3)
    {
        printf("\n\nDo you want to add additional API Call? (Enter '1' if you want, otherwise '0'): ");
        if (fgets(buf, sizeof(buf), stdin) != NULL) {
            addPack2 = strtol(buf, &p, 10);

            if (buf[0] != '\n' && (*p == '\n' || *p == '\0')) {
                if (addPack2 == 1){
                    while (counter2 < 2) {
                        printf("\nAdditional Package 2 -- 100 API call = $5\nHow many API Call do you want to add? : ");
                        if (fgets(buf, sizeof(buf), stdin) != NULL) {
                                addPack2a = strtol(buf, &p, 10);
                                if (buf[0] != '\n' && (*p == '\n' || *p == '\0')) {
                                    if (addPack2a >= 100 && addPack2a == 0) {
                                        counter2 = 2;
                                        counter = 3;
                                    } else {
                                    printf("\n\nMinimum order is 100 API Call and multiple of it.");
                                    }
                                } else {
                                printf ("\nInvalid input entered");
                                }
                        } else {
                            printf ("\nInvalid input entered");
                        }
                    }
                } else if (addPack1 == 0) {
                    counter2 = 2;
                    counter = 3;
                } else {
                    printf ("Invalid input entered");
                }
                } else {
                    printf ("Invalid input entered");
                }
            } else {
                printf ("Invalid input entered");
            }
        }

    orderMainPack = (int) mainPack;
    orderAddPack1 = (int) addPack1a;
    orderAddPack2 = (int) addPack2a;
    printf("\n\norderAddPack1 : $%d \n\n", orderAddPack1);
    printf("\n\nYour total order is : $%ld \n\n", (orderMainPack) + (orderAddPack1*k1) + (orderAddPack2*k2));
    printf("\n\nmPack: %d\naddPack1a: %d\naddPack2a: %d\n\n", orderMainPack*k1, orderAddPack1, orderAddPack2);
    system ("PAUSE");
    }
