#include "ProcMngr.h"

int main() {
    const char szSignature[] = "\x48\x8b\x45\x28\x01\x48";
    char szOpCode[] = "\x90\x90\x90";

    ProcessManager procManager("ac_client");

    procManager.SignaturePayload(szSignature, szOpCode, strlen(szSignature), strlen(szOpCode), 64, 4);

    exit(EXIT_SUCCESS);
}