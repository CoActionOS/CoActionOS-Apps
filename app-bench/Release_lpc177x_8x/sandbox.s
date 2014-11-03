
sandbox.elf:     file format elf32-littlearm


Disassembly of section .text:

de000000 <_text>:
	...
de000018:	000001ff 	.word	0x000001ff
de00001c:	de000431 	.word	0xde000431
de000020:	de000000 	.word	0xde000000
de000024:	00000600 	.word	0x00000600
de000028:	de800000 	.word	0xde800000
de00002c:	00001000 	.word	0x00001000
de000030:	00000080 	.word	0x00000080
de000034:	00000001 	.word	0x00000001
de000038:	00000160 	.word	0x00000160

de00003c <_ctors>:
de00003c:	00000000 	.word	0x00000000

de000040 <_ZTV3Pio>:
	...
de000048:	de00027d de00019d de000315 de0002d5     }...............
de000058:	de000229 de0002c1 de0002e9 de0002a9     )...............
de000068:	de000291 00000000                       ........

de000070 <_ZTV6Periph>:
	...
de000078:	de00027d de000221 de000315 de0002d5     }...!...........
de000088:	de000229 de0002c1 de0002e9 de0002a9     )...............
de000098:	de000291 00000000                       ........

de0000a0 <_ZTV3Pin>:
	...
de0000a8:	de00027d de00019d de000315 de0002d5     }...............
de0000b8:	de000229 de0002c1 de0002e9 de0002a9     )...............
de0000c8:	de000291 00000000 006f6970 7665642f     ........pio./dev
de0000d8:	0000002f 00000000                       /.......

de0000e0 <_ZTV3Phy>:
	...
de0000e8:	deff8005 00000000 00000043              ........C...

de0000f4 <main>:
#include <applib/Timer.hpp>
#include <applib/Pin.hpp>

#include <hwpl/arch.h>

