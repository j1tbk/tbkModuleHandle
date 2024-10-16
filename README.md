# tbkModuleHandle
A simple assemlby, C replacement for GetModuleHandleW from the windows libloaderAPI.h. It retrieves the base address from the LDR_DATA_TABLE_ENTRY Structure. The functions are written in assembly and implemented in C. It avoids including libraries such as windows.h or winternl.h.
