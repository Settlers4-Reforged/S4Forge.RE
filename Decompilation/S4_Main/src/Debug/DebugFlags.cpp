

int DEBUG_FLAGS[307];
bool debug;

int s_iDebugSections;

int GetAvailableSection() {
    if(++s_iDebugSections < 255)
        return s_iDebugSections;
    else
        return -1;
}