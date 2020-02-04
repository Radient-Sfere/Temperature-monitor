double G_TMP = 8.5;
/* temperature */
bool binswitch;
/*bin switch, when off shows the dec*/
char G_TMP_STR[16];
/* the temperature's string         */
char G_TMP_STR_DEC[16];
/* the temperature's string decimal */

/*
 *Char dec to binary changes the values within a char* AND returns it
 *hence the *char type. DON'T USE ON LONGER THINGS LONGER THAN 10 BITS
 */
char* decToBinary(unsigned short n, char *str)
{
        for (int i = 10; i >= 0; i--) {
                int k = n >> i;
                if (k & 1)
                        str[i] = 49;
                else
                        str[i] = 48;
        }
        return str;
}
/*PrintsChartoPtr, by recursively going. Don't use this on non Chars*/
void print(char *str)
{
        for (int i = 9; i >= 0; i--)
                digitalWrite(i, str[i] == '1' ? HIGH : LOW);
}


void setup() {
    for(int i = 10; i>0; --i)
        pinMode(i,OUTPUT);
    pinMode(11, INPUT);
}

void loop() {


G_TMP = analogRead(A0);
binswitch = digitalRead(11);
    decToBinary(binswitch ? G_TMP : (int)(G_TMP * 1000) % 1000, binswitch ? G_TMP_STR : G_TMP_STR_DEC);
    print(binswitch ? G_TMP_STR : G_TMP_STR_DEC);
}