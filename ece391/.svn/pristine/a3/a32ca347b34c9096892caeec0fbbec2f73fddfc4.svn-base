/* kernel.c - the C part of the kernel
 * vim:ts=4 noexpandtab
 */

#include "multiboot.h"
#include "x86_desc.h"
#include "lib.h"
#include "devices/i8259.h"
#include "devices/keyboard.h"
#include "devices/rtc/rtc.h"
#include "devices/terminal.h"
#include "kernel/filesys.h"
#include "calls/execute.h"
#include "calls/general.h"
#include "calls/control.h"
#include "debug.h"
#include "types.h"


void _exception_handler0();
void _exception_handler1();
void _exception_handler2();
void _exception_handler3();
void _exception_handler4();
void _exception_handler5();
void _exception_handler6();
void _exception_handler7();
void _exception_handler8();
void _exception_handler9();
void _exception_handler10();
void _exception_handler11();
void _exception_handler12();
void _exception_handler13();
void _exception_handler14();
void _exception_handler15();
void _exception_handler16();
void _exception_handler17();
void _exception_handler18();
void _exception_handler19();
void _exception_handler20();
void _exception_handler21();
void _exception_handler22();
void _exception_handler23();
void _exception_handler24();
void _exception_handler25();
void _exception_handler26();
void _exception_handler27();
void _exception_handler28();
void _exception_handler29();
void _exception_handler30();
void _exception_handler31();

void _keyboard_handler();
void _rtc_handler();
void _syscall_handler();

void exception_print(int number);

void close_tasks();



uint32_t *page_directory_array = (uint32_t *) 0x9C000;

uint32_t *pt0 = (uint32_t *) 0x9D000;

/* Macros. */
/* Check if the bit BIT in FLAGS is set. */
#define CHECK_FLAG(flags,bit)   ((flags) & (1 << (bit)))

/* Check if MAGIC is valid and print the Multiboot information structure
   pointed by ADDR. */
