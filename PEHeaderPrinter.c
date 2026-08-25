#include <stdio.h>

#define SIZE 8192

unsigned char buffer[SIZE];
int i ;
unsigned short number_of_sections;
unsigned short machine_t;

void signature() {
	
	unsigned int pe = *(unsigned int*)&buffer[0x3c];
	
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

void check_sum() {

	printf("CheckSum : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}

void sub_system() {

	printf("Subsystem : ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");

}

void DLL_Charac() {

	printf("DllCharacteristics : ");

	for (int k = 0; k < 2; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned short);
	printf("\n");

}

void size_stack() {

	if (machine_t == 0x010b) {

		printf("SizeOfStackReserve : ");

		for (int k = 0; k < 4; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned int);


	}
	else if (machine_t == 0x020b) {

		printf("SizeOfStackReserve : ");

		for (int k = 0; k < 8; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned long long);

	}

	printf("\n");

}


void stack_commit() {

	if (machine_t == 0x010b) {

		printf("SizeOfStackCommit : ");

		for (int k = 0; k < 4; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned int);


	}
	else if (machine_t == 0x020b) {

		printf("SizeOfStackCommit : ");

		for (int k = 0; k < 8; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned long long);

	}

	printf("\n");

}

void size_heap() {

	if (machine_t == 0x010b) {

		printf("SizeOfHeapReserve : ");

		for (int k = 0; k < 4; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned int);


	}
	else if (machine_t == 0x020b) {

		printf("SizeOfHeapReserve : ");

		for (int k = 0; k < 8; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned long long);

	}

	printf("\n");

}

void heap_commit() {

	if (machine_t == 0x010b) {

		printf("SizeOfHeapCommit : ");

		for (int k = 0; k < 4; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned int);

	}
	else if (machine_t == 0x020b) {

		printf("SizeOfHeapCommit : ");

		for (int k = 0; k < 8; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned long long);

	}

	printf("\n");

}

void loader() {

	printf("LoaderFlags : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");

}

void number_rva() {

	printf("#NumberOfRvaAndSizes : ");

	for (int k = 0; k < 4; k++) {
		printf("%02X ", buffer[i + k]);
	}

	i += sizeof(unsigned int);
	printf("\n");
	printf("\n");
	printf("\n");
}


const char* names[] = {
		
	"ExportTable",
	"SizeOfExportTable",
	"ImportTable",
	"SizeOfImportTable",
	"ResourceTable",
	"SizeOfResourceTable",
	"ExceptionTable",
	"SizeOfExceptionTable",
	"CertificateTable",
	"SizeOfCertificateTable",
	"BaseRelocationTable",
	"SizeOfBaseRelocationTable",
	"Debug",
	"SizeOfDebug",
	"ArchitectureData",
	"SizeOfArchitectureData",
	"GlobalPtr",
	"4 byte zero",
	"TLSTable",
	"SizeOfTLSTAble",
	"LoadConfigTable",
	"SizeOfLoadConfigTable",
	"BoundImport",
	"SizeOfBoundImport",
	"ImportAddressTable",
	"SizeOfImportAddressTable",
	"DelayImportDescriptor",
	"SizeOfDelayImportDescriptor",
	"CLRRuntimeHeader",
	"SizeOfCLRRuntimeHeader",
	"4 byte zero",
	"4 byte zero"
};


void data_directories() {

	int c = 16; // 0x10 
	int name = 0;

	for (int j = 0; j < c; j++) {

		printf("%s : ",names[name++]);

		for (int k = 0; k < 4; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned int);
		printf("\n");

		printf("%s : ", names[name++]);

		for (int k = 0; k < 4; k++) {
			printf("%02X ", buffer[i + k]);
		}

		i += sizeof(unsigned int);
		printf("\n");


	}


	printf("\n");
	printf("\n");
	printf("\n");

}

const char* sections[] = {
	"",
	"VirtualSize",
	"VirtualAdress",
	"SizeOfRawData",
	"PointerToRawData",
	"PointerToRelocaitons",
	"PointerToLineNumbers",
	"NumberOfRelocations",
	"NumberOfLineNumbers",
	"Characteristics",

};

void section_table() {

	for (int j = 0; j < number_of_sections; j++) {
		
		int field = 0;
		printf("%s",sections[field++]);

		for (int k = 0; k < 8; k++) {

			int c = buffer[i + k];

			if (c >= 32 && c <= 126) {

				printf("%c", c);
			}
			else {
				printf(".");

			}

		}
				
		i += 8;
		printf("\n");
		
				
		for (; field < 10; field++) {
			
			if (field == 7 || field == 8) {
				
				printf("%s : ", sections[field]);

				for (int k = 0; k < 2; k++) {
					printf("%02X ", buffer[i + k]);
				}

				i += sizeof(unsigned short);
				printf("\n");
				continue;

			}

			printf("%s : ", sections[field]);

			for (int k = 0; k < 4; k++) {
				printf("%02X ", buffer[i + k]);
			}

			i += sizeof(unsigned int);
			printf("\n");
			
			
		}
	
	}

}



int main(int argc, char* argv[]) {
	
	if (!argv[1])return 1;

	FILE *file = fopen(argv[1], "rb");

	if (!file)return 1;

	fread(buffer,1, SIZE,file);
	fclose(file);

	/*coff header*/
	signature();
	machine();
	number_sections();
	time_date();
	pointer_to_symbol();
	number_of_symbol();
	size_optional_header();
	character();
	
	/*standart coff header*/
	magic();
	major_linker();
	minor_linker();
	size_of_code();
	size_of_init();
	size_of_uninit();
	address_of_entry();
	base_of_code();
	base_of_data();

	/*windows specific fields*/
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
	check_sum();
	sub_system();
	DLL_Charac();
	size_stack();
	stack_commit();
	size_heap();
	heap_commit();
	loader();
	number_rva();

	/* data directories*/
	data_directories();
	
	/* section table */
	section_table();


	system("pause");

}

