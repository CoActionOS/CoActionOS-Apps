#include <applib/Pio.hpp> //for Thread class
#include <applib/File.hpp> //for Thread class
#include <applib/StringTypes.hpp> //for Thread class
#include <cstdio> //for printf
#include <unistd.h> //for usleep
#include <caos.h>
#include <time.h>

//Here is a list of all the ports and pins that are tested
const pio_t ports[] = {
		{0, 1},
		{0, 0},
		{1, 20},
		{1, 23},
		{1, 24},
		{1, 22},
		{1, 25},
		{1, 26},
		{1, 28},
		{1, 29},
		{1, 0},
		{1, 1},
		{1, 4},
		{1, 8},
		{1, 9},
		{2, 2},
		{2, 3},
		{2, 4},
		{2, 5},
		{2, 6},
		{2, 9},
		{2, 7},
		{2, 8},
		{2, 4},
		{2, 5},
		{0, 22},
		{1, 10},
		{1, 14},
		{1, 15},
		{0, 26},
		{1, 31},
		{0, 25},
		{2, 0},
		{2, 1},
		{0, 7},
		{0, 8},
		{0, 9},
		{0, 6},
		{2, 10},
		{4, 28},
		{4, 29},
		{1, 18},
		//{1, 19}, -- used with the USB, toggling will cause USB to disconnect
		{0, 11},
		{0, 10},
		{255, 255}
};

int main(int argc, char * argv[]){
	int i = 0;
	StringMedium str;
	StringMedium str_read;
	File f;
	time_t t;
	int len;

	t = time(NULL);
	while( ports[i].port != 255 ){
		//Instantiate the Pio class with the port being tested
		Pio pio( ports[i].port );
		printf("Test P%d.%d\n", ports[i].port, ports[i].pin);
		//make the test pin an output
		pio.init(1<<ports[i].pin, PIO_MODE_OUTPUT);
		//Turn the LED on by setting the pin high
		pio.setmask(1<<ports[i].pin);
		//wait for 200ms
		usleep(200*1000);
		//turn the LED off
		pio.clrmask(1<<ports[i].pin);
		//configure the pin as an input
		pio.setattr(1<<ports[i].pin, PIO_MODE_INPUT);
		//close the port
		pio.close();
		i++;
	}

	if( t == time(NULL) ){
		printf("RTC is NOT COUNTING!!!\n");
	}

	if( mkfs("/home") < 0 ){
		perror("Failed to format /home");
		exit(1);
	}

	if( f.create("/home/test1.txt") < 0 ){
		perror("Failed to create /home/test1.txt");
		exit(1);
	}

	str = "This is a test\n";
	len = str.size();

	if( f.write(str.c_str(), len) != len ){
		perror("Failed to write string");
	}

	if( f.close() < 0 ){
		perror("Failed to close");
		exit(0);
	}

	if( f.open("/home/test1.txt") < 0 ){
		perror("Failed to open /home/test1.txt");
		exit(1);
	}

	if( f.read(str_read.data(), len) != len ){
		perror("Failed too read file");
	}

	if( str != str_read ){
		printf("Strings don't match\n");
		printf("%s\n", str_read.c_str());
	}

	f.close();

	if( mkfs("/home") < 0 ){
		perror("Failed to reformat /home");
		exit(1);
	}


	printf("Done\n");
	return 0;
}

