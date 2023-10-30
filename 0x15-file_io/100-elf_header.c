#include "main.h"
#include <stdlib.h>

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, it prints an error message
 * to stderr and exits with the code 98.
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 ||
		e_ident[EI_MAG1] != ELFMAG1 ||
		e_ident[EI_MAG2] != ELFMAG2 ||
		e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(ERROR_EXIT_CODE);
	}
}

/**
 * print_error - Prints an error message to stderr and exits with code 98.
 * @message: The error message to print.
 */
void print_error(char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(ERROR_EXIT_CODE);
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:\t");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x%s", e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * print_class - Prints the class of an ELF header.
 * @class: The class of the ELF header.
 */
void print_class(unsigned char class)
{
	printf("  Class:\t\t\t\t");
	switch (class)
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", class);
		break;
	}
}

/**
 * print_data - Prints the data encoding of an ELF header.
 * @data: The data encoding of the ELF header.
 */
void print_data(unsigned char data)
{
	printf("  Data:\t\t\t\t");
	switch (data)
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", data);
		break;
	}
}

/**
 * print_version - Prints the version of an ELF header.
 * @version: The version of the ELF header.
 */
void print_version(unsigned char version)
{
	printf("  Version:\t\t\t%d", version);
	switch (version)
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @osabi: The OS/ABI of the ELF header.
 */
void print_osabi(unsigned char osabi)
{
	printf("  OS/ABI:\t\t\t");
	switch (osabi)
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", osabi);
		break;
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @abi: The ABI version of the ELF header.
 */
void print_abi(unsigned char abi)
{
	printf("  ABI Version:\t\t\t%d\n", abi);
}

/**
 * print_type - Prints the type of an ELF header.
 * @type: The type of the ELF header.
 */
void print_type(unsigned int type)
{
	printf("  Type:\t\t\t\t");
	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
		break;
	}
}

/**
 * print_entry - Prints the entry point address of an ELF header.
 * @entry: The entry point address of the ELF header.
 */
void print_entry(unsigned long int entry)
{
	printf("  Entry point address:\t\t%#lx\n", entry);
}

int main(int argc, char *argv[])
{
	int file_d, r_result;
	Elf64_Ehdr *header = malloc(sizeof(Elf64_Ehdr));

	if (header == NULL)
	{
		dprintf(STDERR_FILENO, "Memory allocation failed\n");
		exit(ERROR_EXIT_CODE);
	}

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(ERROR_EXIT_CODE);
	}

	file_d = open(argv[1], O_RDONLY);
	if (file_d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file\n");
		free(header);
		exit(ERROR_EXIT_CODE);
	}

	r_result = read(file_d, header, sizeof(Elf64_Ehdr));
	if (r_result != sizeof(Elf64_Ehdr) || lseek(file_d, 0, SEEK_SET) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file\n");
		free(header);
		exit(ERROR_EXIT_CODE);
	}

	if (header->e_ident[EI_MAG0] != ELFMAG0 || header->e_ident[EI_MAG1] != ELFMAG1 ||
			header->e_ident[EI_MAG2] != ELFMAG2 || header->e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		free(header);
		exit(ERROR_EXIT_CODE);
	}

	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident[EI_CLASS]);
	print_data(header->e_ident[EI_DATA]);
	print_version(header->e_ident[EI_VERSION]);
	print_osabi(header->e_ident[EI_OSABI]);
	print_abi(header->e_ident[EI_ABIVERSION]);
	print_type(header->e_type);
	print_entry(header->e_entry);

	free(header);
	close(file_d);
	return (0);
}
