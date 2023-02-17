#pragma once
#include <sys/types.h>
#include "./linked_list/linked_list.h";
#define SLEEP_INTERVAL 1

typedef struct pstat {
    long unsigned int utime_ticks; // tempo speso in ambiente utente
    long int cutime_ticks; // tempo speso in ambiente kernel

    
    long unsigned int stime_ticks; // tempo speso in ambiente utente dai child processo
    long int cstime_ticks;// tempo speso in ambiente kernel dai child processo
    long unsigned int vsize; // virtual memory size in bytes
    long unsigned int rss; // Resident  Set  Size in bytes
    long unsigned int cpu_total_time; //
    long unsigned int start_time_ticks; // orario di avvio processo
} pstat;

typedef struct PidStat {
    pstat current;
    pstat prev;
} PidStat;
typedef struct PidListItem{
  ListItem list;
  pid_t pid;
} PidListItem;
typedef struct PidStatListItem{
  ListItem list;
  pid_t pid;
  PidStat stat;
} PidStatListItem;


void PidList_print(ListHead* head);
PidStatListItem* PidListStat_find(ListHead* head, pid_t pid);
int is_pid_dir(const struct dirent *entry) ;
int getRunningPids( ListHead* head );
PidStatListItem* intializeProcessStats( ListHead *head, pid_t pid );