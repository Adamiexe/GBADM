#include <emu.h>
#include <windows.h>
#include <stdio.h>

#define MAX_ROMS 256

int main(int argc, char** argv) {

    if (argc < 2) {
        WIN32_FIND_DATAA findData;

        HANDLE hFind = FindFirstFileA("rom\\*.*", &findData);

        char roms[MAX_ROMS][MAX_PATH];
        int romCount = 0;

        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                    const char* ext = strrchr(findData.cFileName, '.');
                    if (ext != NULL && (_stricmp(ext, ".gb") == 0 || _stricmp(ext, ".gbc") == 0)) {
                        if (romCount < MAX_ROMS) {
                            strncpy_s(roms[romCount], MAX_PATH, findData.cFileName, _TRUNCATE);

                            romCount++;
                        }
                    }
                }
            } while (FindNextFileA(hFind, &findData) != 0 && romCount < MAX_ROMS);
            FindClose(hFind);
        }
        if (romCount == 0) {
            fprintf(stderr, "No games (.gb or .gbc) found in the ‘rom’ folder.\n");
            return 1;
        }

        printf("--- List of available games ---\n");
        for (int i = 0; i < romCount; i++) {
            printf("[%d] %s\n", i + 1, roms[i]);
        }
        printf("----------------------------------\n");
        printf("Enter the number of the game to launch : ");
        char input[16];
        if (!fgets(input, sizeof(input), stdin)) {
            return 1;
        }

        int choice = atoi(input);
        if (choice < 1 || choice > romCount) {
            fprintf(stderr, "Invalid choice. Closing the emulator.\n");
            return 1;
        }

        char romPath[MAX_PATH];
        snprintf(romPath, sizeof(romPath), "rom\\%s", roms[choice - 1]);

        char* new_argv[2];
        new_argv[0] = argv[0];
        new_argv[1] = romPath;

        return emu_run(2, new_argv);
    }

    return emu_run(argc, argv);
}
