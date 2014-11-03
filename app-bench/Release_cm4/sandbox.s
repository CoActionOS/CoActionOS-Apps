
sandbox.elf:     file format elf32-littlearm


Disassembly of section .text:

de000000 <_text>:
	...
de000018:	000001ff 	.word	0x000001ff
de00001c:	de0000f1 	.word	0xde0000f1
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
de000058:	e92d 43f7 	stmdb	sp!, {r0, r1, r2, r4, r5, r6, r7, r8, r9, lr}
	float t;

	int i;

	value = ~0xFFFFFFED;
	printf("Value is %ld\n", value);
de00005c:	4b1a      	ldr	r3, [pc, #104]	; (de0000c8 <main+0x70>)
de00005e:	481b      	ldr	r0, [pc, #108]	; (de0000cc <main+0x74>)

	for(i=0; i < 1000; i++){
		t = i * 2 * M_PI / 1000;
de000060:	f8df 8088 	ldr.w	r8, [pc, #136]	; de0000ec <main+0x94>
	float t;

	int i;

	value = ~0xFFFFFFED;
	printf("Value is %ld\n", value);
de000064:	2112      	movs	r1, #18
de000066:	4798      	blx	r3
de000068:	2600      	movs	r6, #0

	for(i=0; i < 1000; i++){
		t = i * 2 * M_PI / 1000;
de00006a:	4630      	mov	r0, r6
de00006c:	47c0      	blx	r8
de00006e:	4c18      	ldr	r4, [pc, #96]	; (de0000d0 <main+0x78>)
		printf("%f,%f\n", t, cosf(t));
de000070:	4f18      	ldr	r7, [pc, #96]	; (de0000d4 <main+0x7c>)

	value = ~0xFFFFFFED;
	printf("Value is %ld\n", value);

	for(i=0; i < 1000; i++){
		t = i * 2 * M_PI / 1000;
de000072:	a313      	add	r3, pc, #76	; (adr r3, de0000c0 <main+0x68>)
de000074:	e9d3 2300 	ldrd	r2, r3, [r3]
de000078:	47a0      	blx	r4
de00007a:	2200      	movs	r2, #0
de00007c:	4b16      	ldr	r3, [pc, #88]	; (de0000d8 <main+0x80>)
de00007e:	4c17      	ldr	r4, [pc, #92]	; (de0000dc <main+0x84>)
de000080:	47a0      	blx	r4
de000082:	4b17      	ldr	r3, [pc, #92]	; (de0000e0 <main+0x88>)
de000084:	4798      	blx	r3
		printf("%f,%f\n", t, cosf(t));
de000086:	4b17      	ldr	r3, [pc, #92]	; (de0000e4 <main+0x8c>)
de000088:	ee00 0a10 	vmov	s0, r0

	value = ~0xFFFFFFED;
	printf("Value is %ld\n", value);

	for(i=0; i < 1000; i++){
		t = i * 2 * M_PI / 1000;
de00008c:	4604      	mov	r4, r0
		printf("%f,%f\n", t, cosf(t));
de00008e:	4798      	blx	r3
de000090:	4620      	mov	r0, r4
de000092:	ee10 9a10 	vmov	r9, s0
de000096:	47b8      	blx	r7
de000098:	4604      	mov	r4, r0
de00009a:	4648      	mov	r0, r9
de00009c:	460d      	mov	r5, r1
de00009e:	47b8      	blx	r7
de0000a0:	3602      	adds	r6, #2
de0000a2:	e9cd 0100 	strd	r0, r1, [sp]
de0000a6:	4622      	mov	r2, r4
de0000a8:	480f      	ldr	r0, [pc, #60]	; (de0000e8 <main+0x90>)
de0000aa:	4907      	ldr	r1, [pc, #28]	; (de0000c8 <main+0x70>)
de0000ac:	462b      	mov	r3, r5
de0000ae:	4788      	blx	r1
	int i;

	value = ~0xFFFFFFED;
	printf("Value is %ld\n", value);

	for(i=0; i < 1000; i++){
de0000b0:	f5b6 6ffa 	cmp.w	r6, #2000	; 0x7d0
de0000b4:	d1d9      	bne.n	de00006a <main+0x12>
	}



	return 0;
}
de0000b6:	2000      	movs	r0, #0
de0000b8:	e8bd 83fe 	ldmia.w	sp!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, pc}
de0000bc:	f3af 8000 	nop.w
de0000c0:	54442d18 	.word	0x54442d18
de0000c4:	400921fb 	.word	0x400921fb
de0000c8:	deff85d1 	.word	0xdeff85d1
de0000cc:	de00003c 	.word	0xde00003c
de0000d0:	deff8769 	.word	0xdeff8769
de0000d4:	deff8759 	.word	0xdeff8759
de0000d8:	408f4000 	.word	0x408f4000
de0000dc:	deff876d 	.word	0xdeff876d
de0000e0:	deff875d 	.word	0xdeff875d
de0000e4:	deff8601 	.word	0xdeff8601
de0000e8:	de00004a 	.word	0xde00004a
de0000ec:	deff8755 	.word	0xdeff8755

de0000f0 <crt>:
de0000f0:	b537      	push	{r0, r1, r2, r4, r5, lr}
de0000f2:	4c09      	ldr	r4, [pc, #36]	; (de000118 <crt+0x28>)
de0000f4:	4b09      	ldr	r3, [pc, #36]	; (de00011c <crt+0x2c>)
de0000f6:	6a61      	ldr	r1, [r4, #36]	; 0x24
de0000f8:	6b22      	ldr	r2, [r4, #48]	; 0x30
de0000fa:	4605      	mov	r5, r0
de0000fc:	4808      	ldr	r0, [pc, #32]	; (de000120 <crt+0x30>)
de0000fe:	4798      	blx	r3
de000100:	4628      	mov	r0, r5
de000102:	a901      	add	r1, sp, #4
de000104:	4622      	mov	r2, r4
de000106:	4b07      	ldr	r3, [pc, #28]	; (de000124 <crt+0x34>)
de000108:	4798      	blx	r3
de00010a:	b110      	cbz	r0, de000112 <crt+0x22>
de00010c:	f04f 33ff 	mov.w	r3, #4294967295	; 0xffffffff
de000110:	9301      	str	r3, [sp, #4]
de000112:	9801      	ldr	r0, [sp, #4]
de000114:	4b04      	ldr	r3, [pc, #16]	; (de000128 <crt+0x38>)
de000116:	4798      	blx	r3
de000118:	de000000 	.word	0xde000000
de00011c:	deff87d5 	.word	0xdeff87d5
de000120:	de800000 	.word	0xde800000
de000124:	de00012d 	.word	0xde00012d
de000128:	deff8169 	.word	0xdeff8169

de00012c <crt_common>:
de00012c:	e92d 47f3 	stmdb	sp!, {r0, r1, r4, r5, r6, r7, r8, r9, sl, lr}
de000130:	4e45      	ldr	r6, [pc, #276]	; (de000248 <crt_common+0x11c>)
de000132:	4b46      	ldr	r3, [pc, #280]	; (de00024c <crt_common+0x120>)
de000134:	4d46      	ldr	r5, [pc, #280]	; (de000250 <crt_common+0x124>)
de000136:	f8df a14c 	ldr.w	sl, [pc, #332]	; de000284 <crt_common+0x158>
de00013a:	4614      	mov	r4, r2
de00013c:	4680      	mov	r8, r0
de00013e:	460f      	mov	r7, r1
de000140:	4798      	blx	r3
de000142:	4b44      	ldr	r3, [pc, #272]	; (de000254 <crt_common+0x128>)
de000144:	4631      	mov	r1, r6
de000146:	2220      	movs	r2, #32
de000148:	4798      	blx	r3
de00014a:	4843      	ldr	r0, [pc, #268]	; (de000258 <crt_common+0x12c>)
de00014c:	2100      	movs	r1, #0
de00014e:	1a32      	subs	r2, r6, r0
de000150:	47d0      	blx	sl
de000152:	f8d5 9000 	ldr.w	r9, [r5]
de000156:	f8c9 6074 	str.w	r6, [r9, #116]	; 0x74
de00015a:	f8c6 4288 	str.w	r4, [r6, #648]	; 0x288
de00015e:	2400      	movs	r4, #0
de000160:	f44f 7200 	mov.w	r2, #512	; 0x200
de000164:	6034      	str	r4, [r6, #0]
de000166:	67f4      	str	r4, [r6, #124]	; 0x7c
de000168:	f106 0088 	add.w	r0, r6, #136	; 0x88
de00016c:	4621      	mov	r1, r4
de00016e:	47d0      	blx	sl
de000170:	f8d9 0074 	ldr.w	r0, [r9, #116]	; 0x74
de000174:	4e39      	ldr	r6, [pc, #228]	; (de00025c <crt_common+0x130>)
de000176:	4621      	mov	r1, r4
de000178:	3004      	adds	r0, #4
de00017a:	47b0      	blx	r6
de00017c:	682b      	ldr	r3, [r5, #0]
de00017e:	6f58      	ldr	r0, [r3, #116]	; 0x74
de000180:	6902      	ldr	r2, [r0, #16]
de000182:	f042 0201 	orr.w	r2, r2, #1
de000186:	6102      	str	r2, [r0, #16]
de000188:	4621      	mov	r1, r4
de00018a:	3018      	adds	r0, #24
de00018c:	47b0      	blx	r6
de00018e:	682b      	ldr	r3, [r5, #0]
de000190:	6f58      	ldr	r0, [r3, #116]	; 0x74
de000192:	4621      	mov	r1, r4
de000194:	302c      	adds	r0, #44	; 0x2c
de000196:	47b0      	blx	r6
de000198:	682b      	ldr	r3, [r5, #0]
de00019a:	6f58      	ldr	r0, [r3, #116]	; 0x74
de00019c:	6b82      	ldr	r2, [r0, #56]	; 0x38
de00019e:	f042 0201 	orr.w	r2, r2, #1
de0001a2:	6382      	str	r2, [r0, #56]	; 0x38
de0001a4:	4621      	mov	r1, r4
de0001a6:	3040      	adds	r0, #64	; 0x40
de0001a8:	47b0      	blx	r6
de0001aa:	682b      	ldr	r3, [r5, #0]
de0001ac:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0001ae:	6cc2      	ldr	r2, [r0, #76]	; 0x4c
de0001b0:	f042 0201 	orr.w	r2, r2, #1
de0001b4:	64c2      	str	r2, [r0, #76]	; 0x4c
de0001b6:	4621      	mov	r1, r4
de0001b8:	3054      	adds	r0, #84	; 0x54
de0001ba:	47b0      	blx	r6
de0001bc:	682b      	ldr	r3, [r5, #0]
de0001be:	6f58      	ldr	r0, [r3, #116]	; 0x74
de0001c0:	6e02      	ldr	r2, [r0, #96]	; 0x60
de0001c2:	f042 0201 	orr.w	r2, r2, #1
de0001c6:	6602      	str	r2, [r0, #96]	; 0x60
de0001c8:	4621      	mov	r1, r4
de0001ca:	3068      	adds	r0, #104	; 0x68
de0001cc:	47b0      	blx	r6
de0001ce:	682b      	ldr	r3, [r5, #0]
de0001d0:	6f5b      	ldr	r3, [r3, #116]	; 0x74
de0001d2:	6f5a      	ldr	r2, [r3, #116]	; 0x74
de0001d4:	f042 0201 	orr.w	r2, r2, #1
de0001d8:	675a      	str	r2, [r3, #116]	; 0x74
de0001da:	a901      	add	r1, sp, #4
de0001dc:	4640      	mov	r0, r8
de0001de:	4b20      	ldr	r3, [pc, #128]	; (de000260 <crt_common+0x134>)
de0001e0:	4798      	blx	r3
de0001e2:	682b      	ldr	r3, [r5, #0]
de0001e4:	4606      	mov	r6, r0
de0001e6:	f8d3 8074 	ldr.w	r8, [r3, #116]	; 0x74
de0001ea:	4b1e      	ldr	r3, [pc, #120]	; (de000264 <crt_common+0x138>)
de0001ec:	f44f 7080 	mov.w	r0, #256	; 0x100
de0001f0:	4798      	blx	r3
de0001f2:	4b1d      	ldr	r3, [pc, #116]	; (de000268 <crt_common+0x13c>)
de0001f4:	f8c8 0080 	str.w	r0, [r8, #128]	; 0x80
de0001f8:	6818      	ldr	r0, [r3, #0]
de0001fa:	4b1c      	ldr	r3, [pc, #112]	; (de00026c <crt_common+0x140>)
de0001fc:	f8df 8088 	ldr.w	r8, [pc, #136]	; de000288 <crt_common+0x15c>
de000200:	4798      	blx	r3
de000202:	682b      	ldr	r3, [r5, #0]
de000204:	4d1a      	ldr	r5, [pc, #104]	; (de000270 <crt_common+0x144>)
de000206:	689b      	ldr	r3, [r3, #8]
de000208:	4621      	mov	r1, r4
de00020a:	f9b3 000e 	ldrsh.w	r0, [r3, #14]
de00020e:	4b19      	ldr	r3, [pc, #100]	; (de000274 <crt_common+0x148>)
de000210:	4622      	mov	r2, r4
de000212:	4798      	blx	r3
de000214:	e003      	b.n	de00021e <crt_common+0xf2>
de000216:	f858 3024 	ldr.w	r3, [r8, r4, lsl #2]
de00021a:	4798      	blx	r3
de00021c:	3401      	adds	r4, #1
de00021e:	42ac      	cmp	r4, r5
de000220:	dbf9      	blt.n	de000216 <crt_common+0xea>
de000222:	4631      	mov	r1, r6
de000224:	9801      	ldr	r0, [sp, #4]
de000226:	4b14      	ldr	r3, [pc, #80]	; (de000278 <crt_common+0x14c>)
de000228:	4d14      	ldr	r5, [pc, #80]	; (de00027c <crt_common+0x150>)
de00022a:	4e15      	ldr	r6, [pc, #84]	; (de000280 <crt_common+0x154>)
de00022c:	4798      	blx	r3
de00022e:	2400      	movs	r4, #0
de000230:	6038      	str	r0, [r7, #0]
de000232:	e003      	b.n	de00023c <crt_common+0x110>
de000234:	f856 3024 	ldr.w	r3, [r6, r4, lsl #2]
de000238:	4798      	blx	r3
de00023a:	3401      	adds	r4, #1
de00023c:	42ac      	cmp	r4, r5
de00023e:	dbf9      	blt.n	de000234 <crt_common+0x108>
de000240:	2000      	movs	r0, #0
de000242:	e8bd 87fc 	ldmia.w	sp!, {r2, r3, r4, r5, r6, r7, r8, r9, sl, pc}
de000246:	bf00      	nop
de000248:	de800080 	.word	0xde800080
de00024c:	deff850d 	.word	0xdeff850d
de000250:	deff80a8 	.word	0xdeff80a8
de000254:	deff87cd 	.word	0xdeff87cd
de000258:	de800080 	.word	0xde800080
de00025c:	deff84f1 	.word	0xdeff84f1
de000260:	deff87d1 	.word	0xdeff87d1
de000264:	deff8411 	.word	0xdeff8411
de000268:	deff80a4 	.word	0xdeff80a4
de00026c:	deff87c9 	.word	0xdeff87c9
de000270:	00000000 	.word	0x00000000
de000274:	deff8349 	.word	0xdeff8349
de000278:	de000059 	.word	0xde000059
de00027c:	00000000 	.word	0x00000000
de000280:	de00003c 	.word	0xde00003c
de000284:	deff8259 	.word	0xdeff8259
de000288:	de00003c 	.word	0xde00003c

de00028c <_text_size_align>:
de00028c:	ffffffff 	.word	0xffffffff
de000290:	ffffffff 	.word	0xffffffff
de000294:	ffffffff 	.word	0xffffffff
de000298:	ffffffff 	.word	0xffffffff
de00029c:	ffffffff 	.word	0xffffffff
de0002a0:	ffffffff 	.word	0xffffffff
de0002a4:	ffffffff 	.word	0xffffffff
de0002a8:	ffffffff 	.word	0xffffffff
de0002ac:	ffffffff 	.word	0xffffffff
de0002b0:	ffffffff 	.word	0xffffffff
de0002b4:	ffffffff 	.word	0xffffffff
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
