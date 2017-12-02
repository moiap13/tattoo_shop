#ifndef TATTOOSHOP_MAIN_FUNCTIONS
#define TATTOOSHOP_MAIN_FUNCTIONS

#include <semaphore.h>

#define TIME_WALK_MIN 30
#define TIME_WALK_MAX 50
#define TIME_TATOO_MIN 2
#define TIME_TATOO_MAX 10

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct time_walk_st {
    int walk_min_t;
    int walk_max_t;
} time_walk_t;

typedef struct time_tatoo_st {
    int tatoo_min_t;
    int tatoo_max_t;
} time_tatoo_t;

typedef struct tatooer_st {
    int id_tatooer;
    int time_tatoo;
} tattoer_t;

typedef struct client_st {
    int id_client;
    int time_promenade;
} client_t;

typedef struct client_param_st {
    int id_client;
    int time_promenade;
} client_param_t;

//typedef struct {
//    int count;
//    pthread_mutex_t *mutex;
//    pthread_mutex_t *block;
//} barrier_t;

typedef struct salleAttenteT{
    int nombre_seats_available;
    int nombre_seats_const;
    client_t *client;
}salleAttente_t;

pthread_mutex_t mutex_salle_attente;
sem_t semaphore_balade;
barrier_t barrier;

int randomWalk(time_walk_t walk);
int randomTatoo(time_tatoo_t tatoo);
void barrier_init(barrier_t *b, int count);
void barrier_wait(barrier_t *b);
void barrier_destroy(barrier_t *b);

#endif TATTOOSHOP_MAIN_FUNCTIONS