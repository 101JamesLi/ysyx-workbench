// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vram__Syms.h"


void Vram___024root__trace_chg_sub_0(Vram___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vram___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root__trace_chg_top_0\n"); );
    // Init
    Vram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram___024root*>(voidSelf);
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vram___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vram___024root__trace_chg_sub_0(Vram___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->ram__DOT__ram[0]),8);
        bufp->chgCData(oldp+1,(vlSelf->ram__DOT__ram[1]),8);
        bufp->chgCData(oldp+2,(vlSelf->ram__DOT__ram[2]),8);
        bufp->chgCData(oldp+3,(vlSelf->ram__DOT__ram[3]),8);
        bufp->chgCData(oldp+4,(vlSelf->ram__DOT__ram[4]),8);
        bufp->chgCData(oldp+5,(vlSelf->ram__DOT__ram[5]),8);
        bufp->chgCData(oldp+6,(vlSelf->ram__DOT__ram[6]),8);
        bufp->chgCData(oldp+7,(vlSelf->ram__DOT__ram[7]),8);
    }
    bufp->chgBit(oldp+8,(vlSelf->clk));
    bufp->chgBit(oldp+9,(vlSelf->wen));
    bufp->chgCData(oldp+10,(vlSelf->din),8);
    bufp->chgCData(oldp+11,(vlSelf->addrin),3);
    bufp->chgCData(oldp+12,(vlSelf->addrout),3);
    bufp->chgCData(oldp+13,(vlSelf->dout),8);
}

void Vram___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root__trace_cleanup\n"); );
    // Init
    Vram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram___024root*>(voidSelf);
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
