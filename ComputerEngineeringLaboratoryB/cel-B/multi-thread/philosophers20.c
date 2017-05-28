#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define PHILOSOPHERS 20

pthread_mutex_t chopsticks[PHILOSOPHERS];
int philosophers_status[PHILOSOPHERS] = {0};
int chopsticks_status[PHILOSOPHERS] = {0};
int number[PHILOSOPHERS];

/*
 * philosopher関数
 */
void *philosopher(void *num)
{
    int id;
    int i;
    int status;

    /*** 哲学者の番号 ***/
    id = *(int *)(num);

    /*** 無限ループ ***/
    while (1) {

        /*** 1秒以上5秒以下の時間待つ。 ***/
        sleep(rand() % 5 + 1); 

        /*** 哲学者は自分の左側の箸を確保する。 ***/
        status = pthread_mutex_lock(&chopsticks[id]);

        /*** 哲学者が自分の左側の箸を取れなかった時の処理 ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot lock a mutex.\n");
            exit(EXIT_FAILURE);
        }

        /*** 箸は哲学者に確保された。 ***/
        chopsticks_status[id] = 1;
 
        /*** 哲学者は自分の右側の箸を確保する。 ***/
        status = pthread_mutex_lock(&chopsticks[(id + 1) % PHILOSOPHERS]);

        /*** 哲学者が自分の右側の箸を取れなかった時の処理 ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot lock a mutex.\n");
            exit(EXIT_FAILURE);
        }

        /*** 箸は哲学者に確保された。 ***/
        chopsticks_status[(id + 1) % PHILOSOPHERS] = 1;

        /*** 哲学者は食事を始める。 ***/
        philosophers_status[id] = 1;

        /*** 哲学者の状態を表示する。 ***/
        for (i = 0; i <= PHILOSOPHERS - 1; i++) {
            printf("%d", philosophers_status[i]);
        }

        /*** スペースを表示 ***/
        printf("  ");

        /*** 箸の状態を表示する。 ***/
        for (i = 0; i <= PHILOSOPHERS - 1; i++) {
            printf("%d", chopsticks_status[i]);
        }

        /*** 改行 ***/
        printf("\n");

        /*** 1秒以上10秒以下の時間待つ。 ***/
        sleep(rand() % 10 + 1);

        /*** 哲学者は食事をやめる。 ***/
        philosophers_status[id] = 0;

        /*** 箸は元の場所に戻される。 ***/
        chopsticks_status[id] = 0;

        /*** 哲学者は箸を一本自分の左側に置く。 ***/
        status = pthread_mutex_unlock(&chopsticks[id]);

        /*** 箸を元の場所に置けなかった時の処理。 ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot unlock a mutex.\n");
            exit(EXIT_FAILURE);
        }

        /*** 箸は元の場所に戻される。 ***/
        chopsticks_status[(id + 1) % PHILOSOPHERS] = 0;

        /*** 哲学者は箸を一本自分の左側に置く。 ***/
        status = pthread_mutex_unlock(&chopsticks[(id + 1) % PHILOSOPHERS]);

        /*** 箸を元の場所に置けなかった時の処理。 ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot unlock a mutex.\n");
            exit(EXIT_FAILURE);
        }

    }
}

/*
 * プログラムの開始点
 */
int main(void)
{
    pthread_t philosophers[PHILOSOPHERS];
    int i;
    int status;

    /*** mutexオブジェクトを初期化する。 ***/
    for (i = 0; i <= PHILOSOPHERS - 1; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }
    
    /***  ***/
    for (i = 0; i <= PHILOSOPHERS - 1; i++) {
        /*** スレッド（哲学者）を生成する。 ***/
        number[i] = i;
        status = pthread_create(&philosophers[i], NULL, 
            (void *)philosopher, (void *)&number[i]);

        /*** スレッド（哲学者）の生成に失敗した時の処理。 ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot create a thread.\n");
            exit(EXIT_FAILURE);
        }
    }

    /*** スレッド（哲学者）の終了を待つ。 ***/
    for (i = 0; i <= PHILOSOPHERS - 1; i++) {
        pthread_join(philosophers[i], NULL);
    }

    /*** 正常終了 ***/
    return(EXIT_SUCCESS);
}
