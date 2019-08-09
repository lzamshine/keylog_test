#include <stdio.h>
#include <string.h>

int find_keyboard()
{
	FILE *devices;
	char events[128];
	char handlers[128];
	char *event;
	int evnum = 0, i;

	devices = fopen("/proc/bus/input/devices", "r");
    if (!devices) {
        perror("fopen");
        return evnum;
    }	
	while(fgets(events,sizeof(events), devices))
	{
        if (strstr(events, "H: Handlers=") == events)
            {
            	strcpy(handlers, events);
            	i = 0;
            }
		       
        i++;
		printf("%d %s", i,handlers);
	}
	

	fclose(devices);
}

int main()
{
	find_keyboard();
}