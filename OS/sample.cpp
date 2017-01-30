#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

int count = 0;
void sighandler(int sig)
{
 
 printf("signal occurred %d times\n",sig, ++count);
}
 
int main(void)
{
 struct itimerval it;
 struct sigaction act, oact;
 act.sa_handler = sighandler;
 sigemptyset(&act.sa_mask);
 act.sa_flags = 0;

 sigaction(SIGPROF, &act, &oact); 
 // Start itimer
 it.it_interval.tv_sec = 4;
 it.it_interval.tv_usec = 50000;
 it.it_value.tv_sec = 1;
 it.it_value.tv_usec = 100000;
 setitimer(ITIMER_PROF, &it, NULL);
 for ( ; ; ) ;
}
