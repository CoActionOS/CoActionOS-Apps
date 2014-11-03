
sandbox.elf:     file format elf32-littlearm


Disassembly of section .text:

de000000 <_text>:
	...
de000018:	000001ff 	.word	0x000001ff
de00001c:	de00011d 	.word	0xde00011d
de000020:	de000000 	.word	0xde000000
de000024:	00000400 	.word	0x00000400
de000028:	de800000 	.word	0xde800000
de00002c:	00001000 	.word	0x00001000
de000030:	00000080 	.word	0x00000080
de000034:	00000001 	.word	0x00000001
de000038:	00000160 	.word	0x00000160

de00003c <_ctors>:
de00003c:	756c6156 	.word	0x756c6156
de000040:	73692065 	.word	0x73692065
de000044:	646c2520 	.word	0x646c2520
de000048:	6625000a 	.word	0x6625000a
de00004c:	0a66252c 	.word	0x0a66252c
de000050:	00          	.byte	0x00
de000051:	43          	.byte	0x43
de000052:	0000      	.short	0x0000
de000054:	00000000 	.word	0x00000000

de000058 <main>:
#include <cmath>

#include "XBee.hpp"


int main(int argc, char * argv[]){
de000058:	b570      	push	{r4, r5, r6, lr}
de00005a:	ed2d 8b04 	vpush	{d8-d9}
	float t;

	int i;

	value = ~0xFFFFFFED;
	printf("Value is %ld\n", value);
de00005e:	2112      	movs	r1, #18
#include <cmath>

#include "XBee.hpp"


int main(int argc, char * argv[]){
de000060:	b082      	sub	sp, #8
	float t;

	int i;

	value = ~0xFFFFFFED;
	printf("Value is %ld\n", value);
de000062:	4b21      	ldr	r3, [pc, #132]	; (de0000e8 <main+0x90>)
de000064:	4821      	ldr	r0, [pc, #132]	; (de0000ec <main+0x94>)
de000066:	4798      	blx	r3

	Timer::wait_sec(5);
de000068:	2005      	movs	r0, #5
de00006a:	4b21      	ldr	r3, [pc, #132]	; (de0000f0 <main+0x98>)
de00006c:	4798      	blx	r3

	for(i=0; i < 1000; i++){
de00006e:	2400      	movs	r4, #0
		t = i * 0.001;
de000070:	4620      	mov	r0, r4
de000072:	4b20      	ldr	r3, [pc, #128]	; (de0000f4 <main+0x9c>)
de000074:	4d20      	ldr	r5, [pc, #128]	; (de0000f8 <main+0xa0>)
		printf("%f,%f\n", t, cos(t * 2 * M_PI * 1000));
de000076:	4e21      	ldr	r6, [pc, #132]	; (de0000fc <main+0xa4>)
	printf("Value is %ld\n", value);

	Timer::wait_sec(5);

	for(i=0; i < 1000; i++){
		t = i * 0.001;
de000078:	4798      	blx	r3
de00007a:	a317      	add	r3, pc, #92	; (adr r3, de0000d8 <main+0x80>)
de00007c:	e9d3 2300 	ldrd	r2, r3, [r3]
de000080:	47a8      	blx	r5
de000082:	4b1f      	ldr	r3, [pc, #124]	; (de000100 <main+0xa8>)
de000084:	4798      	blx	r3
de000086:	ee09 0a10 	vmov	s18, r0
		printf("%f,%f\n", t, cos(t * 2 * M_PI * 1000));
de00008a:	ee79 7a09 	vadd.f32	s15, s18, s18
	value = ~0xFFFFFFED;
	printf("Value is %ld\n", value);

	Timer::wait_sec(5);

	for(i=0; i < 1000; i++){
de00008e:	3401      	adds	r4, #1
		t = i * 0.001;
		printf("%f,%f\n", t, cos(t * 2 * M_PI * 1000));
de000090:	ee17 0a90 	vmov	r0, s15
de000094:	47b0      	blx	r6
de000096:	a312      	add	r3, pc, #72	; (adr r3, de0000e0 <main+0x88>)
de000098:	e9d3 2300 	ldrd	r2, r3, [r3]
de00009c:	47a8      	blx	r5
de00009e:	2200      	movs	r2, #0
de0000a0:	4b18      	ldr	r3, [pc, #96]	; (de000104 <main+0xac>)
de0000a2:	47a8      	blx	r5
de0000a4:	4b18      	ldr	r3, [pc, #96]	; (de000108 <main+0xb0>)
de0000a6:	ec41 0b10 	vmov	d0, r0, r1
de0000aa:	4798      	blx	r3
de0000ac:	ee19 0a10 	vmov	r0, s18
de0000b0:	eeb0 8a40 	vmov.f32	s16, s0
de0000b4:	eef0 8a60 	vmov.f32	s17, s1
de0000b8:	47b0      	blx	r6
de0000ba:	ed8d 8b00 	vstr	d8, [sp]
de0000be:	4602      	mov	r2, r0
de0000c0:	460b      	mov	r3, r1
de0000c2:	4812      	ldr	r0, [pc, #72]	; (de00010c <main+0xb4>)
de0000c4:	4908      	ldr	r1, [pc, #32]	; (de0000e8 <main+0x90>)
de0000c6:	4788      	blx	r1
	value = ~0xFFFFFFED;
	printf("Value is %ld\n", value);

	Timer::wait_sec(5);

	for(i=0; i < 1000; i++){
de0000c8:	f5b4 7f7a 	cmp.w	r4, #1000	; 0x3e8
de0000cc:	d1d0      	bne.n	de000070 <main+0x18>
	}



	return 0;
}
de0000ce:	2000      	movs	r0, #0
de0000d0:	b002      	add	sp, #8
de0000d2:	ecbd 8b04 	vpop	{d8-d9}
de0000d6:	bd70      	pop	{r4, r5, r6, pc}
de0000d8:	d2f1a9fc 	.word	0xd2f1a9fc
de0000dc:	3f50624d 	.word	0x3f50624d
de0000e0:	54442d18 	.word	0x54442d18
de0000e4:	400921fb 	.word	0x400921fb
de0000e8:	deff85d1 	.word	0xdeff85d1
de0000ec:	de00003c 	.word	0xde00003c
de0000f0:	de000111 	.word	0xde000111
de0000f4:	deff8755 	.word	0xdeff8755
de0000f8:	deff8769 	.word	0xdeff8769
de0000fc:	deff8759 	.word	0xdeff8759
de000100:	deff875d 	.word	0xdeff875d
de000104:	408f4000 	.word	0x408f4000
de000108:	deff8601 	.word	0xdeff8601
de00010c:	de00004a 	.word	0xde00004a

de000110 <_ZN5Timer8wait_secEm>:
de000110:	b508      	push	{r3, lr}
de000112:	4b01      	ldr	r3, [pc, #4]	; (de000118 <_ZN5Timer8wait_secEm+0x8>)
de000114:	4798      	blx	r3
de000116:	bd08      	pop	{r3, pc}
de000118:	deff8401 	.word	0xdeff8401

de00011c <crt>:
de00011c:	b537      	push	{r0, r1, r2, r4, r5, lr}
de00011e:	4c09      	ldr	r4, [pc, #36]	; (de000144 <crt+0x28>)
de000120:	4b09      	ldr	r3, [pc, #36]	; (de000148 <crt+0x2c>)
de000122:	6a61      	ldr	r1, [r4, #36]	; 0x24
de000124:	6b22      	ldr	r2, [r4, #48]	; 0x30
de000126:	4605      	mov	r5, r0
de000128:	4808      	ldr	r0, [pc, #32]	; (de00014c <crt+0x30>)
de00012a:	4798      	blx	r3
de00012c:	4628      	mov	r0, r5
de00012e:	a901      	add	r1, sp, #4
de000130:	4622      	mov	r2, r4
de000132:	4b07      	ldr	r3, [pc, #28]	; (de000150 <crt+0x34>)
de000134:	4798      	blx	r3
de000136:	b110      	cbz	r0, de00013e <crt+0x22>
de000138:	f04f 33ff 	mov.w	r3, #4294967295	; 0xffffffff
de00013c:	9301      	str	r3, [sp, #4]
de00013e:	9801      	ldr	r0, [sp, #4]
de000140:	4b04      	ldr	r3, [pc, #16]	; (de000154 <crt+0x38>)
de000142:	4798      	blx	r3
de000144:	de000000 	.word	0xde000000
de000148:	deff87d5 	.word	0xdeff87d5
de00014c:	de800000 	.word	0xde800000
de000150:	de000159 	.word	0xde000159
de000154:	deff8169 	.word	0xdeff8169

de000158 <crt_common>:
de000158:	e92d 47f3 	stmdb	sp!, {r0, r1, r4, r5, r6, r7, r8, r9, sl, lr}
de00015c:	4e45      	ldr	r6, [pc, #276]	; (de000274 <crt_common+0x11c>)
de00015e:	4b46      	ldr	r3, [pc, #280]	; (de000278 <crt_common+0x120>)
de000160:	4d46      	ldr	r5, [pc, #280]	; (de00027c <crt_common+0x124>)
de000162:	f8df a14c 	ldr.w	sl, [pc, #332]	; de0002b0 <crt_common+0x158>
de000166:	4614      	mov	r4, r2
de000168:	4680      	mov	r8, r0
de00016a:	460f      	mov	r7, r1
de00016c:	4798      	blx	r3
de00016e:	4b44      	ldr	r3, [pc, #272]	; (de000280 <crt_common+0x128>)
de000170:	4631      	mov	r1, r6
de000172:	2220      	movs	r2, #32
de000174:	4798      	blx	r3
de000176:	4843      	ldr	r0, [pc, #268]	; (de000284 <crt_common+0x12c>)
de000178:	2100      	movs	r1, #0
de00017a:	1a32      	subs	r2, r6, r0
de00017c:	47d0      	blx	sl
de00017e:	f8d5 9000 	ldr.w	r9, [r5]
de000182:	f8c9 6074 	str.w	r6, [r9, #116]	; 0x74
de000186:	f8c6 4288 	str.w	r4, [r6, #648]	; 0x288
de00018a:	2400      	movs	r4, #0
de00018c:	f44f 7200 	mov.w	r2, #512	; 0x200
de000190:	6034      	str	r4, [r6, #0]
de000192:	67f4      	str	r4, [r6, #124]	; 0x7c
de000194:	f106 0088 	add.w	r0, r6, #136	; 0x88
de000198:	4621      	mov	r1, r4
de00019a:	47d0      	blx	sl
de00019c:	f8d9 0074 	ldr.w	r0, [r9, #116]	; 0x74
de0001a0:	4e39      	ldr	r6, [pc, #228]	; (de000288 <crt_common+0x130>)
de0001a2:	4621      	mov	r1, r4
de0001a4:	3004      	adds	r0, #4
de0001a6:	47b0      	blx	r6
de0001a8:	682b      	ldr	r3, [r5, #0]
de0001aa:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0001ac:	6902      	ldr	r2, [r0, #16]
de0001ae:	f042 0201 	orr.w	r2, r2, #1
de0001b2:	6102      	str	r2, [r0, #16]
de0001b4:	4621      	mov	r1, r4
de0001b6:	3018      	adds	r0, #24
de0001b8:	47b0      	blx	r6
de0001ba:	682b      	ldr	r3, [r5, #0]
de0001bc:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0001be:	4621      	mov	r1, r4
de0001c0:	302c      	adds	r0, #44	; 0x2c
de0001c2:	47b0      	blx	r6
de0001c4:	682b      	ldr	r3, [r5, #0]
de0001c6:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0001c8:	6b82      	ldr	r2, [r0, #56]	; 0x38
de0001ca:	f042 0201 	orr.w	r2, r2, #1
de0001ce:	6382      	str	r2, [r0, #56]	; 0x38
de0001d0:	4621      	mov	r1, r4
de0001d2:	3040      	adds	r0, #64	; 0x40
de0001d4:	47b0      	blx	r6
de0001d6:	682b      	ldr	r3, [r5, #0]
de0001d8:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0001da:	6cc2      	ldr	r2, [r0, #76]	; 0x4c
de0001dc:	f042 0201 	orr.w	r2, r2, #1
de0001e0:	64c2      	str	r2, [r0, #76]	; 0x4c
de0001e2:	4621      	mov	r1, r4
de0001e4:	3054      	adds	r0, #84	; 0x54
de0001e6:	47b0      	blx	r6
de0001e8:	682b      	ldr	r3, [r5, #0]
de0001ea:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0001ec:	6e02      	ldr	r2, [r0, #96]	; 0x60
de0001ee:	f042 0201 	orr.w	r2, r2, #1
de0001f2:	6602      	str	r2, [r0, #96]	; 0x60
de0001f4:	4621      	mov	r1, r4
de0001f6:	3068      	adds	r0, #104	; 0x68
de0001f8:	47b0      	blx	r6
de0001fa:	682b      	ldr	r3, [r5, #0]
de0001fc:	6f5b      	ldr	r3, [r3, #116]	; 0x74
de0001fe:	6f5a      	ldr	r2, [r3, #116]	; 0x74
de000200:	f042 0201 	orr.w	r2, r2, #1
de000204:	675a      	str	r2, [r3, #116]	; 0x74
de000206:	a901      	add	r1, sp, #4
de000208:	4640      	mov	r0, r8
de00020a:	4b20      	ldr	r3, [pc, #128]	; (de00028c <crt_common+0x134>)
de00020c:	4798      	blx	r3
de00020e:	682b      	ldr	r3, [r5, #0]
de000210:	4606      	mov	r6, r0
de000212:	f8d3 8074 	ldr.w	r8, [r3, #116]	; 0x74
de000216:	4b1e      	ldr	r3, [pc, #120]	; (de000290 <crt_common+0x138>)
de000218:	f44f 7080 	mov.w	r0, #256	; 0x100
de00021c:	4798      	blx	r3
de00021e:	4b1d      	ldr	r3, [pc, #116]	; (de000294 <crt_common+0x13c>)
de000220:	f8c8 0080 	str.w	r0, [r8, #128]	; 0x80
de000224:	6818      	ldr	r0, [r3, #0]
de000226:	4b1c      	ldr	r3, [pc, #112]	; (de000298 <crt_common+0x140>)
de000228:	f8df 8088 	ldr.w	r8, [pc, #136]	; de0002b4 <crt_common+0x15c>
de00022c:	4798      	blx	r3
de00022e:	682b      	ldr	r3, [r5, #0]
de000230:	4d1a      	ldr	r5, [pc, #104]	; (de00029c <crt_common+0x144>)
de000232:	689b      	ldr	r3, [r3, #8]
de000234:	4621      	mov	r1, r4
de000236:	f9b3 000e 	ldrsh.w	r0, [r3, #14]
de00023a:	4b19      	ldr	r3, [pc, #100]	; (de0002a0 <crt_common+0x148>)
de00023c:	4622      	mov	r2, r4
de00023e:	4798      	blx	r3
de000240:	e003      	b.n	de00024a <crt_common+0xf2>
de000242:	f858 3024 	ldr.w	r3, [r8, r4, lsl #2]
de000246:	4798      	blx	r3
de000248:	3401      	adds	r4, #1
de00024a:	42ac      	cmp	r4, r5
de00024c:	dbf9      	blt.n	de000242 <crt_common+0xea>
de00024e:	4631      	mov	r1, r6
de000250:	9801      	ldr	r0, [sp, #4]
de000252:	4b14      	ldr	r3, [pc, #80]	; (de0002a4 <crt_common+0x14c>)
de000254:	4d14      	ldr	r5, [pc, #80]	; (de0002a8 <crt_common+0x150>)
de000256:	4e15      	ldr	r6, [pc, #84]	; (de0002ac <crt_common+0x154>)
de000258:	4798      	blx	r3
de00025a:	2400      	movs	r4, #0
de00025c:	6038      	str	r0, [r7, #0]
de00025e:	e003      	b.n	de000268 <crt_common+0x110>
de000260:	f856 3024 	ldr.w	r3, [r6, r4, lsl #2]
de000264:	4798      	blx	r3
de000266:	3401      	adds	r4, #1
de000268:	42ac      	cmp	r4, r5
de00026a:	dbf9      	blt.n	de000260 <crt_common+0x108>
de00026c:	2000      	movs	r0, #0
de00026e:	e8bd 87fc 	ldmia.w	sp!, {r2, r3, r4, r5, r6, r7, r8, r9, sl, pc}
de000272:	bf00      	nop
de000274:	de800080 	.word	0xde800080
de000278:	deff850d 	.word	0xdeff850d
de00027c:	deff80a8 	.word	0xdeff80a8
de000280:	deff87cd 	.word	0xdeff87cd
de000284:	de800080 	.word	0xde800080
de000288:	deff84f1 	.word	0xdeff84f1
de00028c:	deff87d1 	.word	0xdeff87d1
de000290:	deff8411 	.word	0xdeff8411
de000294:	deff80a4 	.word	0xdeff80a4
de000298:	deff87c9 	.word	0xdeff87c9
de00029c:	00000000 	.word	0x00000000
de0002a0:	deff8349 	.word	0xdeff8349
de0002a4:	de000059 	.word	0xde000059
de0002a8:	00000000 	.word	0x00000000
de0002ac:	de00003c 	.word	0xde00003c
de0002b0:	deff8259 	.word	0xdeff8259
de0002b4:	de00003c 	.word	0xde00003c

de0002b8 <_text_size_align>:
de0002b8:	ffffffff 	.word	0xffffffff
de0002bc:	ffffffff 	.word	0xffffffff
de0002c0:	ffffffff 	.word	0xffffffff
de0002c4:	ffffffff 	.word	0xffffffff
de0002c8:	ffffffff 	.word	0xffffffff
de0002cc:	ffffffff 	.word	0xffffffff
de0002d0:	ffffffff 	.word	0xffffffff
de0002d4:	ffffffff 	.word	0xffffffff
de0002d8:	ffffffff 	.word	0xffffffff
de0002dc:	ffffffff 	.word	0xffffffff
de0002e0:	ffffffff 	.word	0xffffffff
de0002e4:	ffffffff 	.word	0xffffffff
de0002e8:	ffffffff 	.word	0xffffffff
de0002ec:	ffffffff 	.word	0xffffffff
de0002f0:	ffffffff 	.word	0xffffffff
de0002f4:	ffffffff 	.word	0xffffffff
de0002f8:	ffffffff 	.word	0xffffffff
de0002fc:	ffffffff 	.word	0xffffffff
de000300:	ffffffff 	.word	0xffffffff
de000304:	ffffffff 	.word	0xffffffff
de000308:	ffffffff 	.word	0xffffffff
de00030c:	ffffffff 	.word	0xffffffff
de000310:	ffffffff 	.word	0xffffffff
de000314:	ffffffff 	.word	0xffffffff
de000318:	ffffffff 	.word	0xffffffff
de00031c:	ffffffff 	.word	0xffffffff
de000320:	ffffffff 	.word	0xffffffff
de000324:	ffffffff 	.word	0xffffffff
de000328:	ffffffff 	.word	0xffffffff
de00032c:	ffffffff 	.word	0xffffffff
de000330:	ffffffff 	.word	0xffffffff
de000334:	ffffffff 	.word	0xffffffff
de000338:	ffffffff 	.word	0xffffffff
de00033c:	ffffffff 	.word	0xffffffff
de000340:	ffffffff 	.word	0xffffffff
de000344:	ffffffff 	.word	0xffffffff
de000348:	ffffffff 	.word	0xffffffff
de00034c:	ffffffff 	.word	0xffffffff
de000350:	ffffffff 	.word	0xffffffff
de000354:	ffffffff 	.word	0xffffffff
de000358:	ffffffff 	.word	0xffffffff
de00035c:	ffffffff 	.word	0xffffffff
de000360:	ffffffff 	.word	0xffffffff
de000364:	ffffffff 	.word	0xffffffff
de000368:	ffffffff 	.word	0xffffffff
de00036c:	ffffffff 	.word	0xffffffff
de000370:	ffffffff 	.word	0xffffffff
de000374:	ffffffff 	.word	0xffffffff
de000378:	ffffffff 	.word	0xffffffff
de00037c:	ffffffff 	.word	0xffffffff
de000380:	ffffffff 	.word	0xffffffff
de000384:	ffffffff 	.word	0xffffffff
de000388:	ffffffff 	.word	0xffffffff
de00038c:	ffffffff 	.word	0xffffffff
de000390:	ffffffff 	.word	0xffffffff
de000394:	ffffffff 	.word	0xffffffff
de000398:	ffffffff 	.word	0xffffffff
de00039c:	ffffffff 	.word	0xffffffff
de0003a0:	ffffffff 	.word	0xffffffff
de0003a4:	ffffffff 	.word	0xffffffff
de0003a8:	ffffffff 	.word	0xffffffff
de0003ac:	ffffffff 	.word	0xffffffff
de0003b0:	ffffffff 	.word	0xffffffff
de0003b4:	ffffffff 	.word	0xffffffff
de0003b8:	ffffffff 	.word	0xffffffff
de0003bc:	ffffffff 	.word	0xffffffff
de0003c0:	ffffffff 	.word	0xffffffff
de0003c4:	ffffffff 	.word	0xffffffff
de0003c8:	ffffffff 	.word	0xffffffff
de0003cc:	ffffffff 	.word	0xffffffff
de0003d0:	ffffffff 	.word	0xffffffff
de0003d4:	ffffffff 	.word	0xffffffff
de0003d8:	ffffffff 	.word	0xffffffff
de0003dc:	ffffffff 	.word	0xffffffff
de0003e0:	ffffffff 	.word	0xffffffff
de0003e4:	ffffffff 	.word	0xffffffff
de0003e8:	ffffffff 	.word	0xffffffff
de0003ec:	ffffffff 	.word	0xffffffff
de0003f0:	ffffffff 	.word	0xffffffff
de0003f4:	ffffffff 	.word	0xffffffff
de0003f8:	ffffffff 	.word	0xffffffff
de0003fc:	ffffffff 	.word	0xffffffff

Disassembly of section .data:

de800000 <_data>:
de800000:	00000000 	.word	0x00000000
de800004:	deff80ac 	.word	0xdeff80ac
de800008:	deff80b0 	.word	0xdeff80b0
de80000c:	deff80b4 	.word	0xdeff80b4
	...
de800020:	de000051 	.word	0xde000051
	...
