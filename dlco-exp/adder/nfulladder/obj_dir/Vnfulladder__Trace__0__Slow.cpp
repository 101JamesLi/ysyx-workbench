// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vnfulladder__Syms.h"


VL_ATTR_COLD void Vnfulladder___024root__trace_init_sub__TOP__0(Vnfulladder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vnfulladder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnfulladder___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"in_x", false,-1, 7,0);
    tracep->declBus(c+2,"in_y", false,-1, 7,0);
    tracep->declBus(c+3,"out_c", false,-1, 7,0);
    tracep->pushNamePrefix("nfulladder ");
    tracep->declBus(c+1,"in_x", false,-1, 7,0);
    tracep->declBus(c+2,"in_y", false,-1, 7,0);
    tracep->declBus(c+3,"out_c", false,-1, 7,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vnfulladder___024root__trace_init_top(Vnfulladder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vnfulladder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnfulladder___024root__trace_init_top\n"); );
    // Body
    Vnfulladder___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vnfulladder___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vnfulladder___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vnfulladder___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vnfulladder___024root__trace_register(Vnfulladder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vnfulladder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnfulladder___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vnfulladder___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vnfulladder___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vnfulladder___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vnfulladder___024root__trace_full_sub_0(Vnfulladder___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vnfulladder___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnfulladder___024root__trace_full_top_0\n"); );
    // Init
    Vnfulladder___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnfulladder___024root*>(voidSelf);
    Vnfulladder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vnfulladder___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vnfulladder___024root__trace_full_sub_0(Vnfulladder___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vnfulladder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnfulladder___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->in_x),8);
    bufp->fullCData(oldp+2,(vlSelf->in_y),8);
    bufp->fullCData(oldp+3,(vlSelf->out_c),8);
}
