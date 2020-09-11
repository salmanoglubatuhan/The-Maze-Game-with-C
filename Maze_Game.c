#include <stdio.h>

char ARRaraund[50][50];
int SA2, SU2;
int cashcounter = 0;
void printfunc(int satir, int sutun)
{
    int i, u;
    for (i = 0; i <= (satir - 1); i++)
    {
        for (u = 0; u <= (sutun - 1); u++)
        {
            printf("%c", ARRaraund[i][u]);
        }
        printf("\n");
    }
    printf("\n");
}
int FUNC(char *pointarr, char *pointarr2, int satir, int sutun)
{
    int c = 0;
    if (*pointarr == '*')
    {
        printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
        c = 2;
        printfunc(satir, sutun);
    }
    else if (*pointarr == 'X')
    {
        printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
        printfunc(satir, sutun);
        c = 0;
    }
    else if (*pointarr == '$')
    {
        printf("YOU GOT 1 $.\n");
        *pointarr = 'O';
        *pointarr2 = ' ';
        cashcounter++;
        c = 1;
    }
    else if (*pointarr == ' ')
    {
        *pointarr = 'O';
        *pointarr2 = ' ';
        c = 1;
    }
    return c;
}

int main()
{
    int satir, sutun, satirsayac = 0, sutunsayac = 0, i, u, c = 1, d = 1, SA, SU, SA1, SU1, control = 1, h, SA2, SU2;

    char opr, k, l;
    char *pointarr;
    scanf("%d %d", &satir, &sutun);

    while (satirsayac < satir)
    {
        if (satirsayac == 0)
        {
            while (sutunsayac < sutun)
            {
                ARRaraund[satirsayac][sutunsayac] = '*';
                sutunsayac++;
            }
        }
        else if (satirsayac == (satir - 1))
        {
            while (sutunsayac < sutun)
            {
                ARRaraund[satirsayac][sutunsayac] = '*';
                sutunsayac++;
            }
        }
        else
        {
            sutunsayac = 0;
            while (sutunsayac < sutun)
            {
                if (sutunsayac == 0)
                {
                    ARRaraund[satirsayac][sutunsayac] = '*';
                    sutunsayac++;
                }
                else if (sutunsayac == (sutun - 1))
                {
                    ARRaraund[satirsayac][sutunsayac] = '*';
                    sutunsayac++;
                }
                else
                {
                    ARRaraund[satirsayac][sutunsayac] = ' ';
                    sutunsayac++;
                }
            }
        }
        sutunsayac = 0;
        satirsayac++;
    }

    scanf("%c", &opr);
    while (opr != 'e')
    {
        switch (opr)
        {
        case 's':
            scanf("%d %d", &SA1, &SU1);
            ARRaraund[SA1][SU1] = 'O';
            break;
        case 'f':
            scanf("%d %d", &SA2, &SU2);
            ARRaraund[SA2][SU2] = ' ';
            break;
        case '$':
            scanf("%d %d", &SA, &SU);
            ARRaraund[SA][SU] = '$';
            break;
        case 'b':
            scanf("%d %d", &SA, &SU);
            ARRaraund[SA][SU] = '*';
            break;
        case 'X':
            scanf("%d %d", &SA, &SU);
            ARRaraund[SA][SU] = 'X';
            break;
        }
        scanf(" %c", &opr);
    }
    scanf("%c%c", &k, &l);
    printfunc(satir, sutun);
    while ((scanf("%c", &opr) != EOF) && (control == 1))
    {
        h = 2;
        switch (opr)
        {
        case 'u':
            h = FUNC(&ARRaraund[SA1 - 1][SU1], &ARRaraund[SA1][SU1], satir, sutun);
            if (h == 1)
            {
                SA1 = SA1 - 1;
                 if ((SA1 == SA2) && (SU1 == SU2))
                    { printf("CONGRATS! YOU GOT %d BONUS:)\n", cashcounter);
                   control=0;}
                printfunc(satir, sutun);
            }
            if (h == 0)
                control = 0;
            break;
        case 'd':
            h = FUNC(&ARRaraund[SA1 + 1][SU1], &ARRaraund[SA1][SU1], satir, sutun);
            if (h == 1)
            {
                SA1 = SA1 + 1;
                if ((SA1 == SA2) && (SU1 == SU2))
                    { printf("CONGRATS! YOU GOT %d BONUS:)\n", cashcounter);
                   control=0;}
                printfunc(satir, sutun);
            }
            if (h == 0)
                control = 0;
            break;
        case 'r':
            h = FUNC(&ARRaraund[SA1][SU1 + 1], &ARRaraund[SA1][SU1], satir, sutun);
            if (h == 1)
            {
                SU1 = SU1 + 1;
                if ((SA1 == SA2) && (SU1 == SU2))
                    { printf("CONGRATS! YOU GOT %d BONUS:)\n", cashcounter);
                   control=0;}
                printfunc(satir, sutun);
            }
            if (h == 0)
                control = 0;
            break;
        case 'l':
            h = FUNC(&ARRaraund[SA1][SU1 - 1], &ARRaraund[SA1][SU1], satir, sutun);
            if (h == 1)
            {
                SU1 = SU1 - 1;
                if ((SA1 == SA2) && (SU1 == SU2))
                   { printf("CONGRATS! YOU GOT %d BONUS:)\n", cashcounter);
                   control=0;}
                printfunc(satir, sutun);
            }
            if (h == 0)
                control = 0;
            break;
        case 'q':
            control = 2;
            break;
        }
    }
    if ((SA1 == SA2) && (SU1 == SU2))
    {
    }
    else if (control > 0)
    {
        printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
        printfunc(satir, sutun);
    }
    return 0;
}