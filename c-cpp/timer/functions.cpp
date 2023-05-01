#include "functions.hpp"

void display(int hr, int  min, int  sec) {
    system("clear");
    std::cout << "\rTimer: " << hr << ":" << min << ":" << sec <<std::endl;
}

void timer(int  n, int mode){
    int  hours, min, sec, aux_hours;
    bool loop;

    if (mode == minutos) {
        hours = n;
        
        if (n > 59) hours /= 60;
        else hours = 0;
        
        min = n % 60;
        sec = 0;
    }

    else if (mode == segundos) {
        hours = 0;
        min = 0;
        sec = n;
        
        if (n > 59){
            sec = n % 60;
            min = n/60;
            hours = 0;
            if (min % 60 == 0) { /*Convert minutes -> hours*/
                hours = min / 60;
                min = 0;
            }  
        }
    }
    loop = true;

    while (loop)
    {   
        display(hours,min,sec);
        sleep(1);

        if (((hours == 0) && (min == 0)) && (sec == 0))
        {
            system("play -q bell.wav -t alsa");
            loop = false;
        }
            
        if (sec <= 0)
        {
            if (min == 0) {
                if (hours > 0) /* example: 01:00:00 */
                {
                    hours--;
                    min = 59;
                    sec = 60;
                }
            }

            else
            {
                sec = 60;
                min--;
            }
            
        }
        sec--;
    }

}

void usage() {
    std::cout << "Usage: ./program [option] 'time'" << std::endl;
    std::cout << "By default (with no option) the last argument will be the number of minutes.'" << std::endl;
    std::cout << "The only option -s lets you set the timer to seconds instead of minutes." << std::endl;
    exit(0);
}