void
entry (unsigned long magic, unsigned long addr)
{
	multiboot_info_t *mbi;

	/* Clear the screen. */
	clear();
	
	
	/* Am I booted by a Multiboot-compliant boot loader? */
	if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
	{
		printf ("Invalid magic number: 0x%#x\n", (unsigned) magic);
		return;
	}

	/* Set MBI to the address of the Multiboot information structure. */
	mbi = (multiboot_info_t *) addr;
	boot_block_ptr=(uint32_t *)((module_t *)mbi->mods_addr)->mod_start;

	/* Print out the flags. */
	printf ("flags = 0x%#x\n", (unsigned) mbi->flags);

	/* Are mem_* valid? */
	if (CHECK_FLAG (mbi->flags, 0))
		printf ("mem_lower = %uKB, mem_upper = %uKB\n",
				(unsigned) mbi->mem_lower, (unsigned) mbi->mem_upper);

	/* Is boot_device valid? */
	if (CHECK_FLAG (mbi->flags, 1))
		printf ("boot_device = 0x%#x\n", (unsigned) mbi->boot_device);

	/* Is the command line passed? */
	if (CHECK_FLAG (mbi->flags, 2))
		printf ("cmdline = %s\n", (char *) mbi->cmdline);

	if (CHECK_FLAG (mbi->flags, 3)) {
		int mod_count = 0;
		int i;
		module_t* mod = (module_t*)mbi->mods_addr;
		while(mod_count < mbi->mods_count) {
			printf("Module %d loaded at address: 0x%#x\n", mod_count, (unsigned int)mod->mod_start);
			printf("Module %d ends at address: 0x%#x\n", mod_count, (unsigned int)mod->mod_end);
			printf("First few bytes of module:\n");
			for(i = 0; i<16; i++) {
				printf("0x%x ", *((char*)(mod->mod_start+i)));
			}
			printf("\n");
			mod_count++;
		}
	}
	/* Bits 4 and 5 are mutually exclusive! */
	if (CHECK_FLAG (mbi->flags, 4) && CHECK_FLAG (mbi->flags, 5))
	{
		printf ("Both bits 4 and 5 are set.\n");
		return;
	}

	/* Is the section header table of ELF valid? */
	if (CHECK_FLAG (mbi->flags, 5))
	{
		elf_section_header_table_t *elf_sec = &(mbi->elf_sec);
		
		printf ("elf_sec: num = %u, size = 0x%#x,"
				" addr = 0x%#x, shndx = 0x%#x\n",
				(unsigned) elf_sec->num, (unsigned) elf_sec->size,
				(unsigned) elf_sec->addr, (unsigned) elf_sec->shndx);
	}

	/* Are mmap_* valid? */
	if (CHECK_FLAG (mbi->flags, 6))
	{
		memory_map_t *mmap;

		printf ("mmap_addr = 0x%#x, mmap_length = 0x%x\n",
				(unsigned) mbi->mmap_addr, (unsigned) mbi->mmap_length);
		for (mmap = (memory_map_t *) mbi->mmap_addr;
				(unsigned long) mmap < mbi->mmap_addr + mbi->mmap_length;
				mmap = (memory_map_t *) ((unsigned long) mmap
					+ mmap->size + sizeof (mmap->size)))
			printf (" size = 0x%x,     base_addr = 0x%#x%#x\n"
					"     type = 0x%x,  length    = 0x%#x%#x\n",
					(unsigned) mmap->size,
					(unsigned) mmap->base_addr_high,
					(unsigned) mmap->base_addr_low,
					(unsigned) mmap->type,
					(unsigned) mmap->length_high,
					(unsigned) mmap->length_low);
	}

	/* Construct an LDT entry in the GDT */
	{
		seg_desc_t the_ldt_desc;
		the_ldt_desc.granularity    = 0;
		the_ldt_desc.opsize         = 1;
		the_ldt_desc.reserved       = 0;
		the_ldt_desc.avail          = 0;
		the_ldt_desc.present        = 1;
		the_ldt_desc.dpl            = 0x0;
		the_ldt_desc.sys            = 0;
		the_ldt_desc.type           = 0x2;

		SET_LDT_PARAMS(the_ldt_desc, &ldt, ldt_size);
		ldt_desc_ptr = the_ldt_desc;
		lldt(KERNEL_LDT);
	}

	/* Construct a TSS entry in the GDT */
	{
		seg_desc_t the_tss_desc;
		the_tss_desc.granularity    = 0;
		the_tss_desc.opsize         = 0;
		the_tss_desc.reserved       = 0;
		the_tss_desc.avail          = 0;
		the_tss_desc.seg_lim_19_16  = TSS_SIZE & 0x000F0000;
		the_tss_desc.present        = 1;
		the_tss_desc.dpl            = 0x0;
		the_tss_desc.sys            = 0;
		the_tss_desc.type           = 0x9;
		the_tss_desc.seg_lim_15_00  = TSS_SIZE & 0x0000FFFF;

		SET_TSS_PARAMS(the_tss_desc, &tss, tss_size);

		tss_desc_ptr = the_tss_desc;

		tss.ldt_segment_selector = KERNEL_LDT;
		tss.ss0 = KERNEL_DS;
		tss.esp0 = 0x800000;
		ltr(KERNEL_TSS);
	}

	/* Initialize IDT exceptions 0x00-0x1F defined by Intel idt[0] to idt[31] */
	int i;
	for (i=0; i<32; i++)
	{
		idt[i].seg_selector=KERNEL_CS; /* select kernal code segment */
		idt[i].reserved4=0;            /* unused byte set to 0 */
		idt[i].reserved3=1;            /* set [10:8] to 111 for trap gate (exceptions) */
		idt[i].reserved2=1;
		idt[i].reserved1=1;
		idt[i].size=1;                 /* 32 bit */
		idt[i].reserved0=0;            /* set to 0 for interrupt gates */
		idt[i].dpl=0;                  /* kernel priv */
		idt[i].present=1;              /* Entry is present in IDT */
	}

	/* Initialize keyboard descriptor 0x21 (idt[33]) */
		idt[33].seg_selector=KERNEL_CS; /* select kernal code segment */
		idt[33].reserved4=0;            /* unused byte set to 0 */
		idt[33].reserved3=0;            /* set [10:8] to 110 for interrupt gate */
		idt[33].reserved2=1;
		idt[33].reserved1=1;
		idt[33].size=1;                 /* 32 bit */
		idt[33].reserved0=0;            /* set to 0 for interrupt gates */
		idt[33].dpl=0;                  /* kernel priv */
		idt[33].present=1;              /* Entry is present in IDT */

	/* Initialize RTC descriptor 0x28 (idt[40]) */
		idt[40].seg_selector=KERNEL_CS; /* select kernal code segment */
		idt[40].reserved4=0;            /* unused byte set to 0 */
		idt[40].reserved3=0;            /* set [10:8] to 110 for interrupt gate */
		idt[40].reserved2=1;
		idt[40].reserved1=1;
		idt[40].size=1;                 /* 32 bit */
		idt[40].reserved0=0;            /* set to 0 for interrupt gates */
		idt[40].dpl=0;                  /* kernel priv */
		idt[40].present=1;              /* Entry is present in IDT */

	/* Initialize system call descriptor 0x80 (idt[128]) */
		idt[128].seg_selector=KERNEL_CS; /* select kernal code segment */
		idt[128].reserved4=0;            /* unused byte set to 0 */
		idt[128].reserved3=0;            /* set [10:8] to 110 for interrupt gate */
		idt[128].reserved2=1;
		idt[128].reserved1=1;
		idt[128].size=1;                 /* 32 bit */
		idt[128].reserved0=0;            /* set to 0 for interrupt gates */
		idt[128].dpl=3;                  /* ring3 user mode privilege */
		idt[128].present=1;              /* Entry is present in IDT */
		
	/* Initialize ISR addresses */
	SET_IDT_ENTRY(idt[0], _exception_handler0);
	SET_IDT_ENTRY(idt[1], _exception_handler1);
	SET_IDT_ENTRY(idt[2], _exception_handler2);
	SET_IDT_ENTRY(idt[3], _exception_handler3);
	SET_IDT_ENTRY(idt[4], _exception_handler4);
	SET_IDT_ENTRY(idt[5], _exception_handler5);
	SET_IDT_ENTRY(idt[6], _exception_handler6);
	SET_IDT_ENTRY(idt[7], _exception_handler7);
	SET_IDT_ENTRY(idt[8], _exception_handler8);
	SET_IDT_ENTRY(idt[9], _exception_handler9);
	SET_IDT_ENTRY(idt[10], _exception_handler10);
	SET_IDT_ENTRY(idt[11], _exception_handler11);
	SET_IDT_ENTRY(idt[12], _exception_handler12);
	SET_IDT_ENTRY(idt[13], _exception_handler13);
	SET_IDT_ENTRY(idt[14], _exception_handler14);
	SET_IDT_ENTRY(idt[15], _exception_handler15);
	SET_IDT_ENTRY(idt[16], _exception_handler16);
	SET_IDT_ENTRY(idt[17], _exception_handler17);
	SET_IDT_ENTRY(idt[18], _exception_handler18);
	SET_IDT_ENTRY(idt[19], _exception_handler19);
	SET_IDT_ENTRY(idt[20], _exception_handler20);
	SET_IDT_ENTRY(idt[21], _exception_handler21);
	SET_IDT_ENTRY(idt[22], _exception_handler22);
	SET_IDT_ENTRY(idt[23], _exception_handler23);
	SET_IDT_ENTRY(idt[24], _exception_handler24);
	SET_IDT_ENTRY(idt[25], _exception_handler25);
	SET_IDT_ENTRY(idt[26], _exception_handler26);
	SET_IDT_ENTRY(idt[27], _exception_handler27);
	SET_IDT_ENTRY(idt[28], _exception_handler28);
	SET_IDT_ENTRY(idt[29], _exception_handler29);
	SET_IDT_ENTRY(idt[30], _exception_handler30);
	SET_IDT_ENTRY(idt[31], _exception_handler31);

	SET_IDT_ENTRY(idt[33], _keyboard_handler);
	SET_IDT_ENTRY(idt[40], _rtc_handler);
	SET_IDT_ENTRY(idt[128], _syscall_handler);


		
	/*	Load the IDT with ptr to IDTR */
	lidt(idt_desc_ptr);
		
	/* Set up page tables */
	
	int j;
	pt0[0] = 0;		//first page set to 0 so no NULL reference
	for(j=1; j < NUM_PAGES; j++)
	{
		pt0[j] = (j<<12) | 0xFFF;
	}
	
	/* Set up page directory array */
	
	int add = (int) pt0; //cast the adddress of the page table as an int
	add = add & 0xFFFFF000; //clear lower 12 bits
	add = add | 0x007; //bits for pde setting size to 4KB and permissions
	page_directory_array[0] =(int) add;
	page_directory_array[1] =(int) 0x00400087; //10 MSB of 4MB kernel page
	
	for(j=2; j < NUM_PAGES; j++)
	{
		page_directory_array[j] = 0x2;
	}
	
	asm volatile(
			"movl page_directory_array, %%eax;"
			"movl %%eax, %%cr3;"
			"movl %%cr4, %%eax;"
			"orl $0x00000010, %%eax;"
			"movl %%eax, %%cr4;"
			"movl %%cr0, %%eax;"
			"orl $0x80000000, %%eax;"
			"movl %%eax, %%cr0;     \
			" : /*no outputs*/
			  : /* no inputs*/
			  : "eax"
	);	
		
	
	
	
	/* Init the PIC */
	i8259_init();

	/* Initialize devices, memory, filesystem, enable device interrupts on the
	 * PIC, any other initialization stuff... */
     
 
	rtc_init();
	//rtc_open();
	
	
	/* Keyboard */
   	keyboard_init();
	clear();
	
	terminal_open();
	
	/* Enable interrupts */
	/* Do not enable the following until after you have set up your
	 * IDT correctly otherwise QEMU will triple fault and simple close
	 * without showing you any output */
	//printf("Enabling Interrupts\n");
	sti();
	
	/* Proving that rtc_read() works. */
	// RTC
	/*i = 5;
	while(i-- > 0)
    {
    	int freq = rtc_read();
    	printf("An interrupt just occured at frequency: %d. \n", freq);
    }
    rtc_close();*/

    // File System
    
	clear();
	
	close_tasks();
	
	execute((uint8_t *)"shell",(uint8_t *)" \0");
	
	// Terminal
	terminal_write((uint8_t *)"this is a write test\n",21);
	
	uint8_t * buffer;
	
	uint32_t keycount;
	/* Execute the first program (`shell') ... */
	while(1){
		printf("> ");
		buffer = terminal_read(&keycount);
		printf("this is the buffer: %s", buffer);
	}
	
	/* Spin (nicely, so we don't chew up cycles) */
	asm volatile(".1: hlt; jmp .1;");
}

void
exception_print(int number)
{
	printf("Exception Number: %d\n", number);
	while(1);
	return;
}


void
close_tasks()
{
	control_block_t * cb = (control_block_t *) TCB0;
	cb->present=1;
	cb = (control_block_t *) TCB1;
	cb->present=0;
	cb->thismem=MB8;
	cb->thisks=TKS1;
	cb = (control_block_t *) TCB2;
	cb->present=0;
	cb->thismem=MB12;
	cb->thisks=TKS2;
	cb = (control_block_t *) TCB3;
	cb->present=0;
	cb->thismem=MB16;
	cb->thisks=TKS3;
	cb = (control_block_t *) TCB4;
	cb->present=0;
	cb->thismem=MB20;
	cb->thisks=TKS4;
	cb = (control_block_t *) TCB5;
	cb->present=0;
	cb->thismem=MB24;
	cb->thisks=TKS5;
	cb = (control_block_t *) TCB6;
	cb->present=0;
	cb->thismem=MB28;
	cb->thisks=TKS6;
}

