#pragma once
#include <stdint.h>

typedef struct 
{
   
    uint32_t ds;                                            //manually pushed 
    uint32_t edi, esi, ebp, useless, ebx, edx, ecx, eax;    
    uint32_t interrupt, error;                              // we push interrupt, error is pushed automatically (or our dummy)
    uint32_t eip, cs, eflags, esp, ss;                      
} __attribute__((packed)) Registers;

typedef void (*ISRHandler)(Registers* regs);

void i686_ISR_Initialize();
void i686_ISR_RegisterHandler(int interrupt, ISRHandler handler);
