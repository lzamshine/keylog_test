#include <linux/input.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define DEVICE_KEY 	"/dev/input/event3"

int main(void)
{
	int fd = -1, ret = -1;
	struct input_event ev;

	fd = open(DEVICE_KEY, O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}

	while(1)
	{
		memset(&ev, 0, sizeof(struct input_event));
		ret = read(fd, &ev, sizeof(struct input_event));
		if(ret != sizeof(struct input_event))
		{
			perror("read");
			close(fd);
			return -1;
		}

		printf("-------------------------\n");

		printf("type: %hd\n", ev.type);
		printf("code: %hd\n", ev.code);
		printf("value: %d\n", ev.value);
		printf("\n");
	}

	close(fd);

	return 0;
}