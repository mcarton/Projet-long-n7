void memcpy(void* source, void* destination, int size)
{
    int i;
    for(i = 0; i < size; i=i+1)
    {
        *((int*)destination + i) = *((int*)source + i);
    }
}

bool memcmp(void* b1, void* b2, int size)
{
    int i;
    for(i = 0; i < size; i=i+1)
    {
        if(*((int*)b1 + i) != *((int*)b2 + i))
        {
            return false;
        }
    }
    return true;
}

// used internally by the malloc
void *malloc_start;

// palkeo's malloc
// Very simple system : in block. Before each block we have a header.
// The last bit tell if the block is allocated or not.
// The rest is the size of the block (so we shift >> 1, and we have the size)

// get the nearest power of two that is bigger than the parameter.
int nbp2(int n)
{
    int s = n - 1;
    n = 1;
    while((bool)s)
    {
        s = s >> 1;
        n = n << 1;
    }
    return n;
}

void* malloc(int size) {
    size = nbp2(size);

    int* c = (int*)malloc_start;
    while (
        (bool)(*c & 1)
     || (((*c >> 1) != size) && ((bool)*c))
    ) {
        c = c + (*c >> 1) + 1;
    }
    // c now points to an unused block header of the right size

    int bs = *c >> 1;
    if(bs == 0) { // end of the blocklist
        *c = (size << 1) + 1;
        *(c + size + 1) = 0;
    }
    else {
        // We could split the block here
        *c = *c | 1;
    }
    return (void*)c + 1;
}

int free(void* addr) {
    int* c = (int*)malloc_start;
    while (c < addr - 1) {
        c = c + (*c >> 1) + 1;
        if(*c == 0) {
            return -1; // the address is after the last allocated block...
        }
    }

    // can't find block or already freed
    if ((c != addr - 1) || ((*c & 1) == 0)) {
        return -1;
    }

    *c = *c & 0xFFFFFFFE;
    if (*((int*) (*c >> 1) + 1) == 0) {
        *c = 0; // if it was the last block...
    }

    // We could merge with the next block if it is empty here
    return 0;
}

void* realloc(void* addr, int new_size)
{
    new_size = nbp2(new_size);

    // taken from the free implementation
    // ---
    int* c = (int*)malloc_start;
    while (c < addr - 1) {
        c = c + (*c >> 1) + 1;
        if(*c == 0) {
            return (void*)-1; // the address is after the last allocated block...
        }
    }
    // can't find block or already freed
    if ((c != addr - 1) || ((*c & 1) == 0)) {
        return (void*)-1;
    }
    // ---

    // already the good size
    if((*c >> 1) >= new_size)
    {
        return addr;
    }
    
    // here we will need to allocate a new block and copy it.
    void* new_addr = malloc(new_size);
    memcpy(addr, new_addr, *c >> 1);
    if(free(addr) == -1)
    {
        return (void*)-1;
    }
    return new_addr;
}
