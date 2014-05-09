

#include <pthread.h>

#include <applib/Pin.hpp>
#include <applib/Uart.hpp>
#include <applib/Timer.hpp>
#include <applib/String.hpp>
#include <cstdio>

#include <dev/fifo.h>
#include <applib/Device.hpp>

int main(int argc, char * argv[]){
	Uart uart(0);
	Device vcp;
	Pin led(2,10);
	Pin p(2,9);
	StringMedium str;
	char buffer[256];
	int ret;

	//if 2.9 is held low at startup just let the link thread run
	p.init(Pin::INPUT|Pin::PULLUP);
	if( p.value() == 0 ){
		return 0;
	}

	printf("Start Program in two seconds\n");
	Timer::wait_sec(2);

	//Stop the link-update thread so we can use the virtual serial port for other things
	if( pthread_kill(1, SIGTERM) < 0 ){
		perror("Failed to stop link thread\n");
		return 0;
	}

	//Flash the led to show the use the program is ready
	led.init(Pin::OUTPUT);
	led.clr();
	Timer::wait_sec(1);
	led.set();

	led.setattr(Pin::INPUT);
	led.close();

	uart.open(Uart::NONBLOCK|Uart::RDWR);
	uart.setattr(115200);

	vcp.open("/dev/link-phy-usb", Periph::NONBLOCK | Periph::RDWR);

	//flush the fifo
	if( vcp.ioctl(I_FIFO_FLUSH) < 0 ){
		str = "IOCTL failed\n";
		uart.write(str.c_str(), str.size());
	}

	while(1){
		ret = vcp.read(buffer, 256);
		if( ret > 0 ){
			uart.write(buffer, ret); //output data on the UART
			vcp.write(buffer, ret); //echo if you like
		}

		//see if there is data waiting on the UART
		ret = uart.read(buffer, 256);
		if( ret > 0 ){
			vcp.write(buffer, ret); //send UART data on USB to computer
		}

	}
	return 0;
}