int main(int argc, char * argv[]){
de0000f4:	b530      	push	{r4, r5, lr}
de0000f6:	b087      	sub	sp, #28
 *
 */
class Pin : public Pio {
public:
	/*! \brief Initialize the object with a port/pin combination. */
	Pin(port_t port, uint32_t pin, bool ismask = false) : Pio(port){
de0000f8:	2101      	movs	r1, #1
de0000fa:	4b15      	ldr	r3, [pc, #84]	; (de000150 <main+0x5c>)
de0000fc:	a802      	add	r0, sp, #8
de0000fe:	4798      	blx	r3
de000100:	4b14      	ldr	r3, [pc, #80]	; (de000154 <main+0x60>)

	Pin p(1,18);

	Timer::wait_msec(1000);
de000102:	f44f 707a 	mov.w	r0, #1000	; 0x3e8
de000106:	9302      	str	r3, [sp, #8]
		if( ismask ){
			pinmask_ = pin;
		} else {
			pinmask_ = (1<<pin);
de000108:	f44f 2380 	mov.w	r3, #262144	; 0x40000
de00010c:	9305      	str	r3, [sp, #20]
de00010e:	4b12      	ldr	r3, [pc, #72]	; (de000158 <main+0x64>)
de000110:	4798      	blx	r3
	 * Pio p(0);
	 * p.init((1<<10)|(1<<5), PIO_MODE_OUTPUT)); //pins 0.5 and 0.10 are outputs
	 * \endcode
	 */
	int init(pio_sample_t mask, int mode){
		if( open() <  0 ){
de000112:	9b02      	ldr	r3, [sp, #8]
de000114:	2100      	movs	r1, #0
de000116:	685b      	ldr	r3, [r3, #4]
de000118:	a802      	add	r0, sp, #8

	using Pio::setattr;

	/*! \brief Initialize the pin with the specified mode */
	inline int init(int mode){
		return Pio::init(pinmask_, mode);
de00011a:	9c05      	ldr	r4, [sp, #20]
de00011c:	4798      	blx	r3
de00011e:	2800      	cmp	r0, #0
de000120:	db07      	blt.n	de000132 <main+0x3e>

	/*! \brief Set the attributes for the port */
	int setattr(pio_sample_t mask, int mode){
		pio_attr_t attr;
		attr.mask = mask;
		attr.mode = mode;
de000122:	2302      	movs	r3, #2
de000124:	f8ad 3004 	strh.w	r3, [sp, #4]
		return setattr(&attr);
de000128:	a802      	add	r0, sp, #8
de00012a:	4669      	mov	r1, sp
de00012c:	4b0b      	ldr	r3, [pc, #44]	; (de00015c <main+0x68>)


	/*! \brief Set the attributes for the port */
	int setattr(pio_sample_t mask, int mode){
		pio_attr_t attr;
		attr.mask = mask;
de00012e:	9400      	str	r4, [sp, #0]
		attr.mode = mode;
		return setattr(&attr);
de000130:	4798      	blx	r3
	}

	/*! \brief Assign a boolean to the pin (true is high, false is low) */
	Pin& operator = (bool on){
		if( on ){
			setmask(pinmask_);
de000132:	4d0b      	ldr	r5, [pc, #44]	; (de000160 <main+0x6c>)

	p.init(Pin::OUTPUT);

	while(1){
		p = true;
		Timer::wait_msec(100);
de000134:	4c08      	ldr	r4, [pc, #32]	; (de000158 <main+0x64>)
de000136:	9905      	ldr	r1, [sp, #20]
de000138:	a802      	add	r0, sp, #8
de00013a:	47a8      	blx	r5
de00013c:	2064      	movs	r0, #100	; 0x64
de00013e:	47a0      	blx	r4
		} else {
			clrmask(pinmask_);
de000140:	a802      	add	r0, sp, #8
de000142:	9905      	ldr	r1, [sp, #20]
de000144:	4b07      	ldr	r3, [pc, #28]	; (de000164 <main+0x70>)
de000146:	4798      	blx	r3
		p = false;
		Timer::wait_msec(100);
de000148:	2064      	movs	r0, #100	; 0x64
de00014a:	47a0      	blx	r4
de00014c:	e7f3      	b.n	de000136 <main+0x42>
de00014e:	bf00      	nop
de000150:	de0001bd 	.word	0xde0001bd
de000154:	de0000a8 	.word	0xde0000a8
de000158:	de000169 	.word	0xde000169
de00015c:	de0001e5 	.word	0xde0001e5
de000160:	de0001f9 	.word	0xde0001f9
de000164:	de00020d 	.word	0xde00020d

de000168 <_ZN5Timer9wait_msecEm>:
de000168:	b570      	push	{r4, r5, r6, lr}
de00016a:	4605      	mov	r5, r0
de00016c:	f44f 707a 	mov.w	r0, #1000	; 0x3e8
de000170:	4368      	muls	r0, r5
de000172:	4b08      	ldr	r3, [pc, #32]	; (de000194 <_ZN5Timer9wait_msecEm+0x2c>)
de000174:	4298      	cmp	r0, r3
de000176:	d807      	bhi.n	de000188 <_ZN5Timer9wait_msecEm+0x20>
de000178:	4b07      	ldr	r3, [pc, #28]	; (de000198 <_ZN5Timer9wait_msecEm+0x30>)
de00017a:	4798      	blx	r3
de00017c:	bd70      	pop	{r4, r5, r6, pc}
de00017e:	f44f 707a 	mov.w	r0, #1000	; 0x3e8
de000182:	47b0      	blx	r6
de000184:	3401      	adds	r4, #1
de000186:	e001      	b.n	de00018c <_ZN5Timer9wait_msecEm+0x24>
de000188:	4e03      	ldr	r6, [pc, #12]	; (de000198 <_ZN5Timer9wait_msecEm+0x30>)
de00018a:	2400      	movs	r4, #0
de00018c:	42ac      	cmp	r4, r5
de00018e:	d1f6      	bne.n	de00017e <_ZN5Timer9wait_msecEm+0x16>
de000190:	bd70      	pop	{r4, r5, r6, pc}
de000192:	bf00      	nop
de000194:	000f423f 	.word	0x000f423f
de000198:	deff8405 	.word	0xdeff8405

de00019c <_ZN3Pio4openEi>:
de00019c:	b508      	push	{r3, lr}
de00019e:	460a      	mov	r2, r1
de0001a0:	4b01      	ldr	r3, [pc, #4]	; (de0001a8 <_ZN3Pio4openEi+0xc>)
de0001a2:	4902      	ldr	r1, [pc, #8]	; (de0001ac <_ZN3Pio4openEi+0x10>)
de0001a4:	4798      	blx	r3
de0001a6:	bd08      	pop	{r3, pc}
de0001a8:	de000399 	.word	0xde000399
de0001ac:	de0000d0 	.word	0xde0000d0

de0001b0 <_ZN3Phy5ioctlEii>:
de0001b0:	b508      	push	{r3, lr}
de0001b2:	6803      	ldr	r3, [r0, #0]
de0001b4:	681b      	ldr	r3, [r3, #0]
de0001b6:	4798      	blx	r3
de0001b8:	bd08      	pop	{r3, pc}
	...

de0001bc <_ZN3PioC1Ej>:
de0001bc:	b537      	push	{r0, r1, r2, r4, r5, lr}
de0001be:	4b06      	ldr	r3, [pc, #24]	; (de0001d8 <_ZN3PioC1Ej+0x1c>)
de0001c0:	4d06      	ldr	r5, [pc, #24]	; (de0001dc <_ZN3PioC1Ej+0x20>)
de0001c2:	f103 0218 	add.w	r2, r3, #24
de0001c6:	9200      	str	r2, [sp, #0]
de0001c8:	2206      	movs	r2, #6
de0001ca:	4604      	mov	r4, r0
de0001cc:	47a8      	blx	r5
de0001ce:	4b04      	ldr	r3, [pc, #16]	; (de0001e0 <_ZN3PioC1Ej+0x24>)
de0001d0:	4620      	mov	r0, r4
de0001d2:	6023      	str	r3, [r4, #0]
de0001d4:	bd3e      	pop	{r1, r2, r3, r4, r5, pc}
de0001d6:	bf00      	nop
de0001d8:	de800080 	.word	0xde800080
de0001dc:	de000351 	.word	0xde000351
de0001e0:	de000048 	.word	0xde000048

de0001e4 <_ZN3Pio7setattrEPK10pio_attr_t>:
de0001e4:	b508      	push	{r3, lr}
de0001e6:	6803      	ldr	r3, [r0, #0]
de0001e8:	460a      	mov	r2, r1
de0001ea:	681b      	ldr	r3, [r3, #0]
de0001ec:	4901      	ldr	r1, [pc, #4]	; (de0001f4 <_ZN3Pio7setattrEPK10pio_attr_t+0x10>)
de0001ee:	4798      	blx	r3
de0001f0:	bd08      	pop	{r3, pc}
de0001f2:	bf00      	nop
de0001f4:	40067001 	.word	0x40067001

de0001f8 <_ZN3Pio7setmaskEj>:
de0001f8:	b508      	push	{r3, lr}
de0001fa:	460a      	mov	r2, r1
de0001fc:	4b02      	ldr	r3, [pc, #8]	; (de000208 <_ZN3Pio7setmaskEj+0x10>)
de0001fe:	f247 0103 	movw	r1, #28675	; 0x7003
de000202:	4798      	blx	r3
de000204:	bd08      	pop	{r3, pc}
de000206:	bf00      	nop
de000208:	de0001b1 	.word	0xde0001b1

de00020c <_ZN3Pio7clrmaskEj>:
de00020c:	b508      	push	{r3, lr}
de00020e:	460a      	mov	r2, r1
de000210:	4b02      	ldr	r3, [pc, #8]	; (de00021c <_ZN3Pio7clrmaskEj+0x10>)
de000212:	f247 0104 	movw	r1, #28676	; 0x7004
de000216:	4798      	blx	r3
de000218:	bd08      	pop	{r3, pc}
de00021a:	bf00      	nop
de00021c:	de0001b1 	.word	0xde0001b1

de000220 <_ZN6Periph4openEi>:
de000220:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
de000224:	4770      	bx	lr
	...

de000228 <_ZN6Periph8readlineEPciic>:
de000228:	e92d 4ff7 	stmdb	sp!, {r0, r1, r2, r4, r5, r6, r7, r8, r9, sl, fp, lr}
de00022c:	2400      	movs	r4, #0
de00022e:	f89d a030 	ldrb.w	sl, [sp, #48]	; 0x30
de000232:	f8df b044 	ldr.w	fp, [pc, #68]	; de000278 <_ZN6Periph8readlineEPciic+0x50>
de000236:	4606      	mov	r6, r0
de000238:	460f      	mov	r7, r1
de00023a:	4691      	mov	r9, r2
de00023c:	4698      	mov	r8, r3
de00023e:	4625      	mov	r5, r4
de000240:	6833      	ldr	r3, [r6, #0]
de000242:	2201      	movs	r2, #1
de000244:	68db      	ldr	r3, [r3, #12]
de000246:	4630      	mov	r0, r6
de000248:	f10d 0107 	add.w	r1, sp, #7
de00024c:	4798      	blx	r3
de00024e:	2801      	cmp	r0, #1
de000250:	d107      	bne.n	de000262 <_ZN6Periph8readlineEPciic+0x3a>
de000252:	f89d 3007 	ldrb.w	r3, [sp, #7]
de000256:	3401      	adds	r4, #1
de000258:	4553      	cmp	r3, sl
de00025a:	f807 3b01 	strb.w	r3, [r7], #1
de00025e:	d103      	bne.n	de000268 <_ZN6Periph8readlineEPciic+0x40>
de000260:	e006      	b.n	de000270 <_ZN6Periph8readlineEPciic+0x48>
de000262:	2001      	movs	r0, #1
de000264:	3501      	adds	r5, #1
de000266:	47d8      	blx	fp
de000268:	454c      	cmp	r4, r9
de00026a:	da01      	bge.n	de000270 <_ZN6Periph8readlineEPciic+0x48>
de00026c:	4545      	cmp	r5, r8
de00026e:	dbe7      	blt.n	de000240 <_ZN6Periph8readlineEPciic+0x18>
de000270:	4620      	mov	r0, r4
de000272:	e8bd 8ffe 	ldmia.w	sp!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
de000276:	bf00      	nop
de000278:	de000169 	.word	0xde000169

de00027c <_ZN6Periph5ioctlEiPv>:
de00027c:	b510      	push	{r4, lr}
de00027e:	6883      	ldr	r3, [r0, #8]
de000280:	6844      	ldr	r4, [r0, #4]
de000282:	f853 0024 	ldr.w	r0, [r3, r4, lsl #2]
de000286:	4b01      	ldr	r3, [pc, #4]	; (de00028c <_ZN6Periph5ioctlEiPv+0x10>)
de000288:	4798      	blx	r3
de00028a:	bd10      	pop	{r4, pc}
de00028c:	deff83f5 	.word	0xdeff83f5

de000290 <_ZN6Periph5writeER3Aio>:
de000290:	6842      	ldr	r2, [r0, #4]
de000292:	b508      	push	{r3, lr}
de000294:	6883      	ldr	r3, [r0, #8]
de000296:	4608      	mov	r0, r1
de000298:	f853 3022 	ldr.w	r3, [r3, r2, lsl #2]
de00029c:	600b      	str	r3, [r1, #0]
de00029e:	4b01      	ldr	r3, [pc, #4]	; (de0002a4 <_ZN6Periph5writeER3Aio+0x14>)
de0002a0:	4798      	blx	r3
de0002a2:	bd08      	pop	{r3, pc}
de0002a4:	deff83bd 	.word	0xdeff83bd

de0002a8 <_ZN6Periph4readER3Aio>:
de0002a8:	6842      	ldr	r2, [r0, #4]
de0002aa:	b508      	push	{r3, lr}
de0002ac:	6883      	ldr	r3, [r0, #8]
de0002ae:	4608      	mov	r0, r1
de0002b0:	f853 3022 	ldr.w	r3, [r3, r2, lsl #2]
de0002b4:	600b      	str	r3, [r1, #0]
de0002b6:	4b01      	ldr	r3, [pc, #4]	; (de0002bc <_ZN6Periph4readER3Aio+0x14>)
de0002b8:	4798      	blx	r3
de0002ba:	bd08      	pop	{r3, pc}
de0002bc:	deff83b9 	.word	0xdeff83b9

de0002c0 <_ZN6Periph5writeEPKvi>:
de0002c0:	b510      	push	{r4, lr}
de0002c2:	6883      	ldr	r3, [r0, #8]
de0002c4:	6844      	ldr	r4, [r0, #4]
de0002c6:	f853 0024 	ldr.w	r0, [r3, r4, lsl #2]
de0002ca:	4b01      	ldr	r3, [pc, #4]	; (de0002d0 <_ZN6Periph5writeEPKvi+0x10>)
de0002cc:	4798      	blx	r3
de0002ce:	bd10      	pop	{r4, pc}
de0002d0:	deff8349 	.word	0xdeff8349

de0002d4 <_ZN6Periph4readEPvi>:
de0002d4:	b510      	push	{r4, lr}
de0002d6:	6883      	ldr	r3, [r0, #8]
de0002d8:	6844      	ldr	r4, [r0, #4]
de0002da:	f853 0024 	ldr.w	r0, [r3, r4, lsl #2]
de0002de:	4b01      	ldr	r3, [pc, #4]	; (de0002e4 <_ZN6Periph4readEPvi+0x10>)
de0002e0:	4798      	blx	r3
de0002e2:	bd10      	pop	{r4, pc}
de0002e4:	deff8331 	.word	0xdeff8331

de0002e8 <_ZN6Periph5closeEv>:
de0002e8:	6883      	ldr	r3, [r0, #8]
de0002ea:	6842      	ldr	r2, [r0, #4]
de0002ec:	b510      	push	{r4, lr}
de0002ee:	4604      	mov	r4, r0
de0002f0:	f853 0022 	ldr.w	r0, [r3, r2, lsl #2]
de0002f4:	1c43      	adds	r3, r0, #1
de0002f6:	d008      	beq.n	de00030a <_ZN6Periph5closeEv+0x22>
de0002f8:	4b05      	ldr	r3, [pc, #20]	; (de000310 <_ZN6Periph5closeEv+0x28>)
de0002fa:	4798      	blx	r3
de0002fc:	6862      	ldr	r2, [r4, #4]
de0002fe:	68a3      	ldr	r3, [r4, #8]
de000300:	f04f 31ff 	mov.w	r1, #4294967295	; 0xffffffff
de000304:	f843 1022 	str.w	r1, [r3, r2, lsl #2]
de000308:	bd10      	pop	{r4, pc}
de00030a:	2000      	movs	r0, #0
de00030c:	bd10      	pop	{r4, pc}
de00030e:	bf00      	nop
de000310:	deff8309 	.word	0xdeff8309

de000314 <_ZN6Periph4openEPKci>:
de000314:	b570      	push	{r4, r5, r6, lr}
de000316:	6846      	ldr	r6, [r0, #4]
de000318:	6885      	ldr	r5, [r0, #8]
de00031a:	4604      	mov	r4, r0
de00031c:	f855 3026 	ldr.w	r3, [r5, r6, lsl #2]
de000320:	3301      	adds	r3, #1
de000322:	d110      	bne.n	de000346 <_ZN6Periph4openEPKci+0x32>
de000324:	4608      	mov	r0, r1
de000326:	4b09      	ldr	r3, [pc, #36]	; (de00034c <_ZN6Periph4openEPKci+0x38>)
de000328:	f042 0102 	orr.w	r1, r2, #2
de00032c:	4798      	blx	r3
de00032e:	f845 0026 	str.w	r0, [r5, r6, lsl #2]
de000332:	6862      	ldr	r2, [r4, #4]
de000334:	68a3      	ldr	r3, [r4, #8]
de000336:	f853 0022 	ldr.w	r0, [r3, r2, lsl #2]
de00033a:	2800      	cmp	r0, #0
de00033c:	bfb4      	ite	lt
de00033e:	f04f 30ff 	movlt.w	r0, #4294967295	; 0xffffffff
de000342:	2000      	movge	r0, #0
de000344:	bd70      	pop	{r4, r5, r6, pc}
de000346:	2000      	movs	r0, #0
de000348:	bd70      	pop	{r4, r5, r6, pc}
de00034a:	bf00      	nop
de00034c:	deff832d 	.word	0xdeff832d

de000350 <_ZN6PeriphC1EjiPiPb>:
de000350:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
de000354:	4698      	mov	r8, r3
de000356:	4b0e      	ldr	r3, [pc, #56]	; (de000390 <_ZN6PeriphC1EjiPiPb+0x40>)
de000358:	460e      	mov	r6, r1
de00035a:	4604      	mov	r4, r0
de00035c:	4617      	mov	r7, r2
de00035e:	9d06      	ldr	r5, [sp, #24]
de000360:	4798      	blx	r3
de000362:	4b0c      	ldr	r3, [pc, #48]	; (de000394 <_ZN6PeriphC1EjiPiPb+0x44>)
de000364:	42be      	cmp	r6, r7
de000366:	e884 0148 	stmia.w	r4, {r3, r6, r8}
de00036a:	d301      	bcc.n	de000370 <_ZN6PeriphC1EjiPiPb+0x20>
de00036c:	2300      	movs	r3, #0
de00036e:	6063      	str	r3, [r4, #4]
de000370:	7829      	ldrb	r1, [r5, #0]
de000372:	b949      	cbnz	r1, de000388 <_ZN6PeriphC1EjiPiPb+0x38>
de000374:	f04f 33ff 	mov.w	r3, #4294967295	; 0xffffffff
de000378:	e002      	b.n	de000380 <_ZN6PeriphC1EjiPiPb+0x30>
de00037a:	f848 3021 	str.w	r3, [r8, r1, lsl #2]
de00037e:	3101      	adds	r1, #1
de000380:	42b9      	cmp	r1, r7
de000382:	dbfa      	blt.n	de00037a <_ZN6PeriphC1EjiPiPb+0x2a>
de000384:	2301      	movs	r3, #1
de000386:	702b      	strb	r3, [r5, #0]
de000388:	4620      	mov	r0, r4
de00038a:	e8bd 81f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, pc}
de00038e:	bf00      	nop
de000390:	de000425 	.word	0xde000425
de000394:	de000078 	.word	0xde000078

de000398 <_ZN6Periph5_openEPKci>:
de000398:	b5f0      	push	{r4, r5, r6, r7, lr}
de00039a:	b085      	sub	sp, #20
de00039c:	460d      	mov	r5, r1
de00039e:	4604      	mov	r4, r0
de0003a0:	491a      	ldr	r1, [pc, #104]	; (de00040c <_ZN6Periph5_openEPKci+0x74>)
de0003a2:	4b1b      	ldr	r3, [pc, #108]	; (de000410 <_ZN6Periph5_openEPKci+0x78>)
de0003a4:	a801      	add	r0, sp, #4
de0003a6:	4617      	mov	r7, r2
de0003a8:	4798      	blx	r3
de0003aa:	4629      	mov	r1, r5
de0003ac:	4b19      	ldr	r3, [pc, #100]	; (de000414 <_ZN6Periph5_openEPKci+0x7c>)
de0003ae:	a801      	add	r0, sp, #4
de0003b0:	4798      	blx	r3
de0003b2:	4b19      	ldr	r3, [pc, #100]	; (de000418 <_ZN6Periph5_openEPKci+0x80>)
de0003b4:	a801      	add	r0, sp, #4
de0003b6:	4798      	blx	r3
de0003b8:	4b18      	ldr	r3, [pc, #96]	; (de00041c <_ZN6Periph5_openEPKci+0x84>)
de0003ba:	6865      	ldr	r5, [r4, #4]
de0003bc:	429d      	cmp	r5, r3
de0003be:	f04f 0300 	mov.w	r3, #0
de0003c2:	d007      	beq.n	de0003d4 <_ZN6Periph5_openEPKci+0x3c>
de0003c4:	aa04      	add	r2, sp, #16
de0003c6:	1810      	adds	r0, r2, r0
de0003c8:	3530      	adds	r5, #48	; 0x30
de0003ca:	f800 5c0c 	strb.w	r5, [r0, #-12]
de0003ce:	f800 3c0b 	strb.w	r3, [r0, #-11]
de0003d2:	e000      	b.n	de0003d6 <_ZN6Periph5_openEPKci+0x3e>
de0003d4:	6063      	str	r3, [r4, #4]
de0003d6:	6866      	ldr	r6, [r4, #4]
de0003d8:	68a5      	ldr	r5, [r4, #8]
de0003da:	f855 3026 	ldr.w	r3, [r5, r6, lsl #2]
de0003de:	3301      	adds	r3, #1
de0003e0:	d110      	bne.n	de000404 <_ZN6Periph5_openEPKci+0x6c>
de0003e2:	4b0f      	ldr	r3, [pc, #60]	; (de000420 <_ZN6Periph5_openEPKci+0x88>)
de0003e4:	a801      	add	r0, sp, #4
de0003e6:	f047 0102 	orr.w	r1, r7, #2
de0003ea:	4798      	blx	r3
de0003ec:	f845 0026 	str.w	r0, [r5, r6, lsl #2]
de0003f0:	6862      	ldr	r2, [r4, #4]
de0003f2:	68a3      	ldr	r3, [r4, #8]
de0003f4:	f853 0022 	ldr.w	r0, [r3, r2, lsl #2]
de0003f8:	2800      	cmp	r0, #0
de0003fa:	bfb4      	ite	lt
de0003fc:	f04f 30ff 	movlt.w	r0, #4294967295	; 0xffffffff
de000400:	2000      	movge	r0, #0
de000402:	e000      	b.n	de000406 <_ZN6Periph5_openEPKci+0x6e>
de000404:	2000      	movs	r0, #0
de000406:	b005      	add	sp, #20
de000408:	bdf0      	pop	{r4, r5, r6, r7, pc}
de00040a:	bf00      	nop
de00040c:	de0000d4 	.word	0xde0000d4
de000410:	deff82ad 	.word	0xdeff82ad
de000414:	deff829d 	.word	0xdeff829d
de000418:	deff82bd 	.word	0xdeff82bd
de00041c:	aaee5566 	.word	0xaaee5566
de000420:	deff832d 	.word	0xdeff832d

de000424 <_ZN3PhyC1Ev>:
de000424:	4b01      	ldr	r3, [pc, #4]	; (de00042c <_ZN3PhyC1Ev+0x8>)
de000426:	6003      	str	r3, [r0, #0]
de000428:	4770      	bx	lr
de00042a:	bf00      	nop
de00042c:	de0000e8 	.word	0xde0000e8

de000430 <crt>:
de000430:	b537      	push	{r0, r1, r2, r4, r5, lr}
de000432:	4c09      	ldr	r4, [pc, #36]	; (de000458 <crt+0x28>)
de000434:	4605      	mov	r5, r0
de000436:	6a61      	ldr	r1, [r4, #36]	; 0x24
de000438:	4808      	ldr	r0, [pc, #32]	; (de00045c <crt+0x2c>)
de00043a:	6b22      	ldr	r2, [r4, #48]	; 0x30
de00043c:	4b08      	ldr	r3, [pc, #32]	; (de000460 <crt+0x30>)
de00043e:	4798      	blx	r3
de000440:	4628      	mov	r0, r5
de000442:	a901      	add	r1, sp, #4
de000444:	4622      	mov	r2, r4
de000446:	4b07      	ldr	r3, [pc, #28]	; (de000464 <crt+0x34>)
de000448:	4798      	blx	r3
de00044a:	b110      	cbz	r0, de000452 <crt+0x22>
de00044c:	f04f 33ff 	mov.w	r3, #4294967295	; 0xffffffff
de000450:	9301      	str	r3, [sp, #4]
de000452:	9801      	ldr	r0, [sp, #4]
de000454:	4b04      	ldr	r3, [pc, #16]	; (de000468 <crt+0x38>)
de000456:	4798      	blx	r3
de000458:	de000000 	.word	0xde000000
de00045c:	de800000 	.word	0xde800000
de000460:	deff87d5 	.word	0xdeff87d5
de000464:	de00046d 	.word	0xde00046d
de000468:	deff8169 	.word	0xdeff8169

de00046c <crt_common>:
de00046c:	e92d 47f3 	stmdb	sp!, {r0, r1, r4, r5, r6, r7, r8, r9, sl, lr}
de000470:	4e45      	ldr	r6, [pc, #276]	; (de000588 <crt_common+0x11c>)
de000472:	4b46      	ldr	r3, [pc, #280]	; (de00058c <crt_common+0x120>)
de000474:	4614      	mov	r4, r2
de000476:	4680      	mov	r8, r0
de000478:	460f      	mov	r7, r1
de00047a:	4798      	blx	r3
de00047c:	4b44      	ldr	r3, [pc, #272]	; (de000590 <crt_common+0x124>)
de00047e:	4631      	mov	r1, r6
de000480:	2220      	movs	r2, #32
de000482:	4798      	blx	r3
de000484:	4843      	ldr	r0, [pc, #268]	; (de000594 <crt_common+0x128>)
de000486:	4d44      	ldr	r5, [pc, #272]	; (de000598 <crt_common+0x12c>)
de000488:	1a32      	subs	r2, r6, r0
de00048a:	2100      	movs	r1, #0
de00048c:	f8df a134 	ldr.w	sl, [pc, #308]	; de0005c4 <crt_common+0x158>
de000490:	47d0      	blx	sl
de000492:	f8d5 9000 	ldr.w	r9, [r5]
de000496:	f44f 7200 	mov.w	r2, #512	; 0x200
de00049a:	f8c9 6074 	str.w	r6, [r9, #116]	; 0x74
de00049e:	f8c6 4288 	str.w	r4, [r6, #648]	; 0x288
de0004a2:	2400      	movs	r4, #0
de0004a4:	6034      	str	r4, [r6, #0]
de0004a6:	67f4      	str	r4, [r6, #124]	; 0x7c
de0004a8:	f106 0088 	add.w	r0, r6, #136	; 0x88
de0004ac:	4621      	mov	r1, r4
de0004ae:	47d0      	blx	sl
de0004b0:	f8d9 0074 	ldr.w	r0, [r9, #116]	; 0x74
de0004b4:	4e39      	ldr	r6, [pc, #228]	; (de00059c <crt_common+0x130>)
de0004b6:	4621      	mov	r1, r4
de0004b8:	3004      	adds	r0, #4
de0004ba:	47b0      	blx	r6
de0004bc:	682b      	ldr	r3, [r5, #0]
de0004be:	4621      	mov	r1, r4
de0004c0:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0004c2:	6902      	ldr	r2, [r0, #16]
de0004c4:	f042 0201 	orr.w	r2, r2, #1
de0004c8:	6102      	str	r2, [r0, #16]
de0004ca:	3018      	adds	r0, #24
de0004cc:	47b0      	blx	r6
de0004ce:	682b      	ldr	r3, [r5, #0]
de0004d0:	4621      	mov	r1, r4
de0004d2:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0004d4:	302c      	adds	r0, #44	; 0x2c
de0004d6:	47b0      	blx	r6
de0004d8:	682b      	ldr	r3, [r5, #0]
de0004da:	4621      	mov	r1, r4
de0004dc:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0004de:	6b82      	ldr	r2, [r0, #56]	; 0x38
de0004e0:	f042 0201 	orr.w	r2, r2, #1
de0004e4:	6382      	str	r2, [r0, #56]	; 0x38
de0004e6:	3040      	adds	r0, #64	; 0x40
de0004e8:	47b0      	blx	r6
de0004ea:	682b      	ldr	r3, [r5, #0]
de0004ec:	4621      	mov	r1, r4
de0004ee:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0004f0:	6cc2      	ldr	r2, [r0, #76]	; 0x4c
de0004f2:	f042 0201 	orr.w	r2, r2, #1
de0004f6:	64c2      	str	r2, [r0, #76]	; 0x4c
de0004f8:	3054      	adds	r0, #84	; 0x54
de0004fa:	47b0      	blx	r6
de0004fc:	682b      	ldr	r3, [r5, #0]
de0004fe:	4621      	mov	r1, r4
de000500:	6f58      	ldr	r0, [r3, #116]	; 0x74
de000502:	6e02      	ldr	r2, [r0, #96]	; 0x60
de000504:	f042 0201 	orr.w	r2, r2, #1
de000508:	6602      	str	r2, [r0, #96]	; 0x60
de00050a:	3068      	adds	r0, #104	; 0x68
de00050c:	47b0      	blx	r6
de00050e:	682b      	ldr	r3, [r5, #0]
de000510:	a901      	add	r1, sp, #4
de000512:	6f5b      	ldr	r3, [r3, #116]	; 0x74
de000514:	4640      	mov	r0, r8
de000516:	6f5a      	ldr	r2, [r3, #116]	; 0x74
de000518:	f042 0201 	orr.w	r2, r2, #1
de00051c:	675a      	str	r2, [r3, #116]	; 0x74
de00051e:	4b20      	ldr	r3, [pc, #128]	; (de0005a0 <crt_common+0x134>)
de000520:	4798      	blx	r3
de000522:	682b      	ldr	r3, [r5, #0]
de000524:	4606      	mov	r6, r0
de000526:	f8d3 8074 	ldr.w	r8, [r3, #116]	; 0x74
de00052a:	f44f 7080 	mov.w	r0, #256	; 0x100
de00052e:	4b1d      	ldr	r3, [pc, #116]	; (de0005a4 <crt_common+0x138>)
de000530:	4798      	blx	r3
de000532:	4b1d      	ldr	r3, [pc, #116]	; (de0005a8 <crt_common+0x13c>)
de000534:	f8c8 0080 	str.w	r0, [r8, #128]	; 0x80
de000538:	6818      	ldr	r0, [r3, #0]
de00053a:	4b1c      	ldr	r3, [pc, #112]	; (de0005ac <crt_common+0x140>)
de00053c:	4798      	blx	r3
de00053e:	682b      	ldr	r3, [r5, #0]
de000540:	4621      	mov	r1, r4
de000542:	689b      	ldr	r3, [r3, #8]
de000544:	4622      	mov	r2, r4
de000546:	f9b3 000e 	ldrsh.w	r0, [r3, #14]
de00054a:	4b19      	ldr	r3, [pc, #100]	; (de0005b0 <crt_common+0x144>)
de00054c:	4798      	blx	r3
de00054e:	4d19      	ldr	r5, [pc, #100]	; (de0005b4 <crt_common+0x148>)
de000550:	f8df 8074 	ldr.w	r8, [pc, #116]	; de0005c8 <crt_common+0x15c>
de000554:	e003      	b.n	de00055e <crt_common+0xf2>
de000556:	f858 3024 	ldr.w	r3, [r8, r4, lsl #2]
de00055a:	4798      	blx	r3
de00055c:	3401      	adds	r4, #1
de00055e:	42ac      	cmp	r4, r5
de000560:	dbf9      	blt.n	de000556 <crt_common+0xea>
de000562:	4631      	mov	r1, r6
de000564:	9801      	ldr	r0, [sp, #4]
de000566:	4b14      	ldr	r3, [pc, #80]	; (de0005b8 <crt_common+0x14c>)
de000568:	4798      	blx	r3
de00056a:	2400      	movs	r4, #0
de00056c:	6038      	str	r0, [r7, #0]
de00056e:	4d13      	ldr	r5, [pc, #76]	; (de0005bc <crt_common+0x150>)
de000570:	4e13      	ldr	r6, [pc, #76]	; (de0005c0 <crt_common+0x154>)
de000572:	e003      	b.n	de00057c <crt_common+0x110>
de000574:	f856 3024 	ldr.w	r3, [r6, r4, lsl #2]
de000578:	4798      	blx	r3
de00057a:	3401      	adds	r4, #1
de00057c:	42ac      	cmp	r4, r5
de00057e:	dbf9      	blt.n	de000574 <crt_common+0x108>
de000580:	2000      	movs	r0, #0
de000582:	e8bd 87fc 	ldmia.w	sp!, {r2, r3, r4, r5, r6, r7, r8, r9, sl, pc}
de000586:	bf00      	nop
de000588:	de80009c 	.word	0xde80009c
de00058c:	deff850d 	.word	0xdeff850d
de000590:	deff87cd 	.word	0xdeff87cd
de000594:	de800080 	.word	0xde800080
de000598:	deff80a8 	.word	0xdeff80a8
de00059c:	deff84f1 	.word	0xdeff84f1
de0005a0:	deff87d1 	.word	0xdeff87d1
de0005a4:	deff8411 	.word	0xdeff8411
de0005a8:	deff80a4 	.word	0xdeff80a4
de0005ac:	deff87c9 	.word	0xdeff87c9
de0005b0:	deff8349 	.word	0xdeff8349
de0005b4:	00000000 	.word	0x00000000
de0005b8:	de0000f5 	.word	0xde0000f5
de0005bc:	00000000 	.word	0x00000000
de0005c0:	de00003c 	.word	0xde00003c
de0005c4:	deff8259 	.word	0xdeff8259
de0005c8:	de00003c 	.word	0xde00003c

de0005cc <_text_size_align>:
de0005cc:	ffffffff 	.word	0xffffffff
de0005d0:	ffffffff 	.word	0xffffffff
de0005d4:	ffffffff 	.word	0xffffffff
de0005d8:	ffffffff 	.word	0xffffffff
de0005dc:	ffffffff 	.word	0xffffffff
de0005e0:	ffffffff 	.word	0xffffffff
de0005e4:	ffffffff 	.word	0xffffffff
de0005e8:	ffffffff 	.word	0xffffffff
de0005ec:	ffffffff 	.word	0xffffffff
de0005f0:	ffffffff 	.word	0xffffffff
de0005f4:	ffffffff 	.word	0xffffffff
de0005f8:	ffffffff 	.word	0xffffffff
de0005fc:	ffffffff 	.word	0xffffffff

Disassembly of section .data:

de800000 <_data>:
de800000:	00000000 	.word	0x00000000
de800004:	deff80ac 	.word	0xdeff80ac
de800008:	deff80b0 	.word	0xdeff80b0
de80000c:	deff80b4 	.word	0xdeff80b4
	...
de800020:	de0000f0 	.word	0xde0000f0
	...

Disassembly of section .bss:

de800080 <_ZN3Pio2fdE>:
	...

de800098 <_ZN3Pio13isinitializedE>:
de800098:	00000000                                ....
