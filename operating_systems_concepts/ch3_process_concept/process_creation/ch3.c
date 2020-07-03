// C program for creating a seperate process using the Windows API.

#include <stdio.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Allocate memory.
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create child process.
    if (!CreateProcess(NULL,                                 // No module name (use command line)
                       "C:\\Windows\\System32\\mspaint.exe", // Command line
                       NULL,                                 // Don't inherit process handle
                       NULL,                                 // Don't inherit thread handle
                       FALSE,                                // Disable handle inheritance
                       0,                                    // No creation flag
                       NULL,                                 // User parent's environment block
                       NULL,                                 // Use parent's existing directory
                       &si,                                  // Pointer to STARTUPINFO structure
                       &pi))                                 // Pointer to PROCESS_INFORMATION structure
    {
        fprintf(stderr, "Create Process Failed.");
        return -1;
    }

    // Parent will wait for the child to complete.
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Child Complete.");

    // Close process and thread handles.
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
