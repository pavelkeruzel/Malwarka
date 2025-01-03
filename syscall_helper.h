#ifndef SYSCALLHELPER_H
#define SYSCALLHELPER_H

// Function to get the System Service Number (SSN) for a given function name
int getSyscallID(const char* funcName);

#endif // SYSCALLHELPER_H
