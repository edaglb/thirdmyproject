#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess, attempts = 0, maxAttempts = 10, score;


    // Rastgele sayı üretmek için
    srand(time(0));
    secretNumber = rand() % 100 + 1;  // 1 ile 100 arasında rastgele sayı

    printf("### SAYI TAHMIN OYUNU ###\n");
    printf("1 ile 100 arasinda bir sayi tuttum. Tahmin et bakalim!\n");

    while (attempts < maxAttempts) {
        printf("Tahminini gir (%d hak kaldi): ", maxAttempts - attempts);
    
        scanf("%d", &guess);
        attempts++;

        if (guess > secretNumber)
            printf("Daha kucuk bir sayi dene!\n");
        else if (guess < secretNumber)
            printf("Daha buyuk bir sayi dene!\n");
        else { 
            score = 100-(10*attempts);
            if(score < 0) score = 0;
            printf("Tebrikler! %d tahminde bildin. 🎉\n", attempts);
            printf("Puanin: %d\n", score);
            return 0;
        }
        if( attempts == 3) {
            printf("Ipucu: Sayi %s\n", (secretNumber %2==0) ?"CIFT" : "TEK");
        }
        if(attempts ==5) {
            printf("Ipucu: Say, %s 25\n", (secretNumber>25) ? "BUYUK" : "KUCUK");
        }
    }

            
   printf("Üzgünüm, deneme hakkin bitti! Dogru sayi: %d idi. \n", secretNumber);

    return 0;
}




