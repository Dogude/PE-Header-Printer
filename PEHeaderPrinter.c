#include <stdio.h>

unsigned char buffer[4096];
int i ;
unsigned short number_of_sections;
unsigned short machine_t;

void signature() {
	
	unsigned int pe = *(unsigned int*)&buffer[60];
	
	i = pe;

	printf("Signature : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);	
	printf("\n");

}

void machine() {

	printf("Machine : ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");
}


void number_sections() {

	unsigned short field = *(unsigned short*)&buffer[i];
	
	number_of_sections = field;

	printf("#NumberOfSections : ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");

}


void time_date() {

	printf("TimeDateStamp : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}

void pointer_to_symbol() {

	printf("PointerToSymbolTable : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}


void number_of_symbol() {

	printf("#NumberOfSymbolTable : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}

void size_optional_header() {

	printf("SizeOfOptionalHeader : ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");

}

void character() {

	printf("Characteristics: ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n\n\n");

}


void magic() {

	unsigned short field = *(unsigned short*)&buffer[i];

	machine_t = field;

	printf("Magic : ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");

}


void major_linker() {

	printf("MajorLinkerVersion : ");

	for (int k = 0; k < 1; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned char);
	printf("\n");

}

void minor_linker() {

	printf("MinorLinkerVersion : ");

	for (int k = 0; k < 1; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned char);
	printf("\n");

}


void size_of_code() {

	printf("SizeOfCode : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}

void size_of_init() {

	printf("SizeOfInitializedData : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}


void size_of_uninit() {

	printf("SizeOfUninitializedData : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}


void address_of_entry() {

	printf("AdressOfEntryPoint : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}


void base_of_code() {

	printf("BaseOfCode : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}

void base_of_data() {

	if (machine_t != 0x010b) {
		printf("\n\n\n");
		return;
	}

	printf("BaseOfData : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n\n\n");

}

void image_base() {

	if (machine_t == 0x010b) {

		printf("ImageBase(32bit) : ");

		for (int k = 0; k < 4; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned int);

	}
    else if (machine_t == 0x020b) {
		
		printf("ImageBase(64bit) : ");

		for (int k = 0; k < 8; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned long long);
		
	}
	
	printf("\n");

}

void section_align() {

	printf("SectionAlignment : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");
}

void file_align() {

	printf("FileAlignment : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");
}

void major_os() {

	printf("MajorOperatingSystemVersion : ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");

}

void minor_os() {

	printf("MinorOperatingSystemVersion: ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");
	
}

void major_image() {

	printf("MajorImageVersion: ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");

}

void minor_image() {

	printf("MinorImageVersion : ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");

}

void major_sub() {

	printf("MajorSubsystemVersion: ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");

}

void minor_sub() {

	printf("MinorSubsystemVersion : ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");

}

void win_version() {

	printf("Win32VersionValue : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}

void size_image() {

	printf("SizeOfImage : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}

void size_headers() {

	printf("SizeOfHeaders : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}

int main(int argc, char* argv[]) {
	
	FILE *file = fopen(argv[1], "rb");

	fread(buffer,1,4096,file);
	fclose(file);

	signature();
	machine();
	number_sections();
	time_date();
	pointer_to_symbol();
	number_of_symbol();
	size_optional_header();
	character();
	
	magic();
	major_linker();
	minor_linker();
	size_of_code();
	size_of_init();
	size_of_uninit();
	address_of_entry();
	base_of_code();
	base_of_data();

	image_base();
	section_align();
	file_align();
	major_os();
	minor_os();
	major_image();
	minor_image();
	major_sub();
	minor_sub();
	win_version();
	size_image();
	size_headers();

	system("pause");

}

